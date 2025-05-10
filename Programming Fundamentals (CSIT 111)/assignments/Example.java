public class Example {
  private static double getMark() {
    return Math.random() * 100.0;
  }
  
  private static getTwoMarks(TwoMarks t) {
    
  }
  
  public static void main(String [] args) {
    TwoMarks t = new TwoMarks();
    t.getTwoMarks();
    
  }
}

enum UowGrade {HD, D, C, P, F};

class TwoMarks {
  private double mark1;
  private double mark2;
  
  //accessor method
  public double mark1() {
    return mark1;
  }
  public double mark2() {
    return mark2;
  }
}
class Student {
  private int id;
  private double assessment;
  private double exaMmark;
  private int finalMark;
  private UowGrade g;
  
  //default constructor
  public Student() {
    ++Number;
    id = Number;
  }
  
  //other constructor
  public Student(double assessment, double examMark) {
    this();
    this.assessment = assessment;
    this.examMark = examMark;
    
  }
  
  //copy constructor
  public Student(Student st) {
    this(st.assessment, st.examMark, st.id, st.finalMark);
  }
  
  //assessor method
  public getId() {
    return id;
  }
  
  public double getAssessment() {
    return assessment;
  }
  
  public double getExamMark() {
    return examMark;
  }
  
  public int getFinalMark() {
    return finalMark;
  }
  
  //mutator method
  public void setInfo(double assessment, double examMark) {
    this.assessment = assessment;
    this.examMark = examMark;
    computeFinal();
    computeGrade();
  }
  
  //private method
  private void computeFinal() {
    double average = (assessment + examMark)/2;
    finalMark = (int) (average+0.5);
  }
  private void computeGrade() {
    if (finalMark >= 85) {
      g = UowGrade.HD;
    }
    else if (finalMark >= 75) {
      g = UowGrade.D;
    }
    else if (finalMark >= 65) {
      g = UowGrade.C;
    }
    else if (finalMark >= 50) {
      g = UowGrade.P;
    }
    else {
      g = UowGrade.F;
    }
  }
  
  private void encouragement() {
    switch (g) {
      case HD: System.out.println();
    }
  }
  
  //display
  public void displayInfo() {
    System.out.printf("Student ID: %d%n", id);
    System.out.printf("Assessment Mark: %.1f%n",assessment);
    System.out.printf("Exam Mark: %.1f", examMark);
    System.out.printf("Final Mark: %d%n", finalMark);
  }
}