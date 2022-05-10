
package Ducks;

import fly.FlyBehavior;
import quack.QuackBehavior;


public abstract class Duck {
    FlyBehavior flyBehavior;
    QuackBehavior quackBehavior;
    String color;
    
    public abstract void display();
    
    public void performFly(){
        flyBehavior.fly(this);
    }
    
    public void performQuack(){
        quackBehavior.quack(this);
    }
    
    public void swim(){
        System.out.println("All ducks can swim!");
    }
    
    public String getColor(){
        return color;
    }
}
