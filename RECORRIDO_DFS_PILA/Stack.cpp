#include "Stack.h"

#include <iostream>
#include "TDA_Matriz.h"

using namespace std;
template <class T> Stack<T>::Stack(){
    this ->TOP = 0;
}

template <class T> bool Stack<T>::Push(T elemento){
    if(IsFull()){
        return false;
    }else{
        arrStack[TOP] = elemento;
        TOP++;
        return true;
    }
}

template <class T> T Stack<T>::Pop(){
    if(IsEmpty()){
        throw "¡La pila esta vacia!";
    }
        return arrStack[--TOP];
}

template <class T> bool Stack<T>::IsEmpty(){
    return TOP == 0;
}

template <class T> bool Stack<T>::IsFull(){
    return TOP == SIZE;
}

template <class T> T Stack<T>::Top(){
    if(IsEmpty()){
        throw "¡La pila esta vacia!";
    }
    return arrStack[TOP - 1];
}

template <class T> int Stack<T>::Size(){
    return TOP;
}

template <class T> void Stack<T>::Empty(){
    this ->TOP = 0;
    cout<<"Pila totalmente vacia"<<endl;
}

template class Stack<int>;
template class Stack<float>;
template class Stack<char>;
template class Stack<posiciones>;
