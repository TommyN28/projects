//-----------------------------------------------------------
// Header file for Sort class
//-----------------------------------------------------------

#include <fstream>
#include <iostream>
using namespace std;

class Sort
{
   public:
      // Constructor/Deconstructor
      Sort();
      Sort(const Sort &sort);
      ~Sort();
      
      // Random integer generator method
      void Random(int data[], int range);
      
      // Merge Sort methods
      void ThreeMergeSort(int data[], int copy[], int low, int high);
      void StdMergeSort(int data[], int copy[], int low, int high);
      void merge_sort(int data[], int low, int high, int cmd);
      
      // Write to file method
      void Write(string name, int data[]);
      
      // Obtain array size user
      void ArraySize();
      
      // Get/Set array parameters
      void SetSize(int size);
      void SetRange(int range);
      int GetSize();
      int GetRange();
      
      // User interface
      void UserInt(int data[]);
      
   private:
      int ARRAY_SIZE;
      int RANGE;
};