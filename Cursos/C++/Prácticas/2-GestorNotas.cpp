/*
-------------------------------------------------------------------------------------------------------
GestorNotas.cpp
-------------------------------------------------------------------------------------------------------
Objetivo:

Crea un programa en C++ que gestione las notas de varios alumnos.
Cada alumno puede tener varias asignaturas, y de cada asignatura se guardarán varias notas.

Tendrás que permitir al usuario:

1. Añadir un alumno nuevo.
2. Añadir una asignatura a un alumno.
3. Introducir notas en la asignatura.
4. Mostrar todas las notas de un alumno.
5. Mostrar la media general del alumno (media de medias de sus asignaturas).
6. Mostrar la mejor nota del alumno y la peor.
7. Salir.
-------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//-----------------------------------------------------------------------------------------------------
// CLASE ASIGNATURA
//-----------------------------------------------------------------------------------------------------
class Asignatura{
    public:
        string nombre;
        vector<double> notas;

        // Añadir una nota a la asignatura
        void añadirNota(double n){
            notas.push_back(n);
        }

        // Calcular la media de la asignatura
        double media(){
            double suma = 0;
            for(double n : notas) suma += n;
            return notas.empty() ? 0 : suma / notas.size();
        }

        // Obtener nota máxima
        double max(){
            double maximo = notas[0];
            for(double n : notas){
                if(n > maximo) maximo = n;
            }
            return maximo;
        }

        // Obtener nota mínima
        double min(){
            double minimo = notas[0];
            for(double n : notas){
                if(n < minimo) minimo = n;
            }
            return minimo;
        }

        // Mostrar todas las notas
        void mostrarNotas(){
            cout << "Notas de " << nombre << ": ";
            for(double n : notas) cout << n << " ";
            cout << endl;
        }
};

//-----------------------------------------------------------------------------------------------------
// CLASE ALUMNO
//-----------------------------------------------------------------------------------------------------
class Alumno{
    public:
        string nombre;
        vector<Asignatura> asignaturas;

        // Añadir una asignatura al alumno
        void añadirAsignatura(string nombreAsig){
            Asignatura a;
            a.nombre = nombreAsig;
            asignaturas.push_back(a);
        }

        // Añadir nota a una asignatura concreta
        void añadirNota(string nombreAsig, double nota){
            for(auto &a : asignaturas){
                if(a.nombre == nombreAsig){
                    a.añadirNota(nota);
                    return;
                }
            }
            cout << "Asignatura no encontrada." << endl;
        }

        // Mostrar todas las notas del alumno
        void mostrarNotas(){
            for(auto &a : asignaturas){
                a.mostrarNotas();
            }
        }

        // Calcular la media general del alumno (media de medias)
        double mediaGeneral(){
            double suma = 0;
            for(auto &a : asignaturas){
                suma += a.media();
            }
            return asignaturas.empty() ? 0 : suma / asignaturas.size();
        }

        // Mostrar la mejor y peor nota del alumno
        void mejorPeorNota(){
            double mejor = -1e9, peor = 1e9;
            for(auto &a : asignaturas){
                for(double n : a.notas){
                    if(n > mejor) mejor = n;
                    if(n < peor) peor = n;
                }
            }
            cout << "Mejor nota: " << mejor << " | Peor nota: " << peor << endl;
        }
};

//-----------------------------------------------------------------------------------------------------
// CLASE GESTOR
//-----------------------------------------------------------------------------------------------------
class Gestor{
    private:
        vector<Alumno> alumnos;

    public:
        // Añadir un nuevo alumno
        void nuevoAlumno(){
            Alumno a;
            cout << "Introduce el nombre del alumno: ";
            cin >> a.nombre;
            alumnos.push_back(a);
        }

        // Buscar un alumno por nombre
        Alumno* buscarAlumno(string nombre){
            for(auto &a : alumnos){
                if(a.nombre == nombre) return &a;
            }
            cout << "Alumno no encontrado." << endl;
            return nullptr;
        }

        // Mostrar el menú principal
        void menu(){
            int opcion;
            do{
                cout << "\n============================================================" << endl;
                cout << "                         NotesManager                         " << endl;
                cout << "==============================================================" << endl;
                cout << "1. Añadir un alumno nuevo.                                    " << endl;
                cout << "2. Añadir una asignatura a un alumno.                         " << endl;
                cout << "3. Introducir nota en una asignatura.                         " << endl;
                cout << "4. Mostrar todas las notas de un alumno.                      " << endl;
                cout << "5. Mostrar la media general del alumno.                       " << endl;
                cout << "6. Mostrar la mejor y peor nota del alumno.                   " << endl;
                cout << "7. Salir.                                                     " << endl;
                cout << "==============================================================" << endl;
                cout << "Selecciona una opción: ";
                cin >> opcion;

                string nombreAlumno, nombreAsig;
                double nota;
                Alumno* a;

                switch(opcion){
                    case 1:
                        nuevoAlumno();
                        break;

                    case 2:
                        cout << "Nombre del alumno: ";
                        cin >> nombreAlumno;
                        a = buscarAlumno(nombreAlumno);
                        if(a){
                            cout << "Nombre de la asignatura: ";
                            cin >> nombreAsig;
                            a->añadirAsignatura(nombreAsig);
                        }
                        break;

                    case 3:
                        cout << "Nombre del alumno: ";
                        cin >> nombreAlumno;
                        a = buscarAlumno(nombreAlumno);
                        if(a){
                            cout << "Nombre de la asignatura: ";
                            cin >> nombreAsig;
                            cout << "Nota: ";
                            cin >> nota;
                            a->añadirNota(nombreAsig, nota);
                        }
                        break;

                    case 4:
                        cout << "Nombre del alumno: ";
                        cin >> nombreAlumno;
                        a = buscarAlumno(nombreAlumno);
                        if(a) a->mostrarNotas();
                        break;

                    case 5:
                        cout << "Nombre del alumno: ";
                        cin >> nombreAlumno;
                        a = buscarAlumno(nombreAlumno);
                        if(a) cout << "Media general: " << a->mediaGeneral() << endl;
                        break;

                    case 6:
                        cout << "Nombre del alumno: ";
                        cin >> nombreAlumno;
                        a = buscarAlumno(nombreAlumno);
                        if(a) a->mejorPeorNota();
                        break;

                    case 7:
                        cout << "Saliendo..." << endl;
                        break;

                    default:
                        cout << "Opción no válida." << endl;
                        break;
                }
            }while(opcion != 7);
        }
};

//-----------------------------------------------------------------------------------------------------
// FUNCIÓN PRINCIPAL
//-----------------------------------------------------------------------------------------------------
int main(){
    Gestor g;
    g.menu();
    return 0;
}
//-----------------------------------------------------------------------------------------------------