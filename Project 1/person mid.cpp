// -------------------------------------------------------
// Implementation file for Person class
// Tommy Ngo
// -------------------------------------------------------

#include "person.h"

//------------------------------------------------------------
// Purpose: Constructor function
//------------------------------------------------------------
Person::Person()
{
   
}

//------------------------------------------------------------
// Purpose: Copy function
//------------------------------------------------------------
Person::Person(const Person & person)
{
   
}
//------------------------------------------------------------
// Purpose: Destructor function
//------------------------------------------------------------
Person::~Person()
{
   
}

//------------------------------------------------------------
// Purpose: Read AND print out info in "people.txt"
//------------------------------------------------------------
void Person::Print(const string file)
{
   ifstream din;
   din.open(file);
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
}

//------------------------------------------------------------
// Purpose: Set functions
//------------------------------------------------------------
void Person::SetfirstName(const string fName)
{
   firstName = fName;
}

void Person::SetlastName(const string lName)
{
   lastName = lName;
}

void Person::SetbirthYear(const int byear)
{
   birthYear = byear;
}

void Person::SetdeathYear(const int dyear)
{
   deathYear = dyear;
}

void Person::Setcontribution(const string contribute)
{
   contribution = contribute;
}

//------------------------------------------------------------
// Purpose: Get functions
//------------------------------------------------------------
string Person::GetfirstName() const
{
   return firstName;
}

string Person::GetlastName() const
{
   return lastName;
}

int Person::GetbirthYear() const
{
   return birthYear;
}

int Person::GetdeathYear() const
{
   return deathYear;
}

string Person::Getcontribution() const
{
   return contribution;
}
