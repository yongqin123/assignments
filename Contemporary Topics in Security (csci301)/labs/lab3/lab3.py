import subprocess
p1 = subprocess.call("ls -l | grep py", shell=True) 
