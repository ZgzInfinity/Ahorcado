
#include "Jugador.h"



/*
 * Pre: ---
 * Post: Ha creado un jugador cuyo nombre es igual a <<nombre>> y cuyos puntos es igual a puntos
 */
void crearJugador(char nombre[], int puntuacion, Jugador& j){
    strcpy(j.nombre, nombre);
    j.puntuacion = puntuacion;
}



/*
 * Pre: ---
 * Post : Devuelve el nombre del jugador
 */
void nombre(Jugador j, char nombreJugador[]){
    strcpy(nombreJugador, j.nombre);
}



/*
 * Pre: ---
 * Post : Devuelve los puntos del jugador
 */
int puntuacion(Jugador j){
    return j.puntuacion;
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
void anyadirJugador(const char fichero[], Jugador& jugador){
    // Comprobar que el jugador se encuentra en el fichero

    int enQueLinea = buscarLineaJugador(fichero, jugador);

    // Flujo de lectura asociado al fichero
    ofstream f;
    // Comprobar el resultado
    if (enQueLinea == -1){
        // El jugador no estaba y se guarda en la ultima linea
        f.open(fichero, ios::binary | ios::app);
        // Re-escribir el Jugador con los nuevos puntos
        f.write(reinterpret_cast<char*>(&jugador), sizeof(Jugador));
    }
    else {
        // Modificar el jugador guardado en la linea <<enQueLinea
        f.open(fichero, ios::binary |ios :: in | ios::out);
        // Calculo de la posicion en bytes del jugador a modificar
        int direccion = sizeof(Jugador) * (enQueLinea - 1);
        // Posicionamiento del cursor para poder escribir
        f.seekp(direccion);
        // Re-escribir el Jugador con los nuevos puntos
        f.write(reinterpret_cast<char*>(&jugador), sizeof(Jugador));
    }
    // Cierre del flujo de escritura asociado al ficheroç
    f.close();
}


/*
 * Pre: <<fichero>> es un fichero binario que almacena todos los jugadores del ahorcado registrados
 *      y <<j>> es un jugador que puede estar o no almacenado en el fichero de jugadores <<fichero>>
 * Post: Si el jugador <<j>> se encuentra almacenado en el fichero de jugadores <<fichero>> devuelve la linea
 *       en la que se encuentra. En caso contrario devuelve un valor negativo.
 */
int buscarLineaJugador(const char fichero[], Jugador& j){
    // Flujo de lectura asociado al fichero
    ifstream f;
    f.open(fichero, ios::binary);
    if (f.is_open()){
        // Si el fichero se ha abierto correctamente
        // numero de lineas procesadas
        int numLineas = 0;

        // Control de jugador hallado
        bool encontrado = false;
        char nombreJugador[MAX_LONG_NOMBRE], nombreJugadorActual[MAX_LONG_NOMBRE];
        //  Lectura del nombre del jugador
        Jugador jugadorActual;
        f.read(reinterpret_cast<char*>(&jugadorActual), sizeof(Jugador));

        nombre(j, nombreJugador);

        // Bucle de lectura del fichero
        while (!encontrado && !f.eof()){
            // Quedan lineas pendientes de leer
            nombre (jugadorActual, nombreJugadorActual);

            if (strcmp(nombreJugador, nombreJugadorActual) == 0){
                // jugador encontrado
                encontrado = true;
            }
            // Incremento de las lineas leidas
            numLineas++;

            // Leer un nuevo jugador
            f.read(reinterpret_cast<char*>(&jugadorActual), sizeof(Jugador));
        }
        // Cierre del flujo de lectura
        f.close();
        // Comprobar que el jugador existe
        if (encontrado){
            // Si el jugador existia
            cout << numLineas << endl;
            return numLineas;
        }
        else {
            // No existia y se devuelve valor negativo
            return  -1;
        }
    }
    else {
        // Error al abrir el fichero
        cerr << " El fichero de jugadores " << fichero << " es innacesible " << endl;
        return -1;
    }
}


