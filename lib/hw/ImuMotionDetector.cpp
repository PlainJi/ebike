#include "ImuMotionDetector.h"

#include <cmath>
#include <esp32-hal.h>

static const char *tag = "detector";

// 构造函数
ImuMotionDetector::ImuMotionDetector() {
    dataBuffer.reserve(WINDOW_SIZE); // 预分配内存
}

// 添加新的 IMU 数据
void ImuMotionDetector::addData(const ImuData& newData) {
    if (dataBuffer.size() >= WINDOW_SIZE) {
        dataBuffer.erase(dataBuffer.begin()); // 移除最旧的数据
    }
    dataBuffer.push_back(newData); // 添加新数据
}

// 计算加速度的模
double ImuMotionDetector::calculateAccMagnitude(const ImuData& data) {
    return std::sqrt(data.ax * data.ax + data.ay * data.ay + data.az * data.az);
}

// 计算角速度的模
double ImuMotionDetector::calculateGyroMagnitude(const ImuData& data) {
    return std::sqrt(data.gx * data.gx + data.gy * data.gy + data.gz * data.gz);
}

// 计算数据的方差
double ImuMotionDetector::calculateVariance(const std::vector<double>& values) {
    double mean = 0.0, variance = 0.0;
    for (double value : values) {
        mean += value;
    }
    mean /= values.size();

    for (double value : values) {
        variance += (value - mean) * (value - mean);
    }
    return variance / values.size();
}

// 检测是否静止
bool ImuMotionDetector::isStationary(double accThreshold, double gyroThreshold) {
    if (dataBuffer.size() < WINDOW_SIZE) {
        return false; // 数据不足，无法判断
    }

    // 计算加速度和角速度的模
    std::vector<double> accMagnitudes, gyroMagnitudes;
    for (const ImuData& data : dataBuffer) {
        accMagnitudes.push_back(calculateAccMagnitude(data));
        gyroMagnitudes.push_back(calculateGyroMagnitude(data));
    }

    // 计算方差
    double accVariance = calculateVariance(accMagnitudes);
    double gyroVariance = calculateVariance(gyroMagnitudes);
    ESP_LOGI(tag, "accVariance=%.1lf gyroVariance=%.1lf", accVariance, gyroVariance);

    // 判断是否静止
    return (accVariance < accThreshold && gyroVariance < gyroThreshold);
}

// 检测是否运动
bool ImuMotionDetector::isMoving(double accThreshold, double gyroThreshold) {
    return !isStationary(accThreshold, gyroThreshold);
}