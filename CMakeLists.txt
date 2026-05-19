cmake_minimum_required(VERSION 4.1)
project(solucionador_laberinto)

set(CMAKE_CXX_STANDARD 14)

include_directories(RECORRIDO_DFS_PILA)

add_executable(solucionador_laberinto
        RECORRIDO_DFS_PILA/Doble_Circular_Linked_List.cpp
        RECORRIDO_DFS_PILA/Doble_Circular_Linked_List.h
        RECORRIDO_DFS_PILA/main.cpp
        RECORRIDO_DFS_PILA/Node.cpp
        RECORRIDO_DFS_PILA/Node.h
        RECORRIDO_DFS_PILA/Stack.cpp
        RECORRIDO_DFS_PILA/Stack.h
        RECORRIDO_DFS_PILA/tda_cola.cpp
        RECORRIDO_DFS_PILA/tda_cola.h
        RECORRIDO_DFS_PILA/TDA_Matriz.cpp
        RECORRIDO_DFS_PILA/TDA_Matriz.h)
