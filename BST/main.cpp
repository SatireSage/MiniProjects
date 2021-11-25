// main.cpp, put your driver code here,
// you can manipulate your class objects here
#include <iostream> //cin and cout
#include <sstream>  //string stream
#include <string>   //strings
#include <limits>   //numeric limit
#include "bst.hpp"

// Obtains integer input from user, checks if right data type input
// if not loop and ask for user input again until correct input
int Get_Number()
{
  std::string line;
  int user_input;
  while (std::getline(std::cin, line))
  {
    std::stringstream ss(line);
    if (ss >> user_input)
    {
      if (ss.eof())
      {
        break;
      }
    }
    std::cout << "Please enter a number as input only for the previous input: " << '\n'
              << ">> ";
  }
  return user_input;
}

using namespace ENSC251_Lab3; // Using appropriate namespace

int main()
{
  // Part1
  BinarySearchTree bst1;                                          // Create first BST object
  int keys[] = {10, 5, 15, 3, 7, 13, 18, 4, 6, 9, 8, 16, 19, 17}; // list of keys
  for (int key : keys)                                            // insert the keys into nodes in the first object
  {
    bst1.insertNode(key);
  }

  // Print first binary search tree
  std::cout << std::endl
            << "bst1:\n"
            << bst1 << std::endl;

  BinarySearchTree bst2, bst3; // Create more BST objects
  bst3 = bst2 = bst1;          // Use overloaded operator to create a deep copy of the first object

  // Print second binary search tree
  std::cout << "bst2:\n"
            << bst2 << std::endl;

  // Print third binary search tree
  std::cout << "bst3:\n"
            << bst3 << std::endl;

  BinarySearchTree bst4(bst3); // Create fourth BST object using copy constructor

  // Print fourth binary search tree
  std::cout << "bst4:\n"
            << bst4 << std::endl;

  // Delete the specified nodes
  // First tree:
  bst1.deleteNode(4);
  bst1.deleteNode(9);

  // Second tree:
  bst2.deleteNode(10);

  // Third tree:
  bst3.deleteNode(3);
  bst3.deleteNode(9);
  bst3.deleteNode(16);

  // Fourth tree:
  bst4.deleteNode(18);
  bst4.deleteNode(7);
  bst4.deleteNode(10);

  // Printing all trees after changes:
  std::cout << std::endl
            << "bst1:\n"
            << bst1 << std::endl;

  std::cout << "bst2:\n"
            << bst2 << std::endl;

  std::cout << "bst3:\n"
            << bst3 << std::endl;

  std::cout << "bst4:\n"
            << bst4 << std::endl;

  // Part2
  std::string exitCheck;
  while (true)
  {
    int menu_selector = 0; // resets menu selection value to 0 when loop begins

    if (menu_selector == 0) // main menu
    {
      std::cout << "-----------------------------------------------------------------------------------------------------------------------\n";
      std::cout << "Lab3: Welcome to 251 Binary Search Tree (BST)! Please select one of the following menu options:\n"
                << "Please select one of the folowing:\n"
                << "Select 1: to search a key in bst4\n"
                << "Select 2: to search a successor for a key in bst4\n"
                << "Select 3: to insert a key into bst4\n"
                << "Select 4: to delete a key in bst4\n"
                << "Select 5: to print out bst4\n"
                << "Select 6: to exit the program\n"
                << ">> ";
      menu_selector = Get_Number(); // get user_input
      std::cout << "-----------------------------------------------------------------------------------------------------------------------\n";
    }
    if (menu_selector < 1 || menu_selector > 6)
    {
      std::cout << "You have selected an invalid menu option. Returning to main menu.\n"; // If user selects invalid menu slection, print error and return to menu
    }

    if (menu_selector == 1)
    {
      int key;
      std::cout << "Please enter the key of the node to search:\n"
                << ">> ";
      key = Get_Number();                          // get user_input
      NodePtr searchResult = bst4.searchNode(key); // Search for node based on the key value
      if (searchResult != nullptr)
      {
        std::cout << "The search key is " << searchResult->key << std::endl; // Print the value of the looked up node
        if (searchResult->parent != nullptr)
        {
          std::cout << "The parent key is " << searchResult->parent->key << std::endl; // Print the parent key value of the looked up node
        }
        else
        {
          std::cout << "This node has no parent" << std::endl; // if no parent node
        }
        if (searchResult->left != nullptr)
        {
          std::cout << "The left child key is " << searchResult->left->key << std::endl; // Print the left child key value of the looked up node
        }
        else
        {
          std::cout << "There is no left child" << std::endl; // if no left child node
        }
        if (searchResult->right != nullptr)
        {
          std::cout << "The right child key is " << searchResult->right->key << std::endl; // Print the right child key value of the looked up node
        }
        else
        {
          std::cout << "There is no right child" << std::endl; // if no right child node
        }
      }
      std::cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
    }

    if (menu_selector == 2)
    {
      int key;
      std::cout << "Please enter the key of the successor node to search:\n"
                << ">> ";
      key = Get_Number();                                        // get user_input
      NodePtr searchSuccessorResult = bst4.searchSuccessor(key); // Search for successor node based on the key value
      if (searchSuccessorResult != nullptr)
      {
        std::cout << "The successor key is " << searchSuccessorResult->key << std::endl;
        if (searchSuccessorResult->parent != nullptr)
        {
          std::cout << "The parent key is " << searchSuccessorResult->parent->key << std::endl; // Print the parent key value of the looked up node
        }
        else
        {
          std::cout << "This node has no parent" << std::endl; // if no parent node
        }
        if (searchSuccessorResult->left != nullptr)
        {
          std::cout << "The left child key is " << searchSuccessorResult->left->key << std::endl; // Print the left child key value of the looked up node
        }
        else
        {
          std::cout << "There is no left child" << std::endl; // if no left child node
        }
        if (searchSuccessorResult->right != nullptr)
        {
          std::cout << "The right child key is " << searchSuccessorResult->right->key << std::endl; // Print the right child key value of the looked up node
        }
        else
        {
          std::cout << "There is no right child" << std::endl; // if no right child node
        }
      }

      std::cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
    }

    if (menu_selector == 3)
    {
      int key;
      std::cout << "Please enter the key you would like to insert as a node:\n"
                << ">> ";
      key = Get_Number();                    // get user_input
      bool insertion = bst4.insertNode(key); // Node insertion
      if (insertion)
      {
        std::cout << "\nPrinting updated bst4:\n" // Print the updated tree
                  << bst4 << std::endl;
      }
      else
      {
        std::cout << "Warning: An error occured. Please try again.";
        std::cout << "\nPrinting updated bst4:\n" // Print the updated tree
                  << bst4 << std::endl;
      };
      std::cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
    }

    if (menu_selector == 4)
    {
      int key;
      std::cout << "Please enter the key you would like to delete as a node:\n"
                << ">> ";
      key = Get_Number();                   // get user_input
      bool deletion = bst4.deleteNode(key); // Node deletion
      if (deletion)
      {
        std::cout << "\nPrinting updated bst4:\n" // Print the updated tree
                  << bst4 << std::endl;
      }
      else
      {
        std::cout << "Warning: An error occured. Please try again.";
        std::cout << "\nPrinting updated bst4:\n" // Print the updated tree
                  << bst4 << std::endl;
      };
      std::cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
    }

    if (menu_selector == 5)
    {
      std::cout << "\nPrinting complete bst4:\n" // Print the complete tree
                << bst4;
      std::cout << "-----------------------------------------------------------------------------------------------------------------------\n";
    }

    else if (menu_selector == 6) // exit program prommpt
    {
      std::cout << "Are you sure you wish to completely exit the program? Use Y/N (yes or no) to proceed.\n" // Ensures that the user wishes to exit the program
                << ">> ";
      std::cin >> exitCheck;
      if (exitCheck == "Y" || exitCheck == "y" || exitCheck == "YES" || exitCheck == "yes" || exitCheck == "Yes") // Various forms of the so called term "yes" to agree to the terms of exiting the program
      {
        std::cout << "\nExiting 251 BST!\n";
        break;
      }
      else if (exitCheck == "N" || exitCheck == "n" || exitCheck == "NO" || exitCheck == "no" || exitCheck == "No") // various forms of the so called term "no" to return to go through the main menu cycle from the beginiinng
      {
        std::cout << "\nReturning to main menu!\n";
        // clear input stream since last input was a string
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      else // If the Various forms of the so called term "yes" and "no" are not entered then we resort to force the person to go through the main menu cycle from the beginiinng
      {
        std::cout << "\nInput unrecognized: You are being returned to the main menu.\n";
        // clear input stream since last input was a string
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
    }
  }
  return 0;
}