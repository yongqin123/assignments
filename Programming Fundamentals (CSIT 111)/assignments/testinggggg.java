import java.util.Scanner;
//import java.util.Arrays;

public class testinggggg {
 public static void main(String[] args) {
  Scanner sc = new Scanner(System.in);
  
  System.out.println("Enter three IPhones to be sold");
  System.out.print(" 1.");
  String a = sc.nextLine();

  System.out.print(" 2.");
  String b = sc.nextLine();

  System.out.print(" 3.");
  String c = sc.nextLine();
  
  System.out.printf("Enter the quantities and the costs for '%s'",a);
  Integer d = sc.nextInt();
  Double e = sc.nextDouble();
  System.out.printf("Enter the quantities and the costs for '%s'",b);
  Integer f = sc.nextInt();
  Double g = sc.nextDouble();
  System.out.printf("Enter the quantities and the costs for '%s'",c);
  Integer h = sc.nextInt();
  Double i = sc.nextDouble();
  
  System.out.println("Summary of iPhones");
  System.out.println("------------------");
  System.out.println("");
  System.out.println("iPhone                    Quantity        Price    ");
  System.out.println("--------------------------------------------------");
  System.out.printf("%s                %d            %.2f      %n",a,d,e);
  System.out.printf("%s                 %d            %.2f      %n",b,f,g);
  System.out.printf("%s                 %d            %.2f      %n",c,h,i);
  
  Object[] number_1 = new Object[] {a,d,e};
  Object[] number_2 = new Object[] {b,f,g};
  Object[] number_3 = new Object[] {c,h,i};
  
  //number_1 = 
  //Taks 3
  System.out.println("\n//Task3");
  System.out.println("Select what to swap type in : ");
  System.out.printf(" %s", a);
  System.out.printf(" %s", b);
  System.out.printf(" %s", c);
  System.out.print(" 1.");
  sc.nextLine();
  String which_to_swap1 = sc.nextLine();
  
  System.out.print(" 2.");
  String which_to_swap2 = sc.nextLine();
  
  System.out.println(number_1[0]);
  System.out.println(which_to_swap1);
  System.out.println(which_to_swap2);
  System.out.println(which_to_swap1 == number_1[0]);
  System.out.println(number_1[0].getClass().getName());
  System.out.println(which_to_swap1.getClass().getName());
  if (which_to_swap1.equals(number_1[0])) {
      Object[] swap1 = number_1;
      
      if (which_to_swap2.equals(number_2[0])) {
          Object[] swap2 = number_2;
          number_1 = swap2;
          number_2 = swap1;
          System.out.println("d");
      }
      if (which_to_swap2.equals(number_3[0])) {
          Object[] swap2 = number_3;
          number_1 = swap2;
          number_3 = swap1;
      }
  }
  
  if (which_to_swap1.equals(number_2[0])) {
      Object[] swap1 = number_2;
      if (which_to_swap2 == number_1[0]) {
          Object[] swap2 = number_1;
          number_2 = swap2;
          number_1 = swap1;
      }
      if (which_to_swap2.equals(number_3[0])) {
          Object[] swap2 = number_3;
          number_2 = swap2;
          number_3 = swap1;
      }
  }
  if (which_to_swap1.equals(number_3[0])) {
      Object[] swap1 = number_3;
      if (which_to_swap2.equals(number_1[0])) {
          Object[] swap2 = number_1;
          number_3 = swap2;
          number_1 = swap1;
      }
      if (which_to_swap2.equals(number_2[0])) {
          Object[] swap2 = number_2;
          number_3 = swap2;
          number_2 = swap1;
      }
  }
  /////////////////////////////////////
  
  
  System.out.println("Summary of iPhones after the swaps");
  System.out.println("----------------------------------");
  System.out.println("");
  System.out.println("iPhone                    Quantity        Price    ");
  System.out.println("--------------------------------------------------");
  System.out.printf("%s                %d              %.2f      %n",number_1[0],number_1[1],number_1[2]);
  System.out.printf("%s                  %d              %.2f      %n",number_2[0],number_2[1],number_2[2]);
  System.out.printf("%s                  %d              %.2f      %n",number_3[0],number_3[1],number_3[2]);
  
  //Task4
  System.out.println("//Task4");
  System.out.println("----------------------------------------");
  System.out.println("Please place your order");
  System.out.println("------------------------");
  System.out.printf("No of %s",number_1[0]);
  Integer j = sc.nextInt();
  System.out.printf("No of %s",number_2[0]);
  Integer k = sc.nextInt();  
  System.out.printf("No of %s",number_3[0]);
  Integer l = sc.nextInt();
  
  System.out.println(number_1[2].getClass().getName());
 }
}