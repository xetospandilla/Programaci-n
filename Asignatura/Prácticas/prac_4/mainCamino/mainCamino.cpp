/*
--------------------------------------------------------------------------------------------
Fichero: mainCercano.cpp
Fecha: 06-11-2025
Descripción: Programa en C++ que cálcula el camino formado por puntos dentro de un array.
Autor: Carlos Galán Cubells
--------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <cmath> //La necesitamos para los cálculos de vectores.
using namespace std;

//------------------------------------------------------------------------------------------
//Declaramos la clase punto:

class punto{
    public: 
        double x; double y;
        punto(double x, double y): x(x), y(y ){}
};

//------------------------------------------------------------------------------------------
//Escrivamos la función:

double mainCamino(punto arr[], unsigned int tam){
    double camino = 0; // Esto será lo que nos devolverá la función.
    for(int i = 0; i < tam; i++){
        //Declaramos una variable para ayudarnos: 
        punto p = arr[i];
        //Cálculos para medir el camino:
        double dis = sqrt(pow(p.x, 2) + pow(p.y, 2));
        camino += dis; //Esto será lo que nos devolvera la función.
    } return camino;
}
/*
--------------------------------------------------------------------------------------------
Pruebas automáticas: 
--------------------------------------------------------------------------------------------
*/
int main(){
    //--------------------------------------------------------------------------------------
    //Declaremos el contenido del arreglo:
    punto p1(1,2);
    punto p2(5,6);
    punto p3(7,8);
    //--------------------------------------------------------------------------------------
    //Declaremos el arreglo:
    punto miArr[3] = {p1, p2, p3};
    //--------------------------------------------------------------------------------------
    //Decalaremos variables autiliares:
    double prueba = mainCamino(miArr,3);
    double res_esperada = 20.676;
    //--------------------------------------------------------------------------------------
    //Ahora sí hagamos la prueba:
    if(prueba != res_esperada){
        cout << "Algo no funciona correctamente";
    } cout <<"Todo funciona correctamente."; return 0;
}
//------------------------------------------------------------------------------------------