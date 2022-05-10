
package demowithflyweight;


public class Attacker implements Soldier {

    private final String objective;
    private String weapon;

    public Attacker() {
        objective = "Siege the city.";
    }
    
    @Override
    public void mission() {
        System.out.println("The attacker's weapon is the " + weapon + ". The objective: " + objective);
    }

    @Override
    public void useWeapon(String weapon) {
        this.weapon = weapon;
    }
    
}
