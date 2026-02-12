/*
-------------------------------------------------------------------------------------------------------
Anidamiento de Siwtch-case
-------------------------------------------------------------------------------------------------------
EJM: Programa que elija entre dos idiomas.
-------------------------------------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int main(){
    char idiom, categoria;

    cout << "Menú de opciones(e: Español. i: English." << endl;
    cout << "1.e" << endl;
    cout << "2.i" << endl;
    cin >> idiom;

    switch(idiom){
        case 'e' |'E':
            cout << "Ha seleccionado el idioma Español" << endl;
            cout << "Ahora elija entre estás opciones(l: libro. r: Ropa. t: Tecnología): " << endl;
            cout << "1.l" << endl;
            cout << "2.r" << endl;
            cout << "3.t" << endl;
            cin >> categoria;
            
            switch(categoria){
                case 'l':
                case 'L': 
                    cout << "Has elegido libro." << endl; break;
                case 'r':
                case 'R': 
                    cout << "Has elegido ropa." << endl; break;
                case 't':
                case 'T': 
                    cout << "Has elegido Tecnología." << endl; break;
                
                default: cout << "Opción no valida." << endl; break;
            } break;

        case 'i':
        case 'I':
            cout << "Yo have choosed english" << endl;
            cout << "Now choose another option" << endl;
            cout << "1.l" << endl;
            cout << "2.r" << endl;
            cout << "3.t" << endl;
            cin >> categoria;


                        switch(categoria){
                case 'l':
                case 'L': 
                    cout << "You have chossed book." << endl; break;
                case 'r':
                case 'R': 
                    cout << "You have chossed clothes." << endl; break;
                case 't':
                case 'T': 
                    cout << "You have chossed tecnology." << endl; break;
                
                default: cout << "Non valid option." << endl; break;
    }break;

    default: cout << "Opción no válida. // Non valid option." << endl;
    } return 0;
}

//-----------------------------------------------------------------------------------------------------