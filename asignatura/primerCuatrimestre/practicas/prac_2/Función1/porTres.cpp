//--------------------------------------------------------------------------------------------
// Fichero: PorTres.cpp
// Fecha: 25/9/25
// Descripción: Programa que multiplica un número por tres a través de una función en C++.
// Autor: Carlos Galán Cubells
//--------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;
//--------------------------------------------------------------------------------------------
// R -> porTres -> R
//--------------------------------------------------------------------------------------------
double porTres(double n) {
    return n * 3.0;
}
//--------------------------------------------------------------------------------------------

int main() {
    cout << "Hello world! \n";

    //Voy a llamar a la función
    //HACIENDO UNA PRUEBA AUTOMÁTICA
    double r;

    r = porTres(4.5);
    if (r != 13.5) {
        cout << "La función va mal \n";
    }

    //otra prueba automática
    r = porTres(7.0);
    if (r != 21.0) {
        cout << "La función va mal \n";
    }

    cout << "Hasta luego Lucas \n";

    return 0;
}
//--------------------------------------------------------------------------------------------