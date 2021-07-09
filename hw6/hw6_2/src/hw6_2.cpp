/*
 * Title: hw6_2.cpp
 * Abstract: This program use dynamic programming to solve a coin-collecting problem 
 *			from a given board (some spots are not accessible):
 *			1. To find the maximum coins can be collected
 *			2. To show the path that will give maximum coins collection
 *			
 * Author: Max Halbert
 * ID: 3636
 * Date: 12/14/2020
 */
 
 #include <iostream>
 #include <vector>
 using namespace std;
 
 #define SIZE 26	// size of 2D array but maximum size of the board is 25x25
 #define BLOCKED -1	// for spot that is not accessible
 
 // dynamic coin collecting algorithm to find the maximum coins can be collected
 // in each spot on the board
 void coinHunt(int arr[SIZE][SIZE], int rows, int cols)
 {
 	int top, left;
 	for(int i = 1; i <= rows; i++)
 	{
 		for(int j = 1; j <= cols; j++)
 		{
 			if(arr[i][j] != BLOCKED)
 			{
 				
 				left = arr[i][j-1];	// number of coins collected in the left spot
 				top = arr[i-1][j];	// number of coins collected in the spot above
 				if (left == BLOCKED && top == BLOCKED)
 				{
 					// left spot and spot above are inaccessible, then this spot will be inaccessible
 					arr[i][j] = BLOCKED;	
 				}
 				else if (top > left)
 				{
 					// spot above have more coins than the left spot, then add the coins from above
 					arr[i][j] += top;
 					
 				}
 				else 
 				{
 					arr[i][j] += left;
 				}

 			}
 			//cout << arr[i][j] << " ";
 		}
 		//cout << endl;
 	}
 }
 
 // data structure to store the spot location
 struct location_t
 {
 	int r;	// row number
 	int c;	// column number
 	
 	location_t(int i, int j)
 	{
 		r = i;
 		c = j;
 	}
 };
 
 // find the coin-collecting path by backtracking, take left move as preference if left or above are the same
 bool findPath(int array[SIZE][SIZE], int rows, int cols, vector<location_t *> &p)
 {
 	int i = rows;
 	int j = cols;
 	int current, top, left; // number of coin in current, top and left spots
 	location_t *spot;
 	
 	if (array[rows][cols] == BLOCKED)
 		return false; // unreacheable, no path
 		
 	spot = new location_t(rows, cols);
 	p.push_back(spot);
 	
 	if (rows == 1 && cols == 1)  // only 1 x 1 board
 		return true;
 		
 	// start path from end spot until back to the starting position	
 	while (i != 1 || j != 1)
 	{
 		current = array[i][j];
 		//cout << "(" << i << "," << j << ") ";
 		top = array[i-1][j];
 		left = array[i][j-1];
 		
 		
 		if (top == BLOCKED && left == BLOCKED)
 			return false; // no path
 			
 		if (top > left)
 		{
 			// go up if the above spot has more coins
 			i = i - 1;
 			
 		}
 		else
 		{
 			// go left
 			j = j -1;
 			
 		}
 		spot = new location_t(i, j);
	 	p.push_back(spot);	// store the selected spot in a stack
 	}
 	return true; // there is a path
 }
 
 // print the number of maximum coins collected and the selected path
 void print(vector<location_t *> &path, int numCoins)
 {
 	cout << "Max coins:" << numCoins << endl;
 	cout << "Path:";
 	location_t *spot = path.back();
	cout << "(" << spot->r << "," << spot->c << ")";
 	path.pop_back();
 	delete spot;
 	while (!path.empty())
 	{
 		spot = path.back();
 		cout << "->" <<  "(" << spot->c << "," << spot->r << ")";
 		path.pop_back();
 		delete spot;
 	}
 	cout << endl;
 }
 
 
 int main()
 {
 	int cols;
 	int rows;
 	cin >> cols;
 	cin >> rows;
 	int array[SIZE][SIZE];
 	vector<location_t *> path;
 	
 	int coins;
 	// initialize all the spots above and left of the board as blocked
 	for (int i = 0; i <= rows; i++)
 	{
 		array[i][0] = BLOCKED;
 	}
 	for (int j = 0; j <= cols; j++)
 	{
 		array[0][j] = BLOCKED;
 	}
 	array[1][0] = 0; // entry point to the board is not blocked
 	
 	// read the initial content of the board
 	for(int i = 1; i <= rows; i++)
 	{
 		for(int j = 1; j <= cols; j++)
 		{
 			cin >> coins;
 			if (coins == 2)
 			{	// spot is inaccessible, so set it as blocked
 				coins = BLOCKED;
 			}
 			array[i][j] = coins;
 			//cout << array[i][j] << " ";
 		}
 		//cout << endl;
 	}
 	
 	coinHunt(array, rows, cols);
 	
 	if (findPath(array, rows, cols, path))
 	{
 		print(path, array[rows][cols]);
 	} else
 	{
 		cout << "Max coins:" << 0 << endl;
 		cout << "Path:" << endl;
 	}
 	
 	return 0;
 }