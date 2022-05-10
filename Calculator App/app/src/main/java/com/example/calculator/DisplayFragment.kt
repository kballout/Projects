package com.example.calculator

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import com.example.calculator.databinding.FragmentDisplayBinding


class DisplayFragment : Fragment() {

    private lateinit var binding : FragmentDisplayBinding
    private var eval =  Evaluation()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
    }

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        binding = FragmentDisplayBinding.inflate(inflater, container, false)
        return binding.root
    }

    //function call when button is pressed
    fun changeDisplay(button: String) {
        if(button == "CE"){
            eval.clearEntry()
        }
        else if(button == "C"){
            eval.clearAll()
        }
        else if(button == "="){
            if(eval.validate()){
                eval.calculate()
            }
        }
        else if(button == "√"){
            eval.sqrRoot()
        }
        else if(button == "+/-"){
            eval.invert()
        }
        else{
            eval.addToDisplay(button[0].toString())
        }
        binding.screenDisplay.text = eval.getCurrentDisplay()
    }

}