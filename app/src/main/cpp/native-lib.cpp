#include <jni.h>
#include <string>
#include <unistd.h>
#include <linux/usbdevice_fs.h>
#include <android/log.h>
#include "si5351b.h"
#include "vl530x.h"
#include "IOExpander.h"
#include "GpioControls.h"
#include "rrc2057.h"
#include "icm20689.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_adiuvo_sc66debug_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {

}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_adiuvo_sc66debug_NativeLib_stringFromJNI(JNIEnv *env, jobject thiz) {
    // TODO: implement stringFromJNI()
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C"
JNIEXPORT void JNICALL
Java_com_adiuvo_sc66debug_NativeLib_turnOnCLK0(JNIEnv *env, jobject thiz) {
    // TODO: implement turnOnCLK0()
    turnOnClk0NM();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_adiuvo_sc66debug_NativeLib_turnOnCLK2(JNIEnv *env, jobject thiz) {
    // TODO: implement turnOnCLK0()
    turnOnClk2NM();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_adiuvo_sc66debug_NativeLib_turnOnCLK1(JNIEnv *env, jobject thiz) {
    // TODO: implement turnOnCLK0()
    turnOnClk1NM();
}extern "C"
JNIEXPORT void JNICALL
Java_com_adiuvo_sc66debug_NativeLib_turnOnCLK3(JNIEnv *env, jobject thiz) {
    // TODO: implement turnOnCLK0()
    turnOnClk3NM();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_adiuvo_sc66debug_NativeLib_turnOnCLK4(JNIEnv *env, jobject thiz) {
    // TODO: implement turnOnCLK0()
    turnOnClk4NM();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_adiuvo_sc66debug_NativeLib_turnOnCLK5(JNIEnv *env, jobject thiz) {
    // TODO: implement turnOnCLK0()
    turnOnClk5NM();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_adiuvo_sc66debug_NativeLib_turnOnCLK6(JNIEnv *env, jobject thiz) {
    // TODO: implement turnOnCLK0()
    turnOnClk6NM();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_adiuvo_sc66debug_NativeLib_turnOnCLK7(JNIEnv *env, jobject thiz) {
    // TODO: implement turnOnCLK0()
    turnOnClk7NM();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_adiuvo_sc66debug_NativeLib_turnoffallled(JNIEnv *env, jobject thiz) {
    turnOff();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_adiuvo_sc66debug_NativeLib_turnOnGpio34(JNIEnv *env, jobject thiz) {
    // TODO: implement turnOnGpio34()
    turnOnGpio34();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_adiuvo_sc66debug_NativeLib_turnOnGpio61(JNIEnv *env, jobject thiz) {
    // TODO: implement turnOnGpio61()
    turnOnGpio61();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_adiuvo_sc66debug_NativeLib_turnOnGpio71(JNIEnv *env, jobject thiz) {
    // TODO: implement turnOnGpio71()
    turnOnGpio71();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_adiuvo_sc66debug_NativeLib_turnOffGpio34(JNIEnv *env, jobject thiz) {
    // TODO: implement turnOffGpio34()
    turnOffGpio34();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_adiuvo_sc66debug_NativeLib_turnOffGpio61(JNIEnv *env, jobject thiz) {
    // TODO: implement turnOffGpio61()
    turnOffGpio61();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_adiuvo_sc66debug_NativeLib_turnOffGpio71(JNIEnv *env, jobject thiz) {
    // TODO: implement turnOffGpio71()
    turnOffGpio71();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_adiuvo_sc66debug_NativeLib_IoExpanderUp(JNIEnv *env, jobject thiz) {
    // TODO: implement IoExpanderUp()
    expander_pullEverythingUP();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_adiuvo_sc66debug_NativeLib_IoExpanderDown(JNIEnv *env, jobject thiz) {
    // TODO: implement IoExpanderDown()
    expander_pullDown();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_adiuvo_sc66debug_NativeLib_IoExpanderInit(JNIEnv *env, jobject thiz) {
    // TODO: implement IoExpanderInit()
    expander_init();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_adiuvo_sc66debug_NativeLib_ControllerInit(JNIEnv *env, jobject thiz) {
    // TODO: implement ControllerInit()
    si5351_init();
    expander_init();
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_adiuvo_sc66debug_NativeLib_getDepth(JNIEnv *env, jobject thiz) {
    // TODO: implement getDepth()
    return vl53l0x_getDepth();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_adiuvo_sc66debug_NativeLib_ControllerDeInit(JNIEnv *env, jobject thiz) {
    turnOff();
    expander_pullDown();
}


/**
 * Battery Related Functions
 * */
extern "C"
JNIEXPORT jint JNICALL
Java_com_adiuvo_sc66debug_NativeLib_getAbsoluteStateOfCharge(JNIEnv *env, jobject thiz) {
    // TODO: implement getAbsoluteStateOfCharge()
    return read_AbsoluteStateOfCharge();
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_adiuvo_sc66debug_NativeLib_getRelativeStateOfCharge(JNIEnv *env, jobject thiz) {
    // TODO: implement getAbsoluteStateOfCharge()
    return read_RelativeStateOfCharge();
}


extern "C"
JNIEXPORT jint JNICALL
Java_com_adiuvo_sc66debug_NativeLib_read_1RemainingCapacity(JNIEnv *env, jobject thiz) {
    // TODO: implement read_RemainingCapacity()
    return read_RemainingCapacity();
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_adiuvo_sc66debug_NativeLib_read_1FullChargeCapacity(JNIEnv *env, jobject thiz) {
    // TODO: implement read_FullChargeCapacity()
    return read_FullChargeCapacity();
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_adiuvo_sc66debug_NativeLib_read_1RunTimeToEmpty(JNIEnv *env, jobject thiz) {
    // TODO: implement read_RunTimeToEmpty()
    return read_RunTimeToEmpty();
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_adiuvo_sc66debug_NativeLib_read_1AverageTimeToEmpty(JNIEnv *env, jobject thiz) {
    // TODO: implement read_AverageTimeToEmpty()
    return read_AverageTimeToEmpty();
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_adiuvo_sc66debug_NativeLib_read_1AverageTimeToFull(JNIEnv *env, jobject thiz) {
    // TODO: implement read_AverageTimeToFull()
    return read_AverageTimeToFull();
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_adiuvo_sc66debug_NativeLib_read_1ChargingCurrent(JNIEnv *env, jobject thiz) {
    // TODO: implement read_ChargingCurrent()
    return read_ChargingCurrent();
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_adiuvo_sc66debug_NativeLib_read_1ChargingVoltage(JNIEnv *env, jobject thiz) {
    // TODO: implement read_ChargingVoltage()
    return read_ChargingVoltage();
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_adiuvo_sc66debug_NativeLib_read_1BatteryStatus(JNIEnv *env, jobject thiz) {
    // TODO: implement read_BatteryStatus()
    return read_BatteryStatus();
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_adiuvo_sc66debug_NativeLib_read_1CycleCount(JNIEnv *env, jobject thiz) {
    // TODO: implement read_CycleCount()
    return read_CycleCount();
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_adiuvo_sc66debug_NativeLib_read_1DesignCapacity(JNIEnv *env, jobject thiz) {
    // TODO: implement read_DesignCapacity()
    return read_DesignCapacity();
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_adiuvo_sc66debug_NativeLib_read_1DesignVoltage(JNIEnv *env, jobject thiz) {
    // TODO: implement read_DesignVoltage()
    return read_DesignVoltage();
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_adiuvo_sc66debug_NativeLib_read_1Specificationinfo(JNIEnv *env, jobject thiz) {
    // TODO: implement read_Specificationinfo()
    return read_Specificationinfo();
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_adiuvo_sc66debug_NativeLib_read_1Current(JNIEnv *env, jobject thiz) {
    // TODO: implement read_Current()
    return read_Current();
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_adiuvo_sc66debug_NativeLib_read_1Voltage(JNIEnv *env, jobject thiz) {
    // TODO: implement read_Voltage()
    return read_Voltage();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_adiuvo_sc66debug_NativeLib_setSuperchargeMode(JNIEnv* env, jobject obj, jstring value) {
    // Convert jstring to C-string (char*)
    const char *valueCStr = env->GetStringUTFChars(value, NULL);
    if (!valueCStr) return; // Out of memory error thrown

    // Construct the command
    char command[256];
    snprintf(command, sizeof(command), "i2cset -y 6 0x3f %s w", valueCStr);

    // Execute the command
    FILE* pipe = popen(command, "r");
    if (!pipe) {
        // Handle error
        env->ReleaseStringUTFChars(value, valueCStr);
        return;
    }
    pclose(pipe);

    // Release the C-string
    env->ReleaseStringUTFChars(value, valueCStr);
}


