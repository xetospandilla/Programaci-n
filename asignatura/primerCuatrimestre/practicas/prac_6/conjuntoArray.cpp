/*
--------------------------------------------------------------------------------------------
Fichero: mainPruebas.cpp
Fecha: 6-1-2026
Descripción: Creación de la clase Conjunto en C++ con array simple.
Autor: Carlos Galán Cubells
--------------------------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
class Conjunto {

    private:
        // --- Atributos ---
        // Contador de cuántos huecos estamos usando realmente.
        unsigned int numElementos;
        
        // Array estático. La capacidad máxima es 100 (fija).
        // Los datos reales van de 0 a numElementos-1.
        double elementos[100];

    public:

        // --- Constructor ---
        // Inicializa el contador a 0. El conjunto nace vacío.
        Conjunto() : numElementos(0) {}


        // --- Métodos Modificadores ---

        // "Borra" el contenido reseteando el contador.
        // Eficiencia: O(1) (Instantáneo, no recorre el array).
        void vaciar() {
            this->numElementos = 0;
        }

        // Añade un elemento si hay sitio y no está duplicado.
        void anyadir(double valor) {
            // 1. Seguridad: Comprobar si cabe (límite físico del array).
            if (numElementos >= 100) {
                return; 
            }

            // 2. Unicidad: Comprobar si ya existe (un conjunto no tiene repetidos).
            if (contiene(valor)) {
                return; 
            }

            // 3. Insertar: Guardamos al final y aumentamos el contador.
            elementos[numElementos] = valor;
            numElementos++;
        }

        // Elimina un elemento usando la técnica de "Sustitución por el último".
        void eliminar(double valor) {
            // Paso 1: Buscar la posición de la víctima.
            int posicion = donde(valor);

            // Paso 2: Si existe (es diferente de -1)...
            if (posicion != -1) {
                // ...machacamos el valor a eliminar copiando encima el ÚLTIMO valor del array.
                // Esto evita tener que mover todo el array (muy eficiente).
                elementos[posicion] = elementos[numElementos - 1];
                
                // Paso 3: Reducimos el tamaño para "ocultar" el duplicado que quedó al final.
                numElementos--;
            }
        }


        // --- Métodos Consultores (const) ---
        // Llevan 'const' porque preguntar no modifica el conjunto.

        // Devuelve la cantidad actual de elementos.
        unsigned int talla() const { 
            return numElementos; 
        }

        // Busca un valor y devuelve su índice (0 a 99).
        // Si no lo encuentra, devuelve -1 (código de error estándar).
        int donde(double valor) const {
            for (unsigned int i = 0; i < numElementos; i++) {
                if (elementos[i] == valor) {
                    return i; // ¡Encontrado! Devolvemos la posición.
                }
            }
            return -1; // Hemos recorrido todo y no está.
        }

        // Devuelve true si el elemento existe, false si no.
        // Se apoya en 'donde' para no repetir código logic.
        bool contiene(double valor) const {
            if (donde(valor) != -1) {
                return true;
            }
            return false;
        }

        //Método unir que une dos elementos en uno solo.
        Conjunto unir(const Conjunto& otro) const {
            
            // 1. Crear un conjunto nuevo y vacío para el resultado.
            Conjunto resultado;

            // 2. Copiar MIS elementos (this) en el resultado.
            for(unsigned int i = 0; i < numElementos; i++) {
                // Usamos anyadir para meterlos en el nuevo saco.
                resultado.anyadir(elementos[i]);
            }

            // 3. Copiar los elementos del OTRO conjunto en el resultado.
            // Al ser de la misma clase, podemos acceder a su parte privada 'elementos'.
            for(unsigned int i = 0; i < otro.numElementos; i++) {
                // Al usar anyadir(), si hay repetidos se ignoran automáticamente.
                resultado.anyadir(otro.elementos[i]);
            }

            // 4. Devolvemos el conjunto nuevo lleno.
            return resultado;
        }
};
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
int main() {
    cout << "=== INICIO DE LAS PRUEBAS AUTOMATICAS ===" << endl << endl;

    // ---------------------------------------------------------
    // 1. PRUEBA DEL CONSTRUCTOR Y TALLA
    // ---------------------------------------------------------
    Conjunto c;
    cout << "1. Probando Constructor y Talla inicial..." << endl;
    if (c.talla() == 0) {
        cout << "   [OK] El conjunto se crea vacio." << endl;
    } else {
        cout << "   [ERROR] El conjunto deberia tener talla 0." << endl;
    }

    // ---------------------------------------------------------
    // 2. PRUEBA DE ANYADIR Y CONTIENE
    // ---------------------------------------------------------
    cout << "\n2. Probando Anyadir y Contiene..." << endl;
    c.anyadir(10.5);
    
    // Verificamos que se añadió
    if (c.talla() == 1 && c.contiene(10.5)) {
        cout << "   [OK] Se anyadio el 10.5 correctamente." << endl;
    } else {
        cout << "   [ERROR] Fallo al anyadir 10.5." << endl;
    }

    // Añadimos otro
    c.anyadir(20.0);
    if (c.talla() == 2 && c.contiene(20.0)) {
        cout << "   [OK] Se anyadio el 20.0 correctamente." << endl;
    } else {
        cout << "   [ERROR] Fallo al anyadir 20.0." << endl;
    }

    // ---------------------------------------------------------
    // 3. PRUEBA DE DUPLICADOS (IMPORTANTE)
    // ---------------------------------------------------------
    cout << "\n3. Probando control de Duplicados..." << endl;
    c.anyadir(10.5); // Intentamos meter el 10.5 otra vez
    
    if (c.talla() == 2) {
        cout << "   [OK] Correcto: No se permiten duplicados (talla sigue siendo 2)." << endl;
    } else {
        cout << "   [ERROR] Fallo: Se ha permitido un duplicado (talla aumento)." << endl;
    }

    // ---------------------------------------------------------
    // 4. PRUEBA DE ELIMINAR
    // ---------------------------------------------------------
    cout << "\n4. Probando Eliminar..." << endl;
    // Situación actual: {10.5, 20.0}
    c.eliminar(10.5); // Borramos el primero

    if (c.talla() == 1 && !c.contiene(10.5) && c.contiene(20.0)) {
        cout << "   [OK] Se elimino el 10.5. Queda el 20.0." << endl;
    } else {
        cout << "   [ERROR] Fallo al eliminar." << endl;
    }

    // Probamos eliminar algo que NO existe
    c.eliminar(99.9);
    if (c.talla() == 1) {
        cout << "   [OK] Correcto: Eliminar algo inexistente no rompe nada." << endl;
    } else {
        cout << "   [ERROR] La talla cambio al intentar borrar algo inexistente." << endl;
    }

    // ---------------------------------------------------------
    // 5. PRUEBA DE VACIAR
    // ---------------------------------------------------------
    cout << "\n5. Probando Vaciar..." << endl;
    c.vaciar();
    if (c.talla() == 0 && !c.contiene(20.0)) {
        cout << "   [OK] El conjunto se ha vaciado correctamente." << endl;
    } else {
        cout << "   [ERROR] Vaciar fallo." << endl;
    }

    // ---------------------------------------------------------
    // 6. PRUEBA DE UNIR (Solo si has implementado unir)
    // ---------------------------------------------------------
    cout << "\n6. Probando Unir..." << endl;
    Conjunto A;
    A.anyadir(1.0);
    A.anyadir(2.0);

    Conjunto B;
    B.anyadir(2.0); // Repetido en A
    B.anyadir(3.0);

    // Unimos A y B. Debería dar {1.0, 2.0, 3.0}
    Conjunto C = A.unir(B);

    if (C.talla() == 3 && C.contiene(1.0) && C.contiene(2.0) && C.contiene(3.0)) {
        cout << "   [OK] La union es correcta." << endl;
    } else {
        cout << "   [ERROR] La union fallo. Talla resultante: " << C.talla() << endl;
    }

    cout << "\n=== FIN DE LAS PRUEBAS ===" << endl;
    return 0;
}
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------