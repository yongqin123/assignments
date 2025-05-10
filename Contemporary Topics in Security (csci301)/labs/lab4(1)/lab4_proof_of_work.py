import json
import hashlib

transactions = [ "[3, 4, 5, 6]", "[4, 5, 6, 7]", "[5, 6, 7, 8]", "[6, 7, 8, 9]", "[7, 8, 9, 10]", "[8, 9, 10, 11]", "[9, 10, 11, 12]", "[10, 11, 12, 13]", "[11, 12, 13, 14]", "[12, 13, 14, 15]", "[13, 14, 15, 16]"]

blknum = 0




for i in transactions:
    blknum += 1
    fr = open(str(blknum - 1) + ".json", "r")
    previousblk = fr.read()
    fr.close()

    hashval = hashlib.sha256(previousblk.encode()).hexdigest()

    nonce = 0
    while True:
        tx = json.dumps({'Block number': blknum, 'Hash': hashval, 'Transaction': i, "Nonce" : nonce}, sort_keys=True,indent=4, separators=(',', ': '))
        hashout = hashlib.sha256(tx.encode()).hexdigest()

        if int(hashout, 16) <=  int("0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", 16):
            break
        nonce += 1
    fw = open(str(blknum) + ".json", "w+")
    
    fw.write(tx)
    fw.close()

    fr = open(str(blknum) + ".json", "r")
    blk = fr.read()
    print(blk)
    data = json.loads(blk)["Hash"]
    print(f'Hash value loaded is {data}')

    if data == hashval:
        print(f'Json is correct')
    else:
        print(f'Json is incorrect')

    fr.close()
