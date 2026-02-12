/*--------------------------------------------------------------------------------------------
Fichero: practica1.js
Autor: Carlos Galán Cubells
Fecha: 05/02/2026
Descripción: Función que recibe un callback de la fucnión porTres y lo devuelve.
--------------------------------------------------------------------------------------------*/

//  Función por tres:   R -> porTres -> R
function porTres(a){

    //Multiplicara el número a por tres y nos lo devolverá:
    return a * 3;
}
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//  Función por tres v2: R -> porTres2 -> R
//------------------------------------------------------------------------------------------

function porTres2(a){

    //Utilizamos un callback para llamar a la anterior función por tres:
    let res = callback(porTres(a));

    return res;
}
//----------------------------------------------------------
//  Prueba: 

//  Le damos un valor a la variable a:
let a = 1;

//  Generamos una variable res que será la prueba para comprobar si funciona porTres:
let res = porTres2(a);

//  Hacemos la comprobación y le decimos que si falla nos lo notifique por pantalla:
if(res != 3) console.log("Algo va mal");
//------------------------------------------------------------------------------------------