#include <iostream>
#include "TDA_Matriz.h"
using namespace std;

int main()
{

    TDA_Matriz<int> laberinto;
    laberinto.Create(5, 5);

    // 0 = paso, 1 = pared
    // mismo laberinto del proyecto
    laberinto.Set(0,0,0); laberinto.Set(0,1,0); laberinto.Set(0,2,0); laberinto.Set(0,3,0); laberinto.Set(0,4,0);
    laberinto.Set(1,0,0); laberinto.Set(1,1,1); laberinto.Set(1,2,0); laberinto.Set(1,3,1); laberinto.Set(1,4,0);
    laberinto.Set(2,0,0); laberinto.Set(2,1,0); laberinto.Set(2,2,0); laberinto.Set(2,3,1); laberinto.Set(2,4,0);
    laberinto.Set(3,0,1); laberinto.Set(3,1,1); laberinto.Set(3,2,0); laberinto.Set(3,3,0); laberinto.Set(3,4,0);
    laberinto.Set(4,0,0); laberinto.Set(4,1,0); laberinto.Set(4,2,0); laberinto.Set(4,3,1); laberinto.Set(4,4,0);

    cout << "Laberinto:" << endl;
    laberinto.Print();

    cout << "\nBuscando camino con DFS..." << endl;
    laberinto.DFS_path(laberinto);

  /*
    TDA_Matriz A;
    A.Create(4,4);
    A.Initialize(1);
    A.Set(0,0,0);
    A.Set(0,1,1);
    A.Set(0,2,1);
    A.Set(0,3,1);
    A.Set(1,0,0);
    A.Set(1,1,0);
    A.Set(1,2,0);
    A.Set(1,3,0);
    A.Set(2,0,0);
    A.Set(2,1,1);
    A.Set(2,2,0);
    A.Set(2,3,0);
    A.Set(3,0,1);
    A.Set(3,1,1);
    A.Set(3,2,0);
    A.Set(3,3,0);
    */
    return 0;
}
