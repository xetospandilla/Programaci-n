/*
-------------------------------------------------------------------------------------------------------------------------------
Aritmética de Punteros
-------------------------------------------------------------------------------------------------------------------------------
- La aritmética de punteros es un concepto en programarción, especialmente relevante en lenguajes como C++ y C, que permite
realizar operaciones aritméticas sobre punteros. Los punteros son variables que almacenan direcciones de memoría, y la
aritmética de punteros se utiliza para calcular direcciones de memoría, lo que permite accder y manipular datos en diferentes
posiciones de un array o bloque de memoría.

- Podemos:

    - Incrementar un puntero(++): Al incrementar un puntero, se aumenta su valor para que se apunte al siguiente elemento
    de un arreglo. El incremento se realiza en base al tamaño del tipo de dato al que apunta el puntero. Por emplo si un
    puntero de tipo int, apunta al inicio del arreglo, al incrementar el punrtero, este apuntará 4 bytes adelante en memoría,
    es decir, al siguiente entero del arreglo.

    - Decrecimiento a un puntero(--): Similar al incremento, pero en la dirección opuesta. Al decrementar un puntero, 
    se disminuye su valor para que apunte al elemnto anterior en un arreglo.

    - Suma (+): se puede sumar un entero a un puntero para que el puntero avance varios elementos en un arreglo.
    Al igual que el incremento, el avance se cálcula multiplicando el número entero por el tamaño del tipo de daro
    al que apunta el puntero.

    - Resta(-): se puede restar un entero a un puntero para que el puntero vaya hacia atrás varias posicones
    en un arreglo. También se puede restar dos punteros para obtener la diferencia de elementos entre ellos,
    siempre y cuando ambos punteros apunten a elementos dentro del mismo arrego.
-------------------------------------------------------------------------------------------------------------------------------
*/
    /*-------------------------------*/
#include <iostream>
using namespace std;

int main(){

    int nums[] = {10,20,30};

    int *pnums{nums};

    cout << pnums[0] << endl;
    cout << *(pnums + 2) << endl;
    cout << pnums[2] << endl;


    return 0;
}
    /*-------------------------------*/