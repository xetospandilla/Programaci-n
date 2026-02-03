//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//-----------------------------------------------------------------------------------------------
class Punto{

    private:

        double x; double y;

    public:

        Punto(int X = 0, int Y = 0){
            this-> x = X;
            this-> y = Y;
        }

        double getX() const { return x;}

        double getY() const { return y;}

        double distancia(const Punto& otro) const {
            double restaX = otro.x - this->x;
            double restaY = otro.y - this->y;

            return sqrt(pow(restaX, 2) + pow(restaY, 2));
        }
};
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
class Circulo{

    private:

        Punto Centro;
        double radio = 0;

    public:

        Circulo(double r, Punto p){
            this-> radio = r;
            this-> Centro = p;
        }

        double calcularArea() const {
            return pow(this->radio, 2) * M_PI;
        }

        double calculaPerímetro() const {
            return this->radio * M_PI * 2;
        }

        double distanciaA(const Punto& otro) const{
            return this->Centro.distancia(otro);
        }
};
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
class Conjunto{

    private:

        vector<double> elementos;

    public:

        Conjunto() {};

        void vaciar(){
            elementos.clear();
        }

        bool contiene(double valor) const {

            for(unsigned int i = 0; i < elementos.size(); i++){
                if(elementos[i] == valor){ return true; };
            } return false;
        }

        void agregar(double valor){
            if(!contiene(valor)) { elementos.push_back(valor); }
        }

        void eliminar(double valor){
            for(unsigned int i = 0; i < elementos.size(); i++){
                if(elementos[i] == valor){ elementos.erase(elementos.begin() + i); }
            }
        }

        double getElemento(unsigned int valor) const {
            return elementos[valor];
        }

        Conjunto unir(const Conjunto& otro) const {
            Conjunto resultado;

            for(unsigned int i = 0; i < elementos.size(); i++){
                resultado.agregar(otro.getElemento(i));
            }

            return resultado;
        }

        unsigned int talla() const {
            return elementos.size();
        }

        void imprimir() const {
            cout << "{";
            for(unsigned int i = 0; i < elementos.size(); i++){
                cout << elementos[i] << ", ";
            }
            cout << "}" << endl;
        }
};
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
class Polinomio{

    private: 

        vector<double> coeficientes;

    public:

        Polinomio(unsigned int grado){
            coeficientes.resize(grado + 1);
        }

        void setCoeficiente(unsigned int exponente, double valor){
            if(exponente >= coeficientes.size()){
                coeficientes.resize(exponente + 1, 0.0);
            }

            coeficientes[exponente] = valor;
        }

        double getCoeficiente(unsigned int exponente) const {
            if(exponente < coeficientes.size()){
                return coeficientes[exponente];
            }
        }

        double evaluar(double x) const {
            double suma = 0.0;
            for(unsigned int i = 0; i < coeficientes.size(); i++){
                if(coeficientes[i] != 0.0){
                    suma += coeficientes[i] * pow(x, i);
                }
            }
            return suma;
        }

        unsigned int getGrado() const {
            if(coeficientes.empty()) return 0;

            return coeficientes.size();
        }

        void imprimir() const {
            for(int i = getGrado(); i >= 0; i--){
                if(coeficientes[i] != 0){
                    cout << coeficientes[i] << "x^" << i << " ";
                    if( i > 0) cout << "+ ";
                }
            }
            cout << endl;
        }
};
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
