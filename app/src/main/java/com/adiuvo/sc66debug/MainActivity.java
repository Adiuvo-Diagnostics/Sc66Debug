package com.adiuvo.sc66debug;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

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

public class MainActivity extends AppCompatActivity {


    private ActivityMainBinding binding;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        NativeLib nativeLib=new NativeLib();

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        binding.paramControl.setVisibility(View.GONE);
        binding.gpio34.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean b) {
                if(b){
                    nativeLib.turnOnGpio34();
                }else{
                    nativeLib.turnOffGpio34();
                }
            }
        });
        binding.gpio61.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean b) {
                if(b){
                    nativeLib.turnOnGpio61();
                }else{
                    nativeLib.turnOffGpio61();
                }
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
                Log.d("TAG", "onClick: detectI2c");
                Process process = Runtime.getRuntime().exec("i2cdetect -y 6");
                BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
                StringBuilder output = new StringBuilder();
                String line;
                while ((line = reader.readLine()) != null) {
                    output.append(line).append("\n");
                }
                reader.close();
                process.waitFor();
                String result = output.toString();
                binding.detectI2cLines.setText(result);
            } catch (IOException e) {
                e.printStackTrace();
                binding.detectI2cLines.setText("Error: " + e.getMessage());
            } catch (InterruptedException e) {
                e.printStackTrace();
                binding.detectI2cLines.setText("Error: " + e.getMessage());
            }
        });

    }


}