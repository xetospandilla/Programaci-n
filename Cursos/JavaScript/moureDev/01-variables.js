//------------------------------------------------------------------------
//  Variables | Útil para guardar valores en memoría |
//------------------------------------------------------------------------

//var

var helloWorld = "Hello, JavaScript";
console.log(helloWorld);

helloWorld = "Hola de nuevo, JavaScript";
console.log(helloWorld);

/*
Var -> las variables declaradas con var tienen un ámbito de función (local) o global. 
Se pueden volver a declarar. 

Hoisting(declaración / asignación) => Se peude accder a ellas antes de que estén declaradas
porque se elevan al principio del fichero. Si imprimimos en consola una variable que 
aún no está declarada no lo indicará mostrando "undefined".
*/

//------------------------------------------------------------------------

//let

let helloWorld2 = "Hello, JavaScript2";
console.log(helloWorld2);

helloWorld2 = "Hola de nuevo, JavaScript2";
console.log(helloWorld2);

/*
let -> las variables declaradas con let tienen un ámbito de bloque ({}).
    de su bloque de ejecución. Se eleva igualmente al principio del fichero igual que var,
    pero no se puede acceder antes de ellas antes de que estén declaradas o fuera

*/

//------------------------------------------------------------------------

//const

const helloWorld3 = "Hello, JavaScript3";
console.log(helloWorld3);

//helloWorld3 = "Hola de nuevo, JavaScript3";
//console.log(helloWorld3);


/*
const -> funciona igual que let respecto a su bloque de ejecución,
        pero la variable no es modificable. Su valor es CONSTANTE,
        no puede variar tras su declaración.
*/
//------------------------------------------------------------------------
//  Se recomienda utilizar únicamente let y const, ya que var suele dar
//  más problemas y causar más errores.
//------------------------------------------------------------------------

