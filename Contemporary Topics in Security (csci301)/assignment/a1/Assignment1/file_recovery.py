from Crypto.PublicKey import RSA
from Crypto.Random import get_random_bytes
from Crypto.Cipher import AES, PKCS1_OAEP

from base64 import b64encode
from base64 import b64decode
from Crypto.Util.Padding import pad
from Crypto.Util.Padding import unpad

import os
import random

#From victim pc
#Read key.txt
keytxt = open("key.txt", "r")
contents = keytxt.read()
keytxt.close()
print(contents)
#contents = contents[2:-1]
print(contents)

alphabet = "abcdefghijklmnopqrstuvwxyz"

#Get alphabat table by matching abc order with the decrypted key using key-pairs
alphabetTable = {}
for i in range(len(alphabet)):
    alphabetTable[contents[i]] = alphabet[i]

#Get files containning .enc
array_enc_files = []
for file in os.listdir(os.getcwd()):
    if file.endswith(".enc"):
        array_enc_files.append(file)
        
for i in array_enc_files:
    open_enc_file = open(i,"r")
    content = open_enc_file.read()
    
    content = content[:]
    print(i)
    open_enc_file.close()
    decrypted_text = ""

    #match the cipher text inside .enc files with the alphabat table
    for j in content:
        decrypted_text += alphabetTable[j]
    print(decrypted_text)

    #recreate the original txt files with same name
    new_txt = i[:-4] + ".txt"
    new_txt = open(new_txt , 'w')
    new_txt.write(decrypted_text)
    new_txt.close()
            
