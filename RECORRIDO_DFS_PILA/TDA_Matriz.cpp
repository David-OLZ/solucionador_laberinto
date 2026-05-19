#include "TDA_Matriz.h"
#include <iostream>
#include"Doble_Circular_Linked_List.h"
#include "Stack.h"

using namespace std;

template <class T> TDA_Matriz<T>::TDA_Matriz(){
    this ->rows = 0;
    this ->columns = 0;
}

template <class T> void TDA_Matriz<T>::Create(int filas, int Columnas){
    this ->rows = filas;
    this ->columns = Columnas;
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


template <class T> void TDA_Matriz<T>::DFS_path(TDA_Matriz& matriz_laberinto){
    //Aqui se guardan el pares de coordenadas
    Posiciones padre[100][100];
    TDA_Matriz visitado;//Matriz llamado visitado la cual utilizaremos para saber que lugares ya visitamos
    visitado.Create(matriz_laberinto.Rows(), matriz_laberinto.Columns());//Creamos la matriz visitado con la misma cantidad de filas y columnas de la
    //misma matriz que nos llega desde el parametro de la funcion
    visitado.Initialize(0);//Inicializamos la matriz visitado en ceros (false)

    Doble_Circular_Linked_List<Posiciones> recorrido;//Lista para guardar las posiciones

    //Pila para guardar y sacar las posiciones
    Stack<Posiciones> pila;

    //Se hace uso de la estructura posiciones para pasarle las coordenadas de la entrada de la matriz llamda matriz_laberinto
    Posiciones entrada = {0, 0};
    //Se hace push a la coordenada de la entrada de la matriz
    pila.Push(entrada);
    //Marcamos la entrada de la matriz visitado con 1 (true) para saber que ya lo visitamos
    visitado.Set(0, 0, 1);

    //Bucle while para buscar la buscar el camino de salida de la matriz, guardar y sacar las coordenadas y reconstruir el camino con la lista
    while(!pila.IsEmpty()){
        //Obtenemos la posicion actual que esta guardada en la cima de la pila
        Posiciones actual = pila.Top();
        //Sacamos la coordenada que esta en la cima de la pila
        pila.Pop();
        //Condicional para saber si la coordenada que esta guardado en actual es la salida
        if(actual.fila == matriz_laberinto.Rows() - 1 && actual.columna == matriz_laberinto.Columns() - 1){
        //si la fila de la coordenada actual es igual a la ultima fila de la matriz y la coordenada de la columna de actual es igual a la ultima columna
        //de la matriz del laberinto llegamos a la salida.

            cout << "Llegue a la salida usando el DFS" << endl;
            Posiciones cur = actual;//Guarda en cur las coordenadas guardadas en actual
            while(!(cur.fila == 0 && cur.columna == 0)){//Usamos este while para imprimir las coordenadas guardadas en en padre
                recorrido.insertFirst(cur);//inserta la coordenada guardada en cur a la lista
                cur = padre[cur.fila][cur.columna];//guarda la siguiente coordenada que esta en padre en cur
            }
            Posiciones inicio = {0, 0};//Guarda la coordenada de la entrada de la matriz laberinto en incio
            recorrido.insertFirst(inicio);//Inserta la coordenada de incio en la lista (insert first)
            cout << "Camino: " << endl;
            recorrido.printForward();//Imprime la lista enlazada
            return;//Acaba la ejecucion
        }

        /*
            A partir de aqui empezamos a verificar los vecinos.
        */

        //Aqui se verifica el vecino izquierdo
        int nueva_fila = actual.fila;//Guardamos la coordenada de la fila actual en esta variable.
        int nueva_columna = actual.columna - 1;//Guardamos la coordenada de la columna de la izquierda
        //Verifica que realmente ese movimiento a la izquierda sea valido (que no nos salgamos de la matriz, que el valor sea 0 y que no este visitado)
        if(nueva_columna >= 0 && matriz_laberinto.Get(nueva_fila, nueva_columna) == 0 && visitado.Get(nueva_fila, nueva_columna) == 0){
            Posiciones vecino = {nueva_fila, nueva_columna};//Guarda en vecino la coordenada valida
            pila.Push(vecino);//Metemos esa coordenada en la pila
            visitado.Set(nueva_fila, nueva_columna, 1);//Marcamos la nueva coordenada en la matriz visitado como visitado y evitar repetir coordenada
            padre[nueva_fila][nueva_columna] = actual;//Metemos esa coordenada en padre que se utilizara para insertar en la lista
        }

        //Aqui se verifica en vecino derecho
        nueva_columna = actual.columna + 1;//Guardamos la coordenada de la columna de la derecha
        //Verifica que el movimiento a la derecha sea valido(Que no me salga de la matriz, que puedas pasar y que no se haya visitado)
        if(nueva_columna < matriz_laberinto.Columns() && matriz_laberinto.Get(actual.fila, nueva_columna) == 0 && visitado.Get(actual.fila, nueva_columna) == 0){
            Posiciones vecino = {actual.fila, nueva_columna};//Guardamos en vecino la nueva coordenada valida
            pila.Push(vecino);//Lo metemos en la pila
            visitado.Set(actual.fila, nueva_columna, 1);//Marcamos la nueva ubicacion valida como visitado en la matriz visitado
            padre[actual.fila][nueva_columna] = actual;//Metemos esa coordenada en padre
        }

        //Aqui se verifica el movimiento hacia arriba
        nueva_fila = actual.fila - 1;//Guardamos la nueva coordenada de la fila en nueva_fila
        //Verificamos que el movimiento a arriba sea valido(verifica que no se salga, que no sea 1 y que no este visitado)
        if(nueva_fila >= 0 && matriz_laberinto.Get(nueva_fila, actual.columna) == 0 && visitado.Get(nueva_fila, actual.columna) == 0){
            Posiciones vecino = {nueva_fila, actual.columna};//Guardamos la coordenada en vecino
            pila.Push(vecino);//metemos la coordenada a la pila
            visitado.Set(nueva_fila, actual.columna, 1);//Marcamos la coordenada en visitado como visitado
            padre[nueva_fila][actual.columna] = actual;//Metemos la coordenada en padre
        }

        //Verificamos el movimiento hacia abajo
        nueva_fila = actual.fila + 1;//Guardamos la nueva coordenada de la nueva fila
        //Verificamos que el movimeinto hacia abajo sea valido (verifica que no se salga hacia abajo, verifica que no sea 1, y que no sea visitado)
        if(nueva_fila < matriz_laberinto.Rows() && matriz_laberinto.Get(nueva_fila, actual.columna) == 0 && visitado.Get(nueva_fila, actual.columna) == 0){
            Posiciones vecino = {nueva_fila, actual.columna};//Guarda la coordenada valida en vecino
            pila.Push(vecino);//Metemos la coordenada en vecino
            visitado.Set(nueva_fila, actual.columna, 1);//Marcamos la coordenada en visitado como visitado
            padre[nueva_fila][actual.columna] = actual;//Guarda la coordenada en padre
        }
    }
    //Si no hay movimeintos validos por la pila vacia no hay solucion
    cout << "No existe solucion usando DFS" << endl;
}

//Le dice al cout como imprimir la fila y la columna del struct
ostream& operator<<(ostream& os, const Posiciones& p){
    //dice: imprime un parentesis, despues la fila que esta guardada en la struct posiciones, despues una como y despues la columna guardada en posiciones
    os << "(" << p.fila << "," << p.columna << ")";
    return os;
}

template class TDA_Matriz<int>;
template class TDA_Matriz<float>;
template class TDA_Matriz<char>;
