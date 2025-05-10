
import java.util.Random;


public class Yongqintoh_TestQ5 {

  Random rand = new Random();
  
  private PetType getPet() {
    
    int pick = rand.nextInt(PetType.values().length);
    return PetType.values()[pick];
  }
  
  private double getCost() {
    return rand.nextDouble() + 100.0;
  }
  
  private void get3pets(Pet p1, Pet p2, Pet p3) {
    p1.setInfo(getPet(),getCost());
    p2.setInfo(getPet(),getCost());
    p3.setInfo(getPet(),getCost());
  }
  
  public static void main(String[] args) { 
    Pet p1 = new Pet();
    Pet p2 = new Pet();
    Pet p3 = new Pet();
    get3pets(p1,p2,p3);
    p1.displayInfo();
    p2.displayInfo();
    p3.displayInfo();
  }
}  
  enum PetType {Dog, Cat, Mouse, Duck, Cow}
  
  class Pet {
    private PetType pt;
    private double cost;
    
    public Pet() {}
    
    public Pet(PetType pt, double cost) {
      this.pt = pt;
      this.cost = cost;
    }
    
    public Pet(Pet p) {
      this(p.pt, p.cost);
    }
    
    public PetType getPet() {
      return pt;
    }
    
    public void setInfo(PetType pt, double cost) {
      this.pt = pt;
      this.cost = cost;
    }
    
    private double totalCost() {
      return cost*1.07;
    }
    
    public void displayInfo() {
      System.out.printf("Pet: %s%n", pt);
      System.out.printf("Cost (subtotal): %f%n", cost);
      System.out.printf("GST (7%%): %f%n",cost *0.07);
      System.out.printf("Total Cost:%f%n", this.totalCost());
    }
  }
  

