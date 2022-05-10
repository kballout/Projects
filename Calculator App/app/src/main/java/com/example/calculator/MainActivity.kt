package com.example.calculator

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle

class MainActivity : AppCompatActivity(), BottomFragment.ButtonListener {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
    }


    //button listener override method sends button pressed to the top fragment
    override fun onButtonPress(button: String) {
        val topFragment = supportFragmentManager.findFragmentById(R.id.topFragment) as DisplayFragment
        topFragment.changeDisplay(button)
    }
}