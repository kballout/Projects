
package calculator;

import java.net.URL;
import java.util.HashSet;
import java.util.ResourceBundle;
import java.util.Set;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import java.util.ArrayList;
import java.util.Stack;


public class CalculatorFXMLController implements Initializable {

    @FXML
    private Label screenOutput;
    private ArrayList<String> screenArray = new ArrayList();
    String finalOutput = "";
    Stack<Double> stack = new Stack();
    boolean isError = false;
    boolean divideByZero = false;
    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
       
    }    

    @FXML
    private void numOne(ActionEvent event) {
        screenArray.add("1");
        PrintToScreen();
    }

    @FXML
    private void numTwo(ActionEvent event) {
        screenArray.add("2");
        PrintToScreen();
    }

    @FXML
    private void numThree(ActionEvent event) {
        screenArray.add("3");
        PrintToScreen();
    }

    @FXML
    private void numFour(ActionEvent event) {
        screenArray.add("4");
        PrintToScreen();
    }

    @FXML
    private void numFive(ActionEvent event) {
        screenArray.add("5");
        PrintToScreen();
    }

    @FXML
    private void numSix(ActionEvent event) {
        screenArray.add("6");
        PrintToScreen();
    }

    @FXML
    private void numSeven(ActionEvent event) {
        screenArray.add("7");
        PrintToScreen();
    }

    @FXML
    private void numEight(ActionEvent event) {
        screenArray.add("8");
        PrintToScreen();
    }

    @FXML
    private void numNine(ActionEvent event) {
        screenArray.add("9");
        PrintToScreen();
    }

    @FXML
    private void numZero(ActionEvent event) {
        screenArray.add("0");
        PrintToScreen();
    }

    @FXML
    private void clear(ActionEvent event) {
        screenArray.clear();
        finalOutput = "";
        isError = false;
        divideByZero = false;
        PrintToScreen();
    }

    @FXML
    private void add(ActionEvent event) {
        screenArray.add("+");
        PrintToScreen();
    }

    @FXML
    private void subtract(ActionEvent event) {
        screenArray.add("-");
        PrintToScreen();
    }

    @FXML
    private void multiply(ActionEvent event) {
        screenArray.add("*");
        PrintToScreen();
    }

    @FXML
    private void divide(ActionEvent event) {
        screenArray.add("/");
        PrintToScreen();
    }

    @FXML
    private void space(ActionEvent event) {
        screenArray.add(" ");
        PrintToScreen();
    }
    
    @FXML
    private void calculate(ActionEvent event) {
        String nextNumber = "";
        for(int i = 0; i < screenArray.size(); i++){
            if(" ".equals(screenArray.get(i))){
                double number = Double.parseDouble(nextNumber);
                stack.push(number);
                nextNumber = "";
            }
            else if ("+".equals(screenArray.get(i))){
                PerformOperation(1);
                if(isError == true){
                    break;
                }
                i++;
            }
            else if ("-".equals(screenArray.get(i))){
                PerformOperation(2);
                if(isError == true){
                    break;
                }
                i++;
            }
            else if ("*".equals(screenArray.get(i))){
                PerformOperation(3);
                if(isError == true){
                    break;
                }
                i++;
            }
            else if ("/".equals(screenArray.get(i))){
                PerformOperation(4);
                if(isError == true){
                    break;
                }
                if(divideByZero == true){
                    break;
                }
                i++;
            }
            else {
                nextNumber = nextNumber + screenArray.get(i);
            }
        }
        if(isError == true){
            screenOutput.setText("Error");
        }
        else if(divideByZero == true){
            screenOutput.setText("Cannot divide by zero");
        }
        else{
            double answer = stack.pop();
            if(answer % 1 == 0){
                int convertedAnswer = (int) answer;
                screenOutput.setText(Integer.toString(convertedAnswer));
            }
            else{
               screenOutput.setText(Double.toString(answer)); 
            }
            
        }
    }
    
    public void PerformOperation (int choice){
        Double result;
        if(choice == 1){
            if(stack.size() == 1){
                isError = true;
            }
            else{
             result = stack.pop() + stack.pop();
             stack.push(result);   
            }
        }
        if(choice == 2){
            if(stack.size() == 1){
                isError = true;
            }
            else{
               Double firstVal = stack.pop();
               Double secondVal = stack.pop();
               result = secondVal - firstVal;
               stack.push(result); 
            } 
        }
        if(choice == 3){
            if(stack.size() == 1){
                isError = true;
            }
            else{
              result = stack.pop() * stack.pop();
              stack.push(result);  
            }
        }
        if(choice == 4){
            if(stack.size() == 1){
                isError = true;
            }
            else{
               Double firstVal = stack.pop();
               Double secondVal = stack.pop();
               result = secondVal / firstVal;
               if(result.isInfinite()){
                   divideByZero = true;
               }
               else{
                  stack.push(result);  
               }
            }
        }
    }
    
    public void PrintToScreen(){
        if(!screenArray.isEmpty()){
            finalOutput = finalOutput + screenArray.get(screenArray.size() - 1);
        }
        screenOutput.setText(finalOutput);
    }   
}