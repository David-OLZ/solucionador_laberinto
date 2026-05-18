#include <iostream>
#include "tda_cola.h"

using namespace std;

Cola::Cola() {}

// Calcula la posicion del siguiente elemento
int Cola::siguiente(int r) {
    return (r + 1) % MAXTAMQ;
}

// Inicializa las variables de la cola
void Cola::crearCola() {
    frente = 0;
    final = MAXTAMQ - 1; // Correccion aplicada
    num_elementos = 0;
}

// Verifica si la cola no tiene datos
bool Cola::estaVacia() {
    return frente == siguiente(final);
}

// Verifica si la cola alcanzo su limite
bool Cola::estaLlena() {
    return frente == siguiente(siguiente(final));
}

// Agrega un elemento al final de la cola
bool Cola::insertar(TIPO_DE_DATO x) {
    if (!estaLlena()) {
        final = siguiente(final);
        datos_cola[final] = x;
        num_elementos++;
        return true;
    }
    return false;
}

// Quita el elemento del inicio de la cola
void Cola::remover() {
    if (!estaVacia()) {
        frente = siguiente(frente);
        num_elementos--;
    }
}

// Muestra el primer elemento de la cola
TIPO_DE_DATO Cola::frenteCola() {
    if (!estaVacia()) {
        return datos_cola[frente];
    }
    return '\0'; // Retorna nulo si la cola esta vacia
}

// Devuelve la cantidad de elementos actuales
int Cola::totalElementos() {
    return num_elementos;
}