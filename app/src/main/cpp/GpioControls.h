//
// Created by Ragavendiran Balasubramanian on 05/08/23.
//

#ifndef SC66DEBUG_GPIOCONTROLS_H
#define SC66DEBUG_GPIOCONTROLS_H
#include "gpio.h"
#include <cstdio>


void turnOnGpio34(){
//USB VBUS pin
    gpio_export(34);
    char buf[50];
    sprintf(buf, "out");
    gpio_set_dir(buf, 34);
    sprintf(buf, "1");
    gpio_set_val(buf, 34);
}
void turnOnGpio61(){
//USB VBUS pin
    gpio_export(61);
    char buf[50];
    sprintf(buf, "out");
    gpio_set_dir(buf, 61);
    sprintf(buf, "1");
    gpio_set_val(buf, 61);
}
void turnOnGpio71(){
//USB VBUS pin
    gpio_export(71);
    char buf[50];
    sprintf(buf, "out");
    gpio_set_dir(buf, 71);
    sprintf(buf, "1");
    gpio_set_val(buf, 71);
}

void turnOffGpio34(){
//USB VBUS pin
    gpio_export(34);
    char buf[50];
    sprintf(buf, "out");
    gpio_set_dir(buf, 34);
    sprintf(buf, "0");
    gpio_set_val(buf, 34);
}
void turnOffGpio61(){
//USB VBUS pin
    gpio_export(61);
    char buf[50];
    sprintf(buf, "out");
    gpio_set_dir(buf, 61);
    sprintf(buf, "0");
    gpio_set_val(buf, 61);
}
void turnOffGpio71(){
//USB VBUS pin
    gpio_export(71);
    char buf[50];
    sprintf(buf, "out");
    gpio_set_dir(buf, 71);
    sprintf(buf, "0");
    gpio_set_val(buf, 71);
}


#endif //SC66DEBUG_GPIOCONTROLS_H
