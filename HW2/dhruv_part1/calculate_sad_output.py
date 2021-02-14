import numpy as np
import sys

NUM_BLOCKS=64
BLOCK_SIZE=64
INPUT1_ADDR=0
INPUT2_ADDR=4096
OUTPUT_ADDR=8192

MEM_SIZE=65789

if (len(sys.argv) != 2) :
	print("Error: Pass the sad data file path as the argument")
	sys.exit()

data_file = open(sys.argv[1], "r")
out_file = open("correct_sad_output.txt", "w")
data = []

for el in data_file :
	data.append(int(el))
	
data = np.asarray(data)
	
for block in range(NUM_BLOCKS) :
	sad = np.sum(np.abs(data[ INPUT1_ADDR + block * BLOCK_SIZE : INPUT1_ADDR + (block+1) * BLOCK_SIZE ] - 
		data[ INPUT2_ADDR + block * BLOCK_SIZE : INPUT2_ADDR + (block+1) * BLOCK_SIZE ]))
	print("SAD value for block", block, "is", sad)
	out_file.write(str(sad) + '\n')
out_file.close()
print("Dumped correct output to correct_sad_output.txt")