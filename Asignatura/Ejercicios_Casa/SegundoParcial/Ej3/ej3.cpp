#include <iostream>
#include <cmath>
using namespace std;

class Punto{

    private:
        double x; double y; 

    public:
        //Constructor
        Punto(double X, double Y): x(X), y(Y) {};
        //Setters
        void setX(double X){
            x = X;
        }

        void setY(double Y){
            y = Y;
        }
        //Getters
        double getX(){
            return x;
        }

        double getY(){
            return y;
        }
        //Método distancia.
        double distancia(Punto p){
            return sqrt(pow(x - p.getX(), 2) + pow(y - p.getY(), 2));
        }
};

class Circulo{

    private:
        double Radio = 0; Punto Centro;

    public:
        //Constructor
        Circulo(double Radio, Punto Centro): Radio(Radio), Centro(Centro) {};
        //Setters
        void setRadio(double radio){
            Radio = radio;
        }

        void setCentro(Punto centro){
            Centro = centro;
        }
        //Getters
        double getRadio(){
            return Radio;
        }

        Punto getCentro(){
            return Centro;
        }
        //Método Radio.
        double Perimetro(double radio){
            return 2 * M_PI * radio;
        }
}; 

Punto puntoDerechaAbajo(Circulo circulos[], int size){

    double maxX = circulos[0].getCentro().getX();
    double minY = circulos[0].getCentro().getY();

    for(int i = 1; i < size; i++){
        Punto c = circulos[i].getCentro();

        if(c.getX() > maxX) { maxX = c.getX();};
        if(c.getY() < minY) { minY = c.getY();}; 
    }

    return Punto(maxX, minY);
}

int main(){
    Circulo C1(3, Punto(3,4));
    Circulo C2(2, Punto(2,2));
    Circulo C3(1, Punto(4,1));
    Circulo C4(1, Punto(-1,-1));

    Circulo circulos[4] = {C1, C2, C3, C4};

    Punto Prueba = puntoDerechaAbajo(circulos, 4);
    Circulo Res = C3;

    if(Prueba.getX() != C3.getCentro().getX() && Prueba.getY() != C3.getCentro().getY()){
        cout << "Algo falla" << endl;
    } cout << "Que guapo eres ostia" << endl;
} 