//---------------------------------------------------------
// Fichero: dondeEstaElMayor.cpp
// Fecha: 2-10-2025
// Descripción: Programa en C++ para encontrar la posición del mayor elemento de un array usando punteros.
// Autor: Carlos Galán Cubells
//---------------------------------------------------------

#include <iostream>
using namespace std;

//---------------------------------------------------------
/**
 * Devuelve la posición del mayor elemento en una lista de doubles.
 * @param p puntero al primer elemento del array
 * @param cuantos número de elementos en la lista
 * @return posición (índice) del mayor elemento
 */
//---------------------------------------------------------
int dondeEstaElMayor(const double *p, unsigned int cuantos) {
    if (cuantos == 0) {
        return -1; // Si la lista está vacía, devolvemos -1
    }
    
    int posMayor = 0; // Suponemos que el primer elemento es el mayor
    for (unsigned int i = 1; i < cuantos; i++) {
        if (p[i] > p[posMayor]) {
            posMayor = i; // Actualizamos la posición si encontramos un elemento mayor
        }
    }
    return posMayor; // Devolvemos la posición del mayor
}
//---------------------------------------------------------
int main() {
    // Definimos un array con 8 elementos
    double lista[8] = {3.4, 2.1, 7.8, -6.2, 5.9, -1.1, 6.5, 0.0};
    
    // Buscamos la posición del mayor de los primeros 6 elementos
    int pos = dondeEstaElMayor(&lista[0], 6);

    if (pos != -1) {
        cout << "La posición del mayor es: " << pos << endl;
        cout << "El valor mayor es: " << lista[pos] << endl;
    } else {
        cout << "La lista está vacía." << endl;
    }

    return 0; // Terminación correcta del programa
}
//---------------------------------------------------------