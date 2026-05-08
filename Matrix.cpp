#include "Matrix.h"
#include <cstdlib> // rand
#include <ctime>   // time

template <class T>
Matrix<T>::Matrix(int r, int c) {
    rows = r; //asigna numero de filas
    cols = c; //asigna numero de columnas

    data = new T*[rows]; //asigna el espacio para una lista vertical que su valor depende de rows

    for (int i = 0; i < rows; i++) {
        data[i] = new T[cols]; //importante , el valor de cols lo asignamos en main
    }
}

// Destructor
template <class T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < rows; i++) { //este ciclo libera la memoria usada , primero borra las filas
        delete[] data[i];
    }
    //borra la lista vertical
    delete[] data;
}

// Set
template <class T>
void Matrix<T>::set(int i, int j, T value) {
    data[i][j] = value;
}

// Get
template <class T>
T Matrix<T>::get(int i, int j) const {
    return data[i][j]; //lee el valor que hay en la fila n y columna m
}

// Print
template <class T>
void Matrix<T>::print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << data[i][j] << " "; //imprime en forma de matriz
        }
        cout << endl;
    }
}


//genera matriz
template <class T>
void Matrix<T>::generarLaberinto(double prob) {
    // 1. Generar aleatorio
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double r = (double)rand() / RAND_MAX;
            data[i][j] = (r < prob) ? 1 : 0;
        }
    }
    // 2. Forzar camino
    int i = 0, j = 0;
    while (i < rows-1 || j < cols-1) {

        data[i][j] = 0;

        if (i == rows-1) {
            j++;
        }
        else if (j == cols-1) {
            i++;
        }
        else {
            // avanzar aleatoriamente derecha o abajo
            if (rand() % 2 == 0)
                i++;
            else
                j++;
        }
    }
    // Asegurar salida
    data[rows-1][cols-1] = 0;
}





template class Matrix<float>;
template class Matrix<int>;
template class Matrix<char>;
