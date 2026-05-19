#ifndef NODE_H
#define NODE_H
#include "TDA_Matriz.h"

template <class T> class Node{
private:
    T data;
    Node<T>* next;
    Node<T>* previous;
public:
    Node(T data);

    T getData();
    void setData(T data);

    Node<T>* getNext();
    void setNext(Node<T>* n);
    Node<T>* getPrevious();
    void setPrevious(Node<T>* n);
};

#endif // NODE_H
