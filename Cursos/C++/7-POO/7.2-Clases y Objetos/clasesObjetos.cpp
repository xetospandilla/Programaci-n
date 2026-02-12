/*
-----------------------------------------------------------------------------------------------------------------------------
Clases y objetos
-----------------------------------------------------------------------------------------------------------------------------
- Clase

    - Modelo donde se redactan las características comunes de un grupo de objetos.

- Objeto

    - Ejemplar perteneciente a una clase. (Los objetos son derivados de una clase, ya que tiene unas características
    cómunes).

    - Pueden tener propiedades y métodos:

        - Propiedades: Que cualidades tiene un objeto. Sus atributos. Estos se pueden modificar.

        - Métodos: Las acciones que puede realizar el objeto. Su comportamiento. Estos se llaman.
-----------------------------------------------------------------------------------------------------------------------------
EJM:
*/

#include <iostream>
using namespace std;


class coche{

    //Atributos o propiedades:
    string modelo;
    string color;
    int cilindrada;
    int potencia;
    double precio;

    //Métodos o comportamientos:
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

    return 0; //BreackPont: Sirve para ejecutar un programa hasta antes de este punto.

}
//---------------------------------------------------------------------------------------------------------------------------