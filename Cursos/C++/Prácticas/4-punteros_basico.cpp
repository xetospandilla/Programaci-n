/*
-----------------------------------------------------------------------------------------------------
punteros_basico.cpp
-----------------------------------------------------------------------------------------------------
📝 Ejercicio: Gestión de enteros con punteros

 - Enunciado:

  - Crea un programa en C++ que haga lo siguiente:

  - Pida al usuario cuatro números enteros y los almacene en variables normales (no en un vector).

  - Cree punteros que apunten a cada uno de estos números.

 - Muestre:

  - El valor de cada número usando los punteros.

  - La dirección de memoria de cada número.

  - Cambie el valor de un número a través de su puntero y muestre de nuevo todos los valores para verificar que cambió correctamente.

  - (Opcional) Ordene los números de menor a mayor usando solo punteros para acceder a los valores.

  - Objetivos que cumples con este ejercicio:

  - Declarar punteros y asociarlos a variables.

  - Acceder a valores usando * (desreferenciación).

  - Acceder a direcciones de memoria con &.

  - Modificar valores desde un puntero.

  - Introducción a manipulación indirecta de variables.
-----------------------------------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------------------------
//Variables:
int var1;
int var2;
int var3;
int var4;
//Punteros:
int *v1 = &var1;
int *v2 = &var2;
int *v3 = &var3;
int *v4 = &var4;
//Funcion para almacenar los valores:
void introducirValores(){
 if(
}