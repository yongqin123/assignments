import sqlite3
import re
#connect database
#conn = sqlite3.connect('my.db')
#Create Cursor
#c = conn.cursor()
#Query the database
#c.exucute("INSERT INTO TABLES VALUES ('11/10/2020','1200/1300',1,2)")
#c.executemany("INSERT INTO TABLES VALUES (?,?,?,?)", many_customers)
#commit command
#conn.commit()
#Close our connection
#conn.close()

def create_new_channel():
    #connect database
    conn = sqlite3.connect('my.db')
    #Create Cursor
    c = conn.cursor()
    #Query the database
    c.execute("SELECT DISTINCT channel_id FROM TABLES") #since same multiple channel_id might exist depending on no. of timeslots, distinct will ensure no repeating channelid 
    all_channels_created = c.fetchall()#will be in this format [(1),(2),(3),(4),(5)]
    # commit command
    conn.commit()
    #Close our connection
    conn.close()
    all_channels_created_list = []
    for k in range(len(all_channels_created)):#from [(1),(2),(3),(4),(5)]-->[1,2,3,4,5]
        all_channels_created_list.append(all_channels_created[k][0])
    print(all_channels_created_list)
    
    ch = int(input("\nInput Available Channel Number Shown Above (1-5):\n"))
    
    
    date = input("Date? (e.g dd/mm/yyyy)\n")
    
    #These Chunk Of Codes Below Create Many Time-Slotts/Sessions and stored
    #in a varaible called time_list
    time = input("time? (e.g 0000-1400):\n")
    start_time , end_time = time.split("-") #split them into 
    start_time_2dgt = int(int(start_time)/100) #find 1st two digits of start time
    end_time_2dgt = int(int(end_time)/100) #find 1st two digits of end time
    print(start_time, end_time)
    time_list = []
    
    
    for n in range(start_time_2dgt, end_time_2dgt,3):
        time_list.append(str(n)+":"+(start_time)[2:]+ " - " + str(n+3)+":"+(end_time)[2:])
    print(time_list) #[2:]^ means last two digits of start_time,end_time
    s = "NIL"#might wanna delete this, hmmmm
    
    #row_list is to be used to store all data created and transfer it to database
    row_list =[]
    capacity = int(input("Input Channel Capacity?\n"))
    std_id = "NIL" #this might be useful for student booking part
    is_it_booked = " " #this might be usefull too
    #connect database
    conn = sqlite3.connect('my.db')
    #Create Cursor
    c = conn.cursor()
    for n in range(len(time_list)):
        #each value stored in row ( eg date, time),  will be transfered
        #to their respective column in TABLES(database table).
        row = (date,time_list[n],ch,s,str(ch)+str(s),capacity,std_id,is_it_booked)
        row_list.append(row)

    #Query the database and insert values. Each ? represents a column of a table.
    #No. of ? must be same as no. of columns if not there will be error.
    c.executemany("INSERT INTO TABLES VALUES (?,?,?,?,?,?,?,?)", row_list)

    # commit command
    conn.commit()

    #Close our connection
    conn.close()
    
    print("Channel " + str(ch) + " created")
def edit_channel():
    #connect database
    conn = sqlite3.connect('my.db')
    #Create Cursor
    c = conn.cursor()
    #Query the database
    c.execute("SELECT channel_id FROM TABLES")
    get_channel_id = str(c.fetchall())
    x = re.sub("\D"," ",get_channel_id)
    print("Below are the available channels to edit: " + x)
    choose_channel_id=input("Please enter a channel id that you would like to edit: ")
    #Query the database
    c.execute("SELECT date, time, capacity FROM TABLES WHERE channel_id = (?)", choose_channel_id)
    all_channels_fetched = c.fetchall()
    intoString_fetched_channels = str(all_channels_fetched)

    if(intoString_fetched_channels=='[]'):
        print("That channel does not exist")
    else:
       
        print("The date, time and capacity for this channel is as follows: " + intoString_fetched_channels)
        choose_what_to_edit = input("Please enter specifically what you would like to edit, 'date', 'time', or 'capacity' ")
        if(choose_what_to_edit=="date"):
            choose_date=input("Date? (e.g dd/mm/yyyy):")
            print(choose_date)
            c.executemany("UPDATE TABLES SET date= " + "'" + (choose_date) + "'" + " WHERE channel_id= (?)", choose_channel_id)
            print("Date has been updated successfully! ")
        if(choose_what_to_edit=="time"):
            choose_time=input("time? (e.g 0000 - 1400):")
            c.executemany("UPDATE TABLES SET time=" + "'" + choose_time +"'"+ " WHERE channel_id= (?)", choose_channel_id)
            print("Time has been updated successfully! ")
        if(choose_what_to_edit=="capacity"):
            choose_capacity=int(input("Please enter new capacity:"))
            c.executemany("UPDATE TABLES SET capacity= " + str(choose_capacity) + " WHERE channel_id= (?)", choose_channel_id)
            print("Capacity has been updated successfully! ")
    #c.execute()
   
    # commit command
    conn.commit()
    #Close our connection
    #conn.close()
    
def student_view():
    options = int(input("Select an option: \n1.View Channels and details\n2.Book Sessions\n3.Edit Bookings\n"))
    conn = sqlite3.connect('my.db')
    #Create Cursor
    c = conn.cursor()
    if(options==1):
        #Query the database
        c.execute("SELECT channel_id, date, time, capacity FROM TABLES ")
        all_channels = str(c.fetchall())
        replaceChar1 = all_channels.replace("(","\n")
        replaceChar2 = replaceChar1.replace("[","")
        replaceChar3 = replaceChar2.replace("'","")
        replaceChar4 = replaceChar3.replace(",", "")
        replaceChar5 = replaceChar4.replace(")","\n")
        replaceChar6 = replaceChar5.replace("]","")
        print("Below are the channels and it's detail:\n2 " + replaceChar6)
        conn.commit()
    if(options==2):
        c.execute("SELECT channel_id FROM TABLES")
        available_channels = str(c.fetchall())
        replaceChar1 = available_channels.replace("(","\n")
        replaceChar2 = replaceChar1.replace("[","")
        replaceChar3 = replaceChar2.replace("'","")
        replaceChar4 = replaceChar3.replace(",", "")
        replaceChar5 = replaceChar4.replace(")","\n")
        channel_id_available = replaceChar5.replace("]","")
        print("Below are the available channels:" + channel_id_available)
        x = input("Please select an available channel you would like to book the session: ")
        result = channel_id_available.find(x)
        if(result>=0):
            print(result)
            print("you have selected channel: " + x )   
            c.execute("SELECT time,date FROM SESSION")
            get_date_time = str(c.fetchall())
            replaceChar1 = get_date_time.replace("[","")
            replaceChar2 = replaceChar1.replace("'","")
            replaceChar3 = replaceChar2.replace("]","\n")
            replaceChar4 = replaceChar3.replace(",", "")
            replaceChar5 = replaceChar4.replace("(","")
            datetime = replaceChar5.replace(")","\n")
            print("These are the sessions and its date that has been booked:\n " + datetime)
#            print("Below are the session that has been booked:\n " + replaceChar4)
            print("----- Booking of session -----")
            student_id = input("Enter your student id: ")
            name = input("Enter your name: ")
            date = input("Enter the date? (e.g dd/mm/yyyy):\n")
            time = input("Enter the time? FROM 0600-1800 (e.g. 0000/1400):\n")
            c.execute("SELECT time FROM SESSION")
            get_time = str(c.fetchall())
            c.execute("SELECT date FROM SESSION")
            get_date = str(c.fetchall())
            replace_dateChar1 = get_date.replace("[","")
            replace_dateChar2 = replace_dateChar1.replace("'","")
            replace_dateChar3 = replace_dateChar2.replace("]","")
            replace_dateChar4 = replace_dateChar3.replace(",", "")
            replace_dateChar5 = replace_dateChar4.replace("(","")
            database_date = replace_dateChar5.replace(")","")
            replace_timeChar1 = get_time.replace("[","")
            replace_timeChar2 = replace_timeChar1.replace("'","")
            replace_timeChar3 = replace_timeChar2.replace("]","")
            replace_timeChar4 = replace_timeChar3.replace(",", "")
            replace_timeChar5 = replace_timeChar4.replace("(","")
            database_time = replace_timeChar5.replace(")","")
#            print("time you entered:\n" + time)
#            print("db's time:\n" + database_time)
#            print("date you entered:\n" + date)
#            print("db's date:\n" + database_date)
            resultdate=database_date.find(date)
            resulttime=database_time.find(time)
            print(date+time)
            print(date)
            print(time)
            print(resultdate)
            print(resulttime)
            if(resultdate==-1):
                c.execute("SELECT time FROM SESSION WHERE date =" + "'" + date + "'")
                time_from_chosen_date = str(c.fetchall())
                print("the Date you have selected is: " + date + "The date retrieved from db is: " + time_from_chosen_date)
                if(time_from_chosen_date.find(time)==-1):
                    records = [(x,student_id,name,date,time)]
                    c.executemany("INSERT INTO SESSION (channel_id,student_id, student_name, date, time) VALUES (?,?,?,?,?)",records)
                    print("You have successfully book your session man")                    
                else:
                    print("Session cant be booked")                
            elif(resultdate!=-1):
                print("Theres similar date in database!")
                c.execute("SELECT time FROM SESSION WHERE date=" + "'"+date+"'")
                time_from_specific_date = str(c.fetchall())
                print(time_from_specific_date)
                #IF the time student chose is not in the database:
                if(time_from_specific_date.find(time)==-1):
 #                   resultX = time_from_specific_date.find(time)
#                    print(resultX)
                    #inserting user inputs into records list
                    records = [(x,student_id,name,date,time)]
                    #query to insert student's selected stuff into SESSION table
                    c.executemany("INSERT INTO SESSION (channel_id,student_id, student_name, date, time) VALUES (?,?,?,?,?)",records)
                    print("You have successfully book your session grats")                    
                else:
                    print("Session cant be booked")
#            if(datetime.find(date+time)):
#                if(resultdate>=0):
#                    print("Error, sesion has been booked")
#                    print(resultdate)
#                    print(resulttime)
#                    if(resulttime==-1):
#                        print("Test123")
#                    else:
#                       print("idkwtfimdoinganymore")
#                elif(resulttime==-1) and (resultdate==-1):
#                    print("You may book this slot!")
#           else:
#                print(resultdate)
#                print(resulttime)
#               records = [(x,student_id,name,date,time)]
#                c.executemany("INSERT INTO SESSION (channel_id,student_id, student_name, date, time) VALUES (?,?,?,?,?)",records)
#                print("You have successfully book your session")
     #   for replaceChar6 in len(time_slots):
    #        print(replaceChar6)

        # commit command
            conn.commit()
            conn.close()          
        else:
            print("no such channel exists!!")
#        timeslots=str(time_slots)
#        replaceChar1 = timeslots.replace("[","")
#        replaceChar2 = replaceChar1.replace("'","")
#        replaceChar3 = replaceChar2.replace("]","")
#        replaceChar4 = replaceChar3.replace(",", "\n")
      
                #options = int(input("Select an option: \n1.View Channels \n2. Book Sessions\n3.Edit Bookings"))
#    if(options==2):
##        c.execute("SELECT channel_id, is_it_booked FROM TABLES")
#       fetch_data = c.fetchall()
 #       print(str(fetch_data))
 #       if(str(fetch_data).find('')==-1):
 #           print("There are no slots available")
 #       else:
 ##           print("These are the available slots you can book: ")
  #          print(str(fetch_data))
  #          c.execute("SELECT channel_id FROM TABLES")
  #          channel_ids=str(c.fetchall)
  #          student_select_channel = int(input("Please select a channel: \n"+ channel_ids))
                
Student_or_Staff = int(input("Are you a student or staff?: \n1. Staff\n2. Student\n "))
if(Student_or_Staff==1):
    ManageOrCreate = input("To create a channel, enter C, to edit, enter E: ")
    if(ManageOrCreate=="C"):
        while True:
            create_new_channel()
        
    if(ManageOrCreate=="E"):
        while True: 
            edit_channel()
elif(Student_or_Staff==2):
    while True:
        student_view()
#Close our connection
#conn.close()
while True:
    create_new_channel()
