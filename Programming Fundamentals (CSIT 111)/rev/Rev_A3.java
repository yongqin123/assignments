import java.util.Scanner;
import java.util.Random;
import java.util.Arrays;

class Staff {
    final static int SIZE = 8;
    private String name;
    private double[] score = new double[8];

    public Staff(String name) {
        this.name = name;
        generateScore();
    }
    
    public Staff() {}
    
    public String getName() {
        return name;
    }
    
    private void generateScore() {
        Random rnd = new Random();
        for (int i = 0; i < SIZE; i++) {
            score[i] = Math.random()*10;
        }
        this.score = score;
       
    }
    
    
    
    public void printInfo() {
        
        System.out.printf("%-12s%-5.1f%-5.1f%-5.1f%-5.1f%-5.1f%-5.1f%-5.1f%-5.1f%-5.1f\n",getName(),score[0],score[1],score[2],score[3],score[4],score[5],score[6],score[7],average());
    }
    
    private int highest() {
        double highers = 0;
        int pos = 0;
        for (int i = 0; i < score.length; i++) {
            if (highers < score[i]) {
                highers = score[i];
                pos = i;
            }
            
        }
        System.out.println(highers);
        return pos;
    }
    
    private int lowest() {
        double lowers = 11;
        int pos = 0;
        for (int i = 0; i < score.length; i++) {
            if (lowers > score[i]) {
                lowers = score[i];
                pos = i;
            }
            
        }
        System.out.println(lowers);
        return pos;
    }
    
    public double average() {
        double[] score_dup = score;
        int a = highest();
        int b = lowest();
        score_dup[a] = 0;
        score_dup[b] = 0;
        double sum = 0;
        for (int i = 0; i < score_dup.length; i++) {
            sum += score_dup[i];
            
        }
        return sum / 6;
    }
}






public class Rev_A3 {
    private String[] name = new String[8];
    private Staff[] staff_obj = new Staff[8];
    public static void main(String[] args) {
        Rev_A3 a3 = new Rev_A3();
        for (int i = 0; i < 8; i++) {
            a3.name[i] = "Heng "+(i+1);
            a3.staff_obj[i] = new Staff(a3.name[i]);
            
            
            a3.staff_obj[i].printInfo();
        }
        
        
    }
}