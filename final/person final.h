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
   void SetfirstName(string fName);
   void SetlastName(string lName);
   void SetbirthYear(int byear);
   void SetdeathYear(int dyear);
   void Setcontribution(string contribute);
   
   string GetfirstName();
   string GetlastName();
   int GetbirthYear();
   int GetdeathYear();
   string Getcontribution();

   // Other methods
   void Print();
   void Read();

private:
   // Object attributes
   string firstName;
   string lastName;
   int birthYear;
   int deathYear;
   string contribution;
   
};
#endif