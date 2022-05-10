
package demowithflyweight;

import java.util.HashMap;
import java.util.Map;

public class SoldierFactory {
    private static Map<String, Soldier> soldiersMap = new HashMap<>();
    
    public static Soldier getSoldier(String type){
        Soldier soldier = soldiersMap.get(type);
        if(soldier == null){
            if(type.equalsIgnoreCase("attacker")){
                System.out.println("New attacker created");
                soldier = new Attacker();
                soldiersMap.put(type, soldier);
            }
            else{
                System.out.println("New defender created");
                soldier = new Defender();
                soldiersMap.put(type, soldier);
            }
        }
        return soldier;
    }
}
