/*
--------------------------------------------------------------------------------------------
Fichero: main.cpp
Descripción: Práctica 7 Completa + Todos los ejercicios extra de diapositivas.
Autor: Carlos Galán Cubells
--------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <cmath>     // Para pow, sqrt, M_PI
#include <string>    // Para to_string
#include <algorithm> // Para max

using namespace std;

// ==========================================================================
// 1. FUNCIONES AUXILIARES GLOBALES
// ==========================================================================

// EJERCICIO: Números Triangulares (Ayuda para la clase Conjunto)
// Enunciado: Escribe una función que devuelva verdadero cuando un número natural dado sea triangular.
// (Un número es triangular si es la suma de n naturales consecutivos: 1, 1+2=3, 1+2+3=6...)
bool esTriangular(int num) {
    if (num < 1) return false;
    int suma = 0;
    for (int i = 1; suma < num; ++i) {
        suma += i;
        if (suma == num) return true;
    }
    return false;
}

// ==========================================================================
// 2. CLASE PUNTO
// ==========================================================================
class Punto {
    private: 
        double x; 
        double y;

    public:
        Punto(double X = 0, double Y = 0): x(X), y(Y) {}

        double getX() const { return x; }
        double getY() const { return y; }

        void setX(double X) { x = X; }
        void setY(double Y) { y = Y; }

        string aTexto() const {
            return "(" + to_string(x) + ", " + to_string(y) + ")";
        }
};

// ==========================================================================
// 3. CLASE POLINOMIO
// ==========================================================================
class Polinomio {
    private:
        vector<double> coeficientes;

    public:
        // --- Constructor y Métodos Base ---
        Polinomio() { coeficientes.push_back(0.0); } 

        unsigned int grado() const { return coeficientes.size() - 1; }

        double coeficiente(unsigned int i) const {
            if(i >= coeficientes.size()) return 0.0;
            return coeficientes[i];
        }

        void setCoeficiente(unsigned int i, double valor){
            if(i >= coeficientes.size()) coeficientes.resize(i + 1, 0.0);
            coeficientes[i] = valor;
        }

        double valor(double x) const {
            double suma = 0.0;
            for (unsigned int i = 0; i < coeficientes.size(); i++) {
                suma += coeficientes[i] * pow(x, i);
            }
            return suma;
        }

        Polinomio sumar(const Polinomio& otro) const {
            Polinomio resultado;
            unsigned int gradoMax = max(grado(), otro.grado());

            for(unsigned int i = 0; i <= gradoMax; i++){
                double suma = this->coeficiente(i) + otro.coeficiente(i);
                if(suma != 0.0) resultado.setCoeficiente(i , suma);
            }
            return resultado;
        }

        string aTexto() const {
            string salida = "";
            bool primerTermino = true;
            for(unsigned int i = 0; i < coeficientes.size(); i++){
                double val = coeficientes[i];
                if(val != 0.0 || (i==0 && coeficientes.size()==1)){
                    if(!primerTermino) salida += (val > 0) ? " + " : " ";
                    salida += to_string(val);
                    if (i == 1) salida += "x";
                    else if (i > 1) salida += "x^" + to_string(i);
                    primerTermino = false;
                }
            }
            return salida;
        }

        // --- EJERCICIOS ESPECÍFICOS DE DIAPOSITIVAS ---

        // EJERCICIO: Multiplicar por Monomio
        // Enunciado: Diseña un nuevo método que calcule el producto de un polinomio por un monomio.
        // Ejemplo: (2 + 4x^2 - 2x^3) por 5x.
        Polinomio multiplicarMonomio(double factor, unsigned int gradoMonomio) const {
            Polinomio resultado;
            for(unsigned int i = 0; i < coeficientes.size(); i++) {
                double val = coeficientes[i];
                if (val != 0.0) {
                    // Desplazamos el exponente (i + gradoMonomio) y multiplicamos el valor
                    resultado.setCoeficiente(i + gradoMonomio, val * factor);
                }
            }
            return resultado;
        }

        // EJERCICIO: Máximo en Intervalo
        // Enunciado: Método maximo(a, b) que devuelva el valor más alto del polinomio
        // en el intervalo [a, b], evaluándolo cada 0.1.
        double maximo(double a, double b) const {
            double maxVal = valor(a);
            for (double x = a; x <= b; x += 0.1) {
                double valActual = valor(x);
                if (valActual > maxVal) maxVal = valActual;
            }
            return maxVal;
        }

        // EJERCICIO: Desviación Media
        // Enunciado: Recibe una lista de Puntos y devuelve la media de (y - p(x)).
        // Permite saber si en promedio los puntos están por encima o debajo de la curva.
        double desviacionMedia(const vector<Punto>& puntos) const {
            if (puntos.empty()) return 0.0;
            double suma = 0.0;
            for (size_t i = 0; i < puntos.size(); i++) {
                suma += (puntos[i].getY() - this->valor(puntos[i].getX()));
            }
            return suma / puntos.size();
        }

        // EJERCICIO: Puntos por Encima
        // Enunciado: Recibe un array/vector de puntos y devuelve otro vector con
        // todos aquellos que estén estrictamente por encima de la curva del polinomio.
        vector<Punto> porEncima(const vector<Punto>& puntosEntrada) const {
            vector<Punto> resultado;
            for (size_t i = 0; i < puntosEntrada.size(); i++) {
                // Condición: Y del punto > Valor del polinomio en esa X
                if (puntosEntrada[i].getY() > this->valor(puntosEntrada[i].getX())) {
                    resultado.push_back(puntosEntrada[i]);
                }
            }
            return resultado;
        }
};

// ==========================================================================
// 4. CLASE CONJUNTO
// ==========================================================================
class Conjunto {
    private:
        vector<double> elementos;

    public:
        Conjunto() {}

        void agregar(double n) { elementos.push_back(n); }

        // EJERCICIO: Filtrar con Polinomio
        // Enunciado: Crea un método filtrar() que reciba un polinomio y elimine
        // todos los elementos del conjunto cuyo valor p(x) sea negativo.
        void filtrar(const Polinomio& p) {
            vector<double> supervivientes;
            for (size_t i = 0; i < elementos.size(); i++) {
                if (p.valor(elementos[i]) >= 0) {
                    supervivientes.push_back(elementos[i]);
                }
            }
            elementos = supervivientes;
        }

        // EJERCICIO: Números Triangulares
        // Enunciado: Diseña un método que devuelva, en otro conjunto,
        // los números triangulares del conjunto original.
        Conjunto triangulares() const {
            Conjunto resultado;
            for (size_t i = 0; i < elementos.size(); i++) {
                // Comprobamos si es entero y si cumple la propiedad triangular
                int valorEntero = static_cast<int>(elementos[i]);
                if (elementos[i] == valorEntero && esTriangular(valorEntero)) {
                    resultado.agregar(elementos[i]);
                }
            }
            return resultado;
        }

        void imprimir() const {
            cout << "{ ";
            for (size_t i = 0; i < elementos.size(); i++) cout << elementos[i] << " ";
            cout << "}" << endl;
        }
};

// ==========================================================================
// 5. FUNCIONES DE CADENAS (Arrays de caracteres estilo C)
// ==========================================================================

// EJERCICIO: Primera Repetida
// Enunciado: Recibe texto y devuelve el número de casilla donde aparece
// por primera vez una letra que se repite más adelante. Si no hay, devuelve -1.
int primeraRepetida(const char texto[]) {
    for (int i = 0; texto[i] != '\0'; i++) {
        for (int j = i + 1; texto[j] != '\0'; j++) {
            if (texto[i] == texto[j]) return i;
        }
    }
    return -1;
}

// EJERCICIO: Buscar Caracteres
// Enunciado: Implementa una función buscar(palabra, letras) que devuelva la posición
// de la primera coincidencia de cualquiera de los caracteres de 'letras' en 'palabra'.
int buscar(const char palabra[], const char letras[]) {
    for (int i = 0; palabra[i] != '\0'; ++i) {
        // Para cada letra de la palabra, comprobamos si está en la lista prohibida
        for (int j = 0; letras[j] != '\0'; ++j) {
            if (palabra[i] == letras[j]) {
                return i; // Encontrado
            }
        }
    }
    return -1;
}


// ==========================================================================
// MAIN DE PRUEBAS
// ==========================================================================
int main() {
    cout << "=== 1. POLINOMIO: OPERACIONES EXTRA ===" << endl;
    Polinomio p1; 
    // P(x) = 2 + 3x
    p1.setCoeficiente(0, 2.0);
    p1.setCoeficiente(1, 3.0);
    cout << "Polinomio Original: " << p1.aTexto() << endl;

    // Prueba Multiplicar Monomio (Ej: por 5x^2)
    Polinomio pMonomio = p1.multiplicarMonomio(5.0, 2);
    cout << "Multiplicado por 5x^2 (Esperado 10x^2 + 15x^3): " << pMonomio.aTexto() << endl;

    // Prueba Máximo en intervalo [-2, 2]
    cout << "Maximo en [-2, 2]: " << p1.maximo(-2.0, 2.0) << endl;


    cout << "\n=== 2. CONJUNTO: FILTRADO Y TRIANGULARES ===" << endl;
    Conjunto c;
    c.agregar(1.0);  // Triangular (1)
    c.agregar(3.0);  // Triangular (1+2)
    c.agregar(4.0);  // NO Triangular
    c.agregar(10.0); // Triangular (1+2+3+4)
    c.agregar(-5.0); // Negativo
    
    cout << "Conjunto original: "; c.imprimir();
    
    // Prueba Filtrar Triangulares
    Conjunto cTri = c.triangulares();
    cout << "Solo triangulares (Esperado { 1 3 10 }): "; 
    cTri.imprimir();

    // Prueba Filtrar por Polinomio P(x) = x
    // Debería eliminar el -5.0
    Polinomio pIdentidad; 
    pIdentidad.setCoeficiente(1, 1.0); // P(x) = x
    c.filtrar(pIdentidad);
    cout << "Filtrado p(x)>=0 (Se va el -5): "; c.imprimir();


    cout << "\n=== 3. CADENAS: BUSQUEDA ===" << endl;
    char palabra[] = "programacion";
    char buscarEstas[] = "xyzm"; // La 'm' está en 'programacion'
    
    // Prueba Buscar
    int pos = buscar(palabra, buscarEstas);
    cout << "Palabra: " << palabra << endl;
    cout << "Buscando primera aparicion de: " << buscarEstas << endl;
    cout << "Posicion encontrada: " << pos << " (Letra '" << palabra[pos] << "')" << endl;

    return 0;
}