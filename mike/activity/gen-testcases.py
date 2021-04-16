import sys
import random

if len(sys.argv) != 2 :
	print("Pass number of test points as sole argument")
	sys.exit()
num_pts = int(sys.argv[1])

outfile = open("test-"+str(num_pts)+".ts", "w" )

for i in range(num_pts) :
	outfile.write(str(i/2)+";\n")
	hb = random.gauss(75, 3)
	outfile.write(str(hb)+";\n")
print("Generated test-"+str(num_pts)+".ts")
