
#include "Jugador.h"



/*
 * Pre: ---
 * Post: Ha creado un jugador cuyo nombre es igual a <<nombre>> y cuyos puntos es igual a puntos
 */
void crearJugador(string nombre, int puntuacion, Jugador& j){
    j.nombre = nombre;
    j.puntuacion = puntuacion;
}



/*
 * Pre: ---
 * Post : Devuelve el nombre del jugador
 */
string nombre(const Jugador& j){
    return j.nombre;
}



/*
 * Pre: ---
 * Post : Devuelve los puntos del jugador
 */
int puntuacion(const Jugador& j){
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
    cout << "Linea " << enQueLinea;
    // Flujo de lectura asociado al fichero
    ofstream f;
    // Comprobar el resultado
    if (enQueLinea == -1){
        // El jugador no estaba y se guarda en la ultima linea
        f.open(fichero, ios::binary | ios::app);
        // Re-escribir el Jugador con los nuevos puntos
        f.write(reinterpret_cast<char*>(&jugador), sizeof(Jugador));

        cout << " QUE PASA AQUI " << endl;
    }
    else {
        // Modificar el jugador guardado en la linea <<enQueLinea
        f.open(fichero, ios::binary | ios::app);
        // Calculo de la posicion en bytes del jugador a modificar
        int direccion = sizeof(Jugador) + sizeof(Jugador) * enQueLinea;
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
        string nombreJugador;
        //  Lectura del nombre del jugador
        Jugador jugadorActual;
        f.read(reinterpret_cast<char*>(&jugadorActual), sizeof(Jugador));

        nombreJugador = nombre(j);

        // Bucle de lectura del fichero
        while (!encontrado && !f.eof()){
            // Quedan lineas pendientes de leer
            if (nombreJugador == nombre(jugadorActual)){
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


