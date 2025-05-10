import pandas as pd
import random
import statistics
import sys 
import os

def initial_input():
    days = int(sys.argv[-1])
    s = sys.argv[-2]
    e = sys.argv[-3]
    files = os.listdir(os.curdir)
    if s not in files or e not in files:
        if s not in files:
            print(f"----{s} is not located in the folder----")
        if e not in files:
            print(f"----{e} is not located in the folder----")
        exit()

    events = open(e)
    read_events = events.read().split("\n")
    events_line = read_events[0]
    read_events = read_events[1:]
    events.close()
    events_list = list(map(lambda x : x.split(":")[:-1] , read_events))
    df_events = pd.DataFrame(events_list ,columns=["Event name", "[CD]", "minimum", "maximum" ,"weight"])
    stats = open(s)
    read_stats = stats.read().split("\n")
    stats_line=read_stats[0]
    read_stats = read_stats[1:]
    stats.close()
    stats_list = list(map(lambda x : x.split(":")[:-1] , read_stats))
    df_stats = pd.DataFrame(stats_list, columns=["Event name" ,"mean", "standard deviation"])
    events_all = list(map(lambda x : x[0] , df_events.values.tolist()))
    stats_all = list(map(lambda x : x[0] , df_stats.values.tolist()))
    count_consistencies = 0
    for i in events_all:
        if i in stats_all:
            count_consistencies += 1
    if count_consistencies != len(events_all):
        print("----There are inconsistencies between Stats.txt and Events.txt----")
        exit()
    elif int(stats_line) != len(stats_all) or int(events_line) != len(events_all):
        print("----Number of rows for Stats.txt or Events.txt does not tally!----")
        exit()
    else:
        print("----Stats.txt is processed.----")
        print("----Events.txt is processed.----")
    return days,df_events,df_stats

def generate_baseline_and_total(days, df_stats, df_events, default_or_live):
    if default_or_live == "live":
        input_live = input("----Please input live stats file (.txt) or 'E' to exit:----")
        if input_live.upper() == "E":
            exit()
        files = os.listdir(os.curdir)
        while input_live not in files:
            input_live = input("----Please input live stats file (.txt):----")
        days = int(input("----Please input number of days:----"))
        stats = open(input_live)
        read_stats = stats.read().split("\n")[1:]
        stats.close()
        stats_list = list(map(lambda x : x.split(":")[:-1] , read_stats))
        df_stats = pd.DataFrame(stats_list, columns=["Event name" ,"mean", "standard deviation"])
    
    arr_baseline = []
    for i in range(days):
        arr_baseline.append([])
        arr_baseline[i].append(i+1)
        for j in range(5):
            if j == 1:
                arr_baseline[i].append(round(random.normalvariate(float(df_stats.at[1, "mean"]), float(df_stats.at[1, "standard deviation"])),2))
            else:
                arr_baseline[i].append(round(random.normalvariate(float(df_stats.at[j, "mean"]), float(df_stats.at[j, "standard deviation"]))))
    df_baseline = pd.DataFrame(arr_baseline, columns=["Days", "Logins", "Time online", "Emails sent", "Emails opened", "Emails deleted"])
    df_baseline.set_index("Days",inplace=True)
    df_baseline_total = pd.DataFrame( list(map(lambda x: sum(x[1:])  , arr_baseline)) , columns=["Total"])
    df_baseline_total["Days"] = list(map(lambda x: x[0] , arr_baseline))
    df_baseline_total.set_index("Days",inplace=True)
    arr_columns = ["Logins", "Time online", "Emails sent", "Emails opened", "Emails deleted"]

    arr_mean = list(map(lambda x: sum(x) / days, df_baseline.T.values.tolist()))
    arr_sd = list(map(lambda x: statistics.stdev(x), df_baseline.T.values.tolist()))
    arr_mean_sd = []
    for i in range(len(arr_mean)):
        arr_mean_sd.append([arr_mean[i], arr_sd[i]])
    df_mean_sd = pd.DataFrame(arr_mean_sd, columns=["Mean","Standard Deviation"])
    df_mean_sd["Event Name"] = arr_columns
    df_mean_sd.set_index("Event Name",inplace=True)

    with open(f"{default_or_live}_baseline.txt", 'w') as f:
        dfAsString = df_baseline.to_string(header=True, index=True)
        f.write(dfAsString)
        print(f"----Log file generated as {default_or_live}_baseline.txt----")

    with open(f"{default_or_live}_baseline_total.txt", 'w') as f:
        dfAsString = df_baseline_total.to_string(header=True, index=True)
        f.write(dfAsString)
        print(f"----Total generated for each day as {default_or_live}_baseline_total.txt----")

    with open(f"{default_or_live}_baseline_total_stats.txt", 'w') as f:
        dfAsString = df_mean_sd.to_string(header=True, index=True)
        f.write(dfAsString)
        print(f"----Standard deviation and mean generated for each event as {default_or_live}_baseline_total_stats.txt----")

    if default_or_live == "live":   
        with open("live_anomaly_threshold.txt", "w") as f:
            anomaly_threshold = sum(list(map(lambda x : float(x[4]), df_events.values.tolist())) ) * 2
            f.write(f"Anomaly Threshold: {anomaly_threshold}\n")
            for i in range(len(df_baseline)):
                anomaly_counter = 0
                anomaly_counter += (abs(df_baseline.at[i+1, "Logins"] - df_mean_sd.at["Logins", "Mean"]) / df_mean_sd.at["Logins", "Standard Deviation"] * float(df_events.at[0, "weight"]))
                anomaly_counter += (abs(df_baseline.at[i+1, "Time online"] - df_mean_sd.at["Time online", "Mean"]) / df_mean_sd.at["Time online", "Standard Deviation"] * float(df_events.at[1, "weight"]))
                anomaly_counter += (abs(df_baseline.at[i+1, "Emails sent"] - df_mean_sd.at["Emails sent", "Mean"]) / df_mean_sd.at["Emails sent", "Standard Deviation"] * float(df_events.at[2, "weight"]))
                anomaly_counter += (abs(df_baseline.at[i+1, "Emails opened"] - df_mean_sd.at["Emails opened", "Mean"]) / df_mean_sd.at["Emails opened", "Standard Deviation"] * float(df_events.at[3, "weight"]))
                anomaly_counter += (abs(df_baseline.at[i+1, "Emails deleted"] - df_mean_sd.at["Emails deleted", "Mean"]) / df_mean_sd.at["Emails deleted", "Standard Deviation"] * float(df_events.at[4, "weight"]))
                good_or_bad = "good"
                if anomaly_counter > anomaly_threshold:
                    good_or_bad = "bad"
                f.write(f"Day {i+1}: " + f"{round(anomaly_counter,2)} ({good_or_bad})\n")
        with open("live_anomaly_threshold.txt", "r") as f:
            print(f.read())

if __name__ == '__main__':
    print("----Welcome to IDS----")
    days,df_events,df_stats = initial_input()
    print("----Welcome to Activity Simulation Engine Engine----")
    generate_baseline_and_total(days, df_stats, df_events, "default")
    while True:
        print("----Welcome to Alert Engine----")
        generate_baseline_and_total(days, df_stats, df_events, "live")

