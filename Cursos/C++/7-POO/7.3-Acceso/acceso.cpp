/*
-----------------------------------------------------------------------------------------------------------------------------
Acceso a propiedades y métodos.
-----------------------------------------------------------------------------------------------------------------------------
- Nomenclatura del punto:

    - Objeto.propiedad = valor;

    - Objeto.método;
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

        void setPrecio(double p){ //Método de acceso.
            if(p < 0){precio = abs(p);} else {precio = p;}
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

};

int main(){

    coche cocheMaria;

    coche cocheJuan;

    cocheJuan.setPrecio(-27000);

    cout << "El precio del coche es: " << cocheJuan.getPrecio() << " €" << endl;

    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------