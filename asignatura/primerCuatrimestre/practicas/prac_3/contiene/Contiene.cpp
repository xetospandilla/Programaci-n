//---------------------------------------------------------
// Fichero: Contiene.cpp
// Fecha: 20-10-2025
// Descripción: Programa en C++ que determina si un número 
// está contenido en un array de enteros.
// Autor: Carlos Galán Cubells
//---------------------------------------------------------

#include <iostream>
using namespace std;


//---------------------------------------------------------
/**
 * Comprueba si un número entero está contenido en una lista.
 * @param p puntero al primer elemento del array
 * @param cuantos número de elementos en la lista
 * @param n número que se desea buscar
 * @return verdadero si el número está en la lista, falso en caso contrario
 */
//---------------------------------------------------------
bool contiene(const int *p, unsigned int cuantos, int n) {
    // Recorremos el array comprobando si alguno de los elementos es igual a n
    for (unsigned int i = 0; i < cuantos; i++) {
        if (*(p + i) == n) {    // Usamos aritmética de punteros
            return true;        // Si lo encontramos, devolvemos verdadero
        }
    }
    return false;               // Si no se encuentra, devolvemos falso
}
//---------------------------------------------------------
int main() {
    // Definimos un array con 10 elementos
    int lista[10] = {3, 7, 10, 15, 20, 25, 0, 0, 0, 0};
    
    // Número a buscar
    int n = 15;
    
    // Llamamos a la función contiene() indicando el inicio del array y su tamaño lógico
    bool encontrado = contiene(&lista[0], 6, n);
    
    // Mostramos el resultado
    if (encontrado)
        cout << "El número " << n << " SÍ está en la lista." << endl;
    else
        cout << "El número " << n << " NO está en la lista." << endl;
    
    return 0;   // Terminación correcta del programa
}
//---------------------------------------------------------