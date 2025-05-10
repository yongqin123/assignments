from Crypto.PublicKey import RSA
from Crypto.Random import get_random_bytes
from Crypto.Cipher import AES, PKCS1_OAEP

from base64 import b64encode
from base64 import b64decode
from Crypto.Util.Padding import pad
from Crypto.Util.Padding import unpad


#encryption
symkey = get_random_bytes(16)

recipient_key = RSA.import_key(open("receiver.pem").read())
file_out = open("encrypted_key.bin", "wb")

cipher_rsa = PKCS1_OAEP.new(recipient_key)
enc_data = cipher_rsa.encrypt(symkey)
file_out.write(enc_data)
file_out.close()

open_data = open("new.txt","rb")
data = open_data.read()
cipher = AES.new(symkey, AES.MODE_CBC)
ct_bytes = cipher.encrypt(pad(data, AES.block_size)) #returns ciphertext
iv = b64encode(cipher.iv).decode('utf-8') #initialisation vector
ct = b64encode(ct_bytes).decode('utf-8') 
symkey = b64encode(symkey).decode('utf-8')
print(iv, ct, symkey)
open_data.close()

open_data = open("new.enc","wb")
open_data.write(str.encode(ct))
open_data.close()
#decryption

'''
file_in = open("encrypted_key.bin", "rb")
private_key = RSA.import_key(open("private.pem").read())
enc_key = file_in.read(private_key.size_in_bytes())
cipher_rsa = PKCS1_OAEP.new(private_key)
symkey = cipher_rsa.decrypt(enc_key)
file_in.close

try:
    iv = b64decode("DcmFVtuDNsgaqVsVDnJ+Ew==")
    ct = b64decode("z0wXGBUne0cmzmh4+kRHbA==")
    
    cipher = AES.new(symkey, AES.MODE_CBC, iv)
    pt = unpad(cipher.decrypt(ct), AES.block_size)
    print("The message was: ", pt)
    #output: The message was:  b'secret'
except ValueError:
    print("Incorrect decryption")
except KeyError:
    print("Incorrect Key")
'''
