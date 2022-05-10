
package strategydesign;

import Ducks.DecoyDuck;


public class StrategyDesign {

  
    public static void main(String[] args) {
        DecoyDuck decoy = new DecoyDuck("Yellow");
        decoy.performFly();
        decoy.performQuack();
    }
    
}
