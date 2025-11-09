/*
-------------------------------------------------------------------------------------------------------
Crea un programa que simule una calculadora de estadísticas para una lista de números.

Debe permitir al usuario:

Introducir varios números.

Ver un menú con opciones (suma, media, máximo, mínimo, salir).

Cada opción debe ejecutarse mediante métodos de una clase llamada CalculadoraVector.

Usa vectores para almacenar los números, switch-case para el menú y funciones miembro para los cálculos.
-------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

class Estadistica {
private:
    vector<double> datos;

public:
    void introducirNumeros() {
        int tam;
        cout << "Cuantos valores quieres meter dentro: ";
        cin >> tam;

        double valor;
        for(int v = 0; v < tam; v++){
            cout << "Introduce el valor " << v+1 << ": ";
            cin >> valor;
            datos.push_back(valor);
        }
    }

    void mostrarNumeros() const {
        cout << "Los valores almacenados son: ";
        for(double n:datos) cout << n << ", ";
        cout << endl;
    }

    double suma() const {
        double res = 0;
        for(double n : datos) res += n;
        return res;
    }

    double media() const {
        if(datos.empty()) return 0;
        return suma() / datos.size();
    }

    double max() const {
        if(datos.empty()) return 0;
        double max = datos[0];
        for(int i = 1; i < datos.size(); i++)
            if(datos[i] > max) max = datos[i];
        return max;
    }

    double min() const {
        if(datos.empty()) return 0;
        double min = datos[0];
        for(int i = 1; i < datos.size(); i++)
            if(datos[i] < min) min = datos[i];
        return min;
    }
};

int main(){
    int opcion;
    Estadistica est;
    do{
        cout << "=======================================" << endl;
        cout << "           MENÚ DE OPCIONES            " << endl;
        cout << "=======================================" << endl;
        cout << "1. Introducir números.                 " << endl;
        cout << "2. Mostrar números.                    " << endl;
        cout << "3. Calcular suma.                      " << endl;
        cout << "4. Calcular media.                     " << endl;
        cout << "5. Mostrar número máximo.              " << endl;
        cout << "6. Mostrar número mínimo.              " << endl;
        cout << "7. Salir.                              " << endl;
        cout << "=======================================" << endl;
        cin >> opcion;

        switch(opcion){
            case 1: est.introducirNumeros(); break;

            case 2: est.mostrarNumeros(); break;

            case 3: cout << "Suma: " << est.suma() << endl; break;

            case 4: cout << "Media: " << est.media() << endl; break;

            case 5: cout << "Máximo: " << est.max() << endl; break;

            case 6: cout << "Mínimo: " << est.min() << endl; break;

            case 7: cout << "Saliendo..." << endl; break;

            default: cout << "Opción no valida" << endl; break;
        }
    }while(opcion != 7); return 0;
}