//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
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

        //-------------------------------------------------------------------------------------
        //-------------------------------------------------------------------------------------
        //-------------------------------------------------------------------------------------
        //-------------------------------------------------------------------------------------

        Conjunto noOrignales(vector <double> valores){

            Conjunto c; c.anyadir(1); c.anyadir(2); c.anyadir(4); //Está parte está mal. Hay que quitarla.

            Conjunto resultado;

            double elemento;

            //Bucles, fallo en la prioridad. Overflow.
            for(unsigned int i = 0; i < elementos.size(); i++){
                elemento = elementos[i];
                for(unsigned int z = 0; z < valores.size(); z++){
                    if(elementos[i] == valores[i]) resultado.elementos.push_back(valores[i]);
                }
            } return resultado;

            /*Corregido:
            
            for(unsigned int i = 0; i < valores.size(); i++){
                bool encontrado = false;

                for(unsigned int z = 0; z < elementos.size(); z++){
                    if(valores[i] == elementos[z]){ encontrado = true; break; }
                }

                if(encontrado = false) resulatdo.anyadir(valores[i]);
            } return resultado
            */
        }
    //-------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------
};
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------