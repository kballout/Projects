
package commanddesign;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CommandDesign {

 
    public static void main(String[] args) throws IOException {
        ReceiverCookJohn receiverCookJohn = new ReceiverCookJohn();
        ReceiverCookJeff receiverCookJeff = new ReceiverCookJeff();
        CommandOrder concreteOrderBurger = new ConcreteOrder(receiverCookJohn);
        CommandOrder concreteOrderShake = new ConcreteOrder(receiverCookJeff);
        InvokerWaitress waitress = new InvokerWaitress();
        
        
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String choice;
        do{
            System.out.println("Which meal would you like?\n1)Burger\n2)Malt Shake\n3)Quit");
            choice = input.readLine();
            if(choice.equalsIgnoreCase("1")){
                waitress.takeOrder(concreteOrderBurger);
                waitress.orderUp();
            }
            else if(choice.equalsIgnoreCase("2")){
                waitress.takeOrder(concreteOrderShake);
                waitress.orderUp();
            }
            System.out.println("\n");
        }while(!choice.equalsIgnoreCase("3"));
        
        
    }
    
}
