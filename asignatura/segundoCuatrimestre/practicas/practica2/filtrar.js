/*--------------------------------------------------------------------------------------------
Fichero: filtrar.js
Autor: Carlos Galán Cubells
Fecha: 18/02/2026
Descripción: Creaación de la función filtrar, la cuál filtra los elementos de un arreglo
--------------------------------------------------------------------------------------------*/
//------------------------------------------------------------------------------------------
//  Diseño: Lista<T> + T -> filtrar() -> Lista<T>
//------------------------------------------------------------------------------------------
function filtrar(lista, condicion){
        let listaFiltrada = [];

        for( let i = 0; i < listaFiltrada.length; i++){

            let elemento = lista[i];
            
            if(condicion(elemento)){
                listaFiltrada.push(elemento);
            }
        }
}
//------------------------------------------------------------------------------------------
//  Prueba automática
//------------------------------------------------------------------------------------------
const listaDePalabras = ["examen", "casa", "texto", "xilófono", "árbol", "taxi", "perro"];

function tieneX(palabra){
    return palabra.includes('x');
}

const resultado = filtrar(listaDePalabras, tieneLetraX);

console.log("Palabras originales: ",listaDePalabras);
console.log("Palabras con X: ", resultado);

//------------------------------------------------------------------------------------------