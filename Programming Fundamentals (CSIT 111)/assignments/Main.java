/**
 * @(#)Main.java
 *
 *
 * @author 
 * @version 1.00 2021/1/14
 */
// read the 3 sides of a triangle
// compute and to display its area and perimeter
// File name TestTriangle.java
// Specify a width fir each display. By default the compiler
// lefy justify the output, note the - after the %
// creating a table like in assignment 1
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
		//Declae constant
		final String LINE = "-----"
		
		//Declare a Scanner class object
		Scanner inputt = new Scanner(System.in);
		
		//Declare variables
		double a1,b1,c1;
		double area1, perimeter1;
		double s1; //dummy variable
		
		//Reading 
		System.out.println("Enter the 3 sides of the triangle:");
		a1 = inputt.nextDouble();
		b1 = inputt.nextDouble();
		c1 = inputt.nextDouble();
		
		//To compute the area and perimeter
		s1 = (a1 + b1 + c1)/ 2.0;
		area1 = Math.sqrt(s1 * (s1-a1)*(s1-b1)*(s1-c1));
				
		//To display result    	
		System.out.printf("Area= %.4f /n",area1);
		System.out.println("Perimeter= %.4f /n", a1+b1+c1);
		System.out.println("------------------------------------------");
		//Declare variables
		double a,b,c;
		double area, perimeter;
		double s; //dummy variable
		
		//Reading 
		System.out.println("Enter the 3 sides of the triangle:");
		a2 = inputt.nextDouble();
		b2 = inputt.nextDouble();
		c2 = inputt.nextDouble();
		
		//To compute the area and perimeter
		s2 = (a1 + b2 + c2)/ 2.0;
		area2 = Math.sqrt(s2 * (s2 - a2)*(s2 - b2)*(s2 - c2));
				
		//To display result    	
		System.out.printf("Area= %.4f /n",area2);
		System.out.println("Perimeter= %.4f /n", a2 + b2 + c2);
		
		// Design the table
		System.out.println();
		System.out.println("%10s" + "%");
    }
    
    
}