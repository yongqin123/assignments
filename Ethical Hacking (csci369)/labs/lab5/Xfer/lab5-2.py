#! /usr/bin/env python

from scapy.all import *
from netfilterqueue import NetfilterQueue
import os

# iptablesr = "iptables -A FORWARD -j NFQUEUE --queue-num 1"

# os.system(iptablesr)
# os.system("sysctl net.ipv4.ip_forward=1")

def modify(packet):
    ip_pkt = IP(packet.get_payload())
    # print(ip_pkt.show())
    print(ip_pkt.show2())
    print(ip_pkt.summary())
    print(ip_pkt.command())
    packet.accept()

nfqueue = NetfilterQueue()
nfqueue.bind(1, modify)
try:
    nfqueue.run()
except KeyboardInterrupt:
    nfqueue.unbind()
