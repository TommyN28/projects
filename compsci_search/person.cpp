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
// Purpose: Set functions
//------------------------------------------------------------
void Person::SetfirstName(string fName)
{
   firstName = fName;
}

void Person::SetlastName(string lName)
{
   lastName = lName;
}

void Person::SetbirthYear(int byear)
{
   birthYear = byear;
}

void Person::SetdeathYear(int dyear)
{
   deathYear = dyear;
}

void Person::Setcontribution(string contribute)
{
   contribution = contribute;
}

//------------------------------------------------------------
// Purpose: Get functions
//------------------------------------------------------------
string Person::GetfirstName()
{
   return firstName;
}

string Person::GetlastName()
{
   return lastName;
}

int Person::GetbirthYear()
{
   return birthYear;
}

int Person::GetdeathYear()
{
   return deathYear;
}

string Person::Getcontribution()
{
   return contribution;
}

//------------------------------------------------------------
// Purpose: Misc functions
//------------------------------------------------------------
void Person::Print()
{
   cout << "Name: " << firstName << " " << lastName <<  endl;
   cout << "Birth: " << birthYear << " " << endl <<  "Death: " << deathYear << endl;
   cout << "Info: " << contribution << endl;
}

void Person::Read()
{
   ifstream din;
   din.open("people.txt");
   if (din.fail())
   {
      cout << "Error: could not open file" << endl;
   }
   
   while (!din.eof())
   {
      string First, Last, Info;
      int Birth, Death;
      
      din >> First >> Last >> Birth >> Death;
      getline(din, Info);
   }
   din.close();
}
