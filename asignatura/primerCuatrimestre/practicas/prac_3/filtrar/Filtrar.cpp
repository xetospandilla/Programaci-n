//---------------------------------------------------------
// Fichero: Filtrar.cpp
// Fecha: 20-10-2025
// Descripción: Programa en C++ que genera una nueva lista
// con los valores positivos de una lista original.
// Autor: Carlos Galán Cubells
//---------------------------------------------------------

#include <iostream>
using namespace std;


//---------------------------------------------------------
/**
 * Filtra los valores positivos de una lista de números reales.
 * @param origen puntero al primer elemento del array original
 * @param destino puntero al primer elemento del array filtrado
 * @param cuantos número de elementos en la lista original
 * @return número de valores positivos encontrados
 */
//---------------------------------------------------------
unsigned int filtrar(const float *origen, float *destino, unsigned int cuantos) {
    unsigned int j = 0;  // Contador de elementos positivos

    // Recorremos todos los elementos del array original
    for (unsigned int i = 0; i < cuantos; i++) {
        if (*(origen + i) > 0) {   // Si el valor es positivo...
            *(destino + j) = *(origen + i);  // ... lo copiamos al array destino
            j++;                              // Incrementamos contador de positivos
        }
    }

    // Devolvemos el número total de elementos positivos
    return j;
}
//---------------------------------------------------------
int main() {
    // Definimos un array con números reales positivos y negativos
    float lista[10] = {-3.5, 2.1, 0.0, 7.8, -1.2, 3.3, -9.0, 5.5, 0.0, 4.4};

    // Array para guardar los valores positivos filtrados
    float positivos[10];

    // Llamamos a la función filtrar()
    unsigned int numPositivos = filtrar(&lista[0], &positivos[0], 10);

    // Mostramos el resultado del filtrado
    cout << "Lista original: ";
    for (unsigned int i = 0; i < 10; i++)
        cout << lista[i] << " ";
    cout << endl;

    cout << "Valores positivos: ";
    for (unsigned int i = 0; i < numPositivos; i++)
        cout << positivos[i] << " ";
    cout << endl;

    return 0;   // Terminación correcta del programa
}
//---------------------------------------------------------
