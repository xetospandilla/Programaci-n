#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Mascota{

    private:

        string nombre; 
        int hambre;
        int felicidad;
        int energia;

    public:

        Mascota(string nom){
            this->nombre = nom;

            this-> hambre = 0;
            this-> felicidad = 100;
            this-> energia = 100;
        }



        void comer(){
            this-> hambre -= 20;
            this-> energia += 15;
        }

        void jugar(){
            this-> felicidad += 20;
            this-> energia -= 20;
            this-> hambre += 10;
        }

        void dormir(){
            this-> energia = 100;
            this-> hambre += 20;
        }

        void pasaTurno(){
            this-> hambre += 5;
            this-> felicidad -= 5;
            this-> energia -= 5;

            if(hambre > 100) hambre = 100; 
            if(hambre < 0) hambre = 0;
            if(felicidad < 0) felicidad = 0; 
            if(energia < 0) energia = 0; 

            cout << "-------------------------------------------------" << endl;
            cout << " El tiempo pasa... Tienes hambre y menos energía." << endl;
            cout << "-------------------------------------------------" << endl;
        }

        bool estaVivo()const{
            if(hambre >= 100 || felicidad <= 0 || energia <= 0){
                return false;
            } return true;
        }

        void mostrarEstado()const{
            cout << " ----------------------------" << endl;
            cout << " Nombre: " << nombre << endl;
            cout << " Hambre: " << hambre << endl;
            cout << " Felicidad: " << felicidad << endl;
            cout << " Energia: " << energia << endl;
            cout << " ----------------------------" << endl;
        }
};


int main(){

    int valor;
    srand(time(0));
    string nombre;
    cout << "Iniciando Tamagochi..." << endl;
    cout << "Asigne un nombre a su mascota: "; // Quitamos los endl extra para que quede en una linea
    cin >> nombre;

    Mascota Tamagochi(nombre);
    cout << "Cargando su mascota..." << endl;


    while(Tamagochi.estaVivo()) {

        Tamagochi.mostrarEstado();

        cout << "----- Menu de opciones -----" << endl;
        cout << "1. Comer " << endl;
        cout << "2. Jugar " << endl;
        cout << "3. Dormir " << endl;
        cout << "4. Esperar" << endl;
        cout << "5. Cerrar Tamagochi" << endl;
        cout << "----------------------------" << endl;
        cout << "Elige una opcion: "; 
        cin >> valor;
        
        system("cls");

        switch(valor){
            case 1: 
                Tamagochi.comer(); 
                cout << ">> " << nombre << " comio rico." << endl; 
                break;

            case 2: 
                Tamagochi.jugar(); 
                cout << ">> " << nombre << " jugo un rato." << endl; 
                break;

            case 3: 
                Tamagochi.dormir(); 
                cout << ">> " << nombre << " durmio." << endl; 
                break;

            case 4: 
                cout << ">> Observas a " << nombre << "." << endl; 
                break;

            case 5: 
                cout << "Saliendo del juego..." << endl; 
                system("pause"); // <--- PERFECTO: Espera antes de cerrar
                return 0;

            default: 
                cout << "Opcion no valida." << endl;
                break;
        }

        Tamagochi.pasaTurno();

    } 
    cout << "---------------------------------" << endl;
    cout << "Tú mascota ha muerto... GAME OVER" << endl;
    cout << "---------------------------------" << endl;
    
    system("pause");
    return 0; 
}
