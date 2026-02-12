#include <iostream>
using namespace std;

double ordenar( double list, int cuantos){
 for( int i = 0; i < cuantos; i++){
  if(list[i]-1 > list[i]){
   double list[i] = list[i] + (list[i]-1);
  }
 }
 return list;
}

int main(){
    int esperado[] = {6,7,8,9,10};
    list[] = {6,7,8,9,10}{10,9,8,7,6};
    int* resultado = ordenar(list, 5)

    bool ok = true;
    for(int i = 0; i < cuantos; i++){
        if(resultado[i] != esperado[i]){
            ok = false;
            break;
        }
    }

    if(ok) cout << "✅ La prueba pasó correctamente.";
    else cout << "❌ La prueba falló.";

    delete[] resultado;
   }