from pubnub.callbacks import SubscribeCallback
from pubnub.enums import PNStatusCategory, PNOperationType
from pubnub.pnconfiguration import PNConfiguration
from pubnub.pubnub import PubNub
import sys

pnconfig = PNConfiguration()

pnconfig.subscribe_key = 'sub-c-7411419a-939a-4685-8f59-2013db856813'
pnconfig.publish_key = 'pub-c-0392e5c9-54d1-4290-87a4-22d269b06bd1'
#pnconfig.subscribe_key = 'sub-c-8cb45cae-21eb-4d81-8ac5-7401254f46fa'
#pnconfig.publish_key = 'pub-c-31498550-5bfa-430e-8ab3-e72e0a7f8395' 
pnconfig.user_id = "lab6"
pubnub = PubNub(pnconfig)

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
            pubnub.publish().channel('Channel-idshlu1uu').message(sys.argv[1]).pn_async(my_publish_callback)
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
        fw = open("test1.txt", "w")
        fw.write(str(message.message))
        fw.close()
	

pubnub.add_listener(MySubscribeCallback())
#pubnub.publish().channel('Channel-xj8w2uo6c').message({"sender": pnconfig.uuid, "content": "sys.argv[1]"}).pn_async(my_publish_callback)
pubnub.subscribe().channels('Channel-xj8w2uo6c').execute()


'''
pubnub.add_listener(MySubscribeCallback())
pubnub.subscribe().channels('Channel-myzkh1fig').execute()
'''
