//console.log("Hola Mundo"); //Esto hace la función de imprimir en pantalla en JavaScript

/*
    var -> las variables declaradas con var tienen un ámbito de función (local) o global. Se pueden volver a declarar. Hoisting(declaración / asignación).

    let -> las variables declaradas con let tienen un ámbito de bloque ({}). 
    

    Funciones básicas o sencillas: Una expresión de función flecha es una alternativa compacta a una expresión de función traciconal.
    
    Funciones asíncronas: SetTimeout, Promise, async/await.
*/
//------------------------------------------------------------------------------------------------------
//Primeras pruebas y conceptos:

var saludo = "Hola Mundo";
console.log(saludo);

function sumar(a,b){
    return a + b;
}

const sumar = (a,b) => { return a+b; }

//------------------------------------------------------------------------------------------------------

function factorial(a){
    let n = 1; 

    for(let i = 0; i < a; i++){
        n *= i;
    }

    return n;
}

//------------------------------------------------------------------------------------------------------