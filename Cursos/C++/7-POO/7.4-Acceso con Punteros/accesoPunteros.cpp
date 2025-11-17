/*
-----------------------------------------------------------------------------------------------------------------------------
Acceso a propiedades y métodos mediante punteros
-----------------------------------------------------------------------------------------------------------------------------
- Gestión de memoría dinámica. generar punteros de manera dinámica. ("new").

- Para poder hacer trabajo con Herencia y poliformismo.

- Estrucuturas de daros dinámicas.

- Paso de obketos a funciones.

- Manejo de APIs y Bibliotecas.

- Patrondes de diseño.

- Callbacks y manejo de eventos.

- Optimización de rendimiento.
-----------------------------------------------------------------------------------------------------------------------------
EJM:
*/

#include <iostream>
#include <cmath>
using namespace std;


class coche{

    //Atributos o propiedades:
    string modelo;
    string color;
    int cilindrada;
    int potencia;
    double precio; 

    //Métodos o comportamientos:
    public:

        void setPrecio(double p){
            if(p > 0) precio = p;
            if(p < 0) precio = abs(p);
        }

        double getPrecio(){
            return precio;
        }

        void arrancar(){
            cout << "El coche está arrancando." << endl;
        }

        void acelerar(){
            cout << "El coche está acelerando." << endl;
        }

        void frenar(){
            cout << "El coche está frenando." << endl;
        }

        void girar(){
            cout << "El coche está girando." << endl;
        }

        bool enmarcha(){
            return true;
        }

        //Crear punteros a objetos:

};

int main(){

    coche cocheMaria;

    coche cocheJuan;

    //Crear punteros a objetos:

    coche *pcocheMaria = &cocheMaria;

    coche *pcocheJuan = &cocheJuan;

    //Usar el puntero para acceder a los métodos de objeto cocheJuan:

    pcocheJuan->setPrecio(37000);

    cout << "El precio del coche es: " << pcocheJuan->getPrecio() << " €." << endl;

    //Usando el puntero para acceder a métodos de cocheMaria:

    pcocheMaria->acelerar();

    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------