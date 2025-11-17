/*
-----------------------------------------------------------------------------------------------------------------------------
Modificadores de acceso. Protected.
-----------------------------------------------------------------------------------------------------------------------------
- Vitales para controlar la visibilidad y el encapsulamiento en la POO. En C++. En C++ hay 3 modificadores de acceso:

    - Public: Accesible desde cualquier parte del programa(incluidos funcuiones y clases externas).

    - Private: Accesible solo desde dentro de la misma clase.

    - Protected: Accesible desde dentro de la misma clase y desde clases derivadas (herencia).

-----------------------------------------------------------------------------------------------------------------------------
EJM:
*/

#include <iostream>
using namespace std;

class miclase{
    protected:
        int edad; //Asi no será accesible desde el main, pero sí para las clases con herencia.
        
        /*IMPORTANTE:
        Si no se indica nada es por defecto una propiedad es privada. Aunque, es una buena práctica por el progimo y por ser un código
        más didactico, sería mejor poner o indicar que es "private". Además que ayuda a la claridad en programas complejos.
        */
    public:

        void setValor(int valor){

            if(valor < 0 || valor > 100){
                cout << "Número no compatible." << endl;

                edad = 0;
            } else edad = valor;
        }



};

class derivada:public miclase{ //Para hacer que una clase herede de otra:
    
    /*Al hacer que está clase herede de "miClase", tenga también por consecuente todos las variables, menos las encapsuladas
    (todo lo que estaba en "private") y todos los métodos. La principal ventaja de la herencia es la reutilización de código.*/

    public:

    int getEdad(){
        return edad;
    }
};

int main(){

    derivada obj;

    obj.setValor(35);

    obj.getEdad(); //Acediendo a método público

    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------