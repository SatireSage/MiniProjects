#include "stack.hpp"
#include <iostream>

using namespace std;

template <class T>
Stack<T>::Stack() { top = NULL; }

// Initialize empty stack
template <class T>
Stack<T>::Stack(const Stack &stack)
{
    if (stack.top == NULL)
    {
        top = NULL;
    }
    else
    {
        try
        {
            StackFramePtr bottomStack = new StackFrame;
            StackFramePtr tempStack = stack.top;
            bottomStack->data = tempStack->data; // We assign the pointer data to the the temporary bottomStack
            top = bottomStack;                   // We set the top of the stack as the same as bottomStack
            tempStack = tempStack->link;         // Then we set link of the current stack to tempStack pointer
            while (tempStack != NULL)
            {
                try
                {
                    bottomStack->link = new StackFrame;  // A new node is made at the bottom of stack
                    bottomStack = bottomStack->link;     // Where we link node assigned to bottomStack
                    bottomStack->data = tempStack->data; // tempStack data is then assigned to bottomStack as well
                    tempStack = tempStack->link;         // Finally, a new tempStack pointer from tempStack link
                }
                catch (bad_alloc)
                {
                    cout << "\nWarning: Bad memory allocation.\n";
                }
            }
            bottomStack->link = NULL; // bottom of stack is finally initialized to nullptr
        }
        catch (bad_alloc)
        {
            cout << "\nWarning: Bad memory allocation.\n";
        }
    }
}

// Similar to copy constructor
template <class T>
void Stack<T>::operator=(const Stack &stack)
{
    if (stack.top == NULL)
    {
        top = NULL;
    }
    else
    {
        try
        {
            StackFramePtr bottomStack = new StackFrame;
            StackFramePtr tempStack = stack.top;
            bottomStack->data = tempStack->data;
            top = bottomStack;
            tempStack = tempStack->link;
            while (tempStack != NULL)
            {
                try
                {
                    bottomStack->link = new StackFrame;
                    bottomStack = bottomStack->link;
                    bottomStack->data = tempStack->data;
                    tempStack = tempStack->link;
                }
                catch (bad_alloc)
                {
                    cout << "\nWarning: Bad memory allocation.\n";
                }
            }
            bottomStack->link = NULL;
        }
        catch (bad_alloc)
        {
            cout << "\nWarning: Bad memory allocation.\n";
        }
    }
}

// Checks if stack is empty
template <class T>
bool Stack<T>::empty() const
{
    if (top == NULL)
        return true;
    else
        return false;
}

// Loops through stack and deletes all items
template <class T>
Stack<T>::~Stack()
{
    T topValue;
    while (!empty())
        topValue = pop();
}

// Returns value of top element in stack without affecting stack
template <class T>
typename Stack<T>::StackFramePtr Stack<T>::peek()
{
    return top;
}

// Pushes new item into stack
template <class T>
void Stack<T>::push(T insertVal)
{
    try
    {
        StackFramePtr tempStackPtr = new StackFrame;
        if (empty()) // inserts value, linked second items remains empty
        {
            tempStackPtr->data = insertVal;
            tempStackPtr->link = NULL;
            top = tempStackPtr;
        }
        else // changes linked value to previous top most item, insert new top element
        {
            tempStackPtr->data = insertVal;
            tempStackPtr->link = top;
            top = tempStackPtr;
        }
    }
    catch (bad_alloc)
    {
        cout << "\nWarning: Bad memory allocation.\n";
    }
}

// Removes top element
template <class T>
T Stack<T>::pop()
{
    if (empty()) // Checks if empty
    {
        cout << "\nWarning: Tried to pop an empty stack.\n Exiting program.";
        exit(1);
    }
    else // Removes top element, assigns second element to top
    {
        T result = top->data;
        StackFramePtr temp_ptr = top;
        top = top->link;
        delete temp_ptr;
        return result;
    }
}

/*
Big O notation of reverse function:
Reverse calls upon the following functions: empty, pop, reverse and botStackPush
Since, empty merely checks if the top of the stack is empty or not, it runs in real time. (i.e. O(1))
Similarly, pop consists of an if statement which also runs in real time O(1).
Reverse() and botbotStackPush are recursively called and both have a Big O of O(n) as they are linear in time complexity.
These are essentially nested within Reverse due to recursion therefore we multiply can multiply the notations together:
                O(n) * O(n) = O(n^2)
Hence, the overall time complexity of the reverse function is:
                O(1) + O(1) + O(1) + O(n^2)
                O(1) + O(n^2)
                O(n^2)
For we are only interested in the largest term,
    The time complexity is O(n^2)
*/

// Recursively loops to reverse stack
template <class T>
void Stack<T>::reverse()
{
    if (!empty())
    {
        T topValue = top->data;
        pop();
        reverse();
        botStackPush(topValue);
    }
}

// Helper function for reverse function to insert element into bottom of stack
template <class T>
void Stack<T>::botStackPush(T insertVal)
{
    if (empty())
        push(insertVal);
    else
    {
        T nextValue = top->data;
        pop();
        botStackPush(insertVal);
        push(nextValue);
    }
}