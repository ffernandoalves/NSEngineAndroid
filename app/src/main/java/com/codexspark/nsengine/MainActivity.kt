package com.codexspark.nsengine

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle

class MainActivity : AppCompatActivity() {

    private lateinit var nsEngineView: NSEngineView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
//        setContentView(R.layout.activity_main)
        setContentView(R.layout.layout_test)

        // for Renderer
        nsEngineView = findViewById(R.id.glSurface)
    }

    override fun onPause() {
        super.onPause()
        nsEngineView.onPause()
    }

    override fun onResume() {
        super.onResume()
        nsEngineView.onResume()
    }
}