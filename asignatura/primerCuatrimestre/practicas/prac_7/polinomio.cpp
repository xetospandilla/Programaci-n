/*
--------------------------------------------------------------------------------------------
Fichero: mainPruebas.cpp
Fecha: 7-1-2026
Descripción: Creación de la clase Polinomio en C++.
Autor: Carlos Galán Cubells
--------------------------------------------------------------------------------------------
*/
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
using namespace std;
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
class Polinomio{

    private:

        vector<double> coeficientes;

    public:

        // --- Constructor ---
        
        Polinomio(){
            coeficientes.push_back(0.0); 
        }; //Crea un polinomio "0" (Vacio).

        // --- Métodos Básicos (Setters y Getters).

        //Devuelve el grado del polinomio (El exponente más alto).
        unsigned int grado() const {
            return coeficientes.size() - 1;
        }

        //Devuelve el valor del coeficiente para ese exponente 'i'.
        double coeficiente(unsigned int i) const {
            if( i >= coeficientes.size()){
                return 0.0;
            } return coeficientes[i];
        }

        //Método que nos permitirá construir el polinomio manualmente poniendo valores.
        void setCoeficiente(unsigned int i, double valor){
            if( i >= coeficientes.size()){
                coeficientes.resize(i + 1, 0.0); /*La función .resize() -> Mira el tamaño actual, mira el nuev tamaño que le pides
                Calcula los hucos q le faltan, estira el vector y rellena esos huecos con el valor q le hemos dado (0.0).*/
            } coeficientes[i] = valor;
        }

        // Evalúa el polinomio para un valor concreto de x
        double valor(const Polinomio& otro) const {
            double suma = 0.0;

            // Recorremos todos los coeficientes
            for (unsigned int i = 0; i < coeficientes.size(); i++) {
                // Fórmula: coeficiente * (x elevado a i)
                // Ejemplo: 2.0 * pow(x, 2)
                double suma = coeficiente(i) + otro.coeficiente(i);
            }

            return suma;
        }

        //Multiplica el polinomio por un númro real
        Polinomio multiplicar(double factor) const {

            //Creamos un polinomio nuevo vacio.
            Polinomio resultado;

            //Recorremos nuestros coeficientes.
            for (unsigned int i = 0; i < coeficientes.size(); i++){
                //Cálculamos el nuevo valor multiplicado.
                double nuevoValor = coeficientes[i] * factor;

                //Lo guardamos en el polinomio nuevo.
                resultado.setCoeficiente(i, nuevoValor);
            }

            //Devolvemos el objeto nuevo listo para usar.
            return resultado;
        }

        // Suma dos polinomios y devuelve uno nuevo
        Polinomio sumar(const Polinomio& otro) const {
            Polinomio resultado;

            //Averiguamos cuál de los dos tiene el grado más alto
            unsigned int gradoMax = max(grado(), otro.grado());

            //Recorremos desde 0 hasta el grado máximo
            for(unsigned int i = 0; i <= gradoMax; i++){
                //Pedimos los coeficientes. Si uno es más pequeño
                // su método 'coeficientes(i)' devolverá 0.0 automáticamente.
                double suma = coeficientes[i] + otro.coeficientes[i];

                //Guardamos el resultado si la suma no es cero
                if(suma != 0.0){
                    resultado.setCoeficiente(i , suma);
                }
            }
            return resultado;
        }

        //Método para introducir polinomios de manera escrita.
        string aTexto() const{
            string salida = "";
            bool primerTermino = true; //Para saber si poner el simbolo '+'.

            for(unsigned int i = 0; i < coeficientes.size(); i++){
                double valor = coeficientes[i];

                //Solo imprimimos el coeficientes si no es cero( o si es el término independiente).
                if(valor != 0.0 || (i == 0 && coeficientes.size() == 1)){
                    
                    //Ponemos el '+' separadorm salvo que sea el primero
                    if(!primerTermino){ if(valor > 0) { salida += " + "; } else { salida += " "; }; /*El negativo ya trae su signo '-'*/}
                    salida += to_string(valor);
                    //Añadimos la x y el exponente
                    if (i == 1) { salida += "x"; } else if (i > 1) {salida += "x^" + to_string(i);}

                    primerTermino = false;
                }
            }
            return salida;
        }
};
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
int main() {
    cout << "=== PRUEBA POLINOMIO ===" << endl;

    // 1. Creamos P1(x) = 3 + 2x^2
    Polinomio p1;
    p1.setCoeficiente(0, 3.0);
    p1.setCoeficiente(2, 2.0);
    cout << "Polinomio 1: " << p1.aTexto() << endl;

    // 2. Creamos P2(x) = 1 + 5x (Uno mas pequeño)
    Polinomio p2;
    p2.setCoeficiente(0, 1.0);
    p2.setCoeficiente(1, 5.0);
    cout << "Polinomio 2: " << p2.aTexto() << endl;

    // 3. SUMA (El momento de la verdad)
    // Debería dar: (3+1) + 5x + 2x^2  ->  4 + 5x + 2x^2
    Polinomio suma = p1.sumar(p2);
    
    cout << "-----------------------------" << endl;
    cout << "SUMA (P1 + P2): " << suma.aTexto() << endl;
    
    // Verificaciones automáticas
    if (suma.coeficiente(0) == 4.0 && suma.coeficiente(1) == 5.0 && suma.coeficiente(2) == 2.0) {
        cout << "[OK] La suma es matematicamente correcta." << endl;
    } else {
        cout << "[ERROR] Los coeficientes no cuadran." << endl;
    }

    return 0;
}
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------