// header file bst.hpp to declare your class
#ifndef BST_H
#define BST_H

#include "iostream" // cout, cin functions

namespace ENSC251_Lab3
{

  struct Node
  {
    int key;             // key value of the node
    struct Node *parent; // pointer to parent node
    struct Node *left;   // pointer to left subtree
    struct Node *right;  // pointer to right subtree
  };
  typedef struct Node *NodePtr;

  class BinarySearchTree
  {
  private:
    NodePtr root; // Private member variable which points to the root of the binary search tree

  protected:
    NodePtr minValue(NodePtr tempNode);                 // Function to find the minimum value based node in the binary
    NodePtr searchNode(NodePtr tempNode, int key);      // Overloaded search successor node fucntion
    NodePtr searchSuccessor(NodePtr tempNode, int key); // Overloaded search node fucntion

    NodePtr createNode(int key);                   // Key based node creation function
    NodePtr insertNode(NodePtr tempNode, int key); // Overloaded node insertion function
    NodePtr deleteNode(NodePtr tempNode, int key); // Overloaded node deletion function

    NodePtr deepCopy(NodePtr tempNode); // Function to recursively copy nodes in the binary search tree
    void DestroyTree(NodePtr tempNode); // Function to recursively delete nodes in the binary search tree

  public:
    BinarySearchTree();                                        // Default constructor
    BinarySearchTree(const BinarySearchTree &tree);            // Copy constructor
    BinarySearchTree &operator=(const BinarySearchTree &tree); // Overloded = operator for deepCopy
    ~BinarySearchTree();                                       // Destructor

    NodePtr getNode();                // Get root nodes
    NodePtr searchNode(int key);      // Search node fucntion based on given key
    NodePtr searchSuccessor(int key); // Search successor node fucntion based on given key

    bool insertNode(int key); // Node insertion
    bool deleteNode(int key); // Node deletion

    friend std::ostream &operator<<(std::ostream &outs, BinarySearchTree &Obj); // Overloded << for printing the binary search tree
  };

}

#endif