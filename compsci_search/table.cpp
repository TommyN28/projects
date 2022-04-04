// -------------------------------------------------------
// Implementation file for Table class
// Tommy Ngo
// -------------------------------------------------------

#include "table.h"

//------------------------------------------------------------
// Purpose: Constructor function
//------------------------------------------------------------
Table::Table()
{
   
}

//------------------------------------------------------------
// Purpose: Copy function
//------------------------------------------------------------
Table::Table(const Table & table)
{
   
}
//------------------------------------------------------------
// Purpose: Destructor function
//------------------------------------------------------------
Table::~Table()
{
   
}

//------------------------------------------------------------
// Purpose: Read and print out info in "people.txt"
//------------------------------------------------------------
void Table::PrintTable()
{
   ifstream din;
   din.open("people.txt");
   if (din.fail())
   {
      cout << "Error: could not open file" << endl;
   }
   
   // Read and print data
   while (!din.eof())
   {
      string First, Last, Info;
      int Birth, Death;
      
      din >> First >> Last >> Birth >> Death;
      cout << "Name: " << First << " " << Last <<  endl;
      cout << "Birth: " << Birth << " " << endl <<  "Death: " << Death << endl;
      getline(din, Info);
      cout << "Info: " << Info << endl;
   }
   din.close();
}

//------------------------------------------------------------
// Purpose: Read info in "people.txt" and set the properties
//          in the an array
//------------------------------------------------------------
void Table::ReadTable()
{
   ifstream din;
   din.open("people.txt");
   if (din.fail())
   {
      cout << "Error: could not open file" << endl;
   }
   
   string First, Last, Info;
   int Birth, Death;
   // Read info into an array
   for (int i = 0; i < 21 && i < SIZE && !din.eof(); i++)
   {
      din >> First;
      people[i].SetfirstName(First);
      din >> Last;
      people[i].SetlastName(Last);
      din >> Birth;
      people[i].SetbirthYear(Birth);
      din >> Death;
      people[i].SetdeathYear(Death);
      getline(din, Info);
      people[i].Setcontribution(Info);
      people[i].Print();
   }
   din.close();
}

//-----------------------------------------------------------
// Search array of person objects for matching records
// using first name.
//-----------------------------------------------------------
void Table::SearchTable()
{
   // Prompt user for input
   string choice = "";
   while ((choice != "F") && (choice != "L") && (choice != "B") && (choice != "D"))
   {
      cout << endl << "Enter letter for type of search (F = First Name, L = Last Name, B = Birth Year, D = Death Year): " << endl;
      cin >> choice;
      if ((choice != "F") && (choice != "L") && (choice != "B") && (choice != "D"))
      {
         cout << "Error: invalid input" << endl;
      }
   }

   cout << "Enter search string/integer (please capitalize first letters in names): " << endl;
   string search;
   int searchint;
   if (choice == "F" or choice == "L")
   {
      cin >> search;
   }
   else
   {
      cin >> searchint;
   }
   
   // Search person array for matching data
   for (int i = 0; i < 21; i++)
   {
      if ((choice == "F") && (search == people[i].GetfirstName()))
      {
         cout << endl << "The search yielded this: " << endl;
	      people[i].Print();
      }
      if ((choice == "L") && (search == people[i].GetlastName()))
	   {
	      cout << endl << "The search yielded this: " << endl;
	      people[i].Print();
	   }
	   if ((choice == "B") && (searchint == people[i].GetbirthYear()))
	   {
	      cout << endl << "The search yielded this: " << endl;
	      people[i].Print();
	   }
	   if ((choice == "D") && (searchint == people[i].GetdeathYear()))
	   {
	      cout << endl << "The search yielded this: " << endl;
	      people[i].Print();
	   }
   }
   cout << endl << "Please run program again to search for another person.";
}
