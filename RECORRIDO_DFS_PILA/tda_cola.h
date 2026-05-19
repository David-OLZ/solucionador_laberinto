#ifndef TDA_COLA_H
#define TDA_COLA_H

#include <iostream>

using namespace std;

// Cambio de tipo de dato a char y capacidad aumentada
typedef char TIPO_DE_DATO;
const int MAXTAMQ = 100;

class Cola {
private:
    int frente;
    int final;
    int num_elementos;
    TIPO_DE_DATO datos_cola[MAXTAMQ];

public:
    Cola();
    int siguiente(int r);
    void crearCola();
    bool estaVacia();
    bool estaLlena();
    bool insertar(TIPO_DE_DATO x);
    void remover();
    TIPO_DE_DATO frenteCola();
    int totalElementos();
};

#endif