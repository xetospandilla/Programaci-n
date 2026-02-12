/*
--------------------------------------------------------------------------------------------
Fichero: Ordena3v1.cpp
Fecha: 26-11-2025
Descripción: Programa en C++ que ordena tres números enteros de mayor a meno, ya almacenados
dentro de un array.
Autor: Carlos Galán Cubells
--------------------------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

void ordenar(int arr[3]){

    int n1 = arr[0]; int n2 = arr[1]; int n3 = arr[2];

    cout << "Valores sin ordenar: ";
    for(int i = 0; i < 3; i++){
        cout << arr[i];
    }
    cout << endl;


    int temp;
    for(int i=0; i < 3; i++){
        for(int a = 0; a < 3 - i -1; a++){
            if(arr[a] > arr[a + 1]){
                temp = arr[a];
                arr[a] = arr[a +1];
                arr[a + 1] = temp;
            }
        }
    }

    cout << "Valores ordenados: ";
    for(int i = 0; i < 3; i++){
        cout << arr[i];
    } cout << endl;
}

int main(){

    int miarr[3] = {3,1,2};
    ordenar(miarr);
}