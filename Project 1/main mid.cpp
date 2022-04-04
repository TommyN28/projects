// -------------------------------------------------------
// Programming Foundations 2
// Project 1
// Tommy Ngo
// Purpose: Program to store information about
//          famous computer scientists.
// -------------------------------------------------------

#include "person.h"
#include "table.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
   Person people;
   
   cout << "Enter file name: ";
   string filename = "";
   cin >> filename;
   
   people.Print(filename);
   
   return 0;
}