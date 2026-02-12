/*
-------------------------------------------------------------------------------------------------------
Bucle While
-------------------------------------------------------------------------------------------------------
- Utilizado cuando necesitas realizar una operación un número indeterminado de veces y la
condición de parada depende de algún cálculo o entrada del usuario que ocurre dentro del bucle.

- Sintaxis: 

    - while( condición a evaluar) { cuerpo }
-------------------------------------------------------------------------------------------------------
*/
//---------------------------------------------------
#include <iostream>
using namespace std;

int main(){

    int i{1};

    while(i <= 10){
        if(i % 2 == 0){
            cout << i << "es par" << endl;
        } else {
            cout << i << "es impar" << endl;
        }
        
        i++;
    }

    return 0;
}
//---------------------------------------------------
//-----------------------------------------------------------------------------------------------------