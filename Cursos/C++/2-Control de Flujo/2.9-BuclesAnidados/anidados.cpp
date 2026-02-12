/*
-------------------------------------------------------------------------------------------------------
Bucles Animados
-------------------------------------------------------------------------------------------------------
- ¿Qué son los bucles anidados?

    - Bucle dentro de otro bucle ("muñecas rusas").

    - Pueden ser varios niveles.

    - Permiten recorrer estructuras complejas o generar combinaciones.

- Usos frecuentes de bucles anidados

    - Recorrer arrays y matrices multidimensionales.

    - Generar todas las combinaciones posibles.

    - Simulaciones con múltiples parámetros.

    - Programas de fuerza bruta.

    - Procesamiento gráfico o imágenes (píxel por píxel).

    - Programar tableros de juegos.

    - Algoritmos de ordenación (como burbuja).

    - Operaciones con cadenas y subcadenas.

    - Creación de interfaces/tableros.

- Ejemplo clásico: Tablas de multiplicar

    - Declarar rangos de factores.

    - Bucle exterior: recorre el número base (1 a 10).

    - Bucle interior: recorre los multiplicadores (1 a 10).

    - Imprime resultados tipo "2 x 4 = 8".

    -Usa salto de línea para separar tablas.

- Flujo de ejecución en bucles anidados

    - El bucle exterior avanza solo cuando termina el interior.

    - El interior se reinicia para cada nuevo ciclo del exterior.

    - Se recorren todas las combinaciones posibles de los rangos dados.

- Planteamiento de ejercicio/juego (fin del vídeo)

    - Programa genera un número aleatorio entre 1 y 100.

    - Usuario intenta adivinarlo en máximo 5 intentos.

    - Mensajes de "más alto" y "más bajo" según la respuesta.

    - Al fallar se muestra el número secreto.

    - Pregunta si quiere jugar de nuevo.

    - Utiliza bucles anidados para la lógica del juego.
-------------------------------------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int main(){
    const int MINUM = 1;
    const int MAXN = 10;
    for (int i = MINUM; i <= MAXN; i++) {
        cout << "Tabla del " << i << endl;
        for (int j = MINUM; j <= MAXN; j++) {
            cout << i << " x " << j << " = " << i*j << endl;
        }
        cout << endl; // Espacio entre tablas
    }
    return 0;
}