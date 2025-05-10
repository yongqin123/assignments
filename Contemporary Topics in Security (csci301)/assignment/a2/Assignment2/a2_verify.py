from Crypto.PublicKey import DSA
from Crypto.Signature import DSS
from Crypto.Hash import SHA256
import binascii

def creatingOfstack(iteration):
    # import key pem
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

    param_key = DSA.import_key(public_key_pem)
    #read files scriptPubKey.txt
    f_pubkey = open(f"scriptPubKey{iteration+1}.txt", "rb")
    decoded_pubkey = f_pubkey.read().decode('utf-8')
    f_pubkey_array = decoded_pubkey.split("\n")
    f_pubkey_array = list(map(lambda x: x[2:-1] if x[:3] != "OP_" else x, f_pubkey_array))
    f_pubkey_array = list(map(lambda x: binascii.unhexlify(x) if x.isdigit() != False else x ,f_pubkey_array))
    f_pubkey.close()

    #read files scriptSig.txt
    f_signatures = open(f"scriptSig{iteration+1}.txt", "rb")
    decoded_signature = f_signatures.read().decode('utf-8')
    f_signatures_array = decoded_signature.split("\n")
    f_signatures_array = list(map(lambda x: x[2:-1] if x != "OP_1" else x, f_signatures_array))
    f_signatures_array = list(map(lambda x: str.encode(x) if x != "OP_1" else x, f_signatures_array))
    f_signatures.close()

    print(f"Running Stack for Pair: {iteration+1}")
    #p2ms stack
    counter = 0
    stack = []
    print(f"Stack contains: {stack}")
    
    #number of keys required
    m = 0
    #total number of keys
    n = 0

    #push the signatures to stack
    print(f"--Inserting signatures--")
    for i in f_signatures_array:
        if i != "OP_1":
            stack.append(i)
            print(f"Stack contains: {stack}")
            m += 1

    print(f"--Total {m} signaturs--")
    print(f"--Inserting primary keys--")
    #push the pubkeys to stack
    for i in f_pubkey_array:
        if i == "OP_CHECKMULTISIG":
            print(f"Reached OP_CHECKMULTISIG")
            checksign(stack, param_key)
            break
        elif i[:-1] == "OP_" and counter == 0:
            m = int(i[len(i) -1])
            stack.append(m)
            counter += 1
            print(f"OP_{m} added where M = {m}")
            print(f"Stack contains: {stack}")
        elif i[:-1] == "OP_" and counter != 0:
            n = int(i[len(i) -1])
            stack.append(n)
            counter += 1
            print(f"OP_{n} added to stack where N = {n}")
            print(f"Stack contains: {stack}")
        else:
            stack.append(i)
            print(f"Inserted primary key: {i}")
            print(f"Stack contains: {stack}")
            counter += 1
            
def checksign(stack, param_key):
    
    authentication_counter = 0
    message = b"Contemporary topic in security"
    sig_arr = []
    pk_arr = []

    print(f"Popping 1st value from stack which is N")
    print(f"Stack contains: {stack}")
    
    n = stack.pop()
    print(f"Popping {n} values from stack")
    print(f"Stack contains: {stack}") 
    for i in range(n):
        pkey = stack.pop()
        pk_arr.append(int(pkey))
        print(f"Popping A Primary key") 
        print(f"Stack contains: {stack}") 

    print(f"Popping M from stack")
    print(f"Stack contains: {stack}")
    m = stack.pop()
    for i in range(m):
        sig = stack.pop()
        sig_arr.append(sig)
        print(f"Popping Signatures") 
        print(f"Stack contains: {stack}")
       
    for j in sig_arr:
        for i in pk_arr:
            #create domain and add in y value which is your pkey
            
            tup = [param_key.q, param_key.p, param_key.g]
            tup.append(i)
            tup = tup[::-1]
            
            #reconstruct key/pair using g,p,q,y
            key = DSA.construct(tup,consistency_check=True)
            
            pub_key = key.publickey()
            a = pub_key.export_key()
            
            hash_obj = SHA256.new(message)
            verifier = DSS.new(pub_key, 'fips-186-3')
            try:
                verifier.verify(hash_obj, binascii.unhexlify(j))
                print("Key is authentic")
                authentication_counter += 1
            except ValueError:
                print("Key is not authentic")

    if authentication_counter == m:
        stack.append(1)
        print(f"Stack contains: {stack}")
        print("All keys matched so script is valid")
        print("------------------------------------------------")

##########start of program#########

total_iteration = 3

for i in range(total_iteration):
    creatingOfstack(i)

