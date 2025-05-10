#! /usr/bin/env python

from scapy.all import *
from netfilterqueue import NetfilterQueue
import os

##NFQUEUE is a kernel and user mode module for managing network packets in iptables
##Specifying the queue number for all incoming packet that matches this rule. 
##Default is 0.
#iptableinput = "iptables -I INPUT -j NFQUEUE --queue-num 1"
##Specifying the queue number for outgoing packet. 
#iptableoutput = "iptables -I OUTPUT -j NFQUEUE --queue-num 1"

##Allocating queue number only for packets that are in the forward chain
iptablesr = "iptables -I FORWARD -j NFQUEUE --queue-num 1"
#os.system(iptableinput)
#os.system(iptableoutput)
os.system(iptablesr)

##What is the effect of this command?
os.system("sysctl net.ipv4.ip_forward=1")

def modify(packet):
    ip_pkt = IP(packet.get_payload())
    print(ip_pkt.show())

    ##Release the packet
    packet.accept()

    ##Drops the packet
    #packet.drop()

nfqueue = NetfilterQueue()

#1 is the queue number
nfqueue.bind(1, modify)
try:
    nfqueue.run()
except KeyboardInterrupt:
    nfqueue.unbind()
