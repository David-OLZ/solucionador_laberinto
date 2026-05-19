#include <iostream>
#include "TDA_Matriz.h"
using namespace std;

int main()
{

    TDA_Matriz<int> laberinto;
    laberinto.Create(4, 4);
    int opcion;
    TDA_Matriz<int> *p = &laberinto;

    // 0 = paso, 1 = pared
    // mismo laberinto del proyecto

    laberinto.Set(0,0,0); laberinto.Set(0,1,1); laberinto.Set(0,2,0); laberinto.Set(0,3,1); //laberinto.Set(0,4,0);
    laberinto.Set(1,0,0); laberinto.Set(1,1,0); laberinto.Set(1,2,0); laberinto.Set(1,3,0); //laberinto.Set(1,4,0);
    laberinto.Set(2,0,1); laberinto.Set(2,1,0); laberinto.Set(2,2,1); laberinto.Set(2,3,0); //laberinto.Set(2,4,0);
    laberinto.Set(3,0,0); laberinto.Set(3,1,1); laberinto.Set(3,2,0); laberinto.Set(3,3,0); //laberinto.Set(3,4,0);
    //laberinto.Set(4,0,0); laberinto.Set(4,1,0); laberinto.Set(4,2,0); laberinto.Set(4,3,1); laberinto.Set(4,4,0);
    laberinto.Print();

    do{
        cout<<"1. Resolver laberinto con DFS usando stack"<<endl;
        cout<<"2. Resolver laberinto con BFS usando Queue"<<endl;
        cout<<"3. Salir del programa"<<endl;
        cin>>opcion;
        switch(opcion){
        case 1:
            cout << "Buscando camino con DFS..." << endl;
            cout << "Laberinto:" << endl;
            laberinto.Print();
            laberinto.DFS_path(*p);
            break;
        case 2:
            cout<<"Buscando camino con BFS..."<<endl;
            cout<<"Laberinto: "<<endl;
            laberinto.Print();
            break;
        case 3:
            cout<<"Saliendo del programa...."<<endl;
            return 0;
            break;
        default:
            cout<<"La opción ingresada no es valida, revise la entrada"<<endl;
        }
    }while(opcion != 3);
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
