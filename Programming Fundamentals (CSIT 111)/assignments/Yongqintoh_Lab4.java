/*
Name: Yong Qin Toh
class: T05
declaration: I hereby declare that this is my work and no plagurisation
purpose: for lab4
file: Yongqintoh_Lab4.java
*/
import java.util.Scanner;

enum Type {Equilateral, Isosceles, Scalene, NotTriangle}

class PossibleTriangle {
  private int a;
  private int b;
  private int c;
  private Type pt;
  
  public PossibleTriangle(int a, int b, int c) {
    this.a = a;
    this.b = b;
    this.c = c;
  }
  
  private boolean isTriangle() {
    if ((a > 0) && (b > 0) && (c > 0)) {
      if (((a + b) > c) && ((a+c) > b) && (b+c) > a) {
        return true;
      }
      else {
        this.pt = Type.NotTriangle;
        return false;
      }
    }
    else {
      this.pt = Type.NotTriangle;
      return false;
    }
  }
  
  private Type getType() {
    if (a == b || a == c || b == c) {
      if (a == b && b == c && a == c) {
        return Type.Equilateral;
      }
      return Type.Isosceles;
    }
   
    return Type.Scalene;
    
    
  }
  
  public void displayInfo() {
    System.out.printf("a = %d, b = %d, c= %d%n",this.a,this.b,this.c);
    
    if (this.isTriangle() == false) {
      System.out.println("Not a triangle");
    }
    else {
      switch (this.getType()) {
        case Equilateral: 
          System.out.println("Equilateral triangle");
          System.out.println("Isosceles triangle");
          System.out.println("A triangle");
          break;
        case Isosceles:
          System.out.println("Isosceles triangle");
          System.out.println("A triangle");
          break;
        default:
          System.out.println("Scalene triangle");
          System.out.println("A triangle");
          break;
      }
    }
  }
}



public class Yongqintoh_Lab4 {
  
  
  public static void main(String[] args) { 
    /*
    Scanner sc = new Scanner(System.in);
    System.out.println("Input 3 sides of a triangle:");
    Integer a = sc.nextInt();
    Integer b = sc.nextInt();
    Integer c = sc.nextInt();
    sc.nextLine();
    */
    Integer a1 = 4;
    Integer b1 = 5;
    Integer c1 = 6;
    PossibleTriangle p1 = new PossibleTriangle(a1,b1,c1);
    p1.displayInfo();
    System.out.println("------------------------------------");
    Integer a2 = 1;
    Integer b2 = 2;
    Integer c2 = 3;
    PossibleTriangle p2 = new PossibleTriangle(a2,b2,c2);
    p2.displayInfo();
    System.out.println("------------------------------------");
    Integer a3 = 4;
    Integer b3 = 5;
    Integer c3 = 5;
    PossibleTriangle p3 = new PossibleTriangle(a3,b3,c3);
    p3.displayInfo();
    System.out.println("------------------------------------");
    Integer a4 = 6;
    Integer b4 = 6;
    Integer c4 = 6;
    PossibleTriangle p4 = new PossibleTriangle(a4,b4,c4);
    p4.displayInfo();
    
  }
  
  /* ADD YOUR CODE HERE */
  
}
