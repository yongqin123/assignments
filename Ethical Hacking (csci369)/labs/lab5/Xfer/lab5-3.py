#! /usr/bin/env python
import re 

#to open password list file
dictionary = open("birthday2.txt","r") 
#to write extracted passwords into a file
extracted = open("passwd_ext.txt","w")

rex = re.compile("082[56]") 
passwords = filter(rex.search, dictionary) 

for line in passwords:
    extracted.write(line)

dictionary.close()
extracted.close()
