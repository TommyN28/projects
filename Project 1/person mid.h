#ifndef PERSON_H
#define PERSON_H
//-----------------------------------------------------------
// Purpose: Header file for the Person class.
//          This class is designed to store five pieces of 
//          information describing a famous person.  
// Author:  Tommy Ngo
//-----------------------------------------------------------
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
   // Constructor methods
   Person();
   Person(const Person & person);
   ~Person();

   // Get and Set methods
   // TO BE ADDED
   void SetfirstName(const string fName);
   void SetlastName(const string lName);
   void SetbirthYear(const int byear);
   void SetdeathYear(const int dyear);
   void Setcontribution(const string contribute);
   
   string GetfirstName() const;
   string GetlastName() const;
   int GetbirthYear() const;
   int GetdeathYear() const;
   string Getcontribution() const;

   // Other methods
   // TO BE ADDED
   void Print(const string file);
   // Possibly unused:
   //void Read(const string file);

private:
   // Object attributes
   // TO BE ADDED
   string firstName;
   string lastName;
   int birthYear;
   int deathYear;
   string contribution;
   
};
#endif