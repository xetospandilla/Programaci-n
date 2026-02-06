/*
--------------------------------------------------------------------------------------------
Fichero: mainlejano.cpp
Fecha: 06-11-2025
Descripción: Programa en C++ que identifica entre dos puntos, cuál es más lejano al origen.
Autor: Carlos Galán Cubells
--------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <cmath> //Incluimos la librería cmath para poder realizar ciertos cálculos útiles.
using namespace std;
/*
--------------------------------------------------------------------------------------------
    Declaramos la clase punto:
--------------------------------------------------------------------------------------------
*/
class punto{
    public: 
        double x; double y;//Argumentos.
        punto(double x, double y): x(x), y(y) {}//Métodos: Incialización.
};
//------------------------------------------------------------------------------------------
//Vamos con la función principal:

punto mainlejano(punto p1, punto p2){
    //ponemos que la función es clase punto ya que nos devolverá será un punto.
    //--------------------------------------------------------------------------------------
    double disp1 = sqrt(pow(p1.x, 2) + pow(p1.y, 2));
    double disp2 = sqrt(pow(p2.x, 2) + pow(p2.y, 2));
    //Con esto obtendremos la distancia de cada punto respecto del origen.
    //--------------------------------------------------------------------------------------
    if(disp1 < disp2){
        cout << "El punto dos está más lejos del origen" << endl;
        return p2;
    }
    //Si se cumple la condición nos devolverá el punto 2. Si no:
    cout << "El primer punto está más lejos del origen" << endl;
    return p1;
    //Si no se cumple, nos devolverá el punto 1.
}
/*------------------------------------------------------------------------------------------
    Pruebas automáticas:
------------------------------------------------------------------------------------------*/
int main(){
    //Declaremos los puntos:
    punto p1(2,3);
    punto p2(7,8);
    //--------------------------------------------------------------------------------------
    //Declararemos unas variables auxiliares que nos ayudarám a hacer la prueba:
    punto ej = mainlejano(p1,p2);
    punto res = p2;
    //--------------------------------------------------------------------------------------
    //Vamos con la condición:
    if(ej.x == res.x && ej.y == res.y){
        /*Como tanto ej, como res, son de clase punto. Debemos comparar sus argumentos
        ya que las comparaciones con operadores cómunes no funcionarían.*/
        cout << "Algo falla" << endl;
    } return 0;
}
//------------------------------------------------------------------------------------------