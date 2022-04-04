//------------------------------------------------------------
// Implementation of Math class
//------------------------------------------------------------

#include "math.h"

//------------------------------------------------------------
// Constructor
//------------------------------------------------------------
Math::Math()
{
   var1 = 0;
   var2 = 0;
}

//------------------------------------------------------------
// Copy Constructor
//------------------------------------------------------------
Math::Math(const Math & math)
{
   var1 = math.var1;
   var2 = math.var2;
}

//------------------------------------------------------------
// Deconstructor
//------------------------------------------------------------
Math::~Math()
{
   
}

//------------------------------------------------------------
// User interface
//------------------------------------------------------------
void Math::UserInt()
{
   cout << "Welcome to Tommy's simple calculator.\n";
   cout << "This calculator is currently designed to function"
         << " with only one or two variables.\n";
   cout << "Please select a command: \n";
   cout << "1. Exponent\n"
         << "2) Add\n"
         << "3. Subtract\n"
         << "4. Divide\n"
         << "5. Multiply\n"
         << "6. Square Root\n"
         << "7. Cube Root\n"
         << "0. Quit Program\n";
   
   int command;
   cin >> command;
   while (command != 0)
   {
      if (command == 1)
      {
         cout << "You chose Exponent\n";
         Exponent();
      }
      if (command == 2)
      {
         cout << "You chose Add\n";
         Add();
      }
      if (command == 3)
      {
         cout << "You chose Subtract\n";
         Sub();
      }
      if (command == 4)
      {
         cout << "You chose Divide\n";
         Div();
      }
      if (command == 5)
      {
         cout << "You chose Multiply\n";
         Multi();
      }
      if (command == 6)
      {
         cout << "You chose Square Root\n";
         SRoot();
      }
      if (command == 7)
      {
         cout << "You chose Cube Root\n";
         CRoot();
      }
      else if (command != 0)
      {
         cout << "\nError: Invalid input\n\n"; 
      }
      
      cout << "Please select a command: \n";
      cout << "1. Exponent\n"
         << "2) Add\n"
         << "3. Subtract\n"
         << "4. Divide\n"
         << "5. Multiply\n"
         << "6. Square Root\n"
         << "7. Cube Root\n"
         << "0. Quit Program\n";
         
      cin >> command;
   }
   
   cout << "Thank you for using this program.\n";
}

//------------------------------------------------------------
// Get methods
//------------------------------------------------------------
float Math::getVar1() const
{
   return var1;
}

float Math::getVar2() const
{
   return var2;
}

//------------------------------------------------------------
// Set methods
//------------------------------------------------------------
void Math::setVar1(float num1)
{
   var1 = num1;
}

void Math::setVar2(float num2)
{
   var2 = num2;
}

//------------------------------------------------------------
// Exponent Function
// Purpose: To raise a base number to a specified power
// Input: A base number and a power number
// Output: Base raised to power
//------------------------------------------------------------
void Math::Exponent()
{
   float input;
   
   cout << "Enter a base number: " << endl;
   cin >> input;
   setVar1(input);
   cout << "Enter an exponent: " << endl;
   cin >> input;
   setVar2(input);
   
   float result = pow(var1,var2);
   cout << "------------------------------\n";
   cout << var1 << " ^ " << var2 << " = " << result << endl;
   cout << "------------------------------\n";
}

//------------------------------------------------------------
// Addition Function
// Purpose: To add two separate numbers together
// Input: Two separate numbers
// Output: The sum of both numbers
//------------------------------------------------------------
void Math::Add()
{
   float input;
   
   cout << "Enter the first number: " << endl;
   cin >> input;
   setVar1(input);
   cout << "Enter the second number: " << endl;
   cin >> input;
   setVar2(input);
   
   float result = var1 + var2;
   cout << "------------------------------\n";
   cout << var1 << " + " << var2 << " = " << result << endl;
   cout << "------------------------------\n";
}

//------------------------------------------------------------
// Subtraction Function
// Purpose: To subtract one number from another
// Input: Two separate numbers
// Output: The difference of the second number subtracted
//          from the first
//------------------------------------------------------------
void Math::Sub()
{
   float input;
   
   cout << "Enter the first number: " << endl;
   cin >> input;
   setVar1(input);
   cout << "Enter the second number: " << endl;
   cin >> input;
   setVar2(input);
   
   float result = var1 - var2;
   cout << "------------------------------\n";
   cout << var1 << " - " << var2 << " = " << result << endl;
   cout << "------------------------------\n";
}

//------------------------------------------------------------
// Division Function
// Purpose: To divide one number with another
// Input: Two separate numbers
// Output: The quotient of the first number divided
//          by the second
//------------------------------------------------------------
void Math::Div()
{
   float input;

   cout << "Enter the first number: " << endl;
   cin >> input;
   setVar1(input);
   cout << "Enter the second number: " << endl;
   cin >> input;
   setVar2(input);
   
   float result = var1 / var2;
   cout << "------------------------------\n";
   cout << var1 << " / " << var2 << " = " << result << endl;
   cout << "------------------------------\n";
}

//------------------------------------------------------------
// Multiplication Function
// Purpose: To multiply one number with another
// Input: Two separate numbers
// Output: The product of the first number multiplied
//          by the second
//------------------------------------------------------------
void Math::Multi()
{
   float input;
   
   cout << "Enter the first number: " << endl;
   cin >> input;
   setVar1(input);
   cout << "Enter the second number: " << endl;
   cin >> input;
   setVar2(input);
   
   float result = var1 * var2;
   cout << "------------------------------\n";
   cout << var1 << " * " << var2 << " = " << result << endl;
   cout << "------------------------------\n";

}

//------------------------------------------------------------
// Square Root Function
// Purpose: To calculate the square root of a number
// Input: One number
// Output: The square root of the input number
//------------------------------------------------------------
void Math::SRoot()
{
   float input;
   
   cout << "Enter number: " << endl;
   cin >> input;
   setVar1(input);
   
   float result = sqrt(input);
   cout << "------------------------------\n";
   cout << "Square Root of " << var1 << " = " << result << endl;
   cout << "------------------------------\n";
}

//------------------------------------------------------------
// Cube Root Function
// Purpose: To calculate the cube root of a number
// Input: One number
// Output: The cube root of the input number
//------------------------------------------------------------
void Math::CRoot()
{
   float input;
   
   cout << "Enter number: " << endl;
   cin >> input;
   setVar1(input);
   
   float result = cbrt(input);
   cout << "------------------------------\n";
   cout << "Cube Root of " << var1 << " = " << result << endl;
   cout << "------------------------------\n";
}