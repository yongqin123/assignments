### Q1 ###

#import hashlib
#out = hashlib.sha256(b"hello world").hexdigest()
#print(out)

#print(bin(int(out,16)))

## q9 ##
from Crypto.PublicKey import DSA
from Crypto.Signature import DSS
from Crypto.Hash import SHA256
import binascii

