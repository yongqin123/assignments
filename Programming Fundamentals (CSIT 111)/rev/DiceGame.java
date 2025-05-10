import java.util.Random;

class Dice {
    private int face;
    
    
    public Dice() {
    }

    public int getFace() {
        return face;
    }

    public void setFace(int face) {
        this.face = face;
    }
    
    
}

    
class Player {
    private int score;
    private String name;

    public Player(String name) {
        this.name = name;
    }

    public Player() {
    }

    public void rollDice(Dice dice) {
        Random rnd = new Random();
        score = rnd.nextInt(6) + 1;
        dice.setFace(score);
        
    }

    public String getName() {
        return name;
    }

    public int getScore() {
        return score;
    }

    

    public void setName(String name) {
        this.name = name;
    }
    
    
    
}


public class DiceGame {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        Dice dice = new Dice();
        
        Player player1 = new Player("John");
        Player player2 = new Player("Peter");
        
        player1.rollDice(dice);
        System.out.println("Dice face: " + dice.getFace());
        player2.rollDice(dice);
        System.out.println("Dice face: " + dice.getFace());
        
        if (player1.getScore() > player2.getScore()) {
            System.out.println(player1.getName() + " wins!");
        }
        else if (player1.getScore() < player2.getScore()) {
            System.out.println(player2.getName() + " wins!");
        }
        else {
            System.out.println("It's a tie!");
        }
    }
}
