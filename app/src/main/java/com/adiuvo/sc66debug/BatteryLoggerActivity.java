package com.adiuvo.sc66debug;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.Gravity;
import android.widget.LinearLayout;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;

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
                // Get the values from the native library
                String batteryStatus = String.valueOf(nativeLib.read_BatteryStatus());
                String current = String.valueOf(nativeLib.read_Current());
                String voltage = String.valueOf(nativeLib.read_Voltage());
                String absoluteStateOfCharge = String.valueOf(nativeLib.getAbsoluteStateOfCharge());
                String averageTimeToEmpty = String.valueOf(nativeLib.read_AverageTimeToEmpty());
                String averageTimeToFull = String.valueOf(nativeLib.read_AverageTimeToFull());
                String runTimeToEmpty = String.valueOf(nativeLib.read_RunTimeToEmpty());
                String remainingCapacity = String.valueOf(nativeLib.read_RemainingCapacity());

                // Log the values
                Log.d(TAG, "run: nativeLib.read_BatteryStatus();"+batteryStatus);
                Log.d(TAG,"run: read_Current()"+current);
                Log.d(TAG,"run: read_Voltage()"+voltage);
                Log.d(TAG,"run: getAbsoluteStateOfCharge()"+absoluteStateOfCharge);
                Log.d(TAG,"run: read_AverageTimeToEmpty()"+averageTimeToEmpty);
                Log.d(TAG,"run: read_AverageTimeToFull()"+averageTimeToFull);
                Log.d(TAG,"run: read_RunTimeToEmpty()"+runTimeToEmpty);
                Log.d(TAG,"run: read_RemainingCapacity()"+remainingCapacity);

                // Create a new row with the values
                TableRow newRow = new TableRow(BatteryLoggerActivity.this);
                newRow.addView(createTextView(batteryStatus));
                newRow.addView(createTextView(current));
                newRow.addView(createTextView(voltage));
                newRow.addView(createTextView(absoluteStateOfCharge));
                newRow.addView(createTextView(averageTimeToEmpty));
                newRow.addView(createTextView(averageTimeToFull));
                newRow.addView(createTextView(runTimeToEmpty));
                newRow.addView(createTextView(remainingCapacity));

                // Get the table from the layout and add the new row
                TableLayout table = findViewById(R.id.table);
                table.addView(newRow, 1); // Add at the top of the table
            }
        });
    }

    private TextView createTextView(String text) {
        TextView textView = new TextView(this);
        textView.setText(text);
        textView.setGravity(Gravity.CENTER);
        textView.setLayoutParams(new TableRow.LayoutParams(0, TableRow.LayoutParams.WRAP_CONTENT, 1.0f));
        return textView;
    }

}