/*
-------------------------------------------------------------------------------------------------------
Siwtch-Case
-------------------------------------------------------------------------------------------------------
- la instrucción switch-case es una instrucción condicional especialmente útil cuando se necesita
realizar acciones específicas según el valor de una variable, sin la necesidad de encadenar múltiples
sentencias if-else.

- La sintaxis báisca de la instrución sería la siguiente:

switch (variable) {
    case valor1:
    //Bloque de código para el valor1.
        break;
    case valor2:
    //Bloque de código para el valor2.
        break;
//Más casos.
default:
    //Bloque de código para el caso cuando no se ningún caso anterior.
}
-------------------------------------------------------------------------------------------------------
- Se puede utilizar normalmente en menús de opciones. En máquinas de estados finitos.
En implementación de un intérprete de comandos, etc.

- IMPORTANTE: En C++ switch-case sólo funciona comparado tipos enteros(int, char, long, etc.).
No se puede utilizar para comparar cadenas de caracteres(strings) directamente, pero es posible
hacerlo usando un mapa de hash o alguna otra estructura auxiliar.
-------------------------------------------------------------------------------------------------------
EJM:
*/
#include <iostream>
using namespace std;

int main(){
    int opcion;

    cout << "Menú de opciones: " << endl;
    cout << "1. Mostrar mensajes." << endl;
    cout << "2. Calcular una suma." << endl;
    cout << "3. Salir del programa." << endl;
    cout << "Introduce la opción deseada: " << endl;

    cin >> opcion;

    switch (opcion){
        case 1:
            cout << "Bujarrilla" << endl; break;
        case 2:
            cout << "Introduce dos números entonces: " << endl;
            double n1; cin >> n1;
            cout <<"Introduce otro número: " << endl;
            double n2; cin >> n2;

            cout << "La suma dió: " << n1 + n2 << endl; break;
        case 3:
            cout << "Saliendo del programa." << endl; break;

        default:
            cout << "Opción no valida" << endl;
    } return 0;
}
//-----------------------------------------------------------------------------------------------------
