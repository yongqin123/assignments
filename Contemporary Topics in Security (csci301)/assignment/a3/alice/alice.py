import random
import json
import hashlib
from Crypto.Hash import SHA256
####pubnub###
from pubnub.callbacks import SubscribeCallback
from pubnub.enums import PNStatusCategory, PNOperationType
from pubnub.pnconfiguration import PNConfiguration
from pubnub.pubnub import PubNub
#import PubNub
# find nonce, returns block with correct nonce


#print(findNonce(block))

def my_publish_callback(envelope, status):
    # Check whether request successfully completed or not
    if not status.is_error():
        pass  # Message successfully published to specified channel.
    else:
        pass  # Handle message publish error. Check 'category' property to find out possible issue
        # because of which request did fail.
        # Request can be resent using: [status retry];

class MySubscribeCallback(SubscribeCallback):
    def presence(self, pubnub, presence):
        print(f'presence: {presence.uuid} {presence.event}')
        pass  # handle incoming presence data

    def status(self, pubnub, status):
        if status.category == PNStatusCategory.PNUnexpectedDisconnectCategory:
            pass  # This event happens when radio / connectivity is lost

        elif status.category == PNStatusCategory.PNConnectedCategory:
            pass
            # Connect event. You can do stuff like publish, and know you'll get it.
            # Or just use the connected event to confirm you are subscribed for
            # UI / internal notifications, etc
            #pubnub.publish().channel("Channel-xj8w2uo6c").message('I am connected').pn_async(my_publish_callback)
            #pubnub.publish().channel('Channel-idshlu1uu').message({"sender": pnconfig.uuid, "content": sys.argv[1]}).pn_async(my_publish_callback)
        elif status.category == PNStatusCategory.PNReconnectedCategory:
            pass
            # Happens as part of our regular operation. This event happens when
            # radio / connectivity is lost, then regained.
        elif status.category == PNStatusCategory.PNDecryptionErrorCategory:
            pass
            # Handle message decryption error. Probably client configured to
            # encrypt messages and on live data feed it received plain text.

    def message(self, pubnub, message):
        # Handle new message stored in message.message
        if message.publisher == "bob":
            print(message.message)
                                                                                                                                                                                                                                                                                          
            #print(type(message.message))
            
            json_obj= str(message.message["content"])
            load_json = json.loads(json_obj)
            
            
            print(load_json)
            
            print(message.message)
            nonce = 0
            blknum = load_json["TxID"]
            if blknum == 9:
                print("Game ended successfully")
                pubnub.unsubscribe_all()
            prev_alpha = load_json["Transaction"][1]
            
            abcdefghi.remove(prev_alpha)

            
            fr = open(f"block{blknum}.json", "r+")
            
            previousblk = fr.read()
            fr.close()

            #hash previous block
            hashval = hashlib.sha256(previousblk.encode()).hexdigest()

            #Random Generator
            
            rand_gen = abcdefghi[random.randrange(len(abcdefghi))]
            print("Alice picks " + str(rand_gen))
            abcdefghi.remove(rand_gen)
            hashed_block_int = (2**244)+1 # make it execute at least once

            while hashed_block_int > 2**244:
                
                block = json.dumps({'TxID': blknum+1, 'Hash': hashval, "Nonce" : nonce, "Transaction" : ["Alice", rand_gen]},indent=4, separators=(',', ': '),sort_keys=True)
                hashed_block = SHA256.new(json.dumps(block,sort_keys=True).encode())
                hashed_block_int = int.from_bytes(hashed_block.digest(), byteorder="big")
                #print(hashed_block_int)
                nonce += 1 # increment nonce
            print(hashed_block.hexdigest())
            blknum += 1
            fw = open("block" + str(blknum) + ".json", "w+")
            fw.write(block)
            fw.close()
            pubnub.publish().channel(mychannel).message({"sender" : pnconfig.uuid, "content" : block  }).pn_async(my_publish_callback)
            


'''
#intialise block 0
tx = json.dumps({'TxID': 0, 'Hash': "This is the genesis block", "Nonce" : 0, "Transaction" : []},indent=4, separators=(',', ': '), sort_keys=True)
fw = open("block0.json", "w+")
fw.write(tx)
fw.close()

'''

#user picks an alphabet randomly
#tx = json.dumps({'TxID': txid, 'Hash': hashval, 'Transaction': txid, "Nonce" : nonce}, indent=4, separators=(',', ': '))

#initialise pubnub object
mychannel = "Channel-xj8w2uo6c"
pnconfig = PNConfiguration()

pnconfig.publish_key = "pub-c-0392e5c9-54d1-4290-87a4-22d269b06bd1"
pnconfig.subscribe_key = "sub-c-7411419a-939a-4685-8f59-2013db856813"
pnconfig.user_id = "alice"
pubnub = PubNub(pnconfig)


pubnub.add_listener(MySubscribeCallback())
pubnub.subscribe().channels(mychannel).with_presence().execute()

#intialise block 0
print("Alice's turn")
tx = json.dumps({'TxID': 0, 'Hash': "This is the genesis block", "Nonce" : 0, "Transaction" : []},indent=4, separators=(',', ': '), sort_keys=True)
fw = open("block0.json", "w+")
fw.write(tx)
fw.close()

#transaction
blknum = 0


#while blknum != 6: # testing create 6 blocks i think
nonce = 0
#print(blknum)
#read previous block
fr = open(f"block{blknum}.json", "r+")
previousblk = fr.read()
print(previousblk)
fr.close()

#hash previous block
hashval = hashlib.sha256(previousblk.encode()).hexdigest()

#Random Generator
abcdefghi = ["a","b","c","d","e","f","g","h","i"]
rand_gen = abcdefghi[random.randrange(len(abcdefghi))]
print("Alice picks " + str(rand_gen))
abcdefghi.remove(rand_gen)
hashed_block_int = (2**244)+1 # make it execute at least once

while hashed_block_int > 2**244:
        
    block = json.dumps({'TxID': blknum+1, 'Hash': hashval, "Nonce" : nonce, "Transaction" : ["Alice", rand_gen]},indent=4, separators=(',', ': '),sort_keys=True)
    hashed_block = SHA256.new(json.dumps(block,sort_keys=True).encode())
    hashed_block_int = int.from_bytes(hashed_block.digest(), byteorder="big")
    #print(hashed_block_int)
    nonce += 1 # increment nonce
print(hashed_block.hexdigest())


    

#block = findNonce(block)
blknum += 1
print(block)
print(blknum)
fw = open(f"block{blknum}.json", "w+")

fw.write(block)
print(f"block{blknum}.json")
fw.close()

pubnub.publish().channel(mychannel).message({"sender" : pnconfig.uuid, "content" : block  }).pn_async(my_publish_callback)

    


'''
python Desktop/csci301/assignment/a3/alice/alice.py
'''


