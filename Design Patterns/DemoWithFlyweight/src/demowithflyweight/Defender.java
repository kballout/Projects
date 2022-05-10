
package demowithflyweight;


public class Defender implements Soldier {
    private final String objective;
    private String weapon;

    public Defender() {
        objective = "Defend the city.";
    }
    
    @Override
    public void mission() {
        System.out.println("The defender's weapon is the " + weapon + ". The objective: " + objective);
    }

    @Override
    public void useWeapon(String weapon) {
        this.weapon = weapon;
    }
}
