/*--------------------------------------------------------------------------------------------
Fichero: practica1.js
Autor: Carlos Galán Cubells
Fecha: 05/02/2026
Descripción: Función que recibe un número real y lo multiplica por tres.
--------------------------------------------------------------------------------------------*/
//------------------------------------------------------------------------------------------
//  Función por tres:   R -> porTres -> R
function porTres(a){

    //Multiplicara el número a por tres y nos lo devolverá:
    return a * 3;
}
//----------------------------------------------------------
//  Prueba: 

//  Le damos un valor a la variable a:
let a = 1;

//  Generamos una variable res que será la prueba para comprobar si funciona porTres:
let res = porTres(a);

//  Hacemos la comprobación y le decimos que si falla nos lo notifique por pantalla:
if(res != 3) console.log("Algo va mal");
//------------------------------------------------------------------------------------------