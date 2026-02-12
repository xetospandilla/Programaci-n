/*
-----------------------------------------------------------------------------------------------------------------------------
Gestión de la memoría
-----------------------------------------------------------------------------------------------------------------------------
//Memoría:

- Se divide en varias partes:

    - Segmento de código/texto. Almacena las instrucciónes que la cpu va a ejercutar. El código aquí es estático.

    - Segmento de datos:

        - Parte de datos inicializados.
        - Parte de datos no inicializados(BSS => BLOCK STARTED BY SYMBOL).

    - Stack(Pila).Utilizado para llamadas a funciones, almacenamiento de variables locales, parámetros y devoluciones
    de funciones. (Es de tamaño límitado, normalmente por el sistema opterativo donde se ejecuta la aplicación).

        STACKOVERFLOW => Es cuando se sobrepasa la capacidad del stack.

        También se llama memoría tipo LIFO => Last In First Out. El último en entrar es el primero en salir.
        Ya que los datos se almacenan en forma de pila. 

    - Heap(montón). Parte de la memoría asignada para la asignación dinámica de memoría. Es la asignación de memoría
    durante la ejecución del programa. Esta parte de la memoría está gestionada explicítamente por el programador.

        Eso el programador lo hace manera manual, mediante asignaciones y liberaciones de memoría. 
        El tamaño del Heap es mucho más flexible que el del stakc. Debido a que es dinámico.

        Su mala gestión de memoría puede dar lugar a problemas como las fugas de memoría.

        Sirven para variables y datos que cambian durante la ejecución del programa.
-----------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int main(){

    int *int_ptr{nullptr}; //No debemos inicializar punteros si no sabemos a donde apuntarán.
    //Con esto nos aseguramos de que el puntero apunte a nulo y no a algún elemento residual.

    int_ptr = new int;//Así asignamos un espacio de la memoría en el Heap apra un entero.
    //Aunque nuestro puntero este almacenado en el Stack.

    cout << int_ptr << endl; //Con esto imprimimos la dirección en memoría del puntero a la que apunta. En el Heap.

    cout << &int_ptr << endl; //Con esto imprimimos la dirección en memoría del puntero. Del Stack.

    *int_ptr = 10;

    cout << "Valor antes del delete: " << endl;

    delete int_ptr; //Liberación de memoría. Dejando ese espacio en la memoría libre para asignarse de nuevo.
    //Después de esto el puntero se convierte en un puntero colgante, ya que mantiene la dirección de memoría borrada.

    int_ptr=nullptr;/*Con esto ya el puntero ya no apunta a una dirección válida.
    Previniendo el uso accidental de este puntero de nuevo.*/

}
//-----------------------------------------------------------------------------------------------------------------------------