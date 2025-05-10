from Crypto.PublicKey import DSA
from Crypto.Signature import DSS
from Crypto.Hash import SHA256
import binascii

#Generate public/private key pair in 1024 bits
key = DSA.generate(1024)

#extract out the g,p,q,y values from the key in a tuple
tup = [key.y, key.g, key.p, key.q]

#Sign a message using the key
message = b"Hello"
hash_obj = SHA256.new(message)
signer = DSS.new(key, 'fips-186-3')
signature = signer.sign(hash_obj)

