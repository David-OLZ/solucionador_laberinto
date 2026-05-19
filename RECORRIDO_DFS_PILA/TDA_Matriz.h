#ifndef TDA_MATRIZ_H
#define TDA_MATRIZ_H
#include <iostream>

using namespace std;
//Creacion de una estructura para hacer push de un "solo" elemento
struct posiciones{
    int fila;
    int columna;

    // para que printForward pueda imprimir, ya que no sabe como imprimir los pares del struct
    friend ostream& operator<<(ostream& os, const posiciones& p);
};

template <class T> class TDA_Matriz{
   private:
       T matrix[100][100];
       int rows;
       int columns;
       int posicionColumna;
       int posicionFila;
   public:
       TDA_Matriz();
       void Create(int Rows, int Columns);
       void Initialize(T Value);
       void Set(int Row,int Column,T Value);
       T Get(int Row, int Column);
       int Rows();
       int Columns();
       void Print();
       bool movimientoDer();
       bool movimientoIzq();
       bool movimientoArriba();
       bool movimientoAbajo();
       void ponerMarca(T x);
       void DFS_path(TDA_Matriz& matriz_laberinto);
       void BFS_path(TDA_Matriz& matriz_laberinto);
};

#endif // TDA_MATRIZ_H
