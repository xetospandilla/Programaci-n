//------------------------------------------------------------------------------------------
//  Diseño: Lista<T1> + T + T1->T2 -> reducir() -> T2
//------------------------------------------------------------------------------------------
function reductor(lista, valorInicial, funcionReductora){
    let nuevoValor = valorInicial;

    for(let i = 0; i < lista.length; i++){
        let elemento = lista[i];

        nuevoValor = funcionReductora(acumulado, elemento);
        
    }

    return nuevoValor;
}
//------------------------------------------------------------------------------------------
//  Prueva automática
//------------------------------------------------------------------------------------------
const numeros = [1, 2, 3, 4, 5];

function sumar(a,b){
    return a + b;
}

const resultado = reductor(numeros, 0, sumar);

console.log("Resultado final:", resultado);
//------------------------------------------------------------------------------------------