/*
-------------------------------------------------------------------------------------------------------------------------------
Devolución de punteros
-------------------------------------------------------------------------------------------------------------------------------
- Casos de uso:

    - Acceso a Estructuras de Datos o Clases: Devolviendo un puntero a una instancia, permites que otras partes de tu programa
    interactúen con ella.

    - Eficiencia en la Gestión Memoría: Al devolver un puntero, evitas la copia innecesaria de datos, ya que simplemente
    estás pasando la dirección de memoria donde reside el objeto o los datos.

    - Control sobre la Vida Útil de los Objetos: cuando devuelves un puntero a un objeto creado dinámicamente
    (por ejemplo, usando new), puedes controlar cuánto tiempo existe ese objeto. El objeto puede seguir existiendo
    incluso después de que la fnción que lo creó haya terminado su ejecución.

    - Funciones que devuelven Múltiple Valores: Devolver un puntero a una estructura o arreglo puede ser una forma
    más eficiente de devolver múltiples valores, especialmente si el tamaó del resultado no se conoce de antemano.
--------------------------------------------------------------------------------------------------------------------------------
EJM:
*/
#include <iostream>
using namespace std;

class Coche{

    private:
        //Atributo de la clase coche.
        string modelo;

    public:
        //Método para inicializar el modelo del coche.
        Coche(string modelo): modelo(modelo) {}

        //Método para obtener el módelo del coche.
        string getModelo()const{
            return modelo;
        }

};

//Función que crea un nuevo coche y devuelve un puntero a él.
Coche* nuevoChoche(string modelo){
    Coche* nuevoChoche = new Coche(modelo);

    return nuevoChoche;
}

int main(){

    //Crea coche llamando a la función.

    Coche* miCoche = nuevoChoche("Maza MX5"); //Esto nos devuelve el puntero que devolvía la función.

    //Accede al módelo del coche a través del puntero y muestra el modelo.
    cout << "Modelo del coche : " << miCoche->getModelo() << endl;

    //Es importante liberar la memoría que hemos terminado de usarla.

    delete miCoche;

    return 0;
}
//------------------------------------------------------------------------------------------------------------------------------