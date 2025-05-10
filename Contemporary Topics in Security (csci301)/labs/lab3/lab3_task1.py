import sys
import glob

filein = open(sys.argv[0], 'r')
all_contents = filein.readlines()
print(all_contents)
filein.close()


for item in glob.glob("*.virus"):
 print(item)
