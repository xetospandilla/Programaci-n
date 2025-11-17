/*
-------------------------------------------------------------------------------------------------------
Juego de azar
-------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <cstdlib> //Para rand() y srand()
#include <ctime> // para time()
using namespace std;

int main(){

    srand(time(nullptr)); //Hace que capture el instante haciendo que sea diferente cada vez.
    char continuar;

    do{
        int numeroSecreto = rand() % 100 + 1;

        int intentos = 0;

        bool adivinado = false;

        while(intentos < 5 && !adivinado){
            int miNum;
            cout << "Introduce un número del uno al 100: " << endl;
            cin >> miNum;

            if(miNum == numeroSecreto){
                cout << "!!Adivinado!!";
                adivinado = true;
            } else if (miNum < numeroSecreto){ cout << "El número es mayor " << endl;}
            else {cout << "El número es menor" << endl;}

            intentos++;
        }

        if(!adivinado){
            cout << "Lo siento, no lo has adivinado. El número era: " << numeroSecreto << endl;
        }
        cout << "Quieres jugar de nuevo? (s/n)" << endl;
        cin >> continuar;
    }while(continuar == 's'|| continuar == 'S' );

    return 0;
}
//-----------------------------------------------------------------------------------------------------