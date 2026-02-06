/*
---------------------------------------------------------------
Fichero: mainCuadrante.cpp
Fecha: 05-11-2025
Descripción: Programa en c++ que indica en que cuadrante está un punto.
Autor: Carlos Galán Cubells
---------------------------------------------------------------
*/
#include <iostream>
#include <cmath>
using namespace std;

//-------------------------------------------------------------
double queCuadrante ( int x, int y){
    cout << "Dame una coordenada para el punto en x: " << endl;
    cin >> x;
    cout << "Dame un coordenada para el punto en y: " <<endl;
    cin >> y;
 //------------------------------------------------------------
 int cuadrante; // Esto será lo que nos devolverá la función.
 //------------------------------------------------------------
if(x > 0 && y > y){
    cout << "El punto está en el primer cuatrante";
    cuadrante = 1;
}
if(x < 0 && y < 0){
    cout << "El número está en el segundo cuadrante";
    cuadrante = 2;
}
if(x < 0 && y < 0){
    cout << "El número está en el tercer cuadrante";
    cuadrante = 3;
}
if(x > 0 && y < 0){
    cout << "El número está en el cuarto cuadrante";
    cuadrante = 4;
} return cuadrante;
 //------------------------------------------------------------
}
/*
---------------------------------------------------------------
    PRUEBAS AUTOMÁTICAS
---------------------------------------------------------------
*/
int main(){
    if(queCuadrante(-3,-8) != 3){
    cout << "Algo no va bien" << endl;
    } return 0;
}
//-------------------------------------------------------------
