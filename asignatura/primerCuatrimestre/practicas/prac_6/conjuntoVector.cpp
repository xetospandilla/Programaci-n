/*
--------------------------------------------------------------------------------------------
Fichero: mainPruebas.cpp
Fecha: 6-1-2026
Descripción: Creación de la clase Conjunto en C++ utilizando vectores.
Autor: Carlos Galán Cubells
--------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <vector>
using namespace std;
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
class Conjunto {

    private:
        // --- Atributos ---
        // ¡Magia! Ya no necesitamos 'numElementos' ni definir tamaño [100].
        // El vector se encarga de todo.
        std::vector<double> elementos;

    public:

        // --- Constructor ---
        // El vector nace vacío por defecto. No hay que inicializar nada.
        Conjunto() {}

        // --- Métodos Modificadores ---

        // El vector tiene su propio método para vaciarse.
        void vaciar() {
            elementos.clear(); 
        }

        // Añadir es mucho más simple: no hay límite de espacio.
        void anyadir(double valor) {
            // 1. Solo comprobamos si ya existe (para no repetir).
            if (contiene(valor)) {
                return;
            }
            // 2. 'push_back' mete el valor al final y agranda el vector solo.
            elementos.push_back(valor);
        }

        // Eliminar sigue usando el "Truco del Último" para ser rápido.
        void eliminar(double valor) {
            int posicion = donde(valor);
            
            if (posicion != -1) {
                // Copiamos el último elemento encima del que queremos borrar
                // .back() nos da el último valor.
                elementos[posicion] = elementos.back();
                
                // Borramos la última casilla física del vector.
                elementos.pop_back(); 
            }
        }

        // La unión es idéntica, pero usando la sintaxis de vector.
        Conjunto unir(const Conjunto& otro) const {
            Conjunto resultado;

            // Copiamos los míos
            for(unsigned int i = 0; i < elementos.size(); i++) {
                resultado.anyadir(elementos[i]);
            }
            
            // Copiamos los del vecino
            for(unsigned int i = 0; i < otro.elementos.size(); i++) {
                resultado.anyadir(otro.elementos[i]);
            }

            return resultado;
        }

        // --- Métodos Consultores ---

        // Preguntamos al vector cuánto mide.
        unsigned int talla() const { 
            return elementos.size(); 
        }

        // 'donde' es igual, pero el límite es .size()
        int donde(double valor) const {
            for (unsigned int i = 0; i < elementos.size(); i++) {
                if (elementos[i] == valor) {
                    return i;
                }
            }
            return -1;
        }

        // 'contiene' es idéntico a la versión anterior.
        bool contiene(double valor) const {
            if (donde(valor) != -1) { return true; }
            return false;
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