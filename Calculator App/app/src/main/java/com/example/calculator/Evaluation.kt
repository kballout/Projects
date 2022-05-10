package com.example.calculator

import kotlin.math.sqrt


class Evaluation {
    private var currentDisplay : String = ""
    private var displayArray = ArrayList<String>()
    private var numList = ArrayList<Double>()
    private var operationList = ArrayList<String>()

    //when there's any error this method is called
    private fun setError(){
        clearAll()
        displayArray.add("Error")
    }

    //add an entry, number or operator to the display screen
    fun addToDisplay(entry : String){
        var temp = ""
        //cannot add two decimals in a row
        if(entry[0] == '.' && displayArray.isNotEmpty() && displayArray.last()[displayArray.last().length - 1] == '.'){
            return
        }
        //keep two digit numbers together
        else if((entry[0].isDigit() || entry[0] == '.') && displayArray.isNotEmpty() && (displayArray.last()[0].isDigit() || displayArray.last()[0] == '.')){
            var count = 0
            for (i in displayArray.size downTo 1){
                if(displayArray[i - 1][0].isDigit() || displayArray[i - 1][0] == '.'){
                    temp += displayArray[i - 1]
                    count++
                }
                else{
                    break
                }
            }
            while(count > 0){
                displayArray.removeLast()
                count--
            }
            temp += entry
        }
        if(temp.isNotEmpty()){
            displayArray.add(temp)
        }
        else{
            displayArray.add(entry)
        }
    }

    //clear the previous entry
    fun clearEntry(){
        if(displayArray.isNotEmpty()){
            if(displayArray.last().length > 1){
                displayArray[displayArray.lastIndex] = displayArray.last().substring(0, displayArray.last().length - 1)
            }
            else{
                displayArray.removeLast()
            }
        }
    }

    //clear the entire display and lists
    fun clearAll(){
        numList.clear()
        operationList.clear()
        displayArray.clear()
    }

    //get the current display to place on the top fragment
    fun getCurrentDisplay(): String {
        currentDisplay = ""
        for(i in displayArray){
            currentDisplay += i
        }
        if(currentDisplay == "Error" || currentDisplay == "Infinity"){
            displayArray.clear()
        }
        return currentDisplay
    }

    //invert the previous number +/-
    fun invert(){
        //change to positive
        if(displayArray.last()[0] == '('){
            var num = ""
            for (i in displayArray.last()){
                if(i.isDigit() || i == '.'){
                    num += i
                }
                if(i == ')'){
                    break
                }
            }
            displayArray.removeLast()
            displayArray.add(num)
        }
        //change to negative
        else{
            var num = ""
            var count = 0
            for (i in displayArray.size downTo 1){
                if(displayArray[i - 1][0].isDigit() || displayArray[i - 1][0] == '.'){
                    num += displayArray[i - 1][0]
                    count++
                }
                else{
                    break
                }
            }
            while(count > 0){
                displayArray.removeLast()
                count--
            }
            displayArray.add("(-" + num.reversed() + ")")
        }
    }

    //take the square root of the previous number pressed
    fun sqrRoot() {
        //square root of negative is error
        if(displayArray.isNotEmpty() && displayArray.last()[0] == '('){
            setError()
        }
        else if (displayArray.isNotEmpty() && (displayArray.last()[0].isDigit() || displayArray.last()[0] == '.')){
            val temp = sqrt(displayArray.last().toDouble())
            displayArray.removeLast()
            displayArray.add(temp.toString())
        }
    }

    //validate the input before calculation
    fun validate() : Boolean{
        for ((i, value ) in displayArray.withIndex()){
            //start with operator
            if(i == 0 && !value[0].isDigit() && value[0] != '.' && value[0] != '('){
                setError()
                return false
            }
            //next value is negative
            else if(value[0] == '('){
               numList.add(value.substring(1,value.length - 1).toDouble())
            }
            //next value is number
            else if(value[0].isDigit() || value[0] == '.'){
                numList.add(value.toDouble())
            }
            //next value is operator
            else {
                //2 operators in a row error
                if(displayArray[i - 1][0] == 'x' || displayArray[i - 1][0] == '+' ||
                    displayArray[i - 1][0] == '-' || displayArray[i - 1][0] == '÷' ||
                    displayArray[i - 1][0] == '%' || displayArray[i + 1][0] == 'x' ||
                    displayArray[i + 1][0] == '+' || displayArray[i + 1][0] == '-' ||
                    displayArray[i + 1][0] == '÷' || displayArray[i + 1][0] == '%'){
                        setError()
                        return false
                }
                else{
                    operationList.add(value)
                }
            }
        }
        return true
    }

    //calculate result
    fun calculate() {
        var prev : Int?
        var next : Int?
        //order of operations
        while(numList.size != 1){
            if(operationList.contains("x")){
                prev = operationList.indexOf(operationList.first { it == "x" })
                next = prev + 1
                numList[prev] = numList[prev] * numList[next]
                numList.removeAt(next)
                operationList.removeAt(prev)
            }
            else if(operationList.contains("%")){
                prev = operationList.indexOf(operationList.first { it == "%" })
                next = prev + 1
                numList[prev] = numList[prev] % numList[next]
                numList.removeAt(next)
                operationList.removeAt(prev)
            }
            else if(operationList.contains("÷")){
                prev = operationList.indexOf(operationList.first { it == "÷" })
                next = prev + 1
                numList[prev] = numList[prev] / numList[next]
                numList.removeAt(next)
                operationList.removeAt(prev)
            }
            else if(operationList.contains("+") ){
                prev = operationList.indexOf(operationList.first { it == "+" })
                next = prev + 1
                numList[prev] = numList[prev] + numList[next]
                numList.removeAt(next)
                operationList.removeAt(prev)
            }
            else if(operationList.contains("-")){
                prev = operationList.indexOf(operationList.first { it == "-" })
                next = prev + 1
                numList[prev] = numList[prev] - numList[next]
                numList.removeAt(next)
                operationList.removeAt(prev)
            }
        }
        displayArray.clear()
        var result = numList[0].toString()
        val subResult = result.substring(result.indexOf('.',0,false) + 1, result.length)
        //convert to integer if decimal ends with 0
        if(subResult == "0"){
           result = (numList[0].toInt()).toString()
        }
        //if result is a negative
        if(result[0] == '-'){
            displayArray.add(result.substring(1,result.length))
            invert()
        }
        else{
            displayArray.add(result)
        }
        numList.clear()
        operationList.clear()
    }

}