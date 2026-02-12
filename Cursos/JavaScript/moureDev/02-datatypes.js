//------------------------------------------------------------------------
//  datatypes o tipos de datos
//------------------------------------------------------------------------

//  Cadena de texto (string)

const myname = "Carlos";
const alias = 'Xety';
const email = `xety.cgc@gmail.com`;

//------------------------------------------------------------------------

//  Números (number)

const age = 18; //Entero
const altura = 1.75; //Decimal

//------------------------------------------------------------------------

//  Booleanos (boolean)

const isStudent = true;
const isTeacher = false;

//------------------------------------------------------------------------

//  Undefined

let undefinedValue; //Valor declarado pero sin inicializar.
console.log(undefinedValue); 

//------------------------------------------------------------------------

//  Null

let nullValue = null;
//  Representa que intencionadamente en este punto la variable es nula.
//  Se mostrara en consola como objeto.

//------------------------------------------------------------------------

// Symbol 

let mySymbol = Symbol("mysymbol");

//  Intenta representar esos valores únicos o propiedades de futuros objetos.
//  Sirven para evitar colisiones entre propiedades.

//------------------------------------------------------------------------

//  BigInt

let myBigInt = BigInt(37583750894234823094820398409238409288073089174089347098457230948723);
let myBigInt2 = 375837508973089174987239842389472398999898798987454854089347098457230948723n;

//  Util para cuando nos pasemos de 64bits que es lo que tiene
//  reservado la arquitectura del sistema.

//------------------------------------------------------------------------
//  console.log(typeof "nombre de la variable") -> muestra el tipo 
//  de dato almacenado en la variable.
//------------------------------------------------------------------------