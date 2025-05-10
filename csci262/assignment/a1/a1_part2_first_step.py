from hashlib import md5
import pandas as pd

### First Step ###
read_file = open("Passwords.txt", "r")
contents_arr = read_file.read().split("\n")
length_contents = len(contents_arr)
print(f"Q1: Number of words read in is {length_contents}")
hash_dic = {"Password":contents_arr, "Hashed Value":[], "Reduction Function":[], "Checked":["no"]*length_contents}
hash_dic_reduced = {"Password":[], "Hashed Value":[]}
for i in range(len(contents_arr)):
    new_hash = md5(contents_arr[i].encode("utf-8")).hexdigest()
    hash_dic["Hashed Value"].append(new_hash)
    convert_to_long = ((int(new_hash,base = 16) % length_contents)) + 1
    hash_dic["Reduction Function"].append(convert_to_long)
df1 = pd.DataFrame(hash_dic)
df1.index = df1.index + 1

for i in range(length_contents):
    if df1.loc[i+1]["Checked"] == "no":
        new_reduction_number = df1.loc[i+1]["Reduction Function"]
        hash_dic_reduced["Password"].append(df1.loc[ i+1]["Password"])
        df1.at[i+1,"Checked"] = "yes"
        for j in range(3):
            df1.at[new_reduction_number,"Checked"] = "yes"  
            new_reduction_number = df1.loc[ new_reduction_number]["Reduction Function"]
            df1.at[new_reduction_number,"Checked"] = "yes"  
        hash_dic_reduced["Hashed Value"].append(df1.loc[ new_reduction_number]["Hashed Value"])
 
df2 = pd.DataFrame(hash_dic_reduced)
df2 = df2.sort_values("Hashed Value")

with open("Rainbow.txt", 'w') as f:
    dfAsString = df2.to_string(header=False, index=False)
    f.write(dfAsString)
f.close()

print("Rainbow table generated")