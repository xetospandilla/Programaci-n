/*
-------------------------------------------------------------------------------------------------------------------------
Escribe un programa en C++ que tenga una función llamada mediaTres() que reciba tres números reales y devuelva su media.
Desde el main(), pide los tres números al usuario, llama a la función y muestra el resultado con dos decimales.
-------------------------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <vector>
using namespace std;

double mediaVector(){
    
    vector<double> nums(3);
    for(int i = 0; i < nums.size(); i++){
        cout << "Introduzca un elemento: " << endl;
        cin >> nums[i];
    }

    cout << "------------------------------------------" << endl;
    cout << " Los valores escogidos son: ";
    for (double valor:nums){
        cout << valor << ", ";
    }
    cout << endl;
    cout << "------------------------------------------" << endl;

    double suma = 0;
    for(double valor : nums){
        suma += valor;
    } double media = suma / nums.size();

    cout << "La media de esos tres valores: " << media << endl;
    cout << "------------------------------------------" << endl;
    return media;
}

int main(){
    double media = mediaVector();
    cout << "La media de los tres números dió" << media << endl; return 0;
}
