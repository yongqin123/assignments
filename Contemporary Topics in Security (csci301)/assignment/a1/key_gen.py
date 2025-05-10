from Crypto.PublicKey import RSA
from Crypto.PublicKey import DSA
from Crypto.Signature import DSS
from Crypto.Hash import SHA256
import binascii

key = DSA.generate(2048)

fw = open("asd.pem", "wb")
fw.write(key.publickey().export_key())
fw.close()

fr = open("asd.pem", "rb")
print(fr.read())
