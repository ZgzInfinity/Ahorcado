#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <conio.h>


using namespace std;


const int MAX_LONG_LINEA = 128;


struct Jugador {
    private:
        // Estructura interna del jugador
        string nombre;      // nombre del jugador
        int puntuacion;         // puntos del jugador
    public:

        /*
         * Pre: ---
         * Post: Ha creado un jugador cuyo nombre es igual a <<nombre>> y cuyos puntos es igual a puntos
         */
        friend void crearJugador(string nombre, int puntuacion, Jugador& j);



        /*
         * Pre: ---
         * Post : Devuelve el nombre del jugador
         */
        friend string nombre(const Jugador& j);



        /*
         * Pre: ---
         * Post : Devuelve los puntos del jugador
         */
        friend int puntuacion(const Jugador& j);




        /*
         * Pre: <<ichero>> es un fichero de texto que almacena a razon de una por linea
         *      los jugadores que han sido registrados en el Ahorcado y sus correspondientes puntuaciones,
         *      separadas por un espacio en blanco
         * Post: Si en el fichero de jugadores <<fichero>> no hay ningun jugador cuyo nombre sea igual a <<nombre>>
         *       ha creado una nueva entrada para ese jugador con los puntos almacenados en <<puntosJugador>>.
         *       En caso contrario ha aumentado los puntos que ya tenia el jugador cuyo nombre es igual a <<nombre>> un
         *       total de <<puntosJugador>> puntos
         */
        friend bool anyadirJugador(const char fichero[], const string jugador, const int puntosJugador);

};

#endif // JUGADOR_H_INCLUDED
