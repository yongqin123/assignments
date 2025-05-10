import java.util.Scanner;

/**
 * Auto Generated Java Class.
 */
public class yongqintoh_Lab_2 {
  
  
  public static void main(String[] args) { 
    System.out.print("Enter 4 digits integer to be encrypted: ");
    Scanner sc = new Scanner(System.in);
    Integer my_input = sc.nextInt();
    int a = (my_input / 1000 + 7) % 10  ;
    int b = (my_input % 1000 / 100 +7) % 10;
    int c = (my_input % 100 / 10 +7) % 10;
    int d = (my_input % 10 + 7) % 10;
    String astr = Integer.toString(a);
    String bstr = Integer.toString(b);
    String cstr = Integer.toString(c);
    String dstr = Integer.toString(d);
    System.out.println("Encrypted integer is "+ cstr + dstr + astr + bstr);
    
    System.out.print("Enter 4 digits integer to be decrypted: ");
    Scanner sc2 = new Scanner(System.in);
    Integer my_input2 = sc2.nextInt();
    int a2 = (my_input2 / 1000 + 3) % 10 ;
    int b2 = (my_input2 % 1000 / 100 +3) % 10;
    int c2 = (my_input2 % 100 / 10 +3) % 10;
    int d2 = (my_input2 % 10 + 3) % 10;
    String astr2 = Integer.toString(a2);
    String bstr2 = Integer.toString(b2);
    String cstr2 = Integer.toString(c2);
    String dstr2 = Integer.toString(d2);
    System.out.println("Decrypted integer is " + cstr2 + dstr2 + astr2 + bstr2);
  
  }
}
