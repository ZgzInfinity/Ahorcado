

#include "Arranque.h"
#include "Jugador.h"


/*
 * Pre: <<ficheroPalabrasTexto>> es un fichero de texto que almacena, a razón de una por línea,
 *      un diccionario amplio de palabras en castellano.
 * Post: Ha creado un fichero binario denominado <<ficheroPalabrasBinario>> con el contenido del
 *      fichero <<ficheroPalabrasTexto>>. En caso de que el fichero no exista lo crea, y si no,
 *      lo trunca y reemplaza su contenido y ha guardado en <<totalLineas>> el numero de lineas del
 *      fichero de texto
 */
void crearFicheroPalabrasBinario(const char ficheroPalabrasTexto[], const char ficheroPalabrasBinario[], int& totalLineas){
	// Flujo de lectura asociado al fichero de texto
	ifstream f1;
	// Flujo de escritura asociado al fichero binario
	ofstream f2;

	// Contador de lineas del fichero
	totalLineas = 0;

	// Apertura del fichero de texto
	f1.open(ficheroPalabrasTexto);
	if (f1.is_open()){
		// Si la apertura es un exito abre el fichero binario
		f2.open(ficheroPalabrasBinario,ios::binary);

		if (f2.is_open()){
			// La apertura del fichero binario se hace adecuadamente
			Palabra palabraActual;

			char linea[128];
			// Lectura de la primera palabra del fichero de texto
			f1.getline(linea, 128, '\n');

			while (!f1.eof()){
				// Incremento del numero de lineas leidas
				totalLineas++;
				// Mientras queden palabras por leer
				// Crea una palabra con la información leída
				crearPalabra(linea, int(strlen(linea)), palabraActual);

				// Escritura de la palabra en el fichero binario
				f2.write(reinterpret_cast<char *>(&palabraActual), sizeof(Palabra));

				// Lectura de la siguiente palabra del fichero
				f1.getline(linea, 128, '\n');
			}
			// Cierre del flujo de lectura y del flujo de escritura
			f1.close();
			f2.close();
		}
		else {
			// Error al intentar abrir el fichero de texto
			cerr << " El fichero " << ficheroPalabrasBinario << " es innacesible" << endl;
		}
	}
	else {
		// Error al intentar abrir el fichero de escritura
		cerr << " El fichero " << ficheroPalabrasTexto << " es innacesible" << endl;
	}
}



/*
 * Pre: <<fichero>> es un posible fichero de texto
 * Post: Ha creado un fichero de texto vacio de nombre <<fichero>>
 *       en caso de si inexistencia
 */
void comprobarExistenciaFichero(const char fichero[]){
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
    }
}




/*
 * Pre: <<fichero>> es un fichero binario que almacena todos los jugadores registrados hasta el momento.
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
    f.open(fichero, ios::binary);
    // Comprobar que el fichero de jugadores se ha abierto bien
    if (f.is_open()){
        int i = 0;
        // Almacenado del ultimo jugador leido
        Jugador jugadorActual;
        cout << endl << endl;
        gotoxy(50, 5);
        cout << "   RANKING DE LOS JUGADORES" << endl << endl;

        // Escritura de la cabecera de la clasificacion
        gotoxy(50, 7);
        cout << setfill(' ') << setw(14) << "JUGADOR"  << setfill(' ') << setw(14) << "PUNTUACION" << endl;
        gotoxy(50, 8);
        cout << setfill('=') << setw(14) << "=" << "  " << setfill('=') << setw(12) << "=" << endl;

        // Lectura del jugador
        f.read(reinterpret_cast<char*>(&jugadorActual), sizeof(Jugador));

        while (!f.eof()){
            // Mientras queden lienas por leer

            // Detener sonido ring
            detenerSonidoRing();

            // Reproducir sonido del reing
            sonidoRing();

            gotoxy(50, 9 + i);

            char nombreJugador[MAX_LONG_NOMBRE];

            nombre(jugadorActual, nombreJugador);

            // Mostrar los datos del jugador en cuestion
            cout << i + 1 << " - " << setfill(' ') << setw(10) << nombreJugador
                                   << setfill(' ') << setw(14) << puntuacion(jugadorActual) << endl;

            // Lectura del nuevo jugador
            f.read(reinterpret_cast<char*>(&jugadorActual), sizeof(Jugador));

            // Incremento del indice del jugador en la tabla
            i++;

            // Detener ejecucion 500 milisegundos
            Sleep(1000);
        }
        // Cierre del flujo de lectura del fichero
        f.close();
    }
    else{
        // Error al acceder al fichero de judadores
        cerr << "El fichero de jugadores " << fichero << " es innacesible" << endl;
    }
}

