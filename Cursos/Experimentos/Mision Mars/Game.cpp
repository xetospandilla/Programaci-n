#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Mapa {
private: 
    char tablero[10][10];

public:
    Mapa(){
        // 1. Llenar de puntos
        for(unsigned int i = 0; i < 10; i++){
            for(unsigned int j = 0; j < 10; j++){
                tablero[i][j] = '.';
            }
        }

        // 2. Rocas
        unsigned int rocasColocadas = 0;
        while(rocasColocadas < 10){
            unsigned int y = rand() % 10;
            unsigned int x = rand() % 10;
            if((x != 0 || y != 0) && tablero[y][x] == '.'){
                tablero[y][x] = '#';
                rocasColocadas++;
            }
        }

        // 3. Oro
        unsigned int orosColocados = 0;
        while (orosColocados < 5){
            unsigned int y = rand() % 10;
            unsigned int x = rand() % 10;
            if((x != 0 || y != 0) && tablero[y][x] == '.'){
                tablero[y][x] = '$';
                orosColocados++;
            }
        }

        // 4. Base (CORREGIDO EL ==)
        unsigned int basesColocadas = 0;
        while (basesColocadas < 1){
            unsigned int y = rand() % 10;
            unsigned int x = rand() % 10;
            if((x != 0 || y != 0) && tablero[y][x] == '.'){ // <--- AQUÍ FALTABA UN =
                tablero[y][x] = 'B';
                basesColocadas++;
            }
        }
    }

    void mostrar(int xRobot, int yRobot) {
        cout << "   0 1 2 3 4 5 6 7 8 9" << endl;
        cout << "  ---------------------" << endl;
        for (int i = 0; i < 10; i++) { 
            cout << i << " |"; 
            for (int j = 0; j < 10; j++) { 
                if (i == yRobot && j == xRobot) {
                    cout << "R "; 
                } else {
                    cout << tablero[i][j] << " ";
                }
            }
            cout << "|" << endl;
        }
        cout << "  ---------------------" << endl;
    }

    char getCasilla(unsigned int y, unsigned int x) const {
        return tablero[y][x];
    }

    void limpiarCasilla(unsigned int y, unsigned int x){
        tablero[y][x] = '.';
    }
};

int main(){
    srand(time(0)); 

    Mapa marte;

    // Usamos int normal para evitar problemas al restar (que no de la vuelta a 4 millones)
    int x = 0;
    int y = 0;
    int bateria = 100;
    bool juegoActivo = true;

    while(juegoActivo){
        
        // Limpieza de pantalla
        cout << string(50, '\n'); 

        cout << "--- MISSION TO MARS ---" << endl;
        cout << " Bateria: " << bateria << "%" << endl;
        cout << " Posicion: (" << x << ", " << y << ")" << endl;
        cout << "-----------------------" << endl;

        marte.mostrar(x, y);

        if(bateria <= 0){
            cout << "BATERIA AGOTADA. Mision fallida." << endl;
            break;
        }

        cout << "Mover (w/a/s/d): ";
        char tecla;
        cin >> tecla;

        // CORREGIDO: Inicializamos con la posición actual
        int futuroX = x;
        int futuroY = y;

        if(tecla == 'w') futuroY--;
        else if (tecla == 's') futuroY++;
        else if (tecla == 'a') futuroX--;
        else if (tecla == 'd') futuroX++;

        // Lógica de movimiento
        if(futuroX < 0 || futuroX > 9 || futuroY < 0 || futuroY > 9){
            cout << "¡Cuidado! Fin del mundo. No puedes ir ahi." << endl;
            system("pause"); // Recuerda cambiar esto si no usas Windows
        }
        else {
            char loQueHay = marte.getCasilla(futuroY, futuroX);

            if (loQueHay == '#') {
                cout << "¡CRASH! Una roca. Pierdes 10% de bateria." << endl;
                bateria -= 10;
                system("pause"); 
            } 
            else if (loQueHay == '$') {
                cout << "¡Muestra de ORO encontrada! (+Recargando bateria)" << endl;
                marte.limpiarCasilla(futuroY, futuroX); 
                bateria += 20; 
                x = futuroX;
                y = futuroY;
                system("pause");
            }
            else if (loQueHay == 'B') {
                cout << "¡HAS LLEGADO A LA BASE! Mision Cumplida." << endl;
                juegoActivo = false; return 0;
            }
            else {
                x = futuroX;
                y = futuroY;
                bateria -= 1; 
            }

            system("cls");
        }
    } 

    cout << "GAME OVER" << endl;
    return 0;
}