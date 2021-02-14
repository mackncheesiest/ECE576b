Group 6: Joshua Mack, Dhruv Gajaria, Sahil Hassan, Michael Inouye
ECE 576B
Homework 2: Introduction to modeling with SystemC

Build & Run Instructions

Hello World:
To run the SystemC hello world example, run the following commands:
cd HW2
cd hello_world
make

The output executable will be named 'hello_systemc.out'. To run it, use the following:
./hello_systemc.out

Part 1: Untimed SAD Component
To run Part 1, run the following commands:
cd HW2
cd part1
make

The output executable after the make is named 'sad_part1.out'. A pre-generated memory initialization file has been included named 'input_sad' to run with this part. To run the executable using the sample dataset, use the following:
./sad_part1.out input_sad

Part 2: Mixed Cycle-Accurate and Approximate-Timed SAD Model
To run Part 2, run the following commands:
cd HW2
cd part2
make

The output executable after the make is named 'sad_part2.out'. A pre-generated memory initialization file has been included named 'input_sad' to run with this part (same as before). To run the executable using the sample dataset, use the following:
./sad_part2.out input_sad

