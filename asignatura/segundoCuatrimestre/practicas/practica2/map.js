/*--------------------------------------------------------------------------------------------
Fichero: mapear.js
Autor: Carlos Galán Cubells
Fecha: 18/02/2026
Descripción: Creaación de la función mapear, la cuál modifica los elementos de un arreglo
--------------------------------------------------------------------------------------------*/
//------------------------------------------------------------------------------------------
//  Diseño: Transformación + lista>T1> -> mapear() -> lista<T2>
//------------------------------------------------------------------------------------------
function mapear(Transformación, lista){
    let nuevaLista = [];

    for(let i = 0; i < lista.length; i++){
        let elementoOriginal = lista[i];

        let elementoTransformado = Transformación(elementoOriginal);

        nuevaLista.push(elementoTransformado);
    }

    return nuevaLista;
}
//------------------------------------------------------------------------------------------
//  Prueba automática
//------------------------------------------------------------------------------------------

const listaDePalabras = ["examen", "casa", "texto", "xilófono", "árbol", "taxi", "perro"];

function obtenerLongitud(palabra){
    return palabra.lenght;
}

const resultado = mapear(listaDePalabras, obtenerLongitud);

console.log("Palabras: ", listaDePalabras);
console.log("Longitud de palabras: ", resultado);
//------------------------------------------------------------------------------------------