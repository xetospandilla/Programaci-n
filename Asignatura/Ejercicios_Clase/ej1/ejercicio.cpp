/*
Crea una función que reciba como parámetros dos arreglos de números reales del mismo tamaño
y que devuelva la suma del producto del producto de cada uno de los elementos del arreglo.
Utiliza punteros y no utilices librerias. Realiza una prueba automática.
*/
 //-----------------------------------------------------------------------------------------
#include <iostream>
using namespace std;
/*
-----------------------------------------------------------------------------------------
  Función principal sumaProducto()
-----------------------------------------------------------------------------------------
*/
double sumaProducto(double arr1[], double arr2[]){
  unsigned int tam; //No la declaramos ya que la pediremos más tarde.
  int res = 0; //La inicializamos en 0, para que empiece a contar desde ahí.
 //-----------------------------------------------------------------------------------------
 // Bucle para leer los arreglos y cálculo: 
  for(int i = 0; i < tam; i++){
    double producto = arr1[i] * arr2[i]; //Va multiplicando los elementos de los arreglos.
    res += producto; //Va sumando los productos.
  }
  cout << "El cálculo dió: " << res << endl;
  return res; //Nos devuelve la suma de productos, de los arreglos.
}
/*
-----------------------------------------------------------------------------------------
  Pruebas Automáticas.
-----------------------------------------------------------------------------------------
*/
int main(){
  double arr1[] = {1,2,3,4,5,6};
  double arr2[] = {6,2,3,4,5,6};
  int tam = 6;

  if(sumaProducto(arr1, arr2) != 96){
    cout << "Algo no funciona" << endl;
  } else {
    cout << "Funciona" << endl;
  }
}
//-----------------------------------------------------------------------------------------