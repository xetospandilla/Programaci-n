/*
-------------------------------------------------------------------------------------------------------------------------------
Pointers Pitfalls
-------------------------------------------------------------------------------------------------------------------------------
- Desrefenciación de punteros nulos.

- Fugas de memoria (Memory leaks).

- Desbordamiento de buffer (Buffer overflow).

- Doble liberación (Double free).

- Punteros colgantes (Dangling pointers).

- Violación del acceso (Acces violation).
--------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;

int main(){

    //-----------------------------------
    //Desreferenzación de punteros nulos
    int *ptr = new int[10];//Asigna nuevo espacio en la memoría.

    delete[] ptr;//Borra la última asignación.

    ptr = new int [20];//Asigna nuevo espacio en la memoría.

    delete[] ptr;//Borra la última asignación.
    //-----------------------------------
    //Memory leaks
    int array[5];

    for(int i = 0; i<5; i++){
        array[i] = i;
    }
    //-----------------------------------
    //Doble liberación
    int *pt = new int;

    delete pt;

    if(pt != nullptr) delete ptr;
    //-----------------------------------
    //Punteros colgantes
    int *pr = new int(10);

    delete pr;

    pr = nullptr;

    if(pr !=nullptr) *pr = 5;
    //-----------------------------------
    //Violación de acceso
    int array[5] = {1,2,3,4,5};
    int *prt = &array[6];

    int valor = *prt;

    /*Se corrige teniendo cuidado
    al declarar el array*/
    //-----------------------------------
}
//------------------------------------------------------------------------------------------------------------------------------