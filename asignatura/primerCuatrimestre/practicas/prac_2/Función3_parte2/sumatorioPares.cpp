//--------------------------------------------------------------------------------------------
// Fichero: SumatorioPares.cpp
// Fecha: 1/10/25
// Descripción: Programa que suma números pares naturales usando dos métodos en C++:
//              una función con fórmula matemática directa y otra con bucle sin condición.
// Autor: Carlos Galán Cubells
//--------------------------------------------------------------------------------------------

#include <cassert>
#include <iostream>
using namespace std;

//--------------------------------------------------------------------------------------------
// Versión fórmula:
// La suma de los números pares menores o iguales que n se puede calcular usando la fórmula:
// Si k = n/2 (parte entera), la suma es k * (k + 1)
//--------------------------------------------------------------------------------------------
int sumatorioPares_formula(int n) {
    int k = n / 2;  // n/2 es la cantidad de números pares hasta n
    return k * (k + 1);
}

//--------------------------------------------------------------------------------------------
// Versión iterativa sin condición:
// Se suma solo números pares, evitando usar 'if' con la condición par.
// Se incrementa i de 2 en 2 para recorrer solo pares
//--------------------------------------------------------------------------------------------
int sumatorioPares_iterativo(int n) {
    int res = 0;  // Acumulador
    for (int i = 2; i <= n; i += 2) {  // Incremento de 2 para saltar directamente entre pares
        res += i;  // Suma acumulativa de pares
    }
    return res;
}

//--------------------------------------------------------------------------------------------
int main() {
    // Pruebas automáticas para la fórmula
    assert(sumatorioPares_formula(1) == 0);
    assert(sumatorioPares_formula(4) == 6);   // 2 + 4 = 6
    assert(sumatorioPares_formula(10) == 30); // 2 + 4 + 6 + 8 + 10 = 30

    // Pruebas automáticas para la iterativa
    assert(sumatorioPares_iterativo(1) == 0);
    assert(sumatorioPares_iterativo(4) == 6);
    assert(sumatorioPares_iterativo(10) == 30);

    // Comprobación que ambas funciones dan mismos resultados
    for (int n = 0; n < 1000; ++n) {
        assert(sumatorioPares_formula(n) == sumatorioPares_iterativo(n));
    }

    cout << "Todas las pruebas han pasado correctamente." << endl;
    return 0;
}
//--------------------------------------------------------------------------------------------