//-----------------------------------------------------------
// Programming Foundations 2
// Project 5
// Tommy Ngo
// Program to implement a 3-way merge sorting algorithm
//-----------------------------------------------------------

#include "sort.h"

int main()
{
   Sort s;
   
   // Get array parameters from user
   s.ArraySize();
   
   // Get start time
   clock_t time1=clock();
   
   // Create array and write unsorted data into text file
   int num[s.GetSize()];
   s.Random(num, s.GetRange());
   s.Write("Unsorted.txt", num);
   
   // Call user interface and sort, then write sorted data to file
   s.UserInt(num);
   s.Write("Sorted.txt", num);
   
   // Get end time
   clock_t time2=clock();
   double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
   cout << "Run time: " << run_time << " seconds\n"; 
   
   return 0;
}