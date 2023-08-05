//
// Created by johnd on 13-10-2021.
//

#ifndef PWMSERVO_GPIO_H
#define PWMSERVO_GPIO_H

#include <fcntl.h>
#include <cstring>
#include <cstdlib>
#include <android/log.h>


__unused int gpio_export(int pin)
{
    int ret;
    char buf[50];
    system("su -c chmod -R 777 /sys/class/gpio/export");
    int fd = open("/sys/class/gpio/export",O_WRONLY|O_SYNC);
    if(fd<0)
    {
        ret = -1;
        return ret;
    }
    sprintf(buf,"%d",pin);
    ret = write(fd,buf,strlen(buf));
    close(fd);
    char gpio[100];
    sprintf(gpio,"su -c chmod -R 777 /sys/class/gpio/gpio%d",pin);
    system(gpio);
    return ret;
}

__unused int gpio_unexport(int pin)
{
    int ret;
    char buf[50];
    system("su 0 chmod -R 777 /sys/class/gpio/unexport");
    int fd = open("/sys/class/gpio/unexport",O_WRONLY|O_SYNC);
    if(fd<0)
    {
        ret = -1;
        return ret;
    }
    sprintf(buf, "%d", pin);
    ret = write(fd, buf, strlen(buf));
    close(fd);
    return ret;
}
int gpio_set_dir(char*dir,int pin)
{
    int ret;
    char direction[100];
    sprintf(direction,"su -c chmod -R 777 /sys/class/gpio/gpio%d/direction",pin);
    system(direction);
    char buf[50];
    sprintf(buf,"/sys/class/gpio/gpio%d/direction",pin);
    int fd = open(buf,O_WRONLY|O_SYNC);
    if(fd < 0)
    {
        ret = -1;
        return ret;
    }
    ret=write(fd, dir, strlen(dir));
    close(fd);
    return ret;
}
int gpio_set_val(char*val,int pin)
{
    int ret;
    char value[100];
    sprintf(value,"su -c chmod -R 777 /sys/class/gpio/gpio%d/value",pin);
    system(value);
    char buf[50];
    sprintf(buf,"/sys/class/gpio/gpio%d/value",pin);
    int fd = open(buf, O_RDWR|O_SYNC);
    if(fd<0)
    {
        ret=-1;
        return ret;
    }
    ret=write(fd,val, strlen(val));
    close(fd);
    return ret;
}

int batteryCapacityP1(char*val)
{
    uint8_t ret;
    char value[100];
    sprintf(value,"su -c chmod -R 777 /sys/class/power_supply/battery");
    system(value);
    char buf[50];
    sprintf(buf,"/sys/class/power_supply/battery/capacity");
    int fd = open(buf,O_RDONLY|O_SYNC);
//    __android_log_print(ANDROID_LOG_ERROR, "Battery value 3", "The battery value 3:%d",fd);
    if(fd<0)
    {
        ret=-1;
        return ret;
    }
    ret = read(fd,val,20);
//    __android_log_print(ANDROID_LOG_ERROR, "Battery value 4", "The battery value 4:%d",ret);
//    __android_log_print(ANDROID_LOG_ERROR, "Battery value 5", "The battery value 5 val:%s",val);
    close(fd);
    return ret;
}

int batteryStatusP2(char*val)
{
    uint8_t ret;
    char value[100];
    sprintf(value,"su -c chmod -R 777 /sys/class/power_supply/battery");
    system(value);
    char buf[50];
    sprintf(buf,"/sys/class/power_supply/battery/status");
    int fd = open(buf,O_RDONLY|O_SYNC);
    if(fd<0)
    {
        ret=-1;
        return ret;
    }
    ret = read(fd,val,20);
    close(fd);
    return ret;
}

int batteryHealthP3(char*val)
{
    uint8_t ret;
    char value[100];
    sprintf(value,"su -c chmod -R 777 /sys/class/power_supply/battery");
    system(value);
    char buf[50];
    sprintf(buf,"/sys/class/power_supply/battery/health");
    int fd = open(buf,O_RDONLY|O_SYNC);
    if(fd<0)
    {
        ret=-1;
        return ret;
    }
    ret = read(fd,val,20);
    close(fd);
    return ret;
}

int batteryCurrentNowP4(char*val)
{
    uint8_t ret;
    char value[100];
    sprintf(value,"su -c chmod -R 777 /sys/class/power_supply/battery");
    system(value);
    char buf[50];
    sprintf(buf,"/sys/class/power_supply/battery/current_now");
    int fd = open(buf,O_RDONLY|O_SYNC);
    if(fd<0)
    {
        ret=-1;
        return ret;
    }
    ret = read(fd,val,20);
    close(fd);
    return ret;
}

int batteryVoltageNowP5(char*val)
{
    uint8_t ret;
    char value[100];
    sprintf(value,"su -c chmod -R 777 /sys/class/power_supply/battery");
    system(value);
    char buf[50];
    sprintf(buf,"/sys/class/power_supply/battery/voltage_now");
    int fd = open(buf,O_RDONLY|O_SYNC);
    if(fd<0)
    {
        ret=-1;
        return ret;
    }
    ret = read(fd,val,20);
    close(fd);
    return ret;
}

int batteryVoltageMaxP6(char*val)
{
    uint8_t ret;
    char value[100];
    sprintf(value,"su -c chmod -R 777 /sys/class/power_supply/battery");
    system(value);
    char buf[50];
    sprintf(buf,"/sys/class/power_supply/battery/voltage_max");
    int fd = open(buf,O_RDONLY|O_SYNC);
    if(fd<0)
    {
        ret=-1;
        return ret;
    }
    ret = read(fd,val,20);
    close(fd);
    return ret;
}

int batteryChargeCounterP7(char*val)
{
    uint8_t ret;
    char value[100];
    sprintf(value,"su -c chmod -R 777 /sys/class/power_supply/battery");
    system(value);
    char buf[50];
    sprintf(buf,"/sys/class/power_supply/battery/charge_counter");
    int fd = open(buf,O_RDONLY|O_SYNC);
    if(fd<0)
    {
        ret=-1;
        return ret;
    }
    ret = read(fd,val,20);
    close(fd);
    return ret;
}

int batteryChargeCounterMaxP8(char*val)
{
    uint8_t ret;
    char value[100];
    sprintf(value,"su -c chmod -R 777 /sys/class/power_supply/battery");
    system(value);
    char buf[50];
    sprintf(buf,"/sys/class/power_supply/battery/charge_full");
    int fd = open(buf,O_RDONLY|O_SYNC);
    if(fd<0)
    {
        ret=-1;
        return ret;
    }
    ret = read(fd,val,20);
    close(fd);
    return ret;
}

int batteryTemperatureP9(char*val)
{
    uint8_t ret;
    char value[100];
    sprintf(value,"su -c chmod -R 777 /sys/class/power_supply/battery");
    system(value);
    char buf[50];
    sprintf(buf,"/sys/class/power_supply/battery/temp");
    int fd = open(buf,O_RDONLY|O_SYNC);
    if(fd<0)
    {
        ret=-1;
        return ret;
    }
    ret = read(fd,val,20);
    close(fd);
    return ret;
}

#endif //PWMSERVO_GPIO_H
