//---------------------------------------------------------
// Fichero: esPositivo.cpp
// Fecha: 25-09-2025
// Descripión: programa  en C++ que indica si un número es positivo o no.
// Autor: Carlos Galán Cubells
//---------------------------------------------------------
#include <iostream>
using namespace std;
#include <cassert>

//---------------------------------------------------------
// R -> esPositivo() -> B
//---------------------------------------------------------

bool esPositivo( int a) {
    if ( a >= 0) {
        return true; // devolver verdadero
    } else { 
        return false; // devolver falso
    }
}

//---------------------------------------------------------
//  Pruebas automáticas
//---------------------------------------------------------

int main() {
    // Casos básicos
    assert(esPositivo(5) == true);    // comprobamos que los números positivos funcionan.
    assert(esPositivo(0) == true);    // cero debe ser positivo según la definición usada.
    assert(esPositivo(-1) == false);  // comprobamos que los números número negativos funcionan.
    
    // Casos adicionales
    assert(esPositivo(123456) == true); 
    assert(esPositivo(-99999) == false);

    cout << "Todas las pruebas pasaron correctamente." << endl;
}
