//
// Created by Ragavendiran Balasubramanian on 09/10/23.
//
#include <jni.h>
#include "icm20689.h"

extern "C" JNIEXPORT jboolean JNICALL
Java_com_adiuvo_sc66debug_managers_ICM20689Manager_openI2C(JNIEnv *, jobject) {
    ICM20689 sensor("/dev/i2c-6");
    return sensor.openI2C();
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_adiuvo_sc66debug_managers_ICM20689Manager_initializeSensor(JNIEnv *, jobject) {
    ICM20689 sensor("/dev/i2c-6");
    return sensor.initialize();
}

extern "C" JNIEXPORT jfloatArray JNICALL
Java_com_adiuvo_sc66debug_managers_ICM20689Manager_readAccelerometer(JNIEnv *env, jobject) {
    ICM20689 sensor("/dev/i2c-6");
    float accX, accY, accZ;
    if (sensor.readAccelerometer(accX, accY, accZ)) {
        jfloat output[3] = {accX, accY, accZ};
        jfloatArray result = env->NewFloatArray(3);
        env->SetFloatArrayRegion(result, 0, 3, output);
        return result;
    }
    return nullptr;
}

extern "C"
JNIEXPORT jfloatArray JNICALL
Java_com_adiuvo_sc66debug_managers_ICM20689Manager_readGyroscope(JNIEnv *env, jobject thiz) {
    ICM20689 sensor("/dev/i2c-6");
    float gyroX, gyroY, gyroZ;
    if (sensor.readGyroscope(gyroX, gyroY, gyroZ)) {
        jfloat output[3] = {gyroX, gyroY, gyroZ};
        jfloatArray result = env->NewFloatArray(3);
        env->SetFloatArrayRegion(result, 0, 3, output);
        return result;
    }
    return nullptr;
}