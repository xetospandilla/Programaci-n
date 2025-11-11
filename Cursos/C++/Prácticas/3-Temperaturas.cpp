/*
-----------------------------------------------------------------------------------------------------
🧩 Requisitos

Crea una clase Temperaturas con:

- Un vector<double> privado llamado valores.

-  Un método introducirDatos() que pida 7 temperaturas por teclado.

-  Un método mostrarDatos() que muestre todas las temperaturas.

-  Un método media() que devuelva la media de las temperaturas.

- Un método maximo() que devuelva la más alta.

- Un método minimo() que devuelva la más baja.

En main():

- Crea un objeto de tipo Temperaturas.

- Llama a los métodos en este orden: introducir, mostrar, media, máximo, mínimo.

- Muestra los resultados por pantalla.
-----------------------------------------------------------------------------------------------------
*/

//-------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

class temperatura{
 private:
  vector<double> valores;

 public:
 //Introducir valores:
 void introducirDatos(){
  double temps;
  for(int i = 0; i < 7; i++){
   cout << "Introduzca un valor: ";
   cin >> temps;
   cout << endl;
   valores.push_back(temps);
  }
 }
 //Mostrar valores:
 void mostrarDatos(){
  cout << "Temperaturas almacenadas: ";
  for(double v:valores){
   cout << v << ", ";
  }
  cout << endl;
 }
 //Calcular la media:
 double media(){
  double sum;
  double media;
  for(int i = 0; i < valores.size(); i++){
   sum += valores[i];
  }
  media = sum / valores.size();
  return media; 
 }
 //Temeperatura máxima:
 double máximo(){
  double max = valores[0];
  for(int i = 0; i < valores.size(); i++){
   if(max < valores[i]){ max = valores[i]; }
  } return max;
 }
 //Temeperatura mínima:
 double mínimo(){
  double min = valores[0];
  for(int i = 0; i < valores.size(); i++){
   if(min > valores[i]){ min = valores[i];}
  } return min;
 }
};

//-------------------------------------------------------------------------------------------------

int main(){
 temperatura temp;
 int opcion;

 do{

  cout << "==========================================" << endl;
  cout << "               Temperaturas               " << endl;
  cout << "==========================================" << endl;
  cout << "1. Introducir temperaturas" << endl;
  cout << "2. Mostrar valores introducidos." << endl;
  cout << "3. Calcular la media." << endl;
  cout << "4. Mostrar la temperatura máxima." << endl;
  cout << "5. Mostrar la temperatura mínima. " << endl;
  cout << "6. Salir." << endl;
  cout << "==========================================" << endl;
  cout << "Introduzca su opción: " << endl; cin >> opcion;

  switch(opcion){
   case 1: temp.introducirDatos(); break;
   case 2: temp.mostrarDatos(); break;
   case 3: cout << "La media de temperaturas es: " << temp.media() << endl; break;
   case 4: cout << "La máxima temperaturas es: " << temp.máximo() << endl; break;
   case 5: cout << "La mínima temperaturas es: " << temp.mínimo() << endl; break;
   case 6: cout << "Saliendo..." << endl; break;
   default: cout << "Opción no valida." << endl; break;
  }
 }while(opcion != 6);
}
//-------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------