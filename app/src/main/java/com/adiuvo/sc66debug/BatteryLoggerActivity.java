package com.adiuvo.sc66debug;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.Handler;
import android.util.Log;

public class BatteryLoggerActivity extends AppCompatActivity {

    final static String TAG="BatteryLoggerActivity";
    private Handler handler = new Handler();
    private Runnable tickerRunnable = new Runnable() {
        @Override
        public void run() {
            onTick();
            handler.postDelayed(this, 1000);
        }
    };

    NativeLib nativeLib;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_battery_logger);

    }

    @Override
    protected void onResume() {
        super.onResume();
        nativeLib= new NativeLib();
        startTicker();
    }

    @Override
    protected void onPause() {
        super.onPause();
        stopTicker();
    }

    private void startTicker() {
        handler.post(tickerRunnable);
    }

    private void stopTicker() {
        handler.removeCallbacks(tickerRunnable);
    }

    private void onTick() {
        // This method will be called every second
        Log.d("MainActivity", "Tick");
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                Log.d(TAG, "run: nativeLib.read_BatteryStatus();"+nativeLib.read_BatteryStatus());
                Log.d(TAG,"run: read_Current()"+nativeLib.read_Current());
                Log.d(TAG,"run: read_Voltage()"+nativeLib.read_Voltage());
                Log.d(TAG,"run: getAbsoluteStateOfCharge()"+nativeLib.getAbsoluteStateOfCharge());
                Log.d(TAG,"run: read_AverageTimeToEmpty()"+nativeLib.read_AverageTimeToEmpty());
                Log.d(TAG,"run: read_AverageTimeToFull()"+nativeLib.read_AverageTimeToFull());
                Log.d(TAG,"run: read_RunTimeToEmpty()"+nativeLib.read_RunTimeToEmpty());
                Log.d(TAG,"run: read_RemainingCapacity()"+nativeLib.read_RemainingCapacity());

            }
        });
    }
}