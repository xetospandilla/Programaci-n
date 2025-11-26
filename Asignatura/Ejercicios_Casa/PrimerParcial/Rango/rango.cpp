#include <iostream>
using namespace std;

int* rango(int num1, int num2){
    int cuantos = num2 - num1 + 1;
    int * lista = new int[cuantos];

    for(int i = 0; i < cuantos; i++){
        lista[i] = num1 + i;
    }

    return lista;
}


int main(){
    int esperado[] = {6,7,8,9,10};
    int* resultado = rango(6,10);
    int cuantos = 5;

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