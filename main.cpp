#include <iostream>
#include <Matrix.h>
#include <ctime>

#include "Colors.h"

using namespace std;

int main() {

    srand(time(0)); // Este metodo hace que la matriz generada de n x n cambie en cada ejecucion

    Matrix<int> m(5,5); // asigna el numero de columas y de filas en la matriz

    m.generarLaberinto(); // genera el laberinto de 0s y 1s

    m.print(); //muestra en pantalla la matriz generada






    return 0;
}
