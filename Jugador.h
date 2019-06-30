#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <fcntl.h>
#include <conio.h>


using namespace std;


const int MAX_LONG_LINEA = 128;


/*
 * Pre: <<fichero>> es un posible fichero de texto
 * Post: Ha creado un fichero de texto vacio de nombre <<fichero>>
 *       en caso de si inexistencia
 */
void comprobarExistenciaFichero(const char fichero[]);


/*
 * Pre: <<ichero>> es un fichero de texto que almacena a razon de una por linea
 *      los jugadores que han sido registrados en el Ahorcado y sus correspondientes puntuaciones,
 *      separadas por un espacio en blanco
 * Post: Si en el fichero de jugadores <<fichero>> no hay ningun jugador cuyo nombre sea igual a <<nombre>>
 *       ha creado una nueva entrada para ese jugador con los puntos almacenados en <<puntosJugador>>.
 *       En caso contrario ha aumentado los puntos que ya tenia el jugador cuyo nombre es igual a <<nombre>> un
 *       total de <<puntosJugador>> puntos
 */
bool anyadirJugador(const char fichero[], const string jugador, const int puntosJugador);



/*
 * Pre: <<fichero>> es un fichero de texto que almacena a razon de uno por linea
 *      el nombre y la puntuacionm separados por un espacio en blanco, de todos los jugadores
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
void mostrarClasificacion(const char fichero[]);


#endif // JUGADOR_H_INCLUDED
