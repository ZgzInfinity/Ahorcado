
#include "Jugador.h"

/*
 * Pre: <<fichero>> es un posible fichero de texto
 * Post: Ha creado un fichero de texto vacio de nombre <<fichero>>
 *       en caso de si inexistencia
 */
void comprobarExistenciaFichero (const char fichero[]){
    // Comprobar que el fichero se puede abrir en modo lectura
    int fd = open(fichero, O_RDONLY);
    if (fd > 0){
        // el fichero exsite
        // se cierra el flujo asociado al fichero
        close(fd);
    }
    else {
        // se crea el fichero con permisos de lectura y escritura
        creat(fichero, 0777);
        // Flujo de escritura asociado al fichero de jugadores
        ofstream f;
        // Aperura del flujo de escritura del fichero
        f.open(fichero);
        if (f.is_open()){
            // Escritura de la cabecera del fichero
            f << "   JUGADOR    PUNTUACION " << endl;
            f << " =========  ============" << endl;
            // Cierre del flujo de escritura del fichero
            f.close();
        }
        else{
            // El fichero de jugadores creado presente un error al abrirlo
            cerr << "El fichero de jugadores " << fichero << " es innacesible " << endl;
        }
    }
}


/*
 * Pre: <<ichero>> es un fichero de texto que almacena a razon de una por linea
 *      los jugadores que han sido registrados en el Ahorcado y sus correspondientes puntuaciones,
 *      separadas por un espacio en blanco
 * Post: Si en el fichero de jugadores <<fichero>> no hay ningun jugador cuyo nombre sea igual a <<nombre>>
 *       ha creado una nueva entrada para ese jugador con los puntos almacenados en <<puntosJugador>>.
 *       En caso contrario ha aumentado los puntos que ya tenia el jugador cuyo nombre es igual a <<nombre>> un
 *       total de <<puntosJugador>> puntos
 */
bool anyadirJugador(const char fichero[], const string jugador, const int puntosJugador){
    // Flujo de lectura/escritura del fichero de jugadores
    ifstream f1;
    // Apertura del fichero de jugadores
    f1.open(fichero);
    // Comprobar que el flujo es correcto
    if (f1.is_open()){
        ofstream f2;
        // El fichero de jugadores esta disponible
        string nombreJugador;
        int puntos, totalBytes = 0;
        // Control de jugador hallado
        bool encontrado = false;
        //  Lectura del nombre del jugador

        f1 >> nombreJugador;
        while (!encontrado && !f1.eof()){
            // Fichero no vacio
            // Comparacion del jugador leido con el buscado
            totalBytes += nombreJugador.length() + 1;
            if (nombreJugador == jugador){
                // Jugador hallado
                encontrado = true;
            }
            // Lee los ountos del jugador
            f1 >> puntos;

            if (!encontrado){
                totalBytes += to_string(puntos).length() + 1;
                // Lectura del siguiente jugador
                f1 >> nombreJugador;
            }
        }
        // Comprobar si el jugador estaba o no en el fichero
        if (!encontrado){
            cout << "NO ENCONTRADO " << jugador << " " << puntosJugador << endl;
            f2.open(fichero, ios::app);
            // No estaba y se incorpora como entrada
            f2 << jugador << " " << puntosJugador << endl;
        }
        else {
            f2.open(fichero);
            // Desplazamiento del cursor a la posicion totalBytes desde el comienzo del fichero

            cout << totalBytes << endl,
            // Incremento del total de puntos del jugador
            puntos += puntosJugador;
            // Escribe en el fichero los puntos del jugador modificados
            f2 << puntos << endl;
        }
        f1.close();
        f2.close();
        // Retorno de resultado
        return encontrado;
    }
    else {
        // El fichero de jugadores esta innacessible
        cerr << "El fichero de jugadores " << fichero << " es innacesible " << endl;
        return false;
    }
}



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
void mostrarClasificacion(const char fichero[]){
    // Flujo de lectura del fichero de jugadires
    ifstream f;
    // Apertura del fichero
    f.open(fichero);
    // Comprobar que el fichero de jugadores se ha abierto bien
    if (f.is_open()){
        int i = 0, puntos;
        cout << endl << endl;
        gotoxy(50, 5);
        cout << "   RANKING DE LOS JUGADORES" << endl << endl;

        // Escritura de la cabecera de la clasificacion
        gotoxy(50, 7);
        cout << setfill(' ') << setw(14) << "JUGADOR"  << setfill(' ') << setw(14) << "PUNTUACION" << endl;
        gotoxy(50, 8);
        cout << setfill('=') << setw(14) << "=" << "  " << setfill('=') << setw(12) << "=" << endl;

        string nombreJugador;

        // Lectura del jugador
        f >> nombreJugador;
        while (!f.eof()){
            // Mientras queden lienas por leer

            // Leer la puntuacion del jugador
            f >> puntos;
            gotoxy(50, 9 + i);
            // Mostrar los datos del jugador en cuestion
            cout << i + 1 << " - " << setfill(' ') << setw(10) << nombreJugador
                                   << setfill(' ') << setw(14) << puntos << endl;

            // Lectura del nuevo jugador
            f >> nombreJugador;

            // Incremento del indice del jugador en la tabla
            i++;
        }
        // Cierre del flujo de lectura del fichero
        f.close();
    }
    else{
        // Error al acceder al fichero de judadores
        cerr << "El fichero de jugadores " << fichero << " es innacesible" << endl;
    }
}
