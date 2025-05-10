/*
Name: Toh Yong Qin
Class: T05
Student No.: 7059073
Objective: Lab3
Declaration: I can confirm my work is done by me and no plagurisation
File: yongqintoh_Lab_3.java
*/

import java.util.Scanner;

public class yongqintoh_Lab_3 {
  public static void main(String[] args) { 
    
    // initialise object from scanner class
    Scanner sc = new Scanner(System.in);
    
    // Interaction for inputs
    System.out.printf("%s","Enter the station: ");
    String s = sc.nextLine();
    System.out.printf("%s","Enter the quantity in liter: ");
    Double q = sc.nextDouble();
    System.out.printf("%s","Enter the type of petrol: ");
    sc.nextLine();
    String t = sc.nextLine();
    System.out.printf("%s","Enter the price of petrol: ");
    Double p = sc.nextDouble();
    System.out.printf("%s","Enter discount: ");
    int d = sc.nextInt();
    
    // Initialisation of instance object from PetrolPurchase class
    PetrolPurchase pp1 = new PetrolPurchase(s, q, t, p, d);
    
    // getPayment() returns the final amount to be paid
    pp1.getPayment();
    
    // prints the summary
    System.out.printf("%s%n","Summary of your purchase");
    pp1.printinfo();
    
    // input for more petrol and prints the updated summary 
    System.out.printf("%n%s", "Enter additional quantity of petrol: ");
    Double additional_quantity = sc.nextDouble();
    pp1.setQuantity(pp1.getQuantity() + additional_quantity); 
    pp1.getPayment();
    System.out.printf("%n%s%n", "Your new purchased price");
    pp1.printinfo();
    
    // initialise a new object pp2 as a copy and prints the summary again
    PetrolPurchase pp2 = new PetrolPurchase(pp1);
    System.out.printf("%n%n%s%n","Duplicate the same object");
    pp2.printinfo();
  }
}
class PetrolPurchase {
  private String station;
  private Double quantity;
  private String type;
  private Double price;
  private int discount;
  
  public PetrolPurchase() {}
  
  // constructor
  public PetrolPurchase(String s, Double q, String t, Double p, Integer d) { 
    station = s;
    quantity = q;
    type = t;
    price = p;
    discount = d;
  }
  
  // copy constructor
  public PetrolPurchase(PetrolPurchase pp) {
    this(pp.station, pp.quantity, pp.type, pp.price, pp.discount);
  }
  
  public String getStation() {
    return station;
  }
  public Double getPrice() {
    return price;
  }
  public Double getQuantity() {
    return quantity;
  }
  public Integer getDiscount() {
    return discount;
  }
  public void setStation(String station) {
    this.station = station;
  }
  public void setType(String type) {
    this.type = type;
  }
  public void setPrice(double price) {
    this.price = price;
  }
  public void setQuantity(double quantity) {
    this.quantity = quantity;
  }
  private void setInfo(String s, double q, String t, double p, int d) {
    this.station = station;
    this.type = type;
    this.price = price;
    this.quantity = quantity;
  }
  private double computePayment() {
    return this.price * this.quantity * 0.85;
  }
  
  public double getPayment() {
    return this.computePayment();
  }
  
  public void printinfo() {
    Double actual_cost = this.quantity * this.price;
    System.out.printf("Station: %s%nTotal liter: %.2f%nPetrol Type: %s%nPrice per liter: %.2f%nActual Cost: %.2f%nDiscount (%d%%): %.2f%nAmount to pay: %.2f%n",this.station,this.quantity,this.type,this.price,actual_cost,this.discount,actual_cost * this.discount / 100, this.getPayment());
    
  }
  
  
}



