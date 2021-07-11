# HW 6 Problem 2

**Write a C++ (or Java) program called hw6_2.cpp (or hw6_2.java) to collect maximum number of
coins on an n x m board which was covered in the class. However, the board has several inaccessible
cells in this problem. If you meet an inaccessible cell on the board, you cannot move to the cell because it
is not accessible.**

Input format: This is a sample input from a user.

4 4
0 2 1 1
0 1 2 1
0 0 1 2
1 2 0 1
	
The first line (= 4 and 4 in the example) indicates that the board size is 4 by 4. From the second line,
the configuration of the board is presented. The number 1 indicates that there is a coin on the cell,
while the number 0 means no coin. A cell with the number 2 indicates that the cell is not accessible.
For the homework, you can assume that the board size is less than or equal to 25 x 25.

1. Sample Run 0: Assume that the user typed the following lines

	4 4
	
	0 2 1 1
	
	0 1 2 1
	
	0 0 1 2
	
	1 2 0 1

	This is the correct output. Your program should display maximum coins and path to collect them. When
backtracking from the destination spot, if there is more than one optimal path, your solution should
always pick the path from the left, not from the top.

	Max coins:3
	
	Path:(1,1)->(1,2)->(2,2)->(2,3)->(3,3)->(3,4)->(4,4)

2. Sample Run 1: Assume that the user typed the following lines. Again, when backtracking from the
destination spot, your solution should always pick the path from the left, not from the top, if there is
more than one optimal path.

	4 5
	
	0 0 1 0
	
	0 1 1 0
	
	0 1 1 0
	
	1 1 0 0
	
	0 0 1 0 

	This is the correct output.
	
	Max coins:4
	
	Path:(1,1)->(1,2)->(2,2)->(2,3)->(2,4)->(2,5)->(3,5)->(4,5)
	
3. Sample Run 2: Assume that the user typed the following lines

	3 2

	1 2 1
	
	1 1 1
	
	This is the correct output.

	Max coins:4

	Path:(1,1)->(1,2)->(2,2)->(3,2)

4. Sample Run 3: Assume that the user typed the following lines

	4 2
	
	0 1 0 0
	
	1 1 2 0

	This is the correct output.
	
	Max coins:1

	Path:(1,1)->(2,1)->(3,1)->(4,1)->(4,2)
	