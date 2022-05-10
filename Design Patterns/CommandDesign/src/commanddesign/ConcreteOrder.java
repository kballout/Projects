
package commanddesign;

public class ConcreteOrder extends CommandOrder{
    
    String order;

    public ConcreteOrder(ReceiverCookJohn receiverCookJohn) {
        this.receiverCookJohn = receiverCookJohn;
        order = "Burger";
    }

    public ConcreteOrder(ReceiverCookJeff receiverCookJeff) {
        this.receiverCookJeff = receiverCookJeff;
        order = "Malt Shake";
    }

    
    
    
    @Override
    public void executeOrder() {
        if(order.equalsIgnoreCase("Burger")){
            receiverCookJohn.makeBurger();
        }
        else if(order.equalsIgnoreCase("Malt Shake")){
            receiverCookJeff.makeMaltShake();
        }
    }
    
}
