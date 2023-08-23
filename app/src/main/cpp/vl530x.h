//
// Created by Ragavendiran on 08-09-2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <stdbool.h>
#include <stdint.h>

#ifndef ILLUMINATE_APP_VL530X_H
#define ILLUMINATE_APP_VL530X_H
/* I2C device that the distance sensor is wired to */
#define I2C_LINUX_BUS2 "/dev/i2c-6"
/* Device address of the distance sensor */
#define DISTANCE_SENSOR_DEVICE_ADDRESS 0x29
#define VL53L0X_REG_SYSRANGE_START 0x00
#define VL53L0X_REG_SYSRANGE_MODE_SINGLESHOT 0x00
#define VL53L0X_REG_SYSRANGE_MODE_BACKTOBACK 0x02
/* Address of the distance sensor reading's MSB*/
#define DISTANCE_SENSOR_READING_MSB 0x1e
/* Total number of bytes to read,
 in our case we are reading two bytes,
 the MSB and LSB of the distance reading*/
#define NUM_BYTES_READ 2

static void DistanceSensor_setContinuous(int distanceSensorFD) {
    unsigned char buff[2];
    buff[0] = VL53L0X_REG_SYSRANGE_START;
    buff[1] = VL53L0X_REG_SYSRANGE_MODE_BACKTOBACK;
    int res = write(distanceSensorFD, buff, 2);
    if (res != 2) {
        perror("I2C: Unable to write i2c register.");
        exit(1);
    }
}
static void DistanceSensor_setSingleShot(int distanceSensorFD) {
    unsigned char buff[2];
    buff[0] = VL53L0X_REG_SYSRANGE_START;
    buff[1] = VL53L0X_REG_SYSRANGE_MODE_SINGLESHOT;
    int res = write(distanceSensorFD, buff, 2);
    if (res != 2) {
        perror("I2C: Unable to write i2c register.");
        exit(1);
    }
}
static void DistanceSensor_configPins() {
    // Execute the shell command (output into pipe)
    FILE *pipe = popen("config-pin P9_19 i2c", "r");
    // Close pipe, check program’s exit code
    int exitCode = WEXITSTATUS(pclose(pipe));
    if (exitCode != 0) {
        LOGE("Program failed: %d\n", exitCode);
    }
    pipe = popen("config-pin P9_20 i2c", "r");
    exitCode = WEXITSTATUS(pclose(pipe));
    if (exitCode != 0) {
        LOGE("Program failed: %d\n", exitCode);
    }
}
static int DistanceSensor_init() {
//    DistanceSensor_configPins();
    int distanceSensorFD = open(I2C_LINUX_BUS2 , O_RDWR);
    int result = ioctl(distanceSensorFD, I2C_SLAVE,
                       DISTANCE_SENSOR_DEVICE_ADDRESS);
    if (result < 0) {
        perror("I2C: Unable to set I2C device to slave address.");
        exit(1);
    }
    return distanceSensorFD;
}
static uint16_t DistanceSensor_readReg(int distanceSensorFD) {
    char values[NUM_BYTES_READ];
    unsigned char startRegAddr = DISTANCE_SENSOR_READING_MSB;
    for (int i = 0; i < NUM_BYTES_READ; i++) {
        unsigned char currAddr = startRegAddr + i;
        int res = write(distanceSensorFD, &(currAddr), sizeof(currAddr));
        if (res != sizeof(currAddr)) {
            perror("I2C: Unable to write to i2c register.");
            exit(1);
        }
        res = read(distanceSensorFD, &values[i], sizeof(*values));
        if (res != sizeof(*values)) {
            perror("I2C: Unable to read from i2c register");
            exit(1);
        }
    }
    // Convert the reading to distance
    uint16_t dist = (((uint16_t)(values[0]) << 8) | (uint16_t)(values[1]));
    return dist;
}

uint16_t vl53l0x_getDepth(){
    // Initialize the I2C device
    int distanceSensorFD = DistanceSensor_init();
    // Set device to continuous ranging mode
    DistanceSensor_setContinuous(distanceSensorFD);
    uint16_t dist;
    do{
        dist = DistanceSensor_readReg(distanceSensorFD);
        if (dist > 20 && dist < 8190) {
            LOGE("Reading: %u mm\n", dist);
        } else {
            LOGE("Reading: Nothing detected\n");
            dist=0;
        }
    }while(dist==0);
    //DistanceSensor_setSingleShot(distanceSensorFD);

//
//    // Wait 0.25 sec between each reading
//    struct timespec reqDelay = {0, 300000000};
//    nanosleep(&reqDelay, (struct timespec *) NULL);

    return (dist-81.66);
}

#endif //ILLUMINATE_APP_VL530X_H
