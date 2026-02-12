//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
// Creación de la clase tiempo
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

class Tiempo{

    private: //Atributos privados

        unsigned int horas;
        unsigned int minutos;
        unsigned int segundos;

    public:
        //-----------------------------------------------------------------------------
        //Constructor

        Tiempo(unsigned int _horas, unsigned int _minutos, unsigned int _segundos){

            //----------------------------------------------------

            unsigned int extraMin = _segundos / 60;

            this->segundos = _segundos % 60;
            //----------------------------------------------------

            unsigned int totalMin = _minutos + extraMin; 

            unsigned int extraHoras = totalMin / 60;

            this->minutos = totalMin % 60;

            //----------------------------------------------------
            this->horas = _horas + extraHoras;
            //----------------------------------------------------
        }
        //-----------------------------------------------------------------------------
        //Getters
        
        unsigned int getHoras() const {
            return horas;
        }

        unsigned int getMinutos() const {
            return minutos;
        }
        unsigned int getSegundos() const {
            return segundos;
        }
        //-----------------------------------------------------------------------------
        //Métodos
        void imprimir() const {

            if(horas < 10) {cout << "0";};
            cout << horas << ":";
            //----------------------------------------------------
            if(minutos < 10) {cout << "0";};
            cout << minutos << ":";
            //----------------------------------------------------
            if(segundos < 10) {cout << "0";};
            cout << segundos;
        }
        //-----------------------------------------------------------------------------
        Tiempo sumar(const Tiempo& otro) const {

            return Tiempo(
                this-> horas + otro.horas,
                this-> minutos + otro.minutos,
                this-> segundos + otro.segundos
            );
        
        }
        //-----------------------------------------------------------------------------
        void agregarSegundos(unsigned int seg){
            
            this->segundos = this->segundos + seg;
            //----------------------------------------------------
            unsigned int extraMin = this->segundos / 60;
            this->segundos = this->segundos % 60;

            this->minutos += extraMin;
            //----------------------------------------------------
            unsigned int extraHoras = this->minutos / 60;
            this->minutos = this->minutos % 60;

            this->horas += extraHoras;
            //----------------------------------------------------
        }
        //-----------------------------------------------------------------------------
};

int main() {
    // 1. Prueba de Normalización en el Constructor
    Tiempo t1(0, 61, 61); 
    cout << "T1 (Deberia ser 01:02:01): ";
    t1.imprimir(); 
    cout << endl;

    // 2. Prueba de Getters
    if(t1.getMinutos() == 2) cout << "[OK] Minutos correctos" << endl;
    else cout << "[ERROR] Fallan los minutos" << endl;

    // 3. Prueba de Agregar Segundos
    t1.agregarSegundos(3600); // Sumamos 1 hora en segundos
    cout << "T1 + 1h (Deberia ser 02:02:01): ";
    t1.imprimir(); 
    cout << endl;

    // 4. Prueba de Sumar dos objetos
    Tiempo t2(10, 0, 0);
    Tiempo t3 = t1.sumar(t2); // 02:02:01 + 10:00:00
    cout << "Suma (Deberia ser 12:02:01): ";
    t3.imprimir(); 
    cout << endl;

    // 5. Verificar que T1 no ha cambiado (Const correctness)
    cout << "T1 original sigue igual?: "; 
    t1.imprimir(); // Debería seguir siendo 02:02:01
    cout << endl;

    return 0;
}
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------