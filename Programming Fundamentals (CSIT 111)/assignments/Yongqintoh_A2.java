// Full Name: Yong Qin Toh
// Full Time
// Tutorial Group: T05
// Declaration: It is my own work I have not
// passed my program to my friends

import java.util.Scanner;
import java.io.IOException;
import java.io.File;



public class Yongqintoh_A2 {
  private static Scanner sc;
  
  public static void main(String[] args) throws IOException { 
    sc = new Scanner(new File("textdocument.txt"));
    
    //1st patient
    String firstName1 = sc.nextLine();
    String lastName1 = sc.nextLine();
    Integer day1 = sc.nextInt();
    
    Month month1 = Month.valueOf(sc.next());
    Integer year1 = sc.nextInt();
    
    Integer currentYear1 = sc.nextInt();
    sc.nextLine();
    
    HeartRates h1 = new HeartRates(firstName1, lastName1, new Date(day1, month1, year1), currentYear1);
    h1.printInfo();
    
    System.out.println("----------------------------------------------------------");
    //2nd patient
    String firstName2 = sc.nextLine();
    String lastName2 = sc.nextLine();
    Integer day2 = sc.nextInt();
    
    Month month2 = Month.valueOf(sc.next());
    Integer year2 = sc.nextInt();
    
    Integer currentYear2 = sc.nextInt();
    
    
    HeartRates h2 = new HeartRates(firstName2, lastName2, new Date(day2, month2, year2), currentYear2);
    h2.printInfo();
  }
}  

enum Month {Jan,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec}

class Date {
 
    private int day = 1;
    private Month month = Month.Jan;
    private int year = 2021;
    
    public Date() {}
    
    public Date(int day, Month month, int year) {
      this.day = day;
      this.month = month;
      this.year = year;
    }
    
    public Date(Date d) {
      this(d.day,d.month,d.year);
    }
    
    public int getDay() {
      return day;
    }
    
    public Month getMonth() {
      return month;
    }
    
    public int getYear() {
      return year;
    }
    
    public void setDate(int day, Month month, int  year) {
      this.day = day;
      this.month = month;
      this.year = year;
    }
    
    
}

class HeartRates {
  private String firstName;
  private String lastName;
  private Date dob;
  private int currentYear;
  
  public HeartRates(String firstName, String lastName, Date dob, int currentYear) {
      this.firstName = firstName;
      this.lastName = lastName;
      this.dob = dob;
      this.currentYear = currentYear;
  }
  
  public HeartRates(HeartRates hr) {
      this(hr.firstName, hr.lastName, hr.dob, hr.currentYear);
  }
  
  public String getFirstName() {
      return firstName;
  }
  
  public void setFirstName(String firstName) {
      this.firstName = firstName;
  }
  
  public String getLastName() {
      return lastName;
  }
  
  public void setLastName(String lastName) {
      this.lastName = lastName;
  }
  
  public Date getDOB() {
      return dob;
  }
  
  public void setDOB(Date dob) {
      this.dob = dob;
  }
  
  public int getCurrentYear() {
      return currentYear;
  }
  
  public void setCurrentYear(int currentYear) {
      this.currentYear = currentYear;
  }
  
  public int getAge() {
      return this.getCurrentYear() - dob.getYear();
  }
  
  public int getMaximumHeartRate() {
      return 220 - this.getAge();
  }
  
  public double getMinimumTargetHeartRate() {
      return this.getMaximumHeartRate() / 2.0;
  }
  
  public double getMaximumTargetHeartRate() {
      return this.getMaximumHeartRate() * 0.85;
  }
  
  public void printInfo() {
      System.out.printf("Name: %s, %s%n", this.getFirstName(), this.getLastName());
      System.out.printf("Date of birth: %d %s %d%n", (this.dob).getDay(),String.valueOf(((this.dob).getMonth())),(this.dob).getYear());
      System.out.printf("Current year: %d%n", this.getCurrentYear());
      System.out.printf("Your age: %d years old%n", this.getAge());
      System.out.println("Clinic analysis, base on your age:");
      System.out.printf("        %s%d%n","1. Your maximum heart rate is ",this.getMaximumHeartRate());
      System.out.printf("        %s%.2f%n","2. Your minimum target heart rate is ",this.getMinimumTargetHeartRate());
      System.out.printf("        %s%.2f%n","3. Your maximum target heart rate is ",this.getMaximumTargetHeartRate());
  }
}
  
  

