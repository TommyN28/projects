#ifndef MATH_H
#define MATH_H
//------------------------------------------------------------
// Header file for Math class
//------------------------------------------------------------

#include <cmath>
#include <iostream>
using namespace std;

class Math
{
   public:
      // Constructors/Deconstructors
      Math();
      Math(const Math & math);
      ~Math();
   
      // Operations methods
      void Exponent();
      void Add();
      void Sub();
      void Div();
      void Multi();
      void SRoot();
      void CRoot();
      
      // Misc methods
      void UserInt();
      
      // Get methods
      float getVar1() const;
      float getVar2() const;
      
      // Set methods
      void setVar1(float num1);
      void setVar2(float num2);
      
   private:
      float var1;
      float var2;
};

#endif