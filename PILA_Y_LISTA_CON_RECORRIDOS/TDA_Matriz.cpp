#include "TDA_Matriz.h"
#include <iostream>
#include"Doble_Circular_Linked_List.h"
#include "Stack.h"

using namespace std;

template <class T> TDA_Matriz<T>::TDA_Matriz(){
    this ->rows = 0;
    this ->columns = 0;
    this ->posicionColumna = 0;
    this ->posicionFila = 0;
}

template <class T> void TDA_Matriz<T>::Create(int filas, int Columnas){
    this ->rows = filas;
    this ->columns = Columnas;
    this ->posicionColumna = 0;
    this ->posicionFila = 0;
}

template <class T> void TDA_Matriz<T>::Print(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

}

template <class T> void TDA_Matriz<T>::Initialize(T Value){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            matrix[i][j] = Value;
        }
    }
}

template <class T> void TDA_Matriz<T>::Set(int fila, int columna,  T valor){
    matrix[fila][columna] = valor;
}

template <class T> T TDA_Matriz<T>::Get(int fila, int columna){
    return matrix[fila][columna];
}

template <class T> int TDA_Matriz<T>::Rows(){
    return rows;
}

template <class T> int TDA_Matriz<T>::Columns(){
    return columns;
}

/*
NO NECESARIO YA QUE SOLO REVISO PARA SABER SI ME PUEDO MOVER
Y ESTOS MOVIMIENTOS ME MUEVEN DE LUGAR EN VEZ DE REVISAR
template <class T> bool TDA_Matriz<T>::movimientoAbajo(){
    if(posicionFila < Rows() - 1){
        posicionFila++;
        return true;
    }
    return false;
}

template <class T> bool TDA_Matriz<T>::movimientoArriba(){
    if(posicionFila - 1 >= 0){
        posicionFila--;
        return true;
    }
    return false;
}

template <class T> bool TDA_Matriz<T>::movimientoDer(){
    if(posicionColumna < Columns() - 1){
        posicionColumna++;
        return true;
    }
    return false;
}

template <class T> bool TDA_Matriz<T>::movimientoIzq(){
    if(posicionColumna - 1 >= 0){
        posicionColumna--;
        return true;
    }
    return false;
}

template <class T> void TDA_Matriz<T>::ponerMarca(T x){
    matrix[posicionFila][posicionColumna] = x;
}
*/

template <class T> void TDA_Matriz<T>::DFS_path(TDA_Matriz& matriz_laberinto){
    Posiciones padre[100][100];
    TDA_Matriz visitado;
    visitado.Create(matriz_laberinto.Rows(), matriz_laberinto.Columns());
    visitado.Initialize(0);

    Doble_Circular_Linked_List<Posiciones> recorrido;  // ← Posiciones
    Stack<Posiciones> pila;

    Posiciones entrada = {0, 0};
    pila.Push(entrada);                                // ← Push mayúscula
    visitado.Set(0, 0, 1);

    while(!pila.IsEmpty()){
        Posiciones actual = pila.Top();
        pila.Pop();

        if(actual.fila == matriz_laberinto.Rows() - 1 &&
           actual.columna == matriz_laberinto.Columns() - 1){
            cout << "Llegue a la salida usando el DFS" << endl;
            Posiciones cur = actual;
            while(!(cur.fila == 0 && cur.columna == 0)){
                recorrido.insertFirst(cur);
                cur = padre[cur.fila][cur.columna];
            }
            Posiciones inicio = {0, 0};
            recorrido.insertFirst(inicio);
            cout << "Camino: " << endl;
            recorrido.printForward();
            return;
        }

        int nueva_fila = actual.fila;
        int nueva_columna = actual.columna - 1;
        if(nueva_columna >= 0 && matriz_laberinto.Get(nueva_fila, nueva_columna) == 0 && visitado.Get(nueva_fila, nueva_columna) == 0){
            Posiciones vecino = {nueva_fila, nueva_columna};
            pila.Push(vecino);
            visitado.Set(nueva_fila, nueva_columna, 1);
            padre[nueva_fila][nueva_columna] = actual;
        }

        nueva_columna = actual.columna + 1;
        if(nueva_columna < matriz_laberinto.Columns() && matriz_laberinto.Get(actual.fila, nueva_columna) == 0 && visitado.Get(actual.fila, nueva_columna) == 0){
            Posiciones vecino = {actual.fila, nueva_columna};
            pila.Push(vecino);
            visitado.Set(actual.fila, nueva_columna, 1);
            padre[actual.fila][nueva_columna] = actual;
        }

        nueva_fila = actual.fila - 1;
        if(nueva_fila >= 0 && matriz_laberinto.Get(nueva_fila, actual.columna) == 0 && visitado.Get(nueva_fila, actual.columna) == 0){
            Posiciones vecino = {nueva_fila, actual.columna};
            pila.Push(vecino);
            visitado.Set(nueva_fila, actual.columna, 1);
            padre[nueva_fila][actual.columna] = actual;
        }

        nueva_fila = actual.fila + 1;
        if(nueva_fila < matriz_laberinto.Rows() && matriz_laberinto.Get(nueva_fila, actual.columna) == 0 && visitado.Get(nueva_fila, actual.columna) == 0){
            Posiciones vecino = {nueva_fila, actual.columna};
            pila.Push(vecino);
            visitado.Set(nueva_fila, actual.columna, 1);
            padre[nueva_fila][actual.columna] = actual;
        }
    }
    cout << "No existe solucion usando DFS" << endl;
}


bool Posiciones::operator==(const Posiciones& otro) const {
    return fila == otro.fila && columna == otro.columna;
}

ostream& operator<<(ostream& os, const Posiciones& p){
    os << "(" << p.fila << "," << p.columna << ")";
    return os;
}

template class TDA_Matriz<int>;
template class TDA_Matriz<float>;
template class TDA_Matriz<char>;
