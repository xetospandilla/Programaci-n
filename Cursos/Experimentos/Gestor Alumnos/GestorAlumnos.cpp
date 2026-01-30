#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Alumno{

    private:

        string nombre;
        vector<double> notas;

    public:

        Alumno(string n){
            this->nombre = n;
        }

        string getNombre()const{
            return nombre;
        }

        void agregarNota(double n){
            this->notas.push_back(n);
        }

        double calcularMedia()const{
            
            if(!notas.empty()){
                double suma = 0;

                for(unsigned int i = 0; i < notas.size(); i++){
                    suma += notas[i];
                }

                return suma / notas.size();

            } else { return 0; }
        }

        bool tieneSuspenso()const{
            bool suspenso = false;

            for(unsigned int i = 0; i < notas.size(); i++){
                if(notas[i] < 5){ suspenso = true; }
            }

            return suspenso;
        }
};

vector<string> analizarClase(vector<Alumno> clase){

    vector<string> aprobados;

    for(Alumno alumno : clase){
        
        cout << "Nombre: " << alumno.getNombre() << "| Media: " << alumno.calcularMedia() << endl;
        
        if(!alumno.tieneSuspenso()) aprobados.push_back(alumno.getNombre());
    }
    
    return aprobados;
}

int main(){

    Alumno Mateo("Mateo"); Alumno Pedro("Pedro"); Alumno Juan("Juan");

    Mateo.agregarNota(9.6);
    Mateo.agregarNota(6);
    Mateo.agregarNota(8.6);

    Pedro.agregarNota(6);
    Pedro.agregarNota(4);
    Pedro.agregarNota(7.4);

    Juan.agregarNota(7);
    Juan.agregarNota(6);
    Juan.agregarNota(6);

    vector<Alumno> Clase1A;
    Clase1A.push_back(Mateo);
    Clase1A.push_back(Pedro);
    Clase1A.push_back(Juan);
    
    cout << "----------------------------" << endl;
    cout << "Analisis de la clase: " << endl;
    vector<string> aprobados = analizarClase(Clase1A);
    cout << "----------------------------" << endl;
    cout << " Los aprobados de la clase: " << endl;
    for(string nombre:aprobados){
        cout << "- " << nombre << endl;
    }
    cout << "----------------------------" << endl;

    return 0;
}