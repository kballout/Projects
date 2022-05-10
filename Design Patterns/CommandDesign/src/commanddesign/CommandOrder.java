/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package commanddesign;

/**
 *
 * @author Kassim
 */
public abstract class CommandOrder {
    protected ReceiverCookJohn receiverCookJohn;
    protected ReceiverCookJeff receiverCookJeff;

    public CommandOrder() {
    
    }
    
    public abstract void executeOrder();
    
}
