/*
--------------------------------------------------------------------------------------------
Fichero: puntosInteriores.cpp
Fecha: 28-12-2025
Descripción: Programa en C++ que busca en un array de puntos y devuelve los que están
dentro de un circulo.
Autor: Carlos Galán Cubells
--------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <cmath>
using namespace std;

class Punto {
    private: 
        double x; 
        double y;

    public:
        Punto(double X = 0, double Y = 0): x(X), y(Y) {}

        double getX() { return x; }
        double getY() { return y; }

        void setX(double X) { x = X; }
        void setY(double Y) { y = Y; }

        double distancia(Punto p) {
            return sqrt(pow(x - p.getX(), 2) + pow(y - p.getY(), 2));
        }

        Punto sumar(Punto p1, Punto p2) {
            double newX = p1.getX() + p2.getX();
            double newY = p1.getY() + p2.getY();
            return Punto(newX, newY);
    }
};
//------------------------------------------------------------------------------------------
class Circulo {
    private:
        double Radio; 
        Punto Centro;
    public:
        Circulo(double R, Punto p): Radio(R), Centro(p) {}

        void setRadio(double radio) { Radio = radio; }
        void setCentro(Punto centro) { Centro = centro; }

        double getRadio() { return Radio; }
        Punto getCentro() { return Centro; }

        double Perimetro() {
            return 2 * M_PI * Radio;
        }
};
//------------------------------------------------------------------------------------------

void puntosInteriores(Circulo c, Punto arr[], unsigned int size) {
    const int MAX_CAPACIDAD = 100;
    Punto interiores[MAX_CAPACIDAD];
    int encontrados = 0;

    for(int i = 0; i < size; i++) {
        if(encontrados >= MAX_CAPACIDAD) break;

        double dis = c.getCentro().distancia(arr[i]);

        if (dis < c.getRadio()) {
            interiores[encontrados] = arr[i];
            encontrados++;
        }
    }

    cout << "--- Puntos dentro del circulo ---" << endl;
    cout << "Total encontrados: " << encontrados << endl;
    
    for(int k = 0; k < encontrados; k++) {
        cout << "Punto: (" << interiores[k].getX() << ", " << interiores[k].getY() << ")" << endl;
    }
}

//------------------------------------------------------------------------------------------
//  PRUEBAS AUTOMÁTICAS
//------------------------------------------------------------------------------------------
int main() {
    Punto centro(0, 0);
    Circulo miCirculo(5.0, centro); 

    Punto listaPuntos[] = {
        Punto(1, 1),
        Punto(6, 0),
        Punto(3, 4),
        Punto(-2, 0),
        Punto(10, 10)
    };

    unsigned int tamano = sizeof(listaPuntos) / sizeof(listaPuntos[0]);

    puntosInteriores(miCirculo, listaPuntos, tamano);

    return 0;
}
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------