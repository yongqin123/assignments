'''
2)
from Crypto.Random import get_random_bytes

key = get_random_bytes(16)

print(key)

'''

'''
### 3b ###
from base64 import b64encode
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
from Crypto.Random import get_random_bytes


data = b'secret' 
key = get_random_bytes(16)



cipher = AES.new(key, AES.MODE_CBC)
ct_bytes = cipher.encrypt(pad(data, AES.block_size)) #returns ciphertext
iv = b64encode(cipher.iv).decode('utf-8') #initialisation vector
ct = b64encode(ct_bytes).decode('utf-8') 
key = b64encode(key).decode('utf-8')
print(iv, ct, key)

#ouput: wAzSaaUegGkgbpulmcTl9A== 6pZ1xEmKzpizMkW/WUGtHw== q7v+ZS+POLZUpIDPdAweYw==
#iv, ct, key
'''

'''
#3c
from base64 import b64decode
from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad
try:
    iv = b64decode("TgQ1o84ualYAX4M2ULwhnQ==")
    ct = b64decode("1aPj/PfN/fcJn4+I7clHBQ==")
    key = b64decode("7QIXMjl7hYK8KEUBzIqg9g==")
    cipher = AES.new(key, AES.MODE_CBC, iv)
    pt = unpad(cipher.decrypt(ct), AES.block_size)
    print("The message was: ", pt)
    #output: The message was:  b'secret'
except ValueError:
    print("Incorrect decryption")
except KeyError:
    print("Incorrect Key")
'''

'''
#4b (RSA: generate public and private key pair)
from Crypto.PublicKey import RSA
key = RSA.generate(2048)
private_key = key.export_key()
file_out = open("private.pem", "wb") 
file_out.write(private_key)
print(file_out.read())
file_out.close()
public_key = key.publickey().export_key()
file_out = open("receiver.pem", "wb")


file_out.write(public_key)
print(file_out.read())
file_out.close()
'''

#4c RSA encrytption using PKCS1
from Crypto.PublicKey import RSA
from Crypto.Random import get_random_bytes
from Crypto.Cipher import PKCS1_OAEP
recipient_key = RSA.import_key(open("receiver.pem").read())
data = b"secret"
file_out = open("encrypted_data.bin", "wb")
cipher_rsa = PKCS1_OAEP.new(recipient_key)
print(type(cipher_rsa))
enc_data = cipher_rsa.encrypt(data)
file_out.write(enc_data)
file_out.close()

'''
#4d RSA decyption
from Crypto.PublicKey import RSA
from Crypto.Cipher import AES, PKCS1_OAEP
file_in = open("encrypted_data.bin", "rb")
private_key = RSA.import_key(open("private.pem").read())
enc_data = file_in.read(private_key.size_in_bytes())
cipher_rsa = PKCS1_OAEP.new(private_key)
data = cipher_rsa.decrypt(enc_data)
print(data)
file_in.close()
'''
