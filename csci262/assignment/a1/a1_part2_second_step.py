from hashlib import md5
global rainbow_dic

user_input = str(input("Input a hash: "))
#red = int(new_hash, 16) % 15
read_file = open("Passwords.txt", "r")
passwords_arr = read_file.read().split("\n")
read_file.close()

read_file = open("Rainbow.txt", "r")
rainbow_arr = read_file.read().split("\n")
read_file.close()
rainbow_dic = {}

for i in range(len(rainbow_arr)):
    rainbow_arr[i] = rainbow_arr[i].lstrip().split(" ")
    rainbow_dic[rainbow_arr[i][0]] = rainbow_arr[i][1]

def search(user_input, passwords_arr):
    reduce_hash_input = user_input
    while reduce_hash_input not in rainbow_dic.values():
        reduce = (int(reduce_hash_input, 16) % len(passwords_arr)) + 1
        password = passwords_arr[reduce - 1]
        reduce_hash_input = md5(password.encode("utf-8")).hexdigest()
 
    found_keys = [k for k,v in rainbow_dic.items() if v == reduce_hash_input]
    
    for i in found_keys:
        hashed_password = md5(i.encode("utf-8")).hexdigest()
        if hashed_password == user_input:
            print("Password is " + str(i))
            return True

        for i in range(4):
            reduce = (int(hashed_password, 16) % len(passwords_arr)) + 1
            password = passwords_arr[reduce - 1]
            
            hashed_password = md5(password.encode("utf-8")).hexdigest()
            if hashed_password == user_input:
                print("Password is " + str(password))
                return True
            
    rainbow_dic.pop(found_keys[0], None)
    return False   

while True:     
    if search(user_input, passwords_arr) == True:
        break