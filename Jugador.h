#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <fcntl.h>
#include "Audio.h"


using namespace std;


const int MAX_LONG_LINEA = 128;
const int MAX_LONG_NOMBRE = 100;




struct Jugador {
    private:
        // Estructura interna del jugador
        char nombre[MAX_LONG_NOMBRE];      // nombre del jugador
        int puntuacion;                    // puntos del jugador
    public:

        /*
         * Pre: ---
         * Post: Ha creado un jugador cuyo nombre es igual a <<nombre>> y cuyos puntos es igual a puntos
         */
        friend void crearJugador(char nombre[], int puntuacion, Jugador& j);



        /*
         * Pre: ---
         * Post : Devuelve el nombre del jugador
         */
        friend void nombre(Jugador j, char nombreJugador[]);



        /*
         * Pre: ---
         * Post : Devuelve los puntos del jugador
         */
        friend int puntuacion(Jugador j);




        /*
         * Pre: <<ichero>> es un fichero de texto que almacena a razon de una por linea
         *      los jugadores que han sido registrados en el Ahorcado y sus correspondientes puntuaciones,
         *      separadas por un espacio en blanco
         * Post: Si en el fichero de jugadores <<fichero>> no hay ningun jugador cuyo nombre sea igual a <<nombre>>
         *       ha creado una nueva entrada para ese jugador con los puntos almacenados en <<puntosJugador>>.
         *       En caso contrario ha aumentado los puntos que ya tenia el jugador cuyo nombre es igual a <<nombre>> un
         *       total de <<puntosJugador>> puntos
         */
        friend void anyadirJugador(const char fichero[], Jugador& jugador);




        /*
         * Pre: <<fichero>> es un fichero binario que almacena todos los jugadores del ahorcado registrados
         *      y <<j>> es un jugador que puede estar o no almacenado en el fichero de jugadores <<fichero>>
         * Post: Si el jugador <<j>> se encuentra almacenado en el fichero de jugadores <<fichero>> devuelve la linea
         *       en la que se encuentra. En caso contrario devuelve un valor negativo.
         */
        friend int buscarLineaJugador(const char fichero[], Jugador& j);




        /*
         * Pre: <<jug>> es un puntero a un vector de jugadores regitrados en
         *      el juego del Ahorcado, <<inicio>> y <<fin>> son los indices de los extremos
         *      de la busqueda, inicio >= 0, fin >= 0 y inicio <= fin
         * Post: Ha devuelto el vector de jugadores <<jug>> ordenado por orden decreciente de puntuacion
         *       usando el metodo quicksort
         */
        friend void ordenarJugadores(Jugador *jug, int inicio, int fin);




        /*
         * Pre:  <<fichero>> representa el nombre de un fichero de texto existente
         *       que almacena información sobre todos los jugadores; la tabla <<jugadores>>
         *       tiene capacidad suficiente como para almacenar todos las jugadores que estan
         *       contenidas en el fichero de nombre <<fichero>>.
         * Post: Si se ha podido abrir sin problemas el fichero cuyo nombre es
         *       <<fichero>>, ha copiado la información sobre los jugadores
         *       contenida en el fichero en las primeras <<numJugadores componentes de
         *       la tabla <<jugador>>. En caso contrario, ha escrito un mensaje de error
         *       informando del problema encontrado
         */
        friend void leerJugadores(const char fichero[], Jugador jugadores[], int& numJugadores);




        /*
         * Pre:  * Pre: <<jugadores>> es una tabla que almacena todos los jugadores registrados hasta el momento.
         * Post: Ha mostrado por pantalla una clasificacion de todos los jugadores registrados. La clasificacion
         *       presenta el siguiente formqto:
         *
         *       Ejemplo:
         *
         *         JUGADOR    PUNTUACION
         *       =========  ============
         *          Europe           230
         *      ZgzInfinty            40
         *
         *            . . . . . . . . .
         *
         *         Pitazzo           870
         *            Aeri            90
         */
        friend void mostrarClasificacion(const Jugador jugadores[], const int numJugadores, string nombreJugador);


};

#endif // JUGADOR_H_INCLUDED
