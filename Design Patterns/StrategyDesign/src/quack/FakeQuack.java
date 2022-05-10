
package quack;

import Ducks.Duck;


public class FakeQuack implements QuackBehavior {

    @Override
    public void quack(Duck duck) {
        System.out.println(duck.getColor() + " Duck:" + "Fake Quack!");
    }
    
}
