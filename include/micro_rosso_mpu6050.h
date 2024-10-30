#ifndef __imu_mpu6050_h
#define __imu_mpu6050_h

#include <Wire.h>

class ImuMPU6050 {
public:
  ImuMPU6050();
  static bool setup( TwoWire &wire = Wire,
                     const char* topic_raw = "/imu/raw",
                     const char* topic_temp = "/imu/temperature",
                     timer_descriptor &timer_report = micro_rosso::timer_report
  );
};

#endif  // __imu_mpu6050_h
