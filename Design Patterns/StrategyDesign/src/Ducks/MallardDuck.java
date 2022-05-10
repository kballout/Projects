
package Ducks;

import fly.FlyWithWings;
import quack.Quack;


public class MallardDuck extends Duck{
    
    public MallardDuck(String color) {
        quackBehavior = new Quack();
        flyBehavior = new FlyWithWings();
        this.color = color;
    }
    
    
    @Override
    public void display() {
       
        System.out.println("I'm a mallard duck!");
    }

    
    
}
