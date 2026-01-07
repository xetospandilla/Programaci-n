#include <iostream>
#include <vector>
using namespace std;

// Clase punto: representa un punto en el plano 2D
class punto {
private:
    double x, y; // Coordenadas del punto

public:
    // Constructor: inicializa x e y (por defecto, 0 y 0)
    punto(double X = 0, double Y = 0): x(X), y(Y) {}
    // Métodos getter: devuelven las coordenadas x e y
    double getX() const { return x; }
    double getY() const { return y; }
};

// Función que devuelve un vector de los puntos medios consecutivos de un vector de puntos
vector<punto> medios(vector<punto> arr) {
    vector<punto> pmedios; // Vector para almacenar los puntos medios

    // Itera hasta el penúltimo elemento
    for (int i = 1; i < arr.size() - 1; i++) {
        // Calcula el punto medio entre arr[i] y arr[i+1]
        double xm = (arr[i].getX() + arr[i+1].getX()) / 2.0;
        double ym = (arr[i].getY() + arr[i+1].getY()) / 2.0;
        // Añade el punto medio al vector resultado
        pmedios.push_back(punto(xm, ym));
    }
    return pmedios; // Devuelve el vector de puntos medios
}

int main() {
    // Crea 3 puntos concretos
    punto p1(2,3);
    punto p2(3,2);
    punto p3(1,0);

    // Los mete en un vector
    vector<punto> myarr = {p1, p2, p3};

    // Imprime los valores originales
    cout << "Valores antes del cálculo: " << endl;
    for (const punto& valor : myarr) {
        cout << "X: " << valor.getX() << ", Y: " << valor.getY() << endl;
    }

    // Llama a la función para calcular los puntos medios y los imprime
    cout << "Valores después del cálculo: " << endl;
    for (const punto& valor : medios(myarr)) {
        cout << "X: " << valor.getX() << ", Y: " << valor.getY() << endl;
    }

    return 0;
}