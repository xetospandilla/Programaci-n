/*
--------------------------------------------------------------------------------------------
Fichero: mainCercano.cpp
Fecha: 06-11-2025
Descripción: Programa en C++ que cálcula el camino formado por puntos dentro de un array.
Autor: Carlos Galán Cubells
--------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <cmath> //La necesitamos para los cálculos de vectores.

//------------------------------------------------------------------------------------------
//Declaramos la clase punto:

class punto{
    double x; double y;
    punto(double x, double y): x(x), y(y ){}
};

//------------------------------------------------------------------------------------------
//Escrivamos la función:

double mainCamino(punto arr[]){
    //--------------------------------------------------------------------------------------
    unsigned int tam = sizeof arr;//Para medir el tamaño del array.
    //--------------------------------------------------------------------------------------
    for(int i = 0; i < tam; i++){
        punto *p = &arr[i];
        //Falta terminar bucle. 
    }
}
//------------------------------------------------------------------------------------------