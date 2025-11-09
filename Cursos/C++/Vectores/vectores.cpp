/*
-------------------------------------------------------------------------------------------------------
Vectores
-------------------------------------------------------------------------------------------------------
- Es una clase de la librería estándar de C++. Está clase crea estructuras contenedoras
para almacenar datos secuanciales.

- los vectores pueden crecer o decrecer en tamaño de forma dinámica.

- Tienen una sintaxis muy similar a los arrays.

- Proporcionan múltiples para chequear límites, tamaño, comprovar si existe un elemento, etc.

- Almacenan los valores en posiciones contiguas de la memoria y también en posiciones separadas
accesibles a traves de punteros.
-------------------------------------------------------------------------------------------------------
Características:

- Tamaño dinámico.

- Los elementos almacenados en su interior son del mismo tipo.

- Se accede a los elementos almacenados con su posición o su índice.

- El primer elementos siempre tienen índice 0.

- El último siempre tiene índice size-1.

- Se suele interaccionar con ellos usando bucles.
-------------------------------------------------------------------------------------------------------
*/
//EJM:

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> records {25, 45, 60, 35}; //Con esto estamos dando valores dentro del vector.
    //Vector <"tipos de valores a almacenar"> "nombre del vector" (opcional: nº de valores que almacenará).

    vector <char> letras {'z', 'w', 'r'};

    vector <double> salario_base (350, 2125.5);/*Esto rellena las 350 casillas del vector con el mismo número
    en este caso, con el número 2125.5.*/

    //Para acceder a valores del vector:

    int i = 0;

    while(i<salario_base.size()){
        cout << salario_base[i] << endl;
        i++;
    }

    /*Este bucle hace que mientras la variable del salario base sea menor que 0, entre en el while.
    Dentro haciendo que el tamañao del vector vaya aumentando de uno en uno, hasta llegar a 350.*/
}
/*-----------------------------------------------------------------------------------------------------
Cosas importantes:

- "nombre del vector".at("posicón dentro del vector") => Hace una comprobación de limites.
Si existe la posición que existe. Si no, nos dará error.

- "nombre del vector.size"() => devuelve el número de elementos del vector.

- "nombre del vector".push_back => Añade un elemento al final del vector.
-----------------------------------------------------------------------------------------------------*/