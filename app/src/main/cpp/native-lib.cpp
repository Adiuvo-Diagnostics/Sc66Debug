#include <jni.h>
#include <string>
#include <unistd.h>
#include <linux/usbdevice_fs.h>
#include <android/log.h>
#include "si5351b.h"
#include "vl530x.h"
#include "IOExpander.h"
#include "GpioControls.h"

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