package com.adiuvo.sc66debug;

public class NativeLib {
    // Used to load the 'sc66debug' library on application startup.
    static {
        System.loadLibrary("sc66debug");
    }
    /**
     * A native method that is implemented by the 'sc66debug' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native void turnOnCLK0();
    public native void turnOnCLK1();
    public native void turnOnCLK2();
    public native void turnOnCLK3();
    public native void turnOnCLK4();
    public native void turnOnCLK5();
    public native void turnOnCLK6();
    public native void turnOnCLK7();

    public native void turnoffallled();

    public native void turnOnGpio34();
    public native void turnOnGpio61();
    public native void turnOnGpio71();
    public native void turnOffGpio34();
    public native void turnOffGpio61();
    public native void turnOffGpio71();


    public native void IoExpanderUp();
    public native void IoExpanderDown();
    public native void IoExpanderInit();
    public native void ControllerInit();

    public native int getDepth();


    public native void ControllerDeInit();



    public native int getAbsoluteStateOfCharge();
    public native int read_RemainingCapacity();
    public native int read_FullChargeCapacity();
    public native int read_RunTimeToEmpty();
    public native int read_AverageTimeToEmpty();
    public native int read_AverageTimeToFull();
    public native int read_ChargingCurrent();
    public native int read_Current();
    public native int read_Voltage();
    public native int read_ChargingVoltage();
    public native int read_BatteryStatus();
    public native int read_CycleCount();
    public native int read_DesignCapacity();
    public native int read_DesignVoltage();
    public native int read_Specificationinfo();

    public native void setSuperchargeMode(String  value);

}
