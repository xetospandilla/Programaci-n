/*--------------------------------------------------------------------------------------------
Fichero: allIn.js
Autor: Carlos Galán Cubells
Fecha: 18/02/2026
Descripción: Utilizando las funciones creadas en la práctica 2 para asimilar su uso.
--------------------------------------------------------------------------------------------*/
//------------------------------------------------------------------------------------------
//  Herramientas principales: filtrar, mapear, reductor
//------------------------------------------------------------------------------------------
function filtrar(lista, condicion) {
    let listaFiltrada = [];
    for (let i = 0; i < lista.length; i++) {
        if (condicion(lista[i])) {
            listaFiltrada.push(lista[i]);
        }
    }
    return listaFiltrada;
}

function mapear(lista, transformacion) {
    let nuevaLista = [];
    for (let i = 0; i < lista.length; i++) {
        nuevaLista.push(transformacion(lista[i]));
    }
    return nuevaLista;
}

function reductor(lista, valorInicial, funcionReductora) {
    let acumulado = valorInicial;
    for (let i = 0; i < lista.length; i++) {
        acumulado = funcionReductora(acumulado, lista[i]);
    }
    return acumulado;
}
//------------------------------------------------------------------------------------------
//  Arreglo de palabras que utilizaremos en las pruebas automáticas: 
const palabras = ["Es", "ahora", "tu", "oportunidad", "para", "aprovechar", "este", "día"];

//  Invertir las palabras del arreglo:
function invertir(palabra){ 
    return palabra.split('').reverse().join('');
};
const listaInvertida = mapear(palabras, invertir);

console.log("1. Del revés: ", listaInvertida);

//  Total de caratéres del arreglo:
function sumarLargo(acumulado, palabra){
    return acumulado + palabra;
}
const totalCaracteres = reductor(palabras, 0, sumarLargo);
console.log("2.Total de caracteres: ", totalCaracteres);

//  Ver si una palabra tiene más de 5 letras o no:
function esLarga(palabra){
    if(palabra.length > 5) return true;
    return false;
}
const palabrasLargas = filtrar(palabras,esLarga);
const cantidadLargas = palabrasLargas.length;

console.log("3.Cantidad > 5 letras: ", cantidadLargas);
//------------------------------------------------------------------------------------------