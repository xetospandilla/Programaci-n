#include <iostream>
#include <string>
using namespace std;
//---------------------------------------------------------------------------------------------------------------------------
//EJM 1:
    /*
void intercambio(int &a, int &b){
    //Esta función intercambiará los valores durante la ejecución del código.
    int temp = a;
    a = b;
    b = temp;
}

int main(){

    int var1 = 10;
    int var2 = 20;

    cout << "Valores antes del intercambio: " << var1 << ", " << var2 << "." << endl;

    intercambio(var1, var2);

    cout << "Valores después del intercambio: " << var1 << ", " << var2 << "." << endl;

    return 0;
}
    */
//---------------------------------------------------------------------------------------------------------------------------
//EJM 2:
    /*
void incrementarNonulos( int *valor ){

    if(valor != nullptr) ++(*valor);

}

int main(){
    int a = 5;

    incrementarNonulos(&a);

    cout << "Valor de a: " << a << endl;
}   
    */
//---------------------------------------------------------------------------------------------------------------------------