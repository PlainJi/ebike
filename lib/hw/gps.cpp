#include "gps.h"

#include <cmath>
#include <vector>
#include "sdcard.h"
#include <HardwareSerial.h>

#define UART1_RX 18                 // 接GPS模块的TX
#define UART1_TX 17                 // 接GPS模块的RX
#define EARTH_RADIUS    (6371.009)  // 地球半径
#define KNOTS_TO_KMH    (1.852)     // 节转km/h
#define toRadians(deg)  ((deg) * M_PI / 180.0)

static const char *tag = "gps";
HardwareSerial gpsSerial(1);    // 创建硬件串口对象
GNSSData gnss_data;
static char nmea_buffer[128] = {0};
static char temp_buffer[128] = {0};
static bool get_initial_pos = false;

void gps_init() {
  memset(&gnss_data, 0, sizeof(gnss_data));
  gpsSerial.setRxBufferSize(512);
  gpsSerial.begin(9600, SERIAL_8N1, UART1_RX, UART1_TX);
  ESP_LOGI("gps_init", "GPS 初始化完成，等待数据...");
}

// 将度分格式（DDMM.MMMMM）转换为十进制度格式（DD.DDDDD）
double convertToDecimalDegrees(double degMin, char direction) {
  double degrees = static_cast<int>(degMin / 100); // 提取度
  double minutes = degMin - degrees * 100;        // 提取分
  double decimalDegrees = degrees + minutes / 60.0; // 转换为十进制度
  if (direction == 'S' || direction == 'W') {
      decimalDegrees *= -1; // 南纬或西经为负
  }
  return decimalDegrees;
}

// return distance (m)
double distanceBetween(double lat1, double lon1, double lat2, double lon2) {
  // 将经纬度从度转换为弧度
  double phi1 = toRadians(lat1);
  double phi2 = toRadians(lat2);
  double deltaPhi = toRadians(lat2 - lat1);
  double deltaLambda = toRadians(lon2 - lon1);

  // 应用 Haversine 公式
  double a = sin(deltaPhi / 2) * sin(deltaPhi / 2) + \
             cos(phi1) * cos(phi2) * \
             sin(deltaLambda / 2) * sin(deltaLambda / 2);
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));

  // 计算距离
  return EARTH_RADIUS * c * 1000;
}

// 将时间格式（HHMMSS.SSS）转换为 hh:mm:ss
void formatTime(const char *time, GNSSData &data) {
  int hh = 0, mm = 0, ss = 0, ms = 0;
  if (time != nullptr && strlen(time) >= 6) { // 检查输入是否有效
      sscanf(time, "%2d%2d%2d.%3d", &hh, &mm, &ss, &ms);
  }
  if (ms > 900) {
    ss += 1;
  }
  sprintf(data.time, "%02d:%02d:%02d", hh, mm, ss); // 格式化时间
  data.hour = hh;
  data.minute = mm;
  data.second = ss;
}

// 将日期格式（DDMMYY）转换为 YYYY-MM-DD
void formatDate(const char *date, GNSSData &data) {
  int dd = 0, mm = 0, yy = 0;
  if (date != nullptr && strlen(date) == 6) { // 检查输入是否有效
      sscanf(date, "%2d%2d%2d", &dd, &mm, &yy);
  }
  sprintf(data.date, "20%02d-%02d-%02d", yy, mm, dd); // 格式化日期
  data.year = yy;
  data.month = mm;
  data.day = dd;
}

int countComma(const char *sentence) {
  // 计算逗号的个数
  int commaCount = 0;
  for (int i = 0; sentence[i] != '\0'; i++) {
    if (sentence[i] == ',') {
        commaCount++;
    }
  }
  return commaCount;
}

NMEAType getNMEAType(const char *sentence) {
  // 检查是否以 $ 开头
  if (sentence == nullptr || sentence[0] != '$') {
      return kNMEA_Invalid;
  }

  // 检查是否包含 RMC 或 GGA
  if(strstr(sentence, "RMC") && (countComma(sentence) == 12)) {
    return kNMEA_RMC;
  } else if (strstr(sentence, "GGA") && (countComma(sentence) == 14)){
    return kNMEA_GGA;
  } else if (strstr(sentence, "TXT") && (countComma(sentence) == 4)){
    return kNMEA_TXT;
  }

  return kNMEA_Invalid;
}

std::vector<std::string> splitNMEA(const char* input) {
  std::vector<std::string> tokens;
  const char* start = input;
  const char* end = input;

  while (*end) {
      if (*end == ',') {
          if (start != end) {
              tokens.emplace_back(start, end);
          } else {
              tokens.emplace_back("");
          }
          start = end + 1;
      }
      end++;
  }

  if (start != end) {
      tokens.emplace_back(start, end);
  } else {
      tokens.emplace_back("");
  }

  return tokens;
}

int parseGGA(const char *gga, GNSSData &data) {
  char time[16] = {0}; // 临时变量，存储原始时间

  std::vector<std::string> fields = splitNMEA(gga);
  //ESP_LOGI(tag, "parseGGA fields=%d, %s", fields.size(), fields[0].c_str());
  // 检查字段数量
  if (fields.size() < 15 || fields[0].substr(3, 6) != "GGA") {
    return false; // 无效的 GGA 语句
  }

  // 解析时间
  strncpy(time, fields[1].c_str(), sizeof(time)-1);
  formatTime(time, data);

  // 解析纬度
  if (!fields[2].empty() && !fields[3].empty()) {
    data.latitude = convertToDecimalDegrees(atof(fields[2].c_str()), fields[3][0]);
  } else {
    data.latitude = 0.0; // 无效纬度
  }

  // 解析经度
  if (!fields[4].empty() && !fields[5].empty()) {
    data.longitude = convertToDecimalDegrees(atof(fields[4].c_str()), fields[5][0]);
  } else {
    data.longitude = 0.0; // 无效经度
  }

  // 解析定位质量
  if (!fields[6].empty()) {
    data.fixQuality = atoi(fields[6].c_str());
  } else {
    data.fixQuality = 0; // 无效定位质量
  }

  // 解析卫星数量
  if (!fields[7].empty()) {
    data.numSats = atoi(fields[7].c_str());
  } else {
    data.numSats = 0; // 无效卫星数量
  }

  // 解析HDOP
  if (!fields[8].empty()) {
    data.hdop = atof(fields[8].c_str());
  } else {
    data.hdop = 0; // 无效卫星数量
  }

  // 解析海拔高度
  if (!fields[9].empty()) {
      data.altitude = atof(fields[9].c_str());
  } else {
    data.altitude = 0.0; // 无效海拔高度
  }

  return true;
}

bool parseRMC(const char *rmc, GNSSData &data) {
  char time[16] = {0}; // 临时变量，存储原始时间
  char date[16] = {0}; // 临时变量，存储原始日期

  std::vector<std::string> fields = splitNMEA(rmc);
  //ESP_LOGI(tag, "parseRMC fields=%d, %s", fields.size(), fields[0].c_str());
  // 检查字段数量
  if (fields.size() < 13 || fields[0].substr(3, 6) != "RMC") {
    return false; // 无效的 GGA 语句
  }

  // 解析时间
  strncpy(time, fields[1].c_str(), sizeof(time)-1);
  formatTime(time, data);

  // 定位状态
  if (!fields[2].empty()) {
    data.fixStatus = fields[2][0];
  } else {
    data.fixStatus = 0;
  }

  // 解析纬度
  if (!fields[3].empty() && !fields[4].empty()) {
    data.latitude = convertToDecimalDegrees(atof(fields[3].c_str()), fields[4][0]);
  } else {
    data.latitude = 0.0; // 无效纬度
  }

  // 解析经度
  if (!fields[5].empty() && !fields[6].empty()) {
    data.longitude = convertToDecimalDegrees(atof(fields[5].c_str()), fields[6][0]);
  } else {
    data.longitude = 0.0; // 无效纬度
  }

  // 速度
  if (!fields[7].empty()) {
    data.speed = atof(fields[7].c_str()) * KNOTS_TO_KMH;
  } else {
    data.speed = 0;
  }
  
  // 航向
  if (!fields[8].empty()) {
    data.course = atof(fields[8].c_str());
  } else {
    data.course = 0;
  }

  // 日期
  strncpy(date, fields[9].c_str(), sizeof(date)-1);
  formatDate(date, data);

  return true;

}

// 读取并保存一条完整的 NMEA 语句到缓冲区
bool readNMEASentence(void) {
  static int index = 0; // 静态变量，保存缓冲区索引
  static bool sentenceStarted = false; // 静态变量，保存是否已经开始读取语句

  // 如果没有数据可读，直接返回 false
  if (!gpsSerial.available()) {
      return false;
  }

  // 清空缓冲区（仅在开始新语句时）
  if (!sentenceStarted) {
      memset(nmea_buffer, 0, sizeof(nmea_buffer));
  }

  while (gpsSerial.available()) {
    char c = gpsSerial.read(); // 读取一个字符

    // 检查是否以 $ 开头
    if (!sentenceStarted) {
        if (c == '$') {
            sentenceStarted = true;
            index = 0; // 重置索引
            nmea_buffer[index++] = c; // 保存 $ 到缓冲区
        }
        continue; // 跳过其他字符，直到找到 $
    }

    // 保存字符到缓冲区
    if (index < sizeof(nmea_buffer) - 1) { // 防止缓冲区溢出
      nmea_buffer[index++] = c;
    } else {
        // 缓冲区已满，重置状态并返回 false
        sentenceStarted = false;
        index = 0;
        return false;
    }

    // 检查是否以 \n 结尾
    if (c == '\n') {
      nmea_buffer[index] = '\0'; // 添加字符串结束符
        sentenceStarted = false; // 重置状态
        index = 0;
        return true; // 返回成功
    }
  }

  // 如果没有读到完整的语句，返回 false
  return false;
}

void gps_update_distance() {
  if (!get_initial_pos) {
    if (((int)gnss_data.latitude) && ((int)gnss_data.longitude) && \
         !(int)gnss_data.last_latitude && !(int)gnss_data.last_longitude) {
      gnss_data.last_latitude = gnss_data.latitude;
      gnss_data.last_longitude = gnss_data.longitude;
      get_initial_pos = true;
    }
  } else {
    gnss_data.dist_with_last_pos = distanceBetween( \
        gnss_data.latitude, gnss_data.longitude, \
        gnss_data.last_latitude, gnss_data.last_longitude);
    gnss_data.last_latitude = gnss_data.latitude;
    gnss_data.last_longitude = gnss_data.longitude;

    char temp_str[16] = {0};
    sprintf(temp_str, "distance %.1f", gnss_data.dist_with_last_pos);
    ESP_LOGI(tag, "%s", temp_str);
    sd_write_str(kWRITE_GPS, temp_str);
  }
}

void gps_update(void) {
  if (readNMEASentence()) {
    NMEAType type = getNMEAType(nmea_buffer);

    if (type == kNMEA_RMC) {
      parseRMC(nmea_buffer, gnss_data);
    } else if (type == kNMEA_GGA) {
      parseGGA(nmea_buffer, gnss_data);
      gps_update_distance();
    } else if (type == kNMEA_TXT) {
      //parseTXT(nmea_buffer, gnss_data);
      return;
    } else {
      ESP_LOGI(tag, "can't parse %s", nmea_buffer);
      return;
    }
    //ESP_LOGI(tag, "%s", nmea_buffer);
    sd_write_str(kWRITE_GPS, nmea_buffer);

    // debug info
    sprintf(temp_buffer, "%s %s", gnss_data.date, gnss_data.time);
    //ESP_LOGI(tag, "%s", temp_buffer);
    sd_write_str(kWRITE_GPS, temp_buffer);

    sprintf(temp_buffer, "%f %f %f | %.1f %.1f %.1f | Sta=%c Sats=%d", 
              gnss_data.latitude, gnss_data.longitude, gnss_data.altitude, 
              gnss_data.speed, gnss_data.course, gnss_data.hdop, 
              gnss_data.fixStatus, gnss_data.numSats);
    //ESP_LOGI(tag, "%s", temp_buffer);
    sd_write_str(kWRITE_GPS, temp_buffer);
  }
}
