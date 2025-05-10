from Crypto.PublicKey import DSA
from Crypto.Signature import DSS
from Crypto.Hash import SHA256
import binascii

def program(iteration):
    # Create DSA key 
    public_key_pem = "-----BEGIN PUBLIC KEY-----\n\
    MIIDQzCCAjUGByqGSM44BAEwggIoAoIBAQC2guaUPVAr71KD+gIJn1CvFVcTkzoF\n\
    zXr4n3aN/4lY3rkBfvuOm22y3FWz2TQfy42CGU2SThZ+0xnF7xvAaVLDGRn+H2Ck\n\
    ViUT/B/N9/aTQf66frdtDPmp6FutHDEcp+/6rAjnLUqpJKQ5Qvdlaz+qoVhQhjHN\n\
    QATO5FNyDOszyYpw97tEMydBBhNrxAcoatog+nRxQYnv0zsR9HEZ5ZDUwKMSyFRf\n\
    zleM8ndNH5Mn3fuWG9mDTbID5McwAczjpT6V+qjEfThMqIv3f1cU4bQP5AVZYiLD\n\
    KPoUPMN7Ix3V7+rKJEkOLJNcXxFBNrEsJiS0HWF/UBFhCg9fTu1PueOzAh0A6SLF\n\
    pvIBlujYqBYiqKSYeV7f6lvuIE6M3EgmVwKCAQBvjDsrx0d+RyP8R4QID7VMDEmi\n\
    FDenYPLYsh1eQ+mx4RH9gE6DaVxKg9TBJ2ClssgMQIRG5ksWj8Y5kvQC56wPURpC\n\
    N8x6+c6z64p4d2h9weD8/I8npzRByfozQIcXYhi4HYXqXDj2mcXEBs2/qSHHffRd\n\
    Wk6zOzdSDrO2Mx8r9A5IDmNpHNFkl+tvmxpbzpEg9y1CjrDbUwOuMUUAxe2sKeOT\n\
    j3fztzhM1IsEkPngAtWdc2/tsd4J4Z/Cd9xIX6HC8VKzYEaH3ESfzwU8z6X+1iCB\n\
    0XAz6JL4BT2jLUblYZmfOckVIN6r71S4f+Y3BSURPJphCyEelLA8aXNA1qZXA4IB\n\
    BgACggEBAIxetFr0qICY3X+ZQLaPgjavEz1fdnCxPzfHiG4DxpHblgH81iCN+E7s\n\
    UXwRTUW+vJMCBNAGN3kniLtmIH5GcOpoiQwbvuFtrl5dCU2JxmvSHh+HyL27bWQV\n\
    ESqzXRltZuLIBjwmY2zgoV0NgH9futyZjqNwbFUjGVqnHDKkhWQ8CoNF+XVukDCd\n\
    lz/bJLPrwUcUbK5STTylFlby7hKM0ZIjrTjZW2ae4Le9tqzTLMohq1xuIkPMbzCN\n\
    Vu9iKd821Dg5NtU9fxRGJpm7tNiiD6hoCpCQNiimuxVgWstwhO2+AcVRlZYW5ksI\n\
    0+3FUqNOwcFzd0yI/nGmVjdLGkDLahk=\n\
    -----END PUBLIC KEY-----"

    for i in range(iteration):
        fw = open(f"scriptPubKey{i+1}.txt", "w+")
        param_key = DSA.import_key(public_key_pem)

        #same g, p, q
        tup = [param_key.p, param_key.q, param_key.g]

        #generate dsa keys in 2048 bits with constants g, p, q
        key1 = DSA.generate(2048, domain=tup)
        key2 = DSA.generate(2048, domain=tup)
        key3 = DSA.generate(2048, domain=tup)
        key4 = DSA.generate(2048, domain=tup)

        fw.write(f"OP_2\n{binascii.hexlify(str.encode(str(key1.y)))}\n{binascii.hexlify(str.encode(str(key2.y)))}\n{binascii.hexlify(str.encode(str(key3.y)))}\n{binascii.hexlify(str.encode(str(key4.y)))}\nOP_4\nOP_CHECKMULTISIG")
        fw.close()

        #signing and hexify
        message = b"Contemporary topic in security"
        hash_obj = SHA256.new(message)
        fw2 = open(f"scriptSig{i+1}.txt", "w+") 

        signer1 = DSS.new(key1, 'fips-186-3')
        signature1 = signer1.sign(hash_obj)
        signature_hex1 = binascii.hexlify(signature1)

        signer2 = DSS.new(key2, 'fips-186-3')
        signature2 = signer2.sign(hash_obj)
        signature_hex2 = binascii.hexlify(signature2)

        #write to scriptSig.txt
        fw2.write(f"OP_1\n{signature_hex1}\n{signature_hex2}")
        fw2.close()


#####start of program#####
iteration = 3
program(iteration)
