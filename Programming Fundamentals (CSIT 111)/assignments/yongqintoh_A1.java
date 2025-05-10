// Full Name: Yong Qin Toh
// Full-time
// Tutorial Group: t05
// Declaration: I declare that it is my work and I have not pass the program on to anybody.
// file: yongqintoh_A1

import java.util.Scanner;
//import java.util.Arrays;

public class yongqintoh_A1 {
 public static void main(String[] args) {
   
  //Task 1
  final String LINES = "-----------------------------------";
  Scanner sc = new Scanner(System.in);
  System.out.println("Welcome to iPhones online services");
  System.out.println(LINES);
  System.out.println("Enter three IPhones to be sold");
  System.out.print(" 1.");
  String iphone_name_1 = sc.nextLine();

  System.out.print(" 2.");
  String iphone_name_2 = sc.nextLine();

  System.out.print(" 3.");
  String iphone_name_3 = sc.nextLine();
  
  //Task 2
  System.out.printf("Enter the quantities and the costs for %s",iphone_name_1);
  Integer quantity_1 = sc.nextInt();
  Double cost_1 = sc.nextDouble();
  System.out.printf("Enter the quantities and the costs for %s",iphone_name_2);
  Integer quantity_2 = sc.nextInt();
  Double cost_2 = sc.nextDouble();
  System.out.printf("Enter the quantities and the costs for %s",iphone_name_3);
  Integer quantity_3 = sc.nextInt();
  Double cost_3 = sc.nextDouble();
  
  System.out.println("Summary of iPhones");
  System.out.println("------------------");
  System.out.println("");
  System.out.println("iPhone                    Quantity        Price    ");
  System.out.println("--------------------------------------------------");
  System.out.printf("%s                %d            %.2f      %n",iphone_name_1,quantity_1,cost_1);
  System.out.printf("%s                 %d            %.2f      %n",iphone_name_2,quantity_2,cost_2);
  System.out.printf("%s                 %d            %.2f      %n",iphone_name_3,quantity_3,cost_3);
  
  //Task 3
  System.out.println("\n//Task3");
  
  
  String temp_name1 = iphone_name_1;
  String temp_name2 = iphone_name_2;
  
  iphone_name_2 = temp_name1;
  iphone_name_1 = temp_name2;
  
  Integer temp_quantity1 = quantity_1;
  Double temp_cost1 = cost_1;
  
  Integer temp_quantity2 = quantity_2;
  Double temp_cost2 = cost_2;
  
  quantity_1 = temp_quantity2;
  cost_1 = temp_cost2;
  
  quantity_2 = temp_quantity1;
  cost_2 = temp_cost1;
  
  System.out.println("Summary of iPhones after the swaps");
  System.out.println("----------------------------------");
  System.out.println("");
  System.out.println("iPhone                    Quantity        Price    ");
  System.out.println("--------------------------------------------------");
  System.out.printf("%s                %d              %.2f      %n",iphone_name_1,quantity_1,cost_1);
  System.out.printf("%s                  %d           %.2f      %n",iphone_name_2,quantity_2,cost_2);
  System.out.printf("%s                  %d            %.2f      %n",iphone_name_3,quantity_3,cost_3);
  
  //Task4
  System.out.println("//Task4");
  System.out.println("----------------------------------------");
  System.out.println("Please place your order");
  System.out.println("------------------------");
  System.out.printf("No of %s",iphone_name_1);
  Integer order_1 = sc.nextInt();
  System.out.printf("No of %s",iphone_name_2);
  Integer order_2 = sc.nextInt();  
  System.out.printf("No of %s",iphone_name_3);
  Integer order_3 = sc.nextInt();
  
  Double tot_cost_1 = order_1 * cost_1;
  Double tot_cost_2 = order_2 * cost_2;
  Double tot_cost_3 = order_3 * cost_3;
  Double sub_total = tot_cost_1 + tot_cost_2 + tot_cost_3;
  Double gst = sub_total * 0.07;
  Double total_cost = sub_total + gst;
  
  System.out.println("----------------------");
  System.out.println("Summary of your order");
  System.out.println("----------------------");
  System.out.println("iPhone                    Quantity        Cost    ");
  System.out.println("--------------------------------------------------");
  System.out.printf("%s                %d              %.2f      %n",iphone_name_1,quantity_1,tot_cost_1);
  System.out.printf("%s               %d              %.2f      %n",iphone_name_2,quantity_2,tot_cost_2);
  System.out.printf("%s                %d              %.2f      %n",iphone_name_3,quantity_3,tot_cost_3);
  System.out.println("--------------------------------------------------");
  System.out.printf("Subtotal:                                    %.2f%n",sub_total);
  System.out.printf("GST (7%%):                                    %.2f%n", gst);
  System.out.printf("Total cost:                                  %.2f%n",total_cost);
  System.out.printf("--------------------------------------------------%n");
  
  //Task 5
  System.out.println("//Task 5");
  System.out.println("Balance report");
  System.out.println("----------------------");
  System.out.println("");
  System.out.println("iPhone                    Quantity        Sold         Balance");
  System.out.println("---------------------------------------------------------------");
  System.out.printf("%s                %d              %d            %d %n",iphone_name_1,quantity_1,order_1,quantity_1 - order_1);
  System.out.printf("%s               %d              %d             %d %n",iphone_name_2,quantity_2,order_2,quantity_2 - order_2);
  System.out.printf("%s                %d              %d            %d %n",iphone_name_3,quantity_3,order_3,quantity_3 - order_3);
  System.out.println("---------------------------------------------------------------");
  
 }
}