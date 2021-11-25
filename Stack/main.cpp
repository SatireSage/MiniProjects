#include "stack.hpp"
#include "stack.cpp"
#include <iostream>
#include <cstdlib>
#include <sstream> //string stream
#include <string>
#include <limits> //numeric limit
#include <new>
using namespace std;

// Nuumeric error checking
int Get_Number()
{
     string line;
     int user_input;
     while (getline(cin, line))
     {
          stringstream ss(line);
          if (ss >> user_input)
          {
               if (ss.eof())
               {
                    break;
               }
          }
          cout << "Please enter a number as input only for the previous input: " << '\n'
               << ">> ";
     }
     return user_input;
}

// Print stack with recursion
template <class T>
void StackPrint(Stack<T> stack)
{
     if (stack.empty())
          return;
     T value = stack.peek()->data;
     stack.pop();
     cout << value << endl;
     StackPrint(stack);
     stack.push(value);
}

// Print palindrome stack with recursion
template <class T>
void PalindromePrint(Stack<T> stack)
{
     if (stack.empty())
          return;
     T value = stack.peek()->data;
     stack.pop();
     cout << value;
     PalindromePrint(stack);
     stack.push(value);
}

int main()
{
     // Testing from PDF
     Stack<int> sint1;
     int integers[] = {1, 2, 3, 4, 5, 6};
     for (int num : integers)
     {
          sint1.push(num);
     }
     Stack<int> sint2 = sint1;
     sint1.reverse();
     cout << "First int stack is: " << endl;
     StackPrint(sint1);
     cout << endl;
     cout << "Second int stack is: " << endl;
     StackPrint(sint2);
     cout << endl;

     Stack<double> sdouble1;
     double floats[] = {1.5, 2.5, 3.5, 4.5, 5.5, 6.5};
     for (double nums : floats)
     {
          sdouble1.push(nums);
     }
     cout << "First double stack is: " << endl;
     StackPrint(sdouble1);
     cout << endl;
     Stack<double> sdouble2(sdouble1);
     sdouble2.reverse();
     cout << "Top of second double stack is: " << endl;
     cout << sdouble2.peek()->data << endl;
     // End of Testing from PDF

     // Menu for palindrome
     string exitCheck;
     while (true)
     {
          int menu_selector = 0; // resets menu selection value to 0 when loop begins

          if (menu_selector == 0) // main menu
          {
               cout << "-----------------------------------------------------------------------------------------------------------------------\n";
               cout << "Lab4: Welcome to 251 Stack! Please select one of the following menu options:\n"
                    << "Please select one of the folowing:\n"
                    << "Select 1: to enter a string of your choice.\n"
                    << "Select 2: to exit the program.\n"
                    << ">> ";
               menu_selector = Get_Number(); // get user_input
               cout << "-----------------------------------------------------------------------------------------------------------------------\n";
          }
          if (menu_selector < 1 || menu_selector > 2)
          {
               cout << "You have selected an invalid menu option. Returning to main menu.\n"; // If user selects invalid menu slection, print error and return to menu
          }
          if (menu_selector == 1)
          {
               string input;
               Stack<char> Palindrome;
               cout << "Please enter a value of your choice:\n"
                    << ">> ";
               getline(cin, input);
               for (char charachter : input)
               {
                    Palindrome.push(charachter);
               }
               cout << endl
                    << "Palindrome is: " << endl;
               Palindrome.reverse();
               PalindromePrint(Palindrome);
               Palindrome.reverse();
               PalindromePrint(Palindrome);
               cout << endl;
          }
          else if (menu_selector == 2) // exit program prommpt
          {
               cout << "Are you sure you wish to completely exit the program? Use Y/N (yes or no) to proceed.\n" // Ensures that the user wishes to exit the program
                    << ">> ";
               cin >> exitCheck;
               if (exitCheck == "Y" || exitCheck == "y" || exitCheck == "YES" || exitCheck == "yes" || exitCheck == "Yes") // Various forms of the so called term "yes" to agree to the terms of exiting the program
               {
                    cout << "\nExiting 251 Stack!\n";
                    break;
               }
               else if (exitCheck == "N" || exitCheck == "n" || exitCheck == "NO" || exitCheck == "no" || exitCheck == "No") // various forms of the so called term "no" to return to go through the main menu cycle from the beginiinng
               {
                    cout << "\nReturning to main menu!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
               }
               else // If the Various forms of the so called term "yes" and "no" are not entered then we resort to force the person to go through the main menu cycle from the beginiinng
               {
                    cout << "\nInput unrecognized: You are being returned to the main menu.\n";
                    // clear input stream since last input was a string
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
               }
          }
     }
     return 0;
}