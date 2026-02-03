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
            Centro = Centro;
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

Circulo CirculoMasLejano(Circulo arr[], int size){
    Punto origen(0,0); //(0,0) por defecto

    Circulo CirculoLejano(0,origen);
    double maxDist = 0;

    for(int i = 0; i < size; i++){
        double d = arr[i].getCentro().distancia(origen) - arr[i].getRadio();

        if(d > maxDist){
            maxDist = d;
            CirculoLejano = arr[i];
        }
    } return CirculoLejano;
}

int main(){

    Circulo C1(3,Punto(2,3));
    Circulo C2(2,Punto(4,3));
    Circulo C3(7,Punto(6,5));

    int size = 3;
    Circulo arr[3] = {C1, C2, C3};


    Circulo Prueba = CirculoMasLejano(arr, 3);
    Circulo Res = C2;

    if(Prueba.getRadio() == Res.getRadio() && Prueba.getCentro().getX() == Res.getCentro().getX() && Prueba.getCentro().getY() == Res.getCentro().getY()){
        cout << "Que guapo eres ostia" << endl;
    } else { cout << "Mariquita" << endl; }

    return 0;
}