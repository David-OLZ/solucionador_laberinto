#ifndef TDA_MATRIZ_H
#define TDA_MATRIZ_H
#include <iostream>

using namespace std;
//Creacion de una estructura para hacer push de un "solo" elemento
struct Posiciones{
    int fila;
    int columna;
    bool operator==(const Posiciones& otro) const;

    // para que printForward pueda imprimir
    friend ostream& operator<<(ostream& os, const Posiciones& p);
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
};

#endif // TDA_MATRIZ_H
