//
// Created by Ragavendiran Balasubramanian on 09/10/23.
// Gyroscope and Accelerometer
//
#ifndef ICM20689_H
#define ICM20689_H


#include <jni.h>
#include <cstdint>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <unistd.h>

class ICM20689 {
public:
    // Constructor
    ICM20689(const char* devicePath) : devicePath(devicePath), fd(-1) {}

    // Destructor
    ~ICM20689() {
        if (fd != -1) {
            close(fd);
        }
    }

    // Public Methods
    bool openI2C() {
        fd = open(devicePath, O_RDWR);
        if (fd < 0) {
            return false;
        }
        if (ioctl(fd, I2C_SLAVE, 0x68) < 0) {
            return false;
        }
        return true;
    }

    bool initialize() {
        return writeByte(0x6B, 0x01) &&  // PWR_MGMT_1
               writeByte(0x6C, 0x00) &&  // PWR_MGMT_2
               writeByte(0x1C, 0x00) &&  // ACCEL_CONFIG
               writeByte(0x1B, 0x00);    // GYRO_CONFIG
    }

    bool readAccelerometer(float &accX, float &accY, float &accZ) {
        uint8_t buf[6];
        if (!readBytes(0x3B, buf, 6)) {
            return false;
        }
        int16_t rawAX = (buf[0] << 8) | buf[1];
        int16_t rawAY = (buf[2] << 8) | buf[3];
        int16_t rawAZ = (buf[4] << 8) | buf[5];
        accX = rawAX / 16384.0;
        accY = rawAY / 16384.0;
        accZ = rawAZ / 16384.0;
        return true;
    }

    bool readGyroscope(float &gyroX, float &gyroY, float &gyroZ) {
        uint8_t buf[6];
        if (!readBytes(0x43, buf, 6)) {  // 0x43 is the starting address for GYRO_XOUT_H
            return false;
        }
        int16_t rawGX = (buf[0] << 8) | buf[1];
        int16_t rawGY = (buf[2] << 8) | buf[3];
        int16_t rawGZ = (buf[4] << 8) | buf[5];
        gyroX = rawGX / 131.0;  // Conversion factor from your Arduino code
        gyroY = rawGY / 131.0;
        gyroZ = rawGZ / 131.0;
        return true;
    }


    // Similarly, the readGyroscope method can be added here...

private:
    // Private Member Variables
    int fd;
    const char* devicePath;

    // Private Methods
    bool writeByte(uint8_t reg, uint8_t data) {
        uint8_t buf[2] = {reg, data};
        return (write(fd, buf, 2) == 2);
    }

    bool readBytes(uint8_t reg, uint8_t* buf, int len) {
        if (write(fd, &reg, 1) != 1) {
            return false;
        }
        return (read(fd, buf, len) == len);
    }
};

#endif // ICM20689_H
