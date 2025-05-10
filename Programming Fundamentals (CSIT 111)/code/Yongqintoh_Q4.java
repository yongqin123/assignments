/**
 * Auto Generated Java Class.
 */
public class Yongqintoh_Q4 {
  
  
  public static void main(String[] args) { 
    FourSides fs1 = new FourSides(1,1,1,1);
    FourSides fs2 = new FourSides(8,8,8,8);
    FourSides fs3 = new FourSides(8,9,8,9);
    FourSides fs4 = new FourSides(5,6,7,8);
    FourSides fs5 = new FourSides(3,-1,0,7);
    fs1.displayInfo();
    System.out.println("-----------------------------");
    fs2.displayInfo();
    System.out.println("-----------------------------");
    fs3.displayInfo();
    System.out.println("-----------------------------");
    fs4.displayInfo();
    System.out.println("-----------------------------");
    fs5.displayInfo();
  }
}
  class FourSides {
    private final String SQR = "Square";
    private final String REC = "Rectangle";
    private final String QUA = "Quadrilateral";
    private final String NIL = "No shape";
    private int a;
    private int b;
    private int c;
    private int d;
    private String pt;
    
    public FourSides() {
      
    }
    
    public FourSides(int a, int b, int c, int d) {
      this.a = a;
      this.b = b;
      this.c = c;
      this.d = d;
    }
    
    private String getType() {
      if (a > 0 && b > 0 && c > 0 && d> 0) {
        if (a == b && b == c && c == d) {
          return SQR;
        }
        if (a == (b || c || d) || b
        if (a != b && b != c && c!= d) {
          return QUA;
        }
        else {
          return REC;
        }
      }
      else {
        return NIL;
      }
    }
    public void displayInfo() {
      switch (this.getType()) {
        case "Square":
          System.out.println("It is a square\nIt is a rectanagle\nIt is a quadrilateral");
          break;
        case "Rectangle":
          System.out.println("It is a rectanagle\nIt is a quadrilateral");
          break;
        case "Quadrilateral":
          System.out.println("It is a quadrilateral");
          break;
        case "No shape":
          System.out.println("It is not a valid quadrilateral");
          break;
      }
      
    }
    
  
  }


