/*
--------------------------------------------------------------------------------------------
Fichero: Ordena3v1.cpp
Fecha: 25-11-2025
Descripción: Programa en C++ que ordena tres números enteros de mayor a menor, suponiendo
que ya está almacenados dentro de un array.
Autor: Carlos Galán Cubells
--------------------------------------------------------------------------------------------
*/
#include <iostream>
using namespace std;

void ordenar(int arr[3]){
    int temp;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3 - i -1; j++){
            if(arr[j] > arr[j + 1]){
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j +1] = temp;
            }
        }
    }
}

int main(){

    int myarr[3] = {3,1,2};

    cout << "Valores antes de ordenar: ";

    for(int i = 0; i < 3; i++){
        cout << myarr[i] << " ";
    } cout << endl;

    ordenar(myarr);

    cout << "Valores después de ordenar: ";
    for(int i = 0; i < 3; i++){
        cout << myarr[i] << " ";
    } cout << endl;
    
    return 0;
}