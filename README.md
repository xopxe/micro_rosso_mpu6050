# micro rosso mpu6050

This a module for the [micro_rosso](https://github.com/xopxe/micro_rosso_platformio) system.

It provides support for the MPU6050 IMU by publishing ROS2 topics.

## Loading and starting

First, import the module into your project's `platformio.ini`:

```
lib_deps =
    ...
    https://github.com/xopxe/micro_rosso_mpu6050.git
```

Then, in your `main.cpp`:

```
...
#include "micro_rosso_mpu6050.h"
ImuMPU6050 imu;
...
void setup() {
  Wire.begin(I2C_SDA, I2C_SCL); // initialize I2C as needed
  ...
  !imu.setup(Wire);
  ...
}
```

The setup method allows passing optional topic names and a different micro_rosso timer to change the publication rate (by default, it uses the 5Hz timer). It is declared as follows:

```
  static bool setup(TwoWire &wire = Wire,
                    const char *topic_raw = "/imu/raw",
                    const char *topic_temp = "/imu/temperature",
                    timer_descriptor &timer_report = micro_rosso::timer_report);
```

## Using the module

The module emits the following topics:

* raw imu: [sensor_msgs/msg/imu]([https://docs.ros2.org/foxy/api/sensor_msgs/msg/Imu.html))
* temperature: [sensor_msgs/msg/temperature](https://docs.ros2.org/foxy/api/sensor_msgs/msg/Temperature.html)

## Authors and acknowledgment

jvisca@fing.edu.uy - [Grupo MINA](https://www.fing.edu.uy/inco/grupos/mina/), Facultad de Ingeniería - Udelar, 2024

## License

MIT
