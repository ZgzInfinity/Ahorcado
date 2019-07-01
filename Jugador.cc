
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
bool anyadirJugador(const char fichero[], Jugador jugador){
    // Flujo de lectura/escritura del fichero de jugadores
    ifstream f1;
    // Apertura del fichero de jugadores
    f1.open(fichero, ios::binary | ios::in | ios::out);
    // Comprobar que el flujo es correcto
    if (f1.is_open()){
        ofstream f2;
        // El fichero de jugadores esta disponible
        Jugador jugadorActual;
        int puntos, direccion = 0;
        // Control de jugador hallado
        bool encontrado = false;
        string nombreActual;
        //  Lectura del nombre del jugador
        f1.read(reinterpret_cast<char*>(&jugadorActual), sizeof(Jugador));

        while (!f1.eof() && !encontrado){
            // Fichero no vacio
            // Comparacion del jugador leido con el buscado
            nombreActual = nombre(jugadorActual);
            cout << nombre(jugadorActual) << " " << puntuacion(jugadorActual) << endl;
            if ( nombreActual == nombre(jugador)){
                // Jugador hallado
                encontrado = true;

                // Eliminar los bytes correspondientes al ultimo jugador leido
                direccion -= sizeof(Jugador);
            }
            else {
                // Contar espacio del nuevo jugador
                direccion += sizeof(Jugador);
                //  Lectura del nombre del jugador
                f1.read(reinterpret_cast<char*>(&jugadorActual), sizeof(Jugador));
            }
        }
        f2.open(fichero, ios::binary | ios::in | ios::out);
        f2.seekp(direccion);
        // Comprobar si el jugador estaba o no en el fichero
        if (!encontrado){
            // No estaba y se incorpora como entrada
            f2.write(reinterpret_cast<char*>(&jugador), sizeof(Jugador));
        }
        else {
            // Esta y se reemplaza
            f1.read(reinterpret_cast<char*>(&jugadorActual), sizeof(Jugador));
            // Incremento del total de puntos del jugador
            puntos = puntuacion(jugadorActual);
            puntos += puntuacion(jugador);
            crearJugador(nombreActual, puntos, jugadorActual);
            // Escribe en el fichero los puntos del jugador modificados
            f2.write(reinterpret_cast<char*>(&jugadorActual), sizeof(Jugador));
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



