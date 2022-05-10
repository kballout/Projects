
package fly;

import Ducks.Duck;


public class FlyWithWings implements FlyBehavior{

    @Override
    public void fly(Duck duck) {
        System.out.println(duck.getColor() + " Duck:" + "I'm flying!");
    }
    
}
