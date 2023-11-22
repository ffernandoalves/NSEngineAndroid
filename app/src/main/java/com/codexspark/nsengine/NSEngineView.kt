package com.codexspark.nsengine

import android.content.Context
import android.opengl.GLSurfaceView
import android.util.AttributeSet
import javax.microedition.khronos.egl.EGLConfig
import javax.microedition.khronos.opengles.GL10

internal class NSEngineView(context: Context, attrs: AttributeSet) : GLSurfaceView(context, attrs) {
    init {
        setEGLConfigChooser(8, 8, 8, 0, 16, 0)
        setEGLContextClientVersion(3)
        setRenderer(Renderer())
    }

    private class Renderer: GLSurfaceView.Renderer {
        override fun onSurfaceCreated(gl: GL10, config: EGLConfig) {
            NSEngineLib.init()
        }

        override fun onSurfaceChanged(gl: GL10, width: Int, height: Int) {
            NSEngineLib.resize(width = width,  height = height)
        }

        override fun onDrawFrame(gl: GL10) {
            NSEngineLib.render()
        }
    }
}