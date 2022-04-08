//-----------------------------------------------------------
// Implementation file for Sort class
//-----------------------------------------------------------

#include "sort.h"

//-----------------------------------------------------------
// Constructors/Deconstructors
//-----------------------------------------------------------
Sort::Sort()
{
   
}

Sort::Sort(const Sort &sort)
{
   
}

Sort::~Sort()
{
   
}

//-----------------------------------------------------------
// Random integer generator
//-----------------------------------------------------------
void Sort::Random(int data[], int range)
{
   // Put random data values into array
   for (int index = 0; index < ARRAY_SIZE; index++)
   {
      data[index] = rand() % range;
   }
}

//-----------------------------------------------------------
// 3-way merge sorter
//-----------------------------------------------------------
void Sort::ThreeMergeSort(int data[], int copy[], int low, int high)
{
   // Check terminating condition
   int range = high - low + 1;
   if (range > 1)
   {
      // Divide the array into 3 parts and sort each part
      int mid = low + (high-low) / 3;
      int mid2 = low + 2 * (high-low) / 3;

      ThreeMergeSort(data, copy, low, mid);
      ThreeMergeSort(data, copy, mid + 1, mid2);
      ThreeMergeSort(data, copy, mid2 + 1, high);
      
      // Initialize array indices
      int index1 = low;
      int index2 = mid + 1;
      int index3 = mid2 + 1;
      int index = 0;
      
      // Merge smallest data elements into copy array
      while ((index1 <= mid) && (index2 <= mid2) && (index3 <= high))
      {
	      if ((data[index1] >= data[index2]) && (data[index1] >=data[index3]))
	         copy[index++] = data[index1++];
	      else if ((data[index2] >=data[index1]) && (data[index2] >=data[index3]))
	         copy[index++] = data[index2++];
         else
            copy[index++] = data[index3++];
      }

      // Handling data in first and second sets
      while ((index1 <= mid) && (index2 <= mid2))
      {
         if (data[index1] > data[index2])
            copy[index++] = data[index1++];
         else
            copy[index++] = data[index2++];
      }
      // Handling data in second and third sets
      while ((index2 <= mid2) && (index3 <= high))
      {
         if (data[index2] > data[index3])
            copy[index++] = data[index2++];
         else
            copy[index++] = data[index3++];
      }
      // Handling data in first and third sets
      while ((index1 <= mid) && (index3 <= high))
      {
         if (data[index1] > data[index3])
            copy[index++] = data[index1++];
         else
            copy[index++] = data[index3++];
      }
      
      // Copy any remaining entries from the first set
      while (index1 <= mid)
	      copy[index++] = data[index1++];

      // Copy any remaining entries from the second set
      while (index2 <= mid2)
	      copy[index++] = data[index2++];
	      
      // Copy any remaining entries from the third set
      while (index3 <= high)
	      copy[index++] = data[index3++];

      // Copy data back from the temporary array
      for (index = 0; index < range; index++)
	      data[low + index] = copy[index];
   }
}

//-----------------------------------------------------------
// Standard binary merge sorter
//-----------------------------------------------------------
void Sort::StdMergeSort(int data[], int copy[], int low, int high)
{
   // Borrowed from "sort.cpp"
   // Check terminating condition
   int range = high - low + 1;
   if (range > 1)
   {
      // Divide the array and sort both halves
      int mid = (low + high) / 2;
      StdMergeSort(data, copy, low, mid);
      StdMergeSort(data, copy, mid + 1, high);

      // Initialize array indices
      int index1 = low;
      int index2 = mid + 1;
      int index = 0;

      // Merge smallest data elements into copy array
      while (index1 <= mid && index2 <= high)
      {
	      if (data[index1] > data[index2])
	         copy[index++] = data[index1++];
	      else
	         copy[index++] = data[index2++];
      }

      // Copy any remaining entries from the first half
      while (index1 <= mid)
	      copy[index++] = data[index1++];

      // Copy any remaining entries from the second half
      while (index2 <= high)
	      copy[index++] = data[index2++];

      // Copy data back from the temporary array
      for (index = 0; index < range; index++)
	      data[low + index] = copy[index];
   }
}

//------------------------------------------------------------------
// Copy array creator (borrowed from "sort.cpp")
//------------------------------------------------------------------
void Sort::merge_sort(int data[], int low, int high, int cmd)
{
   if (cmd == 1)
   {
      // Check terminating condition
      int range = high - low + 1;
      if (range > 1)
      {
         // Allocate memory and call merge_sort2
         int *copy = new int[range];
         ThreeMergeSort(data, copy, low, high);
         delete[]copy;
      }
   }
   
   if (cmd == 2)
   {
      // Check terminating condition
      int range = high - low + 1;
      if (range > 1)
      {
         // Allocate memory and call merge_sort2
         int *copy = new int[range];
         StdMergeSort(data, copy, low, high);
         delete[]copy;
      }
   }
}

//-----------------------------------------------------------
// Write to file method
//-----------------------------------------------------------
void Sort::Write(string name, int data[])
{
   // Open output file
   ofstream dout;
   dout.open(name.c_str());
   if (dout.fail())
      cout << "Error: could not open output file\n";

   // Write the data
   for (int i = 0; i < ARRAY_SIZE; i++)
   {
      if (i % 20 == 0)
         dout << endl;
      dout << data[i] << " ";
   }
   dout << endl;
   dout.close();
}

//-----------------------------------------------------------
// Obtain array parameters from user and create array
//-----------------------------------------------------------
void Sort::ArraySize()
{
   cout << "Enter a size for the array: " << endl;
   int n;
   cin >> n;
   SetSize(n);
   
   cout << "Enter a range for integers: " << endl;
   int r;
   cin >> r;
   SetRange(r);
}

//-----------------------------------------------------------
// Set array parameters
//-----------------------------------------------------------
void Sort::SetSize(int size)
{
   ARRAY_SIZE = size;
}

void Sort::SetRange(int range)
{
   RANGE = range;
}

int Sort::GetSize()
{
   return ARRAY_SIZE;
}

int Sort::GetRange()
{
   return RANGE;
}

//-----------------------------------------------------------
// User interface
//-----------------------------------------------------------
void Sort::UserInt(int data[])
{
   cout << "Please choose a sorting method: " << endl;
   cout << "1. 3-way Merge Sort" << endl
         << "2. Classic Binary Merge Sort" << endl;
   int choice;
   cin >> choice;
   while ((choice != 1) && (choice != 2))
   {
      cout << "Error: invalid input" << endl;
      cout << "Please choose a sorting method: " << endl;
      cout << "1. 3-way Merge Sort" << endl
         << "2. Classic Binary Merge Sort" << endl;
      cin >> choice;
   }
   
   if (choice == 1)
   {
      merge_sort(data, 0, ARRAY_SIZE, choice);
   }
   if (choice == 2)
   {
      merge_sort(data, 0, ARRAY_SIZE, choice);
   }
}
