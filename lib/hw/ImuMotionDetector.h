#ifndef IMU_MOTION_DETECTOR_H
#define IMU_MOTION_DETECTOR_H

#include <vector>
#include "aht_bmp_imu.h"

// IMU 静止和运动检测类
class ImuMotionDetector {
public:
    // 构造函数
    ImuMotionDetector();

    // 添加新的 IMU 数据
    void addData(const ImuData& newData);

    // 检测是否静止
    bool isStationary(double accThreshold = 2, double gyroThreshold = 2);

    // 检测是否运动
    bool isMoving(double accThreshold = 2, double gyroThreshold = 2);

private:
    static const int WINDOW_SIZE = 2; // 滑动窗口大小
    std::vector<ImuData> dataBuffer;  // 存储最近 2 次 IMU 数据

    // 计算加速度的模
    double calculateAccMagnitude(const ImuData& data);

    // 计算角速度的模
    double calculateGyroMagnitude(const ImuData& data);

    // 计算数据的方差
    double calculateVariance(const std::vector<double>& values);
};

#endif // IMU_MOTION_DETECTOR_H