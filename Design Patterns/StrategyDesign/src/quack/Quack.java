
package quack;

import Ducks.Duck;


public class Quack implements QuackBehavior {

    @Override
    public void quack(Duck duck) {
        System.out.println(duck.getColor() + " Duck:" + "Quack!");
    }
    
}
