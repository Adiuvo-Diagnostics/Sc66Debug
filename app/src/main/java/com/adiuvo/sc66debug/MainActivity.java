package com.adiuvo.sc66debug;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.CompoundButton;
import android.widget.TextView;

import com.adiuvo.sc66debug.databinding.ActivityMainBinding;
import com.google.android.material.checkbox.MaterialCheckBox;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {


    private ActivityMainBinding binding;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        NativeLib nativeLib=new NativeLib();

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        binding.paramControl.setVisibility(View.GONE);

        binding.batteryStatus.setOnClickListener(view -> startActivity(new Intent(MainActivity.this,BatteryLoggerActivity.class)));
        binding.gpio34.setOnCheckedChangeListener((compoundButton, b) -> {
            if(b){
                nativeLib.turnOnGpio34();
            }else{
                nativeLib.turnOffGpio34();
            }
        });
        binding.gpio61.setOnCheckedChangeListener((compoundButton, b) -> {
            if(b){
                nativeLib.turnOnGpio61();
            }else{
                nativeLib.turnOffGpio61();
            }
        });
        binding.gpio71.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean b) {
                if(b){
                    nativeLib.turnOnGpio71();
                }else{
                    nativeLib.turnOffGpio71();
                }
            }
        });

        /* Controller SECTION*/
        binding.ctrlInit.setOnClickListener(view -> {
            nativeLib.ControllerInit();
            binding.paramControl.setVisibility(View.VISIBLE);
        });
        binding.ctrlDeInit.setOnClickListener(view -> {
            nativeLib.ControllerDeInit();
            binding.paramControl.setVisibility(View.GONE);
        });


        /* IO EXPANDER SECTION*/
        binding.ioUp.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                nativeLib.IoExpanderUp();
            }
        });
        binding.ioDown.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                nativeLib.IoExpanderDown();
            }
        });

        /*LED SECTION*/
        binding.clk0.setOnClickListener(view -> nativeLib.turnOnCLK0());
        binding.clk1.setOnClickListener(view -> nativeLib.turnOnCLK1());
        binding.clk2.setOnClickListener(view -> nativeLib.turnOnCLK2());
        binding.clk3.setOnClickListener(view -> nativeLib.turnOnCLK3());
        binding.clk4.setOnClickListener(view -> nativeLib.turnOnCLK4());
        binding.clk5.setOnClickListener(view -> nativeLib.turnOnCLK5());
        binding.clk6.setOnClickListener(view -> nativeLib.turnOnCLK6());
        binding.clk7.setOnClickListener(view -> nativeLib.turnOnCLK7());
        binding.turnOff.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                nativeLib.turnoffallled();
            }
        });

        /*Depth  SECTION*/
        binding.getDepth.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Log.d("TAG", "onClick: nativeLib.getDepth()"+ nativeLib.getDepth());
                String data= String.valueOf(nativeLib.getDepth());
                Log.d("TAG", "onClick: nativeLib.getDepth()"+ data);
                binding.depthRangeText.setText(data+"mm");
            }
        });


        /*I2C  SECTION*/
        binding.detectI2c.setOnClickListener(view -> {
            try {
                Log.d("TAG", "onClick: detectAllI2c");

                // Get the list of available I2C bus numbers
                Process busListProcess = Runtime.getRuntime().exec("i2cdetect -l");
                busListProcess.waitFor();

                BufferedReader reader = new BufferedReader(new InputStreamReader(busListProcess.getInputStream()));
                String line;
                List<String> busNumbers = new ArrayList<>();
                while ((line = reader.readLine()) != null) {
                    // Parse the bus numbers from the output
                    if (line.contains("i2c-")) {
                        String[] parts = line.split("\\s+");
                        if (parts.length >= 2) {
                            busNumbers.add(parts[0].replace("i2c-", ""));
                        }
                    }
                }
                reader.close();

                StringBuilder allResults = new StringBuilder();
                for (String busNumber : busNumbers) {
                    Process process = Runtime.getRuntime().exec("i2cdetect -y " + busNumber);
                    process.waitFor();

                    int exitValue = process.exitValue();
                    if (exitValue == 0) {
                        reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
                        StringBuilder output = new StringBuilder();
                        while ((line = reader.readLine()) != null) {
                            output.append(line).append("\n");
                        }
                        reader.close();

                        allResults.append("Results for bus ").append(busNumber).append(":\n");
                        allResults.append(output).append("\n");
                    } else {
                        allResults.append("Error for bus ").append(busNumber).append(": Process exited with non-zero status ").append(exitValue).append("\n");
                    }
                }

                String allResultsText = allResults.toString();
                runOnUiThread(() -> binding.detectI2cLines.setText(allResultsText)); // Update UI

            } catch (IOException e) {
                e.printStackTrace();
                String errorMsg = "Error: " + e.getMessage();
                runOnUiThread(() -> binding.detectI2cLines.setText(errorMsg)); // Update UI
            } catch (InterruptedException e) {
                e.printStackTrace();
                String errorMsg = "Error: " + e.getMessage();
                runOnUiThread(() -> binding.detectI2cLines.setText(errorMsg)); // Update UI
            }

        });

    }


}