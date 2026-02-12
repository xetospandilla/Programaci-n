/*
-------------------------------------------------------------------------------------------------------------------------------
Constantes y Punteros
-------------------------------------------------------------------------------------------------------------------------------
1. Punteros a constantes:

    - Puntero que apunta a un valor constante. Esto significa que el valor al que apunta no podrá ser modificado a través
    del puntero.

2. Punteros constantes: 

    - Puntero cuya dirección de memoría no puede cambiar después de su inicialización; sin embargo, el valor al que apunta sí
    que puede ser modificado, a menos que también sea constante.

3. Punteros constantes a constantes:

    - Puntero que no pueda cambiar la dirección de memoría a la que apunta ni modificar el valor almacenado en esa dirección.
--------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int main(){

    //----------------------------------
    //Punteros a constantes:
    const int valor1 = 10;
    const int *pvalor1 = &valor1;

    cout << *pvalor1 << endl;
    //----------------------------------
    //Punteros constantes:
    int valor2 = 11;
    int* const pvalor2 = &valor2;
    /*Estamos obligados a inicializar
    el puntero en el momento de su
    declaración.*/

    cout << *pvalor2 << endl;
    //----------------------------------
    
    //----------------------------------
    //Punteros constantes a constantes.
    const int valor3 = 15;
    const int* const pvalor3 = &valor3;

    cout << *pvalor3 << endl;
    //----------------------------------

    return 0;
}
//------------------------------------------------------------------------------------------------------------------------------
