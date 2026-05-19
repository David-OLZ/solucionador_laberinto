#ifndef TDA_COLA_H
#define TDA_COLA_H

#include <iostream>

using namespace std;

// Cambio de tipo de dato a char y capacidad aumentada
typedef char TIPO_DE_DATO;
const int MAXTAMQ = 100;

template <class T> class Cola {
private:
    int frente;
    int final;
    int num_elementos;
    T datos_cola[MAXTAMQ];

public:
    Cola();
    // Calcula la posicion del siguiente elemento
    int siguiente(int r);

    // Inicializa las variables de la cola
    void crearCola();

    // Verifica si la cola no tiene datos
    bool estaVacia();

    // Verifica si la cola alcanzo su limite
    bool estaLlena();

    // Agrega un elemento al final de la cola
    bool insertar(T x);

    // Quita el elemento del inicio de la cola
    void remover();

    // Muestra el primer elemento de la cola
    T frenteCola();

    // Devuelve la cantidad de elementos actuales
    int totalElementos();
};

#endif