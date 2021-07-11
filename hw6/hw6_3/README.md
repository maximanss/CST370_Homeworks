# HW 6 Problem 3

**Write a C++ (or Java) program called hw6_3.cpp (or hw6_3.java) that implements the Floyd’s
algorithm to display all-pairs shortest paths as we covered in the class.**

Input format: This is a sample input from a user.

4
	
0 -1 3 -1
	
2 0 -1 -1
	
-1 7 0 1
	
6 -1 -1 0
	
The first line (= 4 in the example) indicates that there are four vertices in the input graph. 
Then the following 4 lines present distance between all pairs. Note that the value –1 indicates the infinity.
	
1. Sample Run 0: Assume that the user typed the following lines
	
	4
	
	0 -1 3 -1
	
	2 0 -1 -1
	
	-1 7 0 1
	
	6 -1 -1 0

	This is the correct output. In the class, we drew all five matrices such as D(0), D(1), D(2), D(3), and D(4). For
the homework, just present the last matrix (= D(4)).

	0 10 3 4

	2 0 5 6
	
	7 7 0 1
	
	6 16 9 0
	
2. Sample Run 1: Assume that the user typed the following lines

	3

	0 2 -1

	-1 0 2

	2 -1 0

	This is the correct output.

	0 2 4

	4 0 2

	2 4 0
	
	
