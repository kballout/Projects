package com.example.calculator

import android.content.Context
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import com.example.calculator.databinding.FragmentBottomBinding
import java.lang.ClassCastException

class BottomFragment : Fragment() {

    private lateinit var binding : FragmentBottomBinding
    private var buttonsList = ArrayList<Button>()
    private var activityCallback : ButtonListener? = null

    interface ButtonListener {
        fun onButtonPress(button: String)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
    }

    override fun onAttach(context: Context){
        super.onAttach(context)

        try{
            activityCallback = context as ButtonListener
        }
        catch (exception: ClassCastException){
            throw ClassCastException("$context must implement ButtonListener")
        }
    }

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        binding = FragmentBottomBinding.inflate(inflater, container, false)

        //add all buttons to a list
        buttonsList.add(binding.zero)
        buttonsList.add(binding.decimal)
        buttonsList.add(binding.plusOrMinus)
        buttonsList.add(binding.one)
        buttonsList.add(binding.two)
        buttonsList.add(binding.three)
        buttonsList.add(binding.four)
        buttonsList.add(binding.five)
        buttonsList.add(binding.six)
        buttonsList.add(binding.seven)
        buttonsList.add(binding.eight)
        buttonsList.add(binding.nine)
        buttonsList.add(binding.modulus)
        buttonsList.add(binding.division)
        buttonsList.add(binding.squareRoot)
        buttonsList.add(binding.multiplication)
        buttonsList.add(binding.clearEntry)
        buttonsList.add(binding.subtraction)
        buttonsList.add(binding.clear)
        buttonsList.add(binding.addition)
        buttonsList.add(binding.equals)

        //set button listeners to entire list of buttons
        for (btn in buttonsList){
            btn.setOnClickListener{
                    v: View -> buttonClicked(v, btn)
            }
        }

        return binding.root
    }

    //method for button listener interface sends button pressed
    private fun buttonClicked(view: View, button : Button) {
        activityCallback?.onButtonPress(button.text.toString())
    }


}