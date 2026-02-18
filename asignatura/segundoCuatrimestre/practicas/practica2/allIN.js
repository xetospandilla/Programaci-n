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

//
const palabras = ["Es", "ahora", "tu", "oportunidad", "para", "aprovechar", "este", "día"];
//

function invertir(palabra){ 
    return palabra.split('').reverse().join('');
};
const listaInvertida = mapear(palabras, invertir);

console.log("1. Del revés: ", listaInvertida);

function sumarLargo(acumulado, palabra){
    return acumulado + palabra;
}
const totalCaracteres = reductor(palabras, 0, sumarLargo);
console.log("2.Total de caracteres: ", totalCaracteres);

function esLarga(palabra){
    if(palabra.length > 5) return true;
    return false;
}
const palabrasLargas = filtrar(palabras,esLarga);
const cantidadLargas = palabrasLargas.length;

console.log("3.Cantidad > 5 letras: ", cantidadLargas);