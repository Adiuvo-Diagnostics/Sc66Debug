package com.adiuvo.sc66debug;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

import com.adiuvo.sc66debug.managers.ICM20689Manager;
import com.adiuvo.sc66debug.renderers.GyroRenderer;

import org.rajawali3d.view.SurfaceView;

public class GyroScopeandAccelerometer extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_gyro_scopeand_accelerometer);

        SurfaceView surface = findViewById(R.id.rajawali_surface);
        GyroRenderer renderer = new GyroRenderer(this);
        surface.setSurfaceRenderer(renderer);

        ICM20689Manager icmManager=new ICM20689Manager();
        float[] gyroscopeData = icmManager.getGyroscopeData();
        renderer.setRotation(gyroscopeData[0], gyroscopeData[1], gyroscopeData[2]);


    }
}