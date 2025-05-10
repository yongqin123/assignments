from Crypto.PublicKey import RSA
from Crypto.Random import get_random_bytes
from Crypto.Cipher import AES, PKCS1_OAEP

from base64 import b64encode
from base64 import b64decode
from Crypto.Util.Padding import pad
from Crypto.Util.Padding import unpad

import os
import random

#Open key.bin
file_in = open("key.bin", "rb")

#Get private Key
private_key = RSA.import_key(open("private.pem").read())
enc_key = file_in.read(private_key.size_in_bytes())
cipher_rsa = PKCS1_OAEP.new(private_key)

#Decrypt encrypted key using RSA decryption
key = cipher_rsa.decrypt(enc_key)
file_in.close

#Write decrypted key to key.txt
keytxt = open("key.txt","wb")
keytxt.write(key)
keytxt.close()
