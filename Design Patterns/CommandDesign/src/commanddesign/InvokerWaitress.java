
package commanddesign;


public class InvokerWaitress {
    private CommandOrder commandOrder;
    
    public void takeOrder(CommandOrder commandOrder){
        this.commandOrder = commandOrder;
    }
    
    public void orderUp(){
        commandOrder.executeOrder();
    }
}
