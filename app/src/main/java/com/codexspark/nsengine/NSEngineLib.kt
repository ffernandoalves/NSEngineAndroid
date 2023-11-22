package com.codexspark.nsengine

object NSEngineLib {

    init {
        System.loadLibrary("nsengine")
    }

    external fun init()
    external fun resize(width: Int, height: Int)
    external fun render()
}