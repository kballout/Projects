
package demowithflyweight;

import java.util.Timer;
import java.util.TimerTask;

public class DemoWithFlyweight {
    private static final String[] soldierTypes = {"Attacker" , "Defender"};
    private static final String[] weaponTypes = {"Sword", "Spear", "Bow and Arrow"};
    private static int totalAttackers = 0;
    private static int totalDefenders = 0;
    private static int counter = 0;
    
    public static void main(String[] args) {
        
        Timer timer = new Timer();
        TimerTask task = new TimerTask() {
            @Override
            public void run() {
                if(counter  == 10){
                    System.out.println("Total amount of attackers is: " + totalAttackers);
                    System.out.println("Total amount of defenders is: " + totalDefenders);
                    timer.cancel();
                }
                else{
                    createSoliders();
                    counter++;
                }
            }
        };
        timer.scheduleAtFixedRate(task, 0, 3000);
        
    }

    public static void createSoliders(){
        for (int i = 0; i < 1000; i++) {
            Soldier soldier = SoldierFactory.getSoldier(getRandomType());
            if(soldier.getClass().getSimpleName().equalsIgnoreCase("Attacker")){
                totalAttackers++;
            }
            else{
                totalDefenders++;
            }
            soldier.useWeapon(getRandomWeapon());
            soldier.mission();
        }
    }
    
    private static String getRandomType() {
        return soldierTypes[(int) (Math.random() * soldierTypes.length)];
    }
    
    private static String getRandomWeapon() {
        return weaponTypes[(int) (Math.random() * weaponTypes.length)];
    }
    
}
