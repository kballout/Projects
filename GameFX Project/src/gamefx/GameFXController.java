
package gamefx;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import java.util.Random;

public class GameFXController implements Initializable {

    @FXML
    private ImageView playerOption;
    Image rock = new Image("Rock.png");
    Image paper = new Image("Paper.png");
    Image scissors = new Image("Scissors.png");
    Image spock = new Image("Spock.png");
    Image lizard = new Image("Lizard.png");
    @FXML
    private ImageView computerChoice;
    @FXML
    private Label resultLabel;
    
    
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }    
    
    public int randomizeComputerChoice(){
        Random rand = new Random();
        int randomNumber = rand.nextInt(5);
        switch (randomNumber) {
            case 0 -> computerChoice.setImage(rock);
            case 1 -> computerChoice.setImage(paper);
            case 2 -> computerChoice.setImage(scissors);
            case 3 -> computerChoice.setImage(spock);
            case 4 -> computerChoice.setImage(lizard);
            default -> {
            }
        }
        return randomNumber;
    }
    
    public void printResult(int playerChoice, int randomNumber){
       if(playerChoice == 0){
           switch (randomNumber) {
               case 0 -> resultLabel.setText("Draw!");
               case 1 -> resultLabel.setText("Paper covers rock \n \nYou lose!");
               case 2 -> resultLabel.setText("Rock crushes scissors \n \nYou win!");
               case 3 -> resultLabel.setText("Spock vaporizes rock \n \nYou lose!");
               case 4 -> resultLabel.setText("Rock crushes lizard \n \nYou win!");
               default -> {
               }
           }
      }
      else if(playerChoice == 1){
           switch (randomNumber) {
               case 0 -> resultLabel.setText("Paper covers rock \n \nYou win!");
               case 1 -> resultLabel.setText("Draw!");
               case 2 -> resultLabel.setText("Scissors cuts paper \n \nYou lose!");
               case 3 -> resultLabel.setText("Paper disproves spock \n \nYou win!");
               case 4 -> resultLabel.setText("Lizard eats paper \n \nYou lose!");
               default -> {
               }
           }
      }
      else if(playerChoice == 2){
           switch (randomNumber) {
               case 0 -> resultLabel.setText("Rock crushes scissors \n \nYou lose!");
               case 1 -> resultLabel.setText("Scissors cuts paper \n \nYou win!");
               case 2 -> resultLabel.setText("Draw!");
               case 3 -> resultLabel.setText("Spock smashes scissors \n \nYou lose!");
               case 4 -> resultLabel.setText("Scissors decapitates lizard \n \nYou win!");
               default -> {
               }
           }
      }
      else if(playerChoice == 3){
           switch (randomNumber) {
               case 0 -> resultLabel.setText("Spock vaporizes rock \n \nYou win!");
               case 1 -> resultLabel.setText("Paper disproves spock \n \nYou lose!");
               case 2 -> resultLabel.setText("Spock smashes scissors \n \nYou win!");
               case 3 -> resultLabel.setText("Draw!");
               case 4 -> resultLabel.setText("Lizard poisons spock \n \nYou lose!");
               default -> {
               }
           }
      }
      else if(playerChoice == 4){
           switch (randomNumber) {
               case 0 -> resultLabel.setText("Rock crushes lizard \n \nYou lose!");
               case 1 -> resultLabel.setText("Lizard eats paper \n \nYou win!");
               case 2 -> resultLabel.setText("Scissors decapitates lizard \n \nYou lose!");
               case 3 -> resultLabel.setText("Lizard poisons spock \n \nYou win!");
               case 4 -> resultLabel.setText("Draw!");
               default -> {
               }
           }
      }
    }

    @FXML
    private void selectRock(ActionEvent event) {
        playerOption.setImage(rock);
        printResult(0,randomizeComputerChoice());
        
    }

    @FXML
    private void selectPaper(ActionEvent event) {
        playerOption.setImage(paper);
        printResult(1,randomizeComputerChoice());
    }

    @FXML
    private void selectScissors(ActionEvent event) {
        playerOption.setImage(scissors);
        printResult(2,randomizeComputerChoice());
    }

    @FXML
    private void selectSpock(ActionEvent event) {
        playerOption.setImage(spock);
        printResult(3,randomizeComputerChoice());
    }

    @FXML
    private void selectLizard(ActionEvent event) {
        playerOption.setImage(lizard);
        printResult(4,randomizeComputerChoice());
    }

    
}
