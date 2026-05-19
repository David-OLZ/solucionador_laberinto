#ifndef STACK_H
#define STACK_H

const int SIZE = 50;

template <class T> class Stack{
    private:
    int TOP;
    T arrStack[SIZE];
public:
    Stack();
    bool Push(T element);
    T Pop();
    void Empty();
    T Top();
    bool IsEmpty();
    bool IsFull();
    int Size();
};



#endif // STACK_H
