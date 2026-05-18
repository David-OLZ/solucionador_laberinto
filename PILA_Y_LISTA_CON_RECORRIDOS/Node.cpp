#include "Node.h"

template <class T> Node<T>::Node(T d){
    this->data = d;
    this->next = this;
    this->previous = this;
}

template <class T> T Node<T>::getData(){
    return data;
}

template <class T> void Node<T>::setData(T data){
    this->data = data;
}

template <class T> Node<T>* Node<T>::getNext(){
    return next;
}

template <class T> void Node<T>::setNext(Node* n){
    next = n;
}

template <class T> Node<T>* Node<T>::getPrevious(){
    return previous;
}

template <class T> void Node<T>::setPrevious(Node* n){
    previous = n;
}

template class Node<int>;
template class Node<float>;
template class Node<char>;
template class Node<Posiciones>;
