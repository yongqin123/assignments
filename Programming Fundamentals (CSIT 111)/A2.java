

  


class Date {
  private int day;
  private Month month;
  private int year;
  
  public Date() {}
  
  public Date(int day, Month month, int year) {
    this.day = day;
    this.month = month;
    this.year = year;
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
  public void setDate(int day, Month month, int year) {
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
  
  public HeartRates() {}
  
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
    return this.firstName;
  }
  
  public void setFirstName(String firstName) {
    this.firstName = firstName;
  }
  
  public String getlastName() {
    return this.lastName;
  }
  
  public void setLastName(String lastName) {
    this.lastName = lastName;
  }
  
  //public String 
}

enum Month {Jan,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec}

public class A2 {
  
  
  public static void main(String[] args) { 
    System.out.println("asd");
  }
  
}