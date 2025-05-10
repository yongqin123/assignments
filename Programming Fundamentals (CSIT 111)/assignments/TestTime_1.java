/**
 * Auto Generated Java Class.
 */
public class TestTime_1 { 
  public static void main(String[] args) {
    Time t0 = new Time(11,12,13);
    Time t1 = new Time(15,16,10);
    Time t2 = new Time(20,12,00);
    Time t3 = new Time(15,00,13);
    System.out.println("t0. ");
    t0.displayTime();
    System.out.println("t1. ");
    t1.displayTime();
    System.out.println("t2. ");
    t2.displayTime();
    System.out.println("t3. ");
    t3.displayTime();
    
    System.out.println("");
    
    System.out.println("Explore the use of copied constructor");
    
    Time t4 = new Time(t3);
    
    System.out.println("What happen if we assigned an object to another object?");
    
    Time t5 = new Time(t4);
    
    //assigning a copy to constructor will affect the parameters of the object 
    //that is being copied.
  }
 }


class Time {
    private int hours;
    private int minutes;
    private int seconds;
    
    // constructor
    public Time() {
      this(0,0,0);
    }
    
    public Time(int hours, int minutes, int seconds) {
      /*
      this.hours = hours;
      this.minutes = minutes;
      this.seconds = seconds;
      */
      this.setInfo(hours,minutes,seconds);
    }
    public Time(Time t) {
      /*
      this.hours = t.hours;
      this.minutes = t.minutes;
      this.seconds = t.seconds;
      */
      this(t.hours,t.minutes,t.seconds);
    }
    public int getHours() {
      return hours;
    }
    public int getMinutes() {
      return minutes;
    }
    public int getSeconds() {
      return seconds;
    }
    public void setHours(int hours) {
      this.hours = hours;
    }
    public void setMinutes(int minutes) {
      this.minutes = minutes;
    }
    public void setSeconds(int seconds) {
      this.seconds = seconds;
    }
    public void displayTime() {
      System.out.printf("Current Time is %d:%d:%d", this.hours,this.minutes,this.seconds);
    }
    public void increment() {
      ++seconds;
      int temp = seconds / 60;
      //seconds = seconds 
    }
    private void setInfo(int hours, int minutes, int seconds) {
      
      this.hours = hours;
      this.minutes = minutes;
      this.seconds = seconds;
    }
}  



