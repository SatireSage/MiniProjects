// bst.cpp to implement your class
#include "bst.hpp"
#include <queue>    //queue
#include <iostream> // cout, cin functions

namespace ENSC251_Lab3
{
    // Default Constructor
    BinarySearchTree::BinarySearchTree()
    {
        root = nullptr;
    }

    // Default Destructor
    BinarySearchTree::~BinarySearchTree()
    {
        // Call the Destroying function on root to delete all nodes in the tree
        DestroyTree(root);
    }

    // Recursive Destroying function to delete all the binary search tree node by node
    void BinarySearchTree::DestroyTree(NodePtr tempNode)
    {
        if (tempNode != nullptr)
        {
            DestroyTree(tempNode->left);  // Recusively destroy the left branch
            DestroyTree(tempNode->right); // Recusively destroy the right branch
            tempNode = nullptr;           // Set node value to NULL
            delete tempNode;              // Delete the node
        }
    }

    // Copy constructor for binary search tree
    BinarySearchTree::BinarySearchTree(const BinarySearchTree &tree)
    {
        root = nullptr;             // Set root to NULL
        root = deepCopy(tree.root); // Call deepCopy function to create a deep copy of the tree
    }

    // Overloading the = operator for copying tree
    BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &tree)
    {
        if (&tree != this) // When the left and right sides are not the same object
        {
            root = nullptr;             // Set root to NULL
            root = deepCopy(tree.root); // Call deepCopy function to create a deep copy of the tree
        }
        return *this; // then return the object
    }

    // deepCopy function to make a deep copy of the binary search tree
    NodePtr BinarySearchTree::deepCopy(NodePtr tempNode)
    {
        // Make a new struct
        NodePtr copyNode = new Node;
        if (tempNode == nullptr)
        {
            return nullptr; // return NULL when node is NULL
        }
        else
        {
            // while the node isn't NULL we copy the nodes and their values recursively
            copyNode->key = tempNode->key;               // Copy key values
            copyNode->left = deepCopy(tempNode->left);   // Recusively copy left nodes
            copyNode->right = deepCopy(tempNode->right); // Recusively copy right nodes
            // Copy the parent nodes
            if (copyNode->left != nullptr)
            {
                copyNode->left->parent = copyNode; // Copy parent for left node
            }
            if (copyNode->right != nullptr)
            {
                copyNode->right->parent = copyNode; // Copy parent for right node
            }
        }
        // return the deep copy
        return copyNode;
    }

    // Get function to retrive root
    NodePtr BinarySearchTree::getNode()
    {
        return root;
    }

    // Calls the overloded seachNode function with a copy of root
    NodePtr BinarySearchTree::searchNode(int key)
    {
        if (key >= 0)
        {
            NodePtr search = getNode();
            search = searchNode(search, key); // Calls the overloded search function
            return search;                    // returns the copy of the node looked up
        }
        else
        {
            std::cout << "Please enter a positive number. Returning to main menu." << std::endl;
            return nullptr;
        }
    }

    // Overloded seachNode function with a copy of root and key as paramaters
    NodePtr BinarySearchTree::searchNode(NodePtr tempNode, int key)
    {
        if (tempNode == nullptr)
        {
            std::cout << "\nKey does not exist.";
            return nullptr; // return NULL since node does not exist
        }
        else if (key > tempNode->key) // We go down the right branch if the key value is greater than the nodeKey value
        {
            return searchNode(tempNode->right, key); // Recusively searches the right branch/nodes
        }
        else if (key < tempNode->key) // We go down the left branch if the key value is less than the nodeKey value
        {
            return searchNode(tempNode->left, key); // Recusively searches the left branch/nodes
        }
        else
        {
            return tempNode; // When key == nodeKey we return that node
        }
    }

    // Function to return the minimum node value
    NodePtr BinarySearchTree::minValue(NodePtr tempNode)
    {
        NodePtr currentNode = tempNode;
        // We go down the left to find the leftmost leaf (i.e until we reach NULL for current->left)
        while (currentNode->left != nullptr)
        {
            currentNode = currentNode->left;
        }
        return currentNode; // return the leftmost node
    }

    // searchSuccessor function to retrive the successor node based on key value
    NodePtr BinarySearchTree::searchSuccessor(int key)
    {
        if (key >= 0)
        {
            NodePtr search = getNode();
            NodePtr successor = searchSuccessor(search, key); // Calls the overloded searchSuccessor function
            if (successor == nullptr)
                std::cout << "No successor Found.";
            return successor;
        }
        else
        {
            std::cout << "Please enter a positive number. Returning to main menu." << std::endl;
            return nullptr;
        }
    }

    // Overloaded searchSuccessor function which takes a copy of root and key as paramaters
    NodePtr BinarySearchTree::searchSuccessor(NodePtr tempNode, int key)
    {
        NodePtr current = searchNode(tempNode, key); // looks for the node in root with provided key value
        if (current == nullptr)
            return nullptr;            // return NULL if node doesn't exist
        if (current->right != nullptr) // If right branch of node is not NULL
        {
            return minValue(current->right); // We recursively go down the right branch to find the leftmost node
        }
        else
        {
            NodePtr successor = nullptr;    // We create a NULL node pointer called successor
            NodePtr predecessor = tempNode; // We copy root topic node pointer called predecessor
            while (predecessor != current)  // While the predecessor node doesn't have the same value as our current node
            {
                if (current->key < predecessor->key) // if the current key value is less than its predecessors
                {
                    successor = predecessor;         // We set the successor as the predecessor
                    predecessor = predecessor->left; // the we go once to the left of the current predecessor value
                }
                else
                    predecessor = predecessor->right; // if the current key value is greated than its predecessors, we go once to the right
            }
            return successor; // we return the successor value
        }
    }

    // Helper function to create a new node based on a given key value
    NodePtr BinarySearchTree::createNode(int key)
    {
        NodePtr tempNode = new Node;                // Create new tempNode node
        tempNode->key = key;                        // Set the key
        tempNode->left = tempNode->right = nullptr; // Set the left and right branch to NULL
        tempNode->parent = nullptr;                 // Set the parent branch to NULL
        return tempNode;                            // return the new node
    }

    // Node insertion boolean function
    bool BinarySearchTree::insertNode(int key)
    {
        bool validity;
        if (key >= 0)
        {
            root = insertNode(root, key); // calls overloaded insertNode function
            if (root == nullptr)
            {
                validity = false;
            }
            else
            {
                validity = true;
            }
        }
        else
        {
            std::cout << "Please enter a positive number. Returning to main menu." << std::endl;
            validity = false;
        }
        return validity;
    }

    // Node insertion overloaded function
    NodePtr BinarySearchTree::insertNode(NodePtr tempNode, int key)
    {
        if (tempNode == nullptr) // if the node doesn't exist
        {
            std::cout << "Insertion of key: " << key << " successful!\n";
            return createNode(key); // we create a new node with the key
        }
        if (key < tempNode->key) // if the key value is less than the nodeKey value
        {
            // node key recusrively goes to left branch of the tree
            NodePtr leftchild = insertNode(tempNode->left, key);
            tempNode->left = leftchild;
            leftchild->parent = tempNode;
        }
        else if (key > tempNode->key) // if the key value is greater than the nodeKey value
        {
            // node key recusrively goes to right branch of the tree
            NodePtr rightchild = insertNode(tempNode->right, key);
            tempNode->right = rightchild;
            rightchild->parent = tempNode;
        }
        else
        {
            // the node with key value already exist
            std::cout << "The node with the key " << key << " already exists.";
        }
        return tempNode;
    }

    // Node deletion boolean function
    bool BinarySearchTree::deleteNode(int key)
    {
        bool validity;
        if (key >= 0)
        {
            root = deleteNode(root, key); // calls overloaded insertNode function
            if (root == nullptr)
            {
                validity = false;
            }
            else
            {
                validity = true;
            }
        }
        else
        {
            std::cout << "Please enter a positive number. Returning to main menu." << std::endl;
            validity = false;
        }
        return validity;
    }

    // Node deletion overloaded function
    NodePtr BinarySearchTree::deleteNode(NodePtr tempNode, int key)
    {
        if (tempNode == nullptr) // Node does not exist
        {
            std::cout << "The node with the key " << key << " does not exist.";
            return nullptr;
        }
        if (tempNode->key == key) // when Node found
        {
            if (tempNode->left == nullptr && tempNode->right == nullptr) // if node is a eaf node
            {
                tempNode = nullptr; // Set node to NULL
            }
            else if (tempNode->left == nullptr && tempNode->right != nullptr) // node has one child to the right
            {
                // we shift the child node to the parent node
                tempNode->right->parent = tempNode->parent;
                free(tempNode); // Free the memory allocated
                tempNode = tempNode->right;
            }
            else if (tempNode->left != nullptr && tempNode->right == nullptr) // node has one child to the left
            {
                // we shift the child node to the parent node
                tempNode->left->parent = tempNode->parent;
                free(tempNode); // Free the memory allocated
                tempNode = tempNode->left;
            }
            else // node with only two children
            {
                NodePtr temp = searchSuccessor(key);                         // find its immediate successor node
                int successorKey = temp->key;                                // we copy the key value
                tempNode->key = successorKey;                                // to this node
                tempNode->right->parent->key = tempNode->key;                // update left branch's parent
                tempNode->left->parent->key = tempNode->key;                 // update left right's parent
                tempNode->right = deleteNode(tempNode->right, successorKey); // delete the immediate successor node
            }
        }
        else if (tempNode->key < key) // We go down the left branch if the key value is greater than the nodeKey value
        {
            tempNode->right = deleteNode(tempNode->right, key); // Recusively searches the right branch/nodes
        }
        else // We go down the left branch if the key value is less than the nodeKey value
        {
            tempNode->left = deleteNode(tempNode->left, key); // Recusively searches the left branch/nodes
        }
        return tempNode; // return root
    }

    std::ostream &operator<<(std::ostream &outs, BinarySearchTree &Obj)
    {
        NodePtr rootCopy = Obj.getNode(); // Creates a copy of the root
        NodePtr const spacer = nullptr;   // Creates a newline node set to NULL
        if (rootCopy == nullptr)          // if there the root node is empty
        {
            return outs; // return nothing
        }
        std::queue<NodePtr> que; // creates the queue
        que.push(rootCopy);      // adds the root to the queue
        que.push(spacer);        // adds newline to the queue
        while (true)             // iterates through the tree
        {
            NodePtr currentNode = que.front();
            que.pop();
            if (currentNode != spacer) // If newline is not first in the queue
            {
                outs << currentNode->key << ' '; // Prints the current key
                if (currentNode->parent != nullptr)
                {
                    // Prints the parent of the node, if it exists
                    if (currentNode->key < currentNode->parent->key)
                    {
                        outs << "(" << currentNode->parent->key << "->left), "; // Prints the left branches/nodes
                    }
                    else
                    {
                        outs << "(" << currentNode->parent->key << "->right), "; // Prints the right branches/nodes
                    }
                }
                if (currentNode->left != nullptr)
                {
                    que.push(currentNode->left); // Push next left node to the queue if it exists
                }
                if (currentNode->right != nullptr)
                {
                    que.push(currentNode->right); // Push next right node to the queue if it exists
                }
            }
            else // If spacer is first in the queue, then starts a new line
            {
                outs << std::endl;
                if (que.empty()) // will break if the queue is empty
                    break;
                que.push(spacer); // if the queue is not empty will add spacer to the queue
            }
        }
        return outs;
    }
}