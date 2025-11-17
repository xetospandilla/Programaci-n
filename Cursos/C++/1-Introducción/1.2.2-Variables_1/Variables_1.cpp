//-----------------------------------------------------------------------------------------------------
// Segudo Programa en C++ ! Aprendiendo variables
//-----------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------------------------------

int main(){
    int salario = 100;
    /*
    Con esto hemos creado una variable de tipo entero "int" y la hemos inicializado al darle un valor.
    Las variables tienen diferentes formas de incializarse, pero esta es la más básica.
 */
cout << salario << endl; //Las variables también pueden ser imprimidas en pantalla.
//-----------------------------------------------------------------------------------------------------
salario = 3850; 
/*
Con esto que acabamos de hacer, no cambia el espacio de memoría de la variable, pero sí el contenido.
Durante la ejecución del programa podemos cambiar el contenido de la variable.
Siempre respetando el tipo de la variable.
*/
//-----------------------------------------------------------------------------------------------------
// Flujo -> Orden de ejecución de un programa. Siempre es de arriba o inicio del código hacia abajo.
//-----------------------------------------------------------------------------------------------------
cout << salario;
/*
Volvermos a imprimir en pantalla el valor de la variable salario, el cuál debería haber cambiado.
Ya que le hemos dado un nuevo valor durante la ejecución del programa.
*/
return 0;

}
//-----------------------------------------------------------------------------------------------------