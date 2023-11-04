package com.adiuvo.sc66debug.managers;

public class ICM20689Manager {


    // Native methods
    public native boolean openI2C();
    public native boolean initializeSensor();
    public native float[] readAccelerometer();

    // Example method to use the native methods
    public float[] getAccelerometerData() {
        if (openI2C() && initializeSensor()) {
            return readAccelerometer();
        }
        return null;
    }

    public native float[] readGyroscope();

    public float[] getGyroscopeData() {
        if (openI2C() && initializeSensor()) {
            return readGyroscope();
        }
        return null;
    }
}
