//
// Created by Ragavendiran Balasubramanian on 14/08/23.
//

#ifndef ILLUMINATE_V2_REALM_FLATINFOXY_RRC2057_H
#define ILLUMINATE_V2_REALM_FLATINFOXY_RRC2057_H


#include "i2c6.h"
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <android/log.h>

#define LOG_TAG "I2CReader"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)


// Register Definitions
#define address 0x0b
#define MANUFACTURERACCESS_REG 0x00
#define REMAININGCAPACITY_ALARM_REG 0x01
#define REMAININGTIMEALARM_REG 0x02
#define BATTERYMODE_REG 0x03
#define ATRATE_REG 0x04
#define ATRATETIMETOFULL_REG 0x05
#define ATRATENMETOEMPTY_REG 0x06
#define ATRATEOK_REG 0x07
#define TEMPERATURE_REG 0x08
#define VOLTAGE_REG 0x09
#define CURRENT_REG 0x0a
#define AVERAGECURRENT_REG 0x0b
#define MAXERROR_REG 0x0c
#define RELATIVESTATEOFCHARGE_REG 0x0d
#define ABSOLUTESTATEOFCHARGE_REG 0x0e
#define REMAININGCAPACITY_REG 0x0f
#define FULLCHARGECAPACITY_REG 0x10
#define RUNTIMETOEMPTY_REG 0x11
#define AVERAGETIMETOEMPTY_REG 0x12
#define AVERAGETIMETOFULL_REG 0x13
#define CHARGINGCURRENT_REG 0x14
#define CHARGINGVOLTAGE_REG 0x15
#define BATTERYSTATUS_REG 0x16
#define CYCLECOUNT_REG 0x17
#define DESIGNCAPACITY_REG 0x18
#define DESIGNVOLTAGE_REG 0x19
#define SPECIFICATIONINFO_REG 0x1a
#define MANUFACTURERDATE_REG 0x1b
#define SERIALNUMBER_REG 0x1c
#define MANUFACTURERNAME_REG 0x20
#define DEVICENAME_REG 0x21
#define DEVICECHEMISTRY_REG 0x22
#define MANUFACTURERDATA_REG 0x23

int readI2C2Bytes(int bus, int deviceAddr, int regAddr) {
    char filename[20];
    snprintf(filename, 19, "/dev/i2c-%d", bus);
    int file = open(filename, O_RDWR);
    if (file < 0) {
        perror("Failed to open the bus");
        return -1;
    }

    if (ioctl(file, I2C_SLAVE, deviceAddr) < 0) {
        perror("Failed to acquire bus access or talk to slave");
        close(file);
        return -1;
    }

    // Write the register address
    char buf[1] = { static_cast<char>(regAddr) };
    if (write(file, buf, 1) != 1) {
        perror("Failed to write to the i2c bus");
        close(file);
        return -1;
    }

    // Read the 2 bytes
    char readBuf[2];
    if (read(file, readBuf, 2) != 2) {
        perror("Failed to read from the i2c bus");
        close(file);
        return -1;
    }

    close(file);

    // Combine the 2 bytes into a single 16-bit value
    int value = (static_cast<unsigned char>(readBuf[1]) << 8) | static_cast<unsigned char>(readBuf[0]);
    return static_cast<int16_t>(value);
}

int readI2CByte(int bus, int deviceAddr, int regAddr) {
    char filename[20];
    snprintf(filename, 19, "/dev/i2c-%d", bus);
    int file = open(filename, O_RDWR);
    if (file < 0) {
        LOGE("Failed to open the bus: %s", filename);
        return -1;
    }

    if (ioctl(file, I2C_SLAVE, deviceAddr) < 0) {
        LOGE("Failed to acquire bus access or talk to slave");
        close(file);
        return -1;
    }

    // Read the byte
    char buf[1] = { static_cast<char>(regAddr) };
    if (write(file, buf, 1) != 1) {
        LOGE("Failed to write to the i2c bus");
        close(file);
        return -1;
    }

    if (read(file, buf, 1) != 1) {
        LOGE("Failed to read from the i2c bus");
        close(file);
        return -1;
    }

    close(file);
    return static_cast<unsigned char>(buf[0]);
}

// Read Functions
//int read_ManufacturerAccess() {
//    return read_i2c_device_16(address, MANUF, 2);
//}
//
//int read_RemainingCapacity_Alarm() {
//    return read_i2c_device_16(address, REMAININGC, 2);
//}
//
//int read_RemainingTimeAlarm() {
//    return read_i2c_device_16(address, REMAI, 2);
//}
//
//int read_BatteryMode() {
//    return read_i2c_device_16(address, 2);
//}
//
//int read_AtRate() {
//    return read_i2c_device_16(ad, 2);
//}
//
//int read_AtRateTimeToFull() {
//    return read_i2c_device_16(address, ATR, 2);
//}
//
//int read_AtRatenmeToEmpty() {
//    return read_i2c_device_16(address, ATR, 2);
//}
//
//int read_AtRateOK() {
//    return read_i2c_device_16(addr, 2);
//}
//
//int read_Temperature() {
//    return read_i2c_device_16(address, 2);
//}
//
int read_Voltage() {
    return readI2C2Bytes(6,address, VOLTAGE_REG);
}

int read_Current() {
    return readI2C2Bytes(6,address, CURRENT_REG);
}
//
//int read_AverageCurrent() {
//    return read_i2c_device_16(address, A, 2);
//}
//
//int read_MaxError() {
//    return read_i2c_device_16(addr, 2);
//}
//
//int read_RelativeStateOfCharge() {
//    return read_i2c_device_16(address, RELATIVE, 2);
//}

int read_AbsoluteStateOfCharge() {
    return readI2CByte(6,address,ABSOLUTESTATEOFCHARGE_REG);
}

int read_RemainingCapacity() {
    return readI2CByte(6, address, REMAININGCAPACITY_REG);
}

int read_FullChargeCapacity() {
    return readI2CByte(6,address, FULLCHARGECAPACITY_REG);
}

int read_RunTimeToEmpty() {
    return readI2CByte(6,address, RUNTIMETOEMPTY_REG);
}

int read_AverageTimeToEmpty() {
    return readI2C2Bytes(6,address, AVERAGETIMETOEMPTY_REG);
}

int read_AverageTimeToFull() {
    return readI2C2Bytes(6,address,AVERAGETIMETOFULL_REG);
}

int read_ChargingCurrent() {
    return readI2C2Bytes(6,address,CHARGINGCURRENT_REG);
}

int read_ChargingVoltage() {
    return readI2C2Bytes(6,address,CHARGINGVOLTAGE_REG);
}

int read_BatteryStatus() {
    return readI2C2Bytes(6,address,BATTERYSTATUS_REG);
}

int read_CycleCount() {
    return readI2CByte(6,address, CYCLECOUNT_REG);
}

int read_DesignCapacity() {
    return readI2CByte(6,address, DESIGNCAPACITY_REG);
}

int read_DesignVoltage() {
    return readI2CByte(6,address, DESIGNVOLTAGE_REG);
}

int read_Specificationinfo() {
    return readI2CByte(6,address, SPECIFICATIONINFO_REG);
}

int read_ManufacturerDate() {
    return readI2CByte(6,address, MANUFACTURERDATE_REG);
}

int read_SerialNumber() {
    return readI2CByte(6,address,SERIALNUMBER_REG);
}

// Write Functions
int write_ManufacturerAccess( uint16_t data) {
    return write_i2c_device_16(address, MANUFACTURERACCESS_REG,
                               reinterpret_cast<const uint8_t *>(&data), 2);
}

int write_RemainingCapacity_Alarm( uint16_t data) {
    return write_i2c_device_16(address, REMAININGCAPACITY_ALARM_REG,
                               reinterpret_cast<const uint8_t *>(&data), 2);
}

int write_RemainingTimeAlarm( uint16_t data) {
    return write_i2c_device_16(address, REMAININGTIMEALARM_REG,
                               reinterpret_cast<const uint8_t *>(&data), 2);
}

int write_BatteryMode( uint16_t data) {
    return write_i2c_device_16(address, BATTERYMODE_REG, reinterpret_cast<const uint8_t *>(&data), 2);
}

int write_AtRate( uint16_t data) {
    return write_i2c_device_16(address, ATRATE_REG, reinterpret_cast<const uint8_t *>(&data), 2);
}



#endif //ILLUMINATE_V2_REALM_FLATINFOXY_RRC2057_H
