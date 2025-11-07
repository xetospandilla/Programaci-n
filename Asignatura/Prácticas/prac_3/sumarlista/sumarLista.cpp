//---------------------------------------------------------
// Fichero: esPositivo.cpp
// Fecha: 1-10-2025
// Descripción: Programa en C++ para sumar elementos de un array usando punteros.
// Autor: Carlos Galán Cubells
//---------------------------------------------------------

#include <iostream>
using namespace std;

//---------------------------------------------------------
/**
 * Suma los elementos de una lista de enteros.
 * @param p puntero al primer elemento del array
 * @param cuantos número de elementos en la lista
 * @return suma de los elementos
 */
//---------------------------------------------------------
int sumarLista(const int *p, unsigned int cuantos) {
    int suma = 0;  // Inicializamos la suma a 0
    // Recorremos el array sumando cada elemento
    for (unsigned int i = 0; i < cuantos; i++) {
        suma += p[i];
    }
    return suma;  // Devolvemos la suma total
}
//---------------------------------------------------------
int main() {
    // Definimos un array con 10 elementos
    int lista[10] = {1, 2, 3, 4, 5, 0, 0, 0, 0, 0};
    
    // Sumamos los primeros 5 elementos
    int resultado = sumarLista(&lista[0], 5);
    
    // Mostramos el resultado
    cout << "La suma de la lista es: " << resultado << endl;
    
    return 0;  // Terminación correcta del programa
}
//---------------------------------------------------------