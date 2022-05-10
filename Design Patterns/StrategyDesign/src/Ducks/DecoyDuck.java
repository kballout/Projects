
package Ducks;

import fly.FlyRocketPowered;
import quack.FakeQuack;


public class DecoyDuck extends Duck{
    
    public DecoyDuck(String color) {
        quackBehavior = new FakeQuack();
        flyBehavior = new FlyRocketPowered();
        this.color = color;
        
    }
    
    
    @Override
    public void display() {
       
        System.out.println("I'm a decoy duck!");
    }

    
    
}
