//-----------------------------------------------------------------------------------------------------
// FUNCIONES
//-----------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;
//-----------------------------------------------------------------------------------------------------
// 1. FUNCIONES RECURSIVAS
//-----------------------------------------------------------------------------------------------------
/*
Qué son: 
- Funciones que se llaman a sí mismas.
- Se usan para problemas que se pueden dividir en subproblemas idénticos.
- Siempre requieren un "caso base" para evitar bucles infinitos.
- Útiles: factorial, Fibonacci, recorridos de árboles, algoritmos divide & conquer.

Sintaxis:
tipoRetorno nombreFuncion(parametros) {
    if (condicionBase) return valorBase; // caso base
    return operacion(nombreFuncion(nuevoParametro));
}
Ejemplo:
*/

int factorial(int n) { 
    if (n == 0) return 1; // caso base
    return n * factorial(n - 1); // llamada recursiva
}

// Uso: 
// int f = factorial(5); // f = 120

//-----------------------------------------------------------------------------------------------------
// 2. FUNCIONES INLINE
//-----------------------------------------------------------------------------------------------------
/*
Qué son:
- Indicamos al compilador que reemplace la llamada a la función por el código de la función.
- Reduce overhead de llamada a función.
- Recomendadas para funciones **muy cortas**.

Sintaxis:
inline tipoRetorno nombreFuncion(parametros) { codigo; }

Ejemplo:
*/
inline int suma(int a, int b) {
    return a + b;
}

// Uso:
// int r = suma(3,4); // r = 7

/*
Tip: No abuses. Si la función es muy grande, inline puede aumentar tamaño del ejecutable y no mejorar eficiencia.
*/

//-----------------------------------------------------------------------------------------------------
// 3. SOBRECARGA DE FUNCIONES (Function Overloading)
//-----------------------------------------------------------------------------------------------------
/*
Qué es:
- Varias funciones con el mismo nombre pero diferente número o tipo de parámetros.
- Permite usar un solo nombre de función en distintos contextos.
- El compilador elige la función correcta según argumentos.

Sintaxis:
tipoRetorno nombreFuncion(tipo1 arg1, tipo2 arg2, ...)
tipoRetorno nombreFuncion(tipoX argX, ...)

Ejemplo:
*/
int maximo(int a, int b) {
    return (a > b) ? a : b;
}
double maximo(double a, double b) {
    return (a > b) ? a : b;
}

// Uso:
// int m1 = maximo(3, 5);        // usa int
// double m2 = maximo(3.2, 2.8); // usa double

/*
Tip: La sobrecarga permite escribir código más limpio y legible, evitando nombres redundantes.
*/

//-----------------------------------------------------------------------------------------------------
// 4. PASO DE PARÁMETROS: POR VALOR Y POR REFERENCIA
//-----------------------------------------------------------------------------------------------------
/*
Paso por valor:
- La función recibe una copia de la variable.
- Cambios dentro de la función **no afectan** a la variable original.

Paso por referencia:
- La función recibe la dirección de la variable.
- Cambios dentro de la función **afectan** a la variable original.
- Sintaxis: usar & en el parámetro.

Ejemplo:
*/
void cambiarValor(int x) { x = 100; }      // paso por valor
void cambiarValorRef(int &x) { x = 100; }  // paso por referencia

// Uso:
// int a = 10;
// cambiarValor(a);     // a sigue siendo 10
// cambiarValorRef(a);  // a ahora es 100

/*
Tip: 
- Por valor para valores simples que no quieres modificar.
- Por referencia para modificar variables o evitar copias grandes (arrays, structs, vectores grandes).
*/

//-----------------------------------------------------------------------------------------------------
// 5. PROTOTIPOS DE FUNCIONES
//-----------------------------------------------------------------------------------------------------
/*
Qué son:
- Declaración de la función antes de su uso.
- Permite organizar el código y usar funciones antes de definirlas.
- Útil en programas grandes y proyectos con múltiples archivos.

Sintaxis:
tipoRetorno nombreFuncion(tipo1, tipo2, ...);

Ejemplo:
*/
int sumaPrototipo(int, int); // prototipo

int main() {
    int resultado = sumaPrototipo(5, 7);
    cout << "Suma: " << resultado << endl;
    return 0;
}

// definición de la función después de main
int sumaPrototipo(int a, int b) {
    return a + b;
}

//-----------------------------------------------------------------------------------------------------
// CONSEJOS FINALES SOBRE FUNCIONES
//-----------------------------------------------------------------------------------------------------
/*
1. Nombres claros: reflejan lo que hacen (ej: calcularMedia, intercambiarValores).
2. Funciones cortas: una función = una responsabilidad.
3. Reutilización: evita duplicar código, usa sobrecarga si aplica.
4. Documenta: comentarios, parámetros, retornos.
5. Combina con arrays, vectores y punteros según la necesidad.
6. Usa prototipos para mantener código organizado.
-------------------------------------------------------------------------------------------------------
*/