/*
 * Title: hw6_1.cpp
 * Abstract: This program use radix sort alogrithm to sort the numbers from user
 *			
 * Author: Max Halbert
 * ID: 3636
 * Date: 12/14/2020
 */

#include <iostream>
#include <list>
#include <cmath>
using namespace std; 


// return the number of digits in a number
int getNumDigits(int num)
{
	int n = num;
	int count = 0;
	do
	{
		n = n / 10;
		count ++;
	} while (n > 0);
	return count;
}

// A utility function to print an array 
void print(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    cout << endl;
} 

// use radix sorting alogrithm, n is number of numbers to be sorted, m is the largest number
// arr start with unsorted but return as sorted
void radixSort(int *arr, int n, int m) 
{
   int index;
   int p = 1; // start with the one's place of the numbers
   int d;	// divisor for finding the digit value in a number
   list<int> bucket[10];    // there are 0-9 possible digit values - so 10 buckets 
   int numDigits = getNumDigits(m);
   
   // loop until all the digits are done
   while (p <= numDigits)
   {
   	  d = pow(10, p-1);	// divisor for pth place of a number
      for(int i = 0; i < n; i++) 
      {
         index = (arr[i] / d) % 10; //use the digit value of the number at pth place as index
         bucket[index].push_back(arr[i]);	// put it into the right bucket using index value
      }
      
      int count = 0;
  	  for(int j = 0; j < 10; j++) 
	  {
         //delete from linked lists and store back to array in order
         while(!bucket[j].empty()) 
         {
            arr[count++] = *(bucket[j].begin());
            bucket[j].erase(bucket[j].begin());
         }
         
	  }  
	  print(arr, n); // display the content in the array after each digit is used for sorting
      p++;  // next digit
   }
}
 


// Main Code 
int main() 
{ 
    int size;
    cin >> size;
    if (size <= 0) return 0;
    
    int array[size];
    int num;
    int max;

    // read the input and also look for the largest number in input
    cin >> max;	
    array[0] = max;
    for(int i = 1; i < size; i++)
    {
    	cin >> num;
    	array[i] = num;
    	if (max < num) max = num;
    }
    // Do the radix sorting of the input number
    radixSort(array, size, max);
    
    return 0; 
}