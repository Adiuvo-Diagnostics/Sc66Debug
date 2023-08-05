//
// Created by Ragavendiran on 03-09-2022.
//

#ifndef ILLUMINATE_APP_IOEXPANDER_H
#define ILLUMINATE_APP_IOEXPANDER_H
#endif //ILLUMINATE_APP_IOEXPANDER_H
#include"i2c6.h"
#define PCA9356_ADDRESS 0x41

#include <android/log.h>
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "some-tag", __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "some-tag", __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, "some-tag", __VA_ARGS__))
#define REG_INPUT 0x00
#define REG_OUTPUT 0x01
#define REG_CONFIG 0x03
//*===============================================================================================================*
//  REGISTER POINTERS
//*===============================================================================================================*
//
//  REG_INPUT           0x00        // Input Port Register           (R)    B00000000 (Default)
//  REG_OUTPUT          0x01        // Output Port Register          (R/W)  B00000001
//  REG_POLARITY        0x02        // Polarity Inversion Register   (R/W)  B00000010
//  REG_CONFIG          0x03        // Configuration Register        (R/W)  B00000011
//
//*===============================================================================================================*
//  REGISTER 0: INPUT REGIASTER - READ ONLY (0 = LOW / 1 = HIGH)
//*===============================================================================================================*
//
//  DEFAULT (WITH NO EXTENRAL INPUT SIGNAL CONNECTED): 'HIGH' (ALL IO PINS HAVE WEAK PULL-UP RESISTORS)
//
//  DEFAULT
//  PIN_IO0             BIT 0          1
//  PIN_IO1             BIT 1          1
//  PIN_IO2             BIT 2          1
//  PIN_IO3             BIT 3          1
//
//  BITS 4-7: NOT USED (DEFAULT: 1)
//
//*===============================================================================================================*
//  REGISTER 1: OUTPUT REGIASTER - READ / WRITE (0 = LOW / 1 = HIGH)
//*===============================================================================================================*
//
//  DEFAULT
//  IO0                 BIT 0          1
//  IO1                 BIT 1          1
//  IO2                 BIT 2          1
//  IO3                 BIT 3          1
//
//  BITS 4-7: NOT USED (DEFAULT: 1) - MAY BE SET AS '0' OR '1'
//
//*===============================================================================================================*
//  REGISTER 3: CONFIGURATION - READ / WRITE (0 = OUTPUT / 1 = INPUT)
//*===============================================================================================================*
//
//  POWER-UP DEFAULT: ALL PINS ARE SET AS 'INPUT' (1)
//
//  DEFAULT             BITS          Default  Req
//  PIN_IO0             BIT 0         1        0     //USB_LED               OUT
//  PIN_IO1             BIT 1         1        0     //BAT_STATUS_LED        OUT
//  PIN_IO2             BIT 2         1        0     //PWR_SW_EN             OUT
//  PIN_IO3             BIT 3         1        1     //INT_BAT               IN
//  BITS 4-7: NOT USED (DEFAULT: 1) - MAY BE SET AS '0' OR '1'

#define IO3_READ_REGISTER 0x08               // To set 0000 1000 to configure the REGISTERS as input or output ports.
#define IO_USBandBatteryLED_PULLUP 0x03      // To set 0000 0011
#define IO_PWR_Switch_UP  0x04               // To set 0000 0100
#define IO_PULL_ALL_UP  0x15                 // To set 0000 1111
#define IO_PWR_Switch_DOWN 0x00              // To set 0000 0000

void expander_init()
{
    opendevice();
    uint8_t data=IO3_READ_REGISTER;
    write_i2c_device_8(PCA9356_ADDRESS, REG_CONFIG,&data);
    LOGE("IOExpander.h: expander Data %hhu",data);
    LOGE("IOExpander.h: expander addr of Data %l",&data);
    LOGE("IOExpander.h: expander addr of Device %d",PCA9356_ADDRESS);
    LOGE("IOExpander.h: expander addr of Reg Config %d",REG_CONFIG);
    closedevice();
}

void expander_pullUP() {
    opendevice();
    uint8_t data=IO_PWR_Switch_UP;
    write_i2c_device_8(PCA9356_ADDRESS, REG_OUTPUT,&data);
    closedevice();
}
void expander_pullDown() {
    opendevice();
    uint8_t data=IO_PWR_Switch_DOWN;
    write_i2c_device_8(PCA9356_ADDRESS, REG_OUTPUT,&data);
    closedevice();
}

void expander_pullEverythingUP() {
    opendevice();
    uint8_t data=IO_PULL_ALL_UP;
    write_i2c_device_8(PCA9356_ADDRESS, REG_OUTPUT,&data);
    closedevice();
}
