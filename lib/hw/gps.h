#ifndef _GPS_H_
#define _GPS_H_

// $GNGGA,,,,,,0,00,25.5,,,,,,*64
// $GNRMC,,V,,,,,,,,,,M*4E
// $GPTXT,01,01,01,ANTENNA OK*35

// $GNGGA,121057.000,,,,,0,00,3.0,,,,,,*4B
// NRMC,121057.000,V,,,,,,,200325,,,N*55
// $GPTXT,01,01,01,ANTENNA OK*35

// const char *rmc = "$GNRMC,123300.000,A,3957.44996,N,11628.97404,E,3.63,47.96,180325,,,A*48";
// const char *gga = "$GNGGA,123136.000,3957.42595,N,11628.91408,E,1,15,1.0,36.5,M,0.0,M,,*4C";
// const char *txt = "$GPTXT,01,01,01,ANTENNA OK*35";

// 0	$GPRMC	语句类型（GPRMC 或 GNRMC）
// 1	时间	    UTC时间，格式为 hhmmss.sss
// 2	状态	    定位状态：A（有效）或 V（无效）
// 3	纬度	    格式为 ddmm.mmmm（度分格式）
// 4	纬度方向   纬度方向：N（北纬）或 S（南纬）
// 5	经度	    格式为 dddmm.mmmm（度分格式）
// 6	经度方向	 经度方向：E（东经）或 W（西经）
// 7	速度	    地面速度（单位：节）
// 8	航向	    地面航向（单位：度，真北为参考）
// 9	日期	    UTC日期，格式为 ddmmyy
// 10	磁偏角	   磁偏角（单位：度）
// 11	磁偏角方向	磁偏角方向：E（东）或 W（西）
// 12	模式指示	 定位模式：A（自动）、D（差分）、E（估算）、N（无效）
// 13	校验和	   校验和（* 后的两位十六进制数）

// 0	$GPGGA   语句类型（GPGGA 或 GNGGA）
// 1	时间	    UTC时间，格式为 hhmmss.sss
// 2	纬度      格式为 ddmm.mmmm（度分格式）
// 3	纬度方向   纬度方向：N（北纬）或 S（南纬）
// 4	经度	    格式为 dddmm.mmmm（度分格式）
// 5	经度方向	 经度方向：E（东经）或 W（西经）
// 6	定位质量	 0初始化， 1单点定位， 2码差分， 3无效PPS， 4固定解， 5浮点解， 6正在估算 7，人工输入固定值， 8模拟模式， 9WAAS差分
// 7	卫星数量 	 使用的卫星数量
// 8	水平精度 	 水平精度因子（HDOP）
// 9	海拔高度 	 海拔高度（单位：米）
// 10	海拔单位	 海拔高度单位：M（米）
// 11	大地水准面高度	大地水准面高度（单位：米）
// 12	大地水准面单位	大地水准面高度单位：M（米）
// 13	差分时间	差分时间（从最近一次差分信号接收的秒数）
// 14	差分站 ID	差分站 ID
// 15	校验和	校验和（* 后的两位十六进制数）

// $PCAS00*01\r\n					保存配置
// $PCAS02,250*18\r\n				定位更新间隔250ms
// $PCAS02,1000*2E\r\n				定位更新间隔1000ms
// $PCAS03,1,0,0,0,1,0,0,0*02\r\n	打开GGA、RMC，其余关闭
// $PCAS11,0*1D\r\n					便携模式
// $PCAS11,1*1C\r\n					静态模式
// $PCAS11,2*1F\r\n					步行模式
// $PCAS11,3*1E\r\n					车载模式

enum NMEAType{
  kNMEA_Invalid = 0,
  kNMEA_GGA = 1,
  kNMEA_RMC = 2,
  kNMEA_TXT = 3,
};

struct GNSSData {
  // 格式化后的时间和日期
  char time[32] = {0};         // 时间戳（hh:mm:ss）
  char date[32] = {0};         // 日期（YYYY-MM-DD）
  int hour = 0;
  int minute = 0;
  int second = 0;
  int year = 0;
  int month = 0;
  int day = 0;

  // 经纬度
  double latitude = 0.0;       // 纬度（十进制度）
  double longitude = 0.0;      // 经度（十进制度）
  double last_latitude = 0.0;       // 纬度（十进制度）
  double last_longitude = 0.0;      // 经度（十进制度）
  double dist_with_last_pos = 0.0;

  // GGA 数据
  int fixQuality = 0;          // 定位质量
  int numSats = 0;             // 卫星数量
  double hdop = 0.0;           // 水平精度因子
  double altitude = 0.0;       // 海拔高度
  double geoidHeight = 0.0;    // 大地水准面高度

  // RMC 数据
  char fixStatus = 'V';           // 状态（A=有效，V=无效）
  double speed = 0.0;          // 速度
  double course = 0.0;         // 航向

  // TXT 数据
  char txtMessage[32] = {0};   // 天线状态
};

extern GNSSData gnss_data;

void gps_init();
void gps_config(void);
void gps_update();
void gps_print();

#endif