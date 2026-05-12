#ifndef MATRIX_H
#define MATRIX_H


#include <iostream>
using namespace std;

template <class T>
class Matrix {
private:
    int rows; // filas
    int cols; // columas
    T** data; //puntero doble a data para matriz dinamica, apunta a rows y a cols
public:

    Matrix(int r, int c); //constructor , le damos dos enteros para la matriz
    ~Matrix(); // destrutor
    void set(int i, int j, T value); // set para modificar los datos privados
    T get(int i, int j) const; //get para leer los datos privados
    void print() const; //imprimir la matriz

    void generarLaberinto(double prob = 0.9); // generar la matriz aleatoria, el parametro prob definira la probailidad de generar 1s en la matriz

};

#endif // MATRIX_H
