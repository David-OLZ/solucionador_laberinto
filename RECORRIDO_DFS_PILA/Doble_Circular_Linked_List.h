#ifndef DOBLE_CIRCULAR_LINKED_LIST_H
#define DOBLE_CIRCULAR_LINKED_LIST_H


#include "Node.h"

template <class T> class Doble_Circular_Linked_List{
private:
    Node<T> *head;
    int size;
public:
    Doble_Circular_Linked_List();
    ~Doble_Circular_Linked_List();

    void insertFirst(T dato);
    void insertAfter(Node<T>* previous, T data);
    void insertLast(T dato);

    Node<T> *search(T data);
    Node<T> *get(int posicion);

    void deleteList();
    bool isEmpty();

    void printForward();
    void printBackwards();
    int Size();
};

#endif // DOBLE_CIRCULAR_LINKED_LIST_H
