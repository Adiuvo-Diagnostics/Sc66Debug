package com.adiuvo.sc66debug.renderers;

import android.content.Context;
import android.view.MotionEvent;

import org.rajawali3d.Object3D;

import org.rajawali3d.primitives.Plane;
import org.rajawali3d.renderer.Renderer;

public class GyroRenderer extends Renderer {

    private Object3D plane;
    private float pitch = 0, roll = 0, yaw = 0;

    public GyroRenderer(Context context) {
        super(context);
    }

    @Override
    protected void initScene() {
        plane = new Plane(2, 2, 1, 1);
        getCurrentScene().addChild(plane);
        getCurrentCamera().setPosition(3, 3, 3);
        getCurrentCamera().setLookAt(plane.getPosition());
    }

    public void setRotation(float pitch, float roll, float yaw) {
        this.pitch = pitch;
        this.roll = roll;
        this.yaw = yaw;
    }

    @Override
    protected void onRender(long ellapsedRealtime, double deltaTime) {
        plane.setRotation(pitch, yaw, roll);
        super.onRender(ellapsedRealtime, deltaTime);
    }

    @Override
    public void onOffsetsChanged(float xOffset, float yOffset, float xOffsetStep, float yOffsetStep, int xPixelOffset, int yPixelOffset) {

    }

    @Override
    public void onTouchEvent(MotionEvent event) {

    }
}

