//--------------------------------------------------------------------------------------------
// Fichero: sumatorio.cpp
// Fecha: 1/10/25
// Descripción: Programa que suma números a través de dos funciones en C++:
//              una con fórmula matemática y otra con bucle.
// Autor: Carlos Galán Cubells
//--------------------------------------------------------------------------------------------

#include <cassert>   // Para usar assert en las pruebas automáticas
#include <iostream> 
using namespace std;

//--------------------------------------------------------------------------------------------
//  Versión fórmula: sumatorio con fórmula matemática n*(n+1)/2
//--------------------------------------------------------------------------------------------
int sumatorio_formula(int n) {
    return n * (n + 1) / 2;
}

//--------------------------------------------------------------------------------------------
//  Versión iterativa: sumatorio utilizando bucle for
//--------------------------------------------------------------------------------------------
int sumatorio_iterativo(int n) {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res += i;  // Suma sucesiva de i al resultado
    }
    return res;
}

//--------------------------------------------------------------------------------------------
int main() {
    //----------------------------------------------------------------------------------------
    // Pruebas automáticas con assert para verificar la funcionalidad
    //----------------------------------------------------------------------------------------
    // Pruebas para la función sumatorio_formula
    assert(sumatorio_formula(1) == 1);
    assert(sumatorio_formula(5) == 15);
    assert(sumatorio_formula(10) == 55);
    
    // Pruebas para la función sumatorio_iterativo
    assert(sumatorio_iterativo(1) == 1);
    assert(sumatorio_iterativo(5) == 15);
    assert(sumatorio_iterativo(10) == 55);
    
    // Comprobación que ambas funciones devuelven el mismo resultado para valores de 0 a 999
    for (int n = 0; n < 1000; ++n) {
        assert(sumatorio_formula(n) == sumatorio_iterativo(n));
    }
    
    cout << "Todas las pruebas han pasado correctamente." << endl;
    return 0;
}
//--------------------------------------------------------------------------------------------