#include "Doble_Circular_Linked_List.h"

#include <stddef.h>
#include <iostream>
#include "TDA_Matriz.h"

using namespace std;

template <class T> Doble_Circular_Linked_List<T>::Doble_Circular_Linked_List(){
    size = 0;
    head = NULL;
}

template <class T>void Doble_Circular_Linked_List<T>::insertFirst(T data) {
    Node<T> *newNode = new Node<T>(data);
    if (head == NULL) {
        head = newNode;
        newNode->setNext(head);
        newNode->setPrevious(head);
    } else {

        Node<T> *ultimo = head->getPrevious();

        newNode->setNext(head);
        newNode->setPrevious(ultimo);

        ultimo->setNext(newNode);
        head->setPrevious(newNode);

        head = newNode;
    }
    size++;
}

template <class T> void Doble_Circular_Linked_List<T>::deleteList(){
    if (head == NULL){
        return;
    }
    head->getPrevious()->setNext(NULL);

    Node<T> *p = head;
    while (p != NULL) {
        Node<T> *aux = p;
        p = p->getNext();
        delete aux;
    }

    head = NULL;
    size = 0;
}

template <class T> bool Doble_Circular_Linked_List<T>::isEmpty(){
    return size == 0;
}

template <class T> void Doble_Circular_Linked_List<T>::insertAfter(Node<T> *previous, T data){
    if(previous == NULL){
        insertFirst(data);
        return;
    }

        Node<T> *newNode = new Node<T>(data);
        newNode->setNext(previous->getNext());
        newNode->setPrevious(previous);
        previous->getNext()->setPrevious(newNode);
        previous->setNext(newNode);
        size++;
}

template <class T> void Doble_Circular_Linked_List<T>::insertLast(T data){
    Node<T> *newNode = new Node<T>(data);
    if (head == NULL) {
        head = newNode;
        newNode->setNext(head);
        newNode->setPrevious(head);
    } else {

        Node<T> *ultimo = head->getPrevious();

        newNode->setNext(head);
        newNode->setPrevious(ultimo);

        ultimo->setNext(newNode);
        head->setPrevious(newNode);
    }
    size++;
}

template <class T> Node<T>* Doble_Circular_Linked_List<T>::get(int posicion){
    if(posicion < 0 || posicion >= size){
        return NULL;
    }
    Node<T> *actual = head;

    for(int i = 0; i < posicion; i++){
        actual = actual->getNext();
    }
    return actual;
}

template <class T> void Doble_Circular_Linked_List<T>::printForward(){
    if(head == NULL){
        return;
    }
    Node<T> *p = head;

    do{
        cout<<p->getData()<<endl;
        p = p->getNext();
    }while(p != head);
}

template <class T> void Doble_Circular_Linked_List<T>::printBackwards(){
    if(head == NULL){
        return;
    }
    Node<T> *p = head->getPrevious();

    do{
        cout << p->getData() << endl;
        p = p->getPrevious();
    } while(p != head->getPrevious());
}


template <class T> Doble_Circular_Linked_List<T>::~Doble_Circular_Linked_List(){
    cout<<"Destructor activado"<<endl;
    deleteList();
}

template <class T> int Doble_Circular_Linked_List<T>::Size(){
    return size;
}

template class Doble_Circular_Linked_List<int>;
template class Doble_Circular_Linked_List<char>;
template class Doble_Circular_Linked_List<float>;
template class Doble_Circular_Linked_List<posiciones>;
