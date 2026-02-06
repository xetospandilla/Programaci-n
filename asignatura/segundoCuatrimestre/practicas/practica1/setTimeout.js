/*--------------------------------------------------------------------------------------------
Fichero: practica1.js
Autor: Carlos Galán Cubells
Fecha: 05/02/2026
Descripción:
--------------------------------------------------------------------------------------------*/
//------------------------------------------------------------------------------------------
//Función set time out:

//Espera 2000ms para realizar la acción indicada. En este caso: imprimir en consola hola 1.
setTimeout ( function () {
console.log (" hola 1 ");
}, 2000 )

//Espera 2000ms para realizar la acción indicada. En este caso: imprimir en consola hola 2.
setTimeout ( function () {
console.log (" hola 2 ");
}, 2000 )
//------------------------------------------------------------------------------------------
//  Respuesta: como esperan el mismo tiempo, lo que ocurrirá es que se imprimirán a la vez.
//------------------------------------------------------------------------------------------
//  Modificación para que tarde dos segundos más el segundo input:

//Espera 2000ms para realizar la acción indicada. En este caso: imprimir en consola hola 1.
setTimeout ( function () {
console.log (" hola 1 ");
}, 2000 )

//Espera 4000ms para realizar la acción indicada. En este caso: imprimir en consola hola 2.
setTimeout ( function () {
console.log (" hola 2 ");
}, 4000 )
//------------------------------------------------------------------------------------------