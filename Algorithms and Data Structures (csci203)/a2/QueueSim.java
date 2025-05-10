import java.util.*;
import java.io.File;  // Import the File class
import java.io.FileNotFoundException;  // Import this class to handle errors
import java.util.Scanner; // Import the Scanner class to read text files
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.ArrayList;
import java.util.stream.Stream;
import java.util.Calendar;
import java.util.Date;

class Customer {
    private Integer minute_primary = 0;
    private Integer minute_secondary = 0;

    private Integer arrival;

    private Integer arrivePrimary;

    private Integer arriveSecondary;
    private static Integer number = 0;
    private Integer numBer;
    public Customer() {}

    public Customer(Integer arrival, Integer arrivePrimary, Integer arriveSecondary) {
        this.arrival = arrival;
        this.arrivePrimary = arrivePrimary;
        this.arriveSecondary = arriveSecondary;
        numBer = number;
        number++;
    }

    public Integer getArrival() {
        return arrival;
    }

    public void setArrival(Integer arrival) {
        this.arrival = arrival;
    }

    public Integer getArrivePrimary() {
        return arrivePrimary;
    }

    public void setArrivePrimary(Integer arrivePrimary) {
        this.arrivePrimary = arrivePrimary;
    }

    public Integer getMinute_primary() {
        return minute_primary;
    }

    public void setMinute_primary(Integer minute_primary) {
        this.minute_primary = minute_primary;
    }

    public Integer getMinute_secondary() {
        return minute_secondary;
    }

    public void setMinute_secondary(Integer minute_secondary) {
        this.minute_secondary = minute_secondary;
    }

    public Integer getArriveSecondary() {
        return arriveSecondary;
    }

    public void setArriveSecondary(Integer arriveSecondary) {
        this.arriveSecondary = arriveSecondary;
    }

    @Override
    public String toString() {
        return "" + "Arrival: "+arrival+" Minute Primary: "+minute_primary+" Minute Secondary: "+minute_secondary;
    }
}

class Server {
    private String server_name;
    private Integer idle_time = 0;
    private Boolean status = true;
    private Integer remaining_server_time;
    private Customer currentCustomer = new Customer();

    public Server(String server_name, Boolean status) {
        this.server_name = server_name;
        this.status = status;
    }

    public String getServer_name() {
        return server_name;
    }

    public void setServer_name(String server_name) {
        this.server_name = server_name;
    }

    public Integer getIdle_time() {
        return idle_time;
    }

    public void incrementIdleTime() {
        this.idle_time += 1;
    }

    public boolean getStatus() {
        return status;
    }

    public void setStatus(Boolean status) {
        this.status = status;
    }

    public Integer getRemaining_server_time() {
        return remaining_server_time;
    }

    public void setRemaining_server_time(Integer remaining_server_time) {
        this.remaining_server_time = remaining_server_time;
    }

    public Customer getCurrentCustomer() {
        return currentCustomer;
    }

    public void setCurrentCustomer(Customer currentCustomer) {
        this.currentCustomer = currentCustomer;
    }
}





class QueueSim {
    public static void main(String[] args)
    {
        Calendar cl = Calendar.getInstance(TimeZone.getDefault());
        Date date = cl.getTime();
        System.out.println("Simulation Start Time: "+date);
        try {
            String file = "A2data6.txt";
            File myObj = new File(file);
            Scanner myReader = new Scanner(myObj);
            //myReader.hasNextLine();


            int primaryServers = myReader.nextInt();
            int secondaryServers = myReader.nextInt();


            ArrayList<Customer> arr_customers = new ArrayList<Customer>();
            List<Server> arr_primaryServer = new ArrayList<Server>();
            List<Server> arr_SecServer = new ArrayList<Server>();

            for (int i = 0; i < primaryServers; i++) {
                arr_primaryServer.add(new Server("Primary Server "+(i+1),true));
            }

            for (int i = 0; i < secondaryServers; i++) {
                arr_SecServer.add(new Server("Secondary Server "+(i+1),true));
            }


            Queue<Customer> primary_queue = new LinkedList<>();
            Queue<Customer> secondary_queue = new LinkedList<>();

            int k = 0;
            while (myReader.hasNextLine()) {
                arr_customers.add(new Customer(myReader.nextInt(),myReader.nextInt(),myReader.nextInt()));
            }


            int indexOfcustomer = 0;
            boolean openShop = true;
            int time = 1;
            List <Boolean> ps = arr_primaryServer.stream().map(i -> i.getStatus()).collect(Collectors.toList()); // ps = primary status
            List <Boolean> ss = arr_SecServer.stream().map(i -> i.getStatus()).collect(Collectors.toList());  // ss = secondary status

            int timeWhenPrimaryFirstDataInserted = arr_customers.get(indexOfcustomer).getArrival();
            int countServicetime = 0;
            int totalPrimaryQueuetime = 0;
            int totalSecondaryQueuetime = 0;
            int maxQueueSizePri = 0;
            int maxQueueSizeSec = 0;
            int numOfcustpri = 0;
            int numOfcustsec = 0;
            int serviceTimePr = 0;
            int serviceTimerSec = 0;

            while (true) {
                ps = arr_primaryServer.stream().map(i -> i.getStatus()).collect(Collectors.toList()); // ps = [true,true,true,true,true,true]
                ss = arr_SecServer.stream().map(i -> i.getStatus()).collect(Collectors.toList());
                while (arr_customers.get(indexOfcustomer).getArrival() == time & arr_customers.get(indexOfcustomer).getArrival() != 0) {

                    ps = arr_primaryServer.stream().map(i -> i.getStatus()).collect(Collectors.toList()); // ps = primary status
                    ss = arr_SecServer.stream().map(i -> i.getStatus()).collect(Collectors.toList());  // ss = secondary status


                    if (ps.contains(true)) {
                        arr_primaryServer.get(ps.indexOf(true)).setCurrentCustomer(arr_customers.get(indexOfcustomer));

                        arr_primaryServer.get(ps.indexOf(true)).getCurrentCustomer().setMinute_primary(time + arr_primaryServer.get(ps.indexOf(true)).getCurrentCustomer().getArrivePrimary());
                        //System.out.println(arr_primaryServer.get(0).getCurrentCustomer());
                        arr_primaryServer.get(ps.indexOf(true)).setStatus(false);
                    }

                    else {
                        numOfcustpri +=1;
                        primary_queue.add(arr_customers.get(indexOfcustomer));
                    }

                    countServicetime+=arr_customers.get(indexOfcustomer).getArrivePrimary();
                    countServicetime+=arr_customers.get(indexOfcustomer).getArriveSecondary();
                    indexOfcustomer++;
                }

                while (ps.contains(true) & primary_queue.size() > 0) {
                    arr_primaryServer.get(ps.indexOf(true)).setCurrentCustomer(primary_queue.peek());

                    arr_primaryServer.get(ps.indexOf(true)).getCurrentCustomer().setMinute_primary(time + arr_primaryServer.get(ps.indexOf(true)).getCurrentCustomer().getArrivePrimary());
                    arr_primaryServer.get(ps.indexOf(true)).setStatus(false);
                    primary_queue.poll();
                }

                List <Integer> arr_minute_primary = arr_primaryServer.stream().map(i -> i.getCurrentCustomer().getMinute_primary()).collect(Collectors.toList()); // [5,15.....]

                //loop the arraylist which contains the accumumalated time in primary server that is needed to transfer out from primary to secondary server
                for (int i = 0; i < arr_minute_primary.size(); i++) {

                    if (arr_minute_primary.get(i) == time ) {

                        //check if there exist a secondary server that is free
                        if (ss.contains(true)) {
                            //set the current customer of secondary server that is to be transfered from primary to secondary server
                            arr_SecServer.get(ss.indexOf(true)).setCurrentCustomer(arr_primaryServer.get(i).getCurrentCustomer());
                            //calculate and set the accumulated time required for customer to be moved out of the secondary server

                            arr_SecServer.get(ss.indexOf(true)).getCurrentCustomer().setMinute_secondary(time + arr_SecServer.get(ss.indexOf(true)).getCurrentCustomer().getArriveSecondary());

                            //empties the current customer in the primary server
                            arr_primaryServer.get(i).setCurrentCustomer(new Customer());
                            //set secondary server as false since its occupied
                            arr_SecServer.get(ss.indexOf(true)).setStatus(false);
                            //since customer transfered out of primary server, true
                            arr_primaryServer.get(i).setStatus(true);

                        }
                        else {
                            numOfcustsec += 1;
                            
                            secondary_queue.add(arr_primaryServer.get(i).getCurrentCustomer());
                            //empties the current customer in the primary server
                            arr_primaryServer.get(i).setCurrentCustomer(new Customer());
                            arr_primaryServer.get(i).setStatus(true);

                        }
                    }

                }

                while (ss.contains(true) & secondary_queue.size() > 0) {
                    arr_SecServer.get(ss.indexOf(true)).setCurrentCustomer(secondary_queue.peek());
                    arr_SecServer.get(ss.indexOf(true)).getCurrentCustomer().setMinute_secondary(time + arr_SecServer.get(ss.indexOf(true)).getCurrentCustomer().getArriveSecondary());
                    arr_SecServer.get(ss.indexOf(true)).setStatus(false);
                    secondary_queue.poll();
                }

                ss = arr_SecServer.stream().map(i -> i.getStatus()).collect(Collectors.toList());
                ps = arr_primaryServer.stream().map(i -> i.getStatus()).collect(Collectors.toList());
                List <Integer> arr_minute_secondary = arr_SecServer.stream().map(i -> i.getCurrentCustomer().getMinute_secondary()).collect(Collectors.toList());

                for (int i = 0; i < arr_minute_secondary.size(); i++) {
                    if (arr_minute_secondary.get(i) == time) {
                        arr_SecServer.get(i).setCurrentCustomer(new Customer());
                        arr_SecServer.get(i).setStatus(true);
                    }
                }



                ss = arr_SecServer.stream().map(i -> i.getStatus()).collect(Collectors.toList());

                while (ss.contains(true) & secondary_queue.size() > 0) {
                    arr_SecServer.get(ss.indexOf(true)).setCurrentCustomer(secondary_queue.peek());
                    arr_SecServer.get(ss.indexOf(true)).getCurrentCustomer().setMinute_secondary(time + arr_SecServer.get(ss.indexOf(true)).getCurrentCustomer().getArriveSecondary());
                    arr_SecServer.get(ss.indexOf(true)).setStatus(false);
                    secondary_queue.poll();
                }

                ps = arr_primaryServer.stream().map(i -> i.getStatus()).collect(Collectors.toList());
                ss = arr_SecServer.stream().map(i -> i.getStatus()).collect(Collectors.toList());


                int numberOfTrueInPrimary = 0;
                int numberOfTrueInSecondary = 0;



                for (int i = 0; i < ps.size(); i++) {
                    if (ps.get(i) == true) {
                        numberOfTrueInPrimary += 1;
                    }
                    if (ss.get(i) == true) {
                        numberOfTrueInSecondary +=1;
                    }
                }

                if (numberOfTrueInPrimary == 6 && numberOfTrueInSecondary == 6 && time > timeWhenPrimaryFirstDataInserted) {

                    break;
                }

                if (primary_queue.size() > 0) {
                    totalPrimaryQueuetime += 1;
                }

                if (secondary_queue.size() > 0) {
                    totalSecondaryQueuetime+=1;
                }

                if (primary_queue.size() > maxQueueSizePri) {
                    maxQueueSizePri = primary_queue.size();
                }

                if (secondary_queue.size() > maxQueueSizeSec) {
                    maxQueueSizeSec = secondary_queue.size();
                }
                for (int i = 0; i < ps.size(); i++) {
                    if (ps.get(i) == true) {
                        arr_primaryServer.get(i).incrementIdleTime();
                    }
                    if (ss.get(i) == true) {
                        arr_SecServer.get(i).incrementIdleTime();
                    }
                }

                time += 1;

            }
            System.out.println(""+file + " is used for this simulation.");
            System.out.println("Start simulation using filename -> " +file);
            System.out.println("This simulation uses " + primaryServers + " primary server(s), and "+ secondaryServers + " secondary server(s).");
            System.out.println("");

            System.out.println("Total minute of simulation: "+ time);
            System.out.println("Number of people served: " + indexOfcustomer);
            System.out.println("");
            System.out.println("Total service time: "+ countServicetime);
            System.out.printf("Average total service time: %.2f minutes%n",(double)countServicetime/indexOfcustomer);
            System.out.println("");
            System.out.println("Average total time in primary server queue: "+(double)(numOfcustpri/maxQueueSizePri));
            System.out.println("Average total time in Secondary server queue: " +(double)numOfcustsec/maxQueueSizeSec);
            System.out.println("Average total time in both queue: " +(double)(numOfcustsec+numOfcustsec)/maxQueueSizeSec);
            System.out.println("");
            System.out.printf("Average length of primary queue: %.5f%n",(double)totalPrimaryQueuetime/time);
            System.out.printf("Average length of secondary queue: %.5f%n" ,(double)totalSecondaryQueuetime/time);
            System.out.printf("Average overall length of queue: %.5f%n", (double)(totalPrimaryQueuetime+totalSecondaryQueuetime)/time);
            System.out.println("");
            System.out.printf("Total primary queue size: %d%n" , numOfcustpri);
            System.out.printf("Total secondary queue size: %d%n" , numOfcustsec);
            System.out.println("");
            System.out.println("Maximum length of primary queue: " + maxQueueSizePri);
            System.out.println("Maximum length of secondary queue: "+ maxQueueSizeSec);
            System.out.println("Average maximum length of queue: "+ ((maxQueueSizeSec+maxQueueSizeSec)/2));
            System.out.println("Maximum length of overall queue: " + (maxQueueSizePri+maxQueueSizeSec));
            System.out.println("");
            System.out.println("Total idle time for each server:");
            for (int i = 0; i < arr_primaryServer.size(); i++) {
                System.out.println("Primary Server " + i + ": " + arr_primaryServer.get(i).getIdle_time() + " minutes");
            }
            System.out.println("");
            for (int i = 0; i < arr_SecServer.size(); i++) {
                System.out.println("Secondary Server " + i + ": " + arr_SecServer.get(i).getIdle_time() + " minutes");
            }
            cl = Calendar.getInstance(TimeZone.getDefault());
            date = cl.getTime();
            System.out.printf("Simulation ends after %d minute(s) or %.5f hour(s) of simulation process.%n",time,(double)(countServicetime/60));
            System.out.println("Simulation End Time: "+ date);
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
}