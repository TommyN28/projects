// -------------------------------------------------------
// Programming Foundations 2
// Project 1
// Tommy Ngo
// Purpose: Program to store and search for information about
//          famous computer scientists.
// -------------------------------------------------------

#include "person.h"
#include "table.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
   // Declare Table object
   Table table;

   // Read and store info from "people.txt"
   table.ReadTable();
   
   // Initiate search
   table.SearchTable();

   return 0;
}
