// Assume that we have a record inside a text file ("studentfile.txt")

java.util.Scanner;
java.util.IOException;
java.util.File;

/* 
class UOW {
 
  private Student s;
  private Program p;
  
  public UOW() {
    s = new Student();
  }
  
  public UOW(Student s, Program p) {
    this.s = s;
    this.p = p;
  }
  
  public UOW(UOW u) {
    this.s = u.s;
    this.p = u.p;
  }
  
  
}*/

public class TestUow_1 {
  private static Scanner input;
  
  public static void main(String[] args) throws IOException {  
    Student s0 = new Student("John", 'M');
    Student s1 = new Student("Tom", 'F');
    Student s2 = new Student("asd", 'M');
    Student s3 = new Student("qeqw", 'F');
    s0.displayInfo();
    
    input = new Scanner(new File("studentfile.txt"));
    String name = input.nextLine();
    char gender = input.next().charAt(0);
    Program p = Program.valueOf(input.next());
    
    
  }
}

class Student {
  private static int NUMBER = 20210000;
  private String name;
  private int id;
  private char gender;
  
  //Default constuctor
  public Student() {
    ++NUMBER;
    id = NUMBER;
  }
  
  public Student(String name,char gender) {
    ++NUMBER;
    id = NUMBER;
    this.name = name;
    this.gender = gender;
  }
  
  public Student(Student s) {
    ++NUMBER;
    id = NUMBER;
    this.name = name;
    this.gender = gender;
  } 
  
  public String getName() {
    return name;
  }
  
  public int getID() {
    return id;
  }
  
  public char getGender() {
    return gender;
  }
  
  public void setInfo(String name, char gender) {
    this.name = name;
    this.gender = gender;
  }
  
  public void displayInfo() {
    System.out.printf("Student name: %s%n", name);
    System.out.printf("Student ID: %d%n",id);
    System.out.printf("Gender: %s%n",gender);
    System.out.println();
  }
}
