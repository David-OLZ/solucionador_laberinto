#ifndef TDA_MATRIZ_H
#define TDA_MATRIZ_H


class TDA_Matriz{
   private:
       int matrix[100][100];
       int rows;
       int columns;
       int posicionColumna;
       int posicionFila;
   public:
       TDA_Matriz();
       void Create(int Rows, int Columns);
       void Initialize(int Value);
       void Set(int Row,int Column,int Value);
       int Get(int Row, int Column);
       int Rows();
       int Columns();
       void Print();
       void movimientoDer();
       void movimientoIzq();
       void movimientoArriba();
       void movimientoAbajo();
       void ponerMarca(int x);
};

#endif // TDA_MATRIZ_H
