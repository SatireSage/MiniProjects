#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <cstdlib>

template <class T>
class Stack
{
protected:
    struct StackFrame
    {
        T data;
        StackFrame *link;
    };
    typedef StackFrame *StackFramePtr;

public:
    Stack();
    Stack(const Stack &stack);
    void operator=(const Stack &stack);
    ~Stack();

    StackFramePtr peek();
    void push(T NewValue);
    T pop();
    bool empty() const;
    void reverse();
    void botStackPush(T topValue);

private:
    StackFramePtr top;
};

#endif