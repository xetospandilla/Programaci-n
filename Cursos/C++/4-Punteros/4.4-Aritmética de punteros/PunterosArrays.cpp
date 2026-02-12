/*
-------------------------------------------------------------------------------------------------------------------------------
Punteros y Arrays
-------------------------------------------------------------------------------------------------------------------------------
- En C++ un array es básicamente un puntero al primer elemento del array.

    - El valor del nombre del array es la dirección en memoría del primer elemento del arrya.

    - CUando se usa el nombre del array sin ningún índice se obtiene la dirección en memoría del primer elemento del array.

    - Cuando un puntero apunta al mismo tipo de dato que los elementos de un array, es casi en todos los escenarios,
    puedes usar el nombre del puntero y el nombre del array intercambiable para realizar operaciones similares,
    especialmente en lo que respecta a la indexación y aritmética de punteros. Sin embargo, el "casi" indica
    que hay excepciones a esta regla.
-------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int main(){

    int nums[] = {10,20,30,40};

    //-----------------------------------------------------------------------------------
    cout << nums << endl; //Dirección de memoría del primer elemento del array.

    cout << *nums << endl; //Valor de lo que hay almacenado en esa dirección de memoría.
    //-----------------------------------------------------------------------------------
    int *p_nums(nums);
    //-----------------------------------------------------------------------------------
    cout << p_nums << endl; //Esto hará lo mismo que:  cout << nums << endl;

    cout << *p_nums << endl; //Esto hará lo mismo que:  cout << *nums << endl;
    //-----------------------------------------------------------------------------------
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------
