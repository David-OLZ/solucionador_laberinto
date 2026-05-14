#include "TDA_Matriz.h"
#include <iostream>
using namespace std;

TDA_Matriz::TDA_Matriz(){
}

void TDA_Matriz::Create(int filas, int Columnas){
    this ->rows = filas;
    this ->columns = Columnas;
    this ->posicionColumna = 0;
    this ->posicionFila = 0;
}

void TDA_Matriz::Print(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

}

void TDA_Matriz::Initialize(int Value){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            matrix[i][j] = Value;
        }
    }
}

void TDA_Matriz::Set(int fila, int columna, int valor){
    matrix[fila][columna] = valor;
}

int TDA_Matriz::Get(int fila, int columna){
    return matrix[fila][columna];
}

int TDA_Matriz::Rows(){
    return rows;
}

int TDA_Matriz::Columns(){
    return columns;
}

void TDA_Matriz::movimientoAbajo(){
    if(posicionFila < Rows()){
        posicionFila++;
    }
}

void TDA_Matriz::movimientoArriba(){
    if(posicionFila - 1 >= 0){
        posicionFila--;
    }
}

void TDA_Matriz::movimientoDer(){
    if(posicionColumna < Columns()){
        posicionColumna++;
    }
}

void TDA_Matriz::movimientoIzq(){
    if(posicionColumna - 1 >= 0){
        posicionColumna--;
    }
}

void TDA_Matriz::ponerMarca(int x){
    matrix[posicionFila][posicionColumna] = x;
}
