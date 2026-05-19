#include <iostream>
#include "tda_cola.h"
#include "TDA_Matriz.h"

using namespace std;

template <class T> Cola<T>::Cola() {}

// Calcula la posicion del siguiente elemento
template <class T> int Cola<T>::siguiente(int r) {
    return (r + 1) % MAXTAMQ;
}

// Inicializa las variables de la cola
template <class T> void Cola<T>::crearCola() {
    frente = 0;
    final = MAXTAMQ - 1; // Correccion aplicada
    num_elementos = 0;
}

// Verifica si la cola no tiene datos
template <class T> bool Cola<T>::estaVacia() {
    return frente == siguiente(final);
}

// Verifica si la cola alcanzo su limite
template <class T> bool Cola<T>::estaLlena() {
    return frente == siguiente(siguiente(final));
}

// Agrega un elemento al final de la cola
template <class T> bool Cola<T>::insertar(T x) {
    if (!estaLlena()) {
        final = siguiente(final);
        datos_cola[final] = x;
        num_elementos++;
        return true;
    }
    return false;
}

// Quita el elemento del inicio de la cola
template <class T> void Cola<T>::remover() {
    if (!estaVacia()) {
        frente = siguiente(frente);
        num_elementos--;
    }
}

// Muestra el primer elemento de la cola
template <class T> T Cola<T>::frenteCola() {
    if (estaVacia()) {
        throw "La cola esta vacia"; // Lanza error si no hay datos
    }
    return datos_cola[frente];
}

// Devuelve la cantidad de elementos actuales
template <class T> int Cola<T>::totalElementos() {
    return num_elementos;
}

template class Cola<int>;
template class Cola<float>;
template class Cola<char>;
template class Cola<posiciones>;