import json
import hashlib
####pubnub###
from pubnub.callbacks import SubscribeCallback
from pubnub.enums import PNStatusCategory, PNOperationType
from pubnub.pnconfiguration import PNConfiguration
from pubnub.pubnub import PubNub
#import PubNub


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
        pass  # handle incoming presence data

    def status(self, pubnub, status):
        if status.category == PNStatusCategory.PNUnexpectedDisconnectCategory:
            pass  # This event happens when radio / connectivity is lost

        elif status.category == PNStatusCategory.PNConnectedCategory:
            # Connect event. You can do stuff like publish, and know you'll get it.
            # Or just use the connected event to confirm you are subscribed for
            # UI / internal notifications, etc
            pubnub.publish().channel('Channel-xj8w2uo6c').message('Hello world!').pn_async(my_publish_callback)
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
        print(message.message)
        fw = open("test.txt", "w")
        fw.write(str(message.message))
        fw.close()

#intialise block 0
txid = 0
txid += 1
tx = json.dumps({'TxID': 0, 'Hash': "This is the genesis block", "Nonce" : 0, "Transaction" : []},indent=4, separators=(',', ': '))
fw = open("block0.json", "w+")
fw.write(tx)
fw.close()

#transaction
blknum = 0
nonce = 0
blknum += 1
fr = open("block" + str(blknum - 1) + ".json", "r")
previousblk = fr.read()
fr.close()

hashval = hashlib.sha256(previousblk.encode()).hexdigest()

#user picks an alphabet randomly
tx = json.dumps({'TxID': txid, 'Hash': hashval, 'Transaction': txid, "Nonce" : nonce}, indent=4, separators=(',', ': '))

#initialise pubnub object
mychannel = "Channel-xj8w2uo6c"
pnconfig = PNConfiguration()
pnconfig.subscribe_key = "sub-c-7411419a-939a-4685-8f59-2013db856813"
pnconfig.publish_key = "pub-c-8442b00d-c381-4fc7-bc22-aa3eb7e20dc3"
pnconfig.user_id = "assignment3"
pubnub = PubNub(pnconfig)


pubnub.add_listener(MySubscribeCallback())
pubnub.subscribe().channels(mychannel).execute()





