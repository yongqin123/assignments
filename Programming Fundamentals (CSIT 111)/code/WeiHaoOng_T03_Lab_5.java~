/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author weihao
 */
//Full Name: Wei Hao Ong
//Full Time 
//UOW Student no: 7058895
//Tutorial group: T03
//Declaration:This is my own work, I have not passed this program to anyone
//
//File name: WeiHaoOng_T03_Lab_5.java

class MyInteger{
    private int n;
    
    public MyInteger(){
      
    }
    
    public MyInteger(int n){
        this.n=n;
    }
    
    public int getInteger(){
        return n;
    }
    
    public void setInteger(int n){
        this.n = n;
    }
    
}
public class WeiHaoOng_T03_Lab_5 {

    /**
     * @param args the command line arguments
     */
    private static Random rand;
    private static Scanner input;
    
    public static void getTwoIntegers(MyInteger m, MyInteger n){
        n.setInteger(rand.nextInt(10));
        m.setInteger(rand.nextInt(10));
              
    }
    
    public static char getOperator(){
        String operatorString = "+-*";
        
        char ch = operatorString.charAt((rand.nextInt(3)));
        return ch;
    }
    public static boolean checkAnswer(int x, int y, char oper, int answer){
        MyInteger MI = new MyInteger();
        oper = getOperator();
        answer = MI.getInteger();
        MyInteger m = new MyInteger();
        MyInteger n = new MyInteger();
        getTwoIntegers(m,n);      
        return true;
    }
    public static void main(String[] args) {
        // TODO code application logic here.
        
       System.out.println("Welcome to CSIT111 Arithmetic World");
       System.out.println("You will solve 5 difficult arithmetic\n");
       System.out.println(getOperator());
     /*  MyInteger MI = new MyInteger();
       
       for(int i=1; i<=5; i++){
           //System.out.printf("Question %d: %d %d = ?%n", i,);
           System.out.println("Your answer: ");
           int ans = input.nextInt();
           MI.setInteger(ans);
           
           
       }
        */
    }
    
}
