/*
-------------------------------------------------------------------------------------------------------
Bucles Infinitos
-------------------------------------------------------------------------------------------------------
1. ¿Qué es un bucle infinito?

    - Bucle que se repite indefinidamente (sin finalizar por sí solo)

    - Frecuente causarlo por error al programar (condiciones mal definidas)

    - No siempre es signo de mala programación, también es útil y necesario en muchos contextos

2. Usos comunes y escenarios donde son útiles

    - Aplicaciones que deben ejecutarse continuamente:

        - Servidores, listeners (ejemplo: chat en red LAN)

        - Monitoreo de puertos o conexiones entrantes

    - Sistemas embebidos y servidores:

        - Programas diseñados para correr "para siempre" (hasta apagarse manualmente)

        - Interfaces de usuario o aplicaciones interactivas:

        - Juegos, sistemas que esperan entrada del usuario (ej. pulsar botón)

        - Monitoreo de sensores en tiempo real

    - Prototipado y depuración:

        - Repetir sección de código mientras se observa su comportamiento

    - Tareas repetitivas prolongadas:

        - "Polling" de hardware, mantenimiento de conexiones de red

    - Sistemas de control manual:

        - Espera de interacción física (interruptores/botones)

    - Patrones de diseño:

        - Loop de eventos en interfaces gráficas (esperar y manejar eventos)

3. Cómo crear bucles infinitos en C++

    - Usando for(;;) (for sin condición, sin incremento, ni inicialización)

    - Usando while(true)

    - Por error: condición de salida nunca se cumple (ej: variable que nunca se actualiza)

4. Buenas prácticas

    - Los bucles infinitos deben ser intencionales y controlados

    - Importante tener maneras de salir del bucle si es necesario (entrada del usuario, señal, etc.)
-------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

double leerTemperatura() {
    return 20.0 + (rand() % 21); // genera entre 20 y 40
}

void esperarSegundos(int segundos) {
    this_thread::sleep_for(chrono::seconds(segundos));
}

int main() {
    const double tempLimite = 35.0;
    while (true) {
        double tempActual = leerTemperatura();
        cout << "Temperatura actual: " << tempActual << "°C" << endl;
        if (tempActual > tempLimite) {
            cout << "ALERTA: Temperatura elevada detectada: " << tempActual << "°C" << endl;
        }
        esperarSegundos(3);
    }
}
//-----------------------------------------------------------------------------------------------------