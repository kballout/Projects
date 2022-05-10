
package fly;

import Ducks.Duck;


public class FlyNoWay implements FlyBehavior{

    @Override
    public void fly(Duck duck) {
        System.out.println(duck.getColor() + " Duck:" + "I can't fly!");
    }
    
}
