/*
--------------------------------------------------------------------------------------------
Fichero: Ordena3v1.cpp
Fecha: 25-11-2025
Descripción: Programa en C++ que ordena tres números enteros de mayor a menor.
Autor: Carlos Galán Cubells
--------------------------------------------------------------------------------------------
*/
#include <iostream>
using namespace std;
//------------------------------------------------------------------------------------------
//ORDENAR3V1
//------------------------------------------------------------------------------------------
void ordenar(int n1, int n2, int n3) {
    cout << "Valores sin ordenar: " << n1 << " " << n2 << " " << n3 << endl;

    int arr[3];
    arr[0] = n1;
    arr[1] = n2;
    arr[2] = n3;

    int temp;
    for (int i = 0; i < 3; i++) {
        for (int a = 0; a < 3 - i - 1; a++) {
            if (arr[a] > arr[a + 1]) { // descendente
                temp = arr[a];
                arr[a] = arr[a + 1];
                arr[a + 1] = temp;
            }
        }
    }

    cout << "Valores ordenados: ";
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//------------------------------------------------------------------------------------------
int main(){
    ordenar(3,1,2);
    return 0;
}
//------------------------------------------------------------------------------------------