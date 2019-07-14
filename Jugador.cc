
#include "Jugador.h"
#include "Menu.h"



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
    Jugador jug;
    char nombreJug[MAX_LONG_NOMBRE];

    nombre(jugador, nombreJug);

    // Flujo de lectura asociado al fichero
    fstream f;
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
        // Posicionamiento del cursor para poder leer
        f.seekg(direccion);
        // Lectura del jugador que ha jugado
        f.read(reinterpret_cast<char*>(&jug), sizeof(Jugador));
        // Puntuacion de las partidas anteriores
        int puntosViejos = puntuacion(jug);
        // Nuevo jugador con los datos actualizados
        crearJugador(nombreJug, puntosViejos + puntuacion(jugador), jugador);
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


/*
 * Pre: <<jug>> es un puntero a un vector de jugadores, <<inicio>> y <<fin>> son los
 *      intervalos de busqueda, inicio >= 0, fin >= 0 y inicio <= fin
 * Post: Ha establecido los jugadores que debe reordenar por orden decreciente de puntuacion
 */
int dividir(Jugador *jug, int inicio, int fin)
{
  int izq;
  int der;
  int pibote;
  Jugador temp;

  pibote = puntuacion(jug[inicio]);
  izq = inicio;
  der = fin;

  //Mientras no se cruzen los índices
  while (izq < der){
    while (puntuacion(jug[der]) < pibote){
	  der--;
    }

	while ((izq < der) && (puntuacion(jug[izq]) >= pibote)){
      izq++;
    }

    // Si todavia no se cruzan los indices seguimos intercambiando
	if(izq < der){
      temp = jug[izq];
      jug[izq] = jug[der];
      jug[der] = temp;
    }
  }

  //Los indices ya se han cruzado, ponemos el pivote en el lugar que le corresponde
  temp = jug[der];
  jug[der] = jug[inicio];
  jug[inicio] = temp;

  //La nueva posición del pivote
  return der;
}



/*
 * Pre: <<jug>> es un puntero a un vector de jugadores regitrados en
 *      el juego del Ahorcado, <<inicio>> y <<fin>> son los indices de los extremos
 *      de la busqueda, inicio >= 0, fin >= 0 y inicio <= fin
 * Post: Ha devuelto el vector de jugadores <<jug>> ordenado por orden decreciente de puntuacion
 *       usando el metodo quicksort
 */
void ordenarJugadores(Jugador *jug, int inicio, int fin)
{
  int pivote;
  if(inicio < fin)
  {
    pivote = dividir(jug, inicio, fin);
    // Ordeno todos los jugadores menores
    ordenarJugadores(jug, inicio, pivote - 1);
    // Ordeno todos los jugadores mayores
    ordenarJugadores(jug, pivote + 1, fin);
  }
}



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
void leerJugadores(const char fichero[], Jugador jugadores[], int& numJugadores){
    // Flujo de lectura del fichero de jugadires
    ifstream f;
    // Apertura del fichero
    f.open(fichero, ios::binary);
    // Comprobar que el fichero de jugadores se ha abierto bien
    if (f.is_open()){
        numJugadores = 0;
        Jugador jugadorLeido;

        // Lectura del jugador
        f.read(reinterpret_cast<char*>(&jugadorLeido), sizeof(Jugador));

        // Mientras queden jugadores pendientes de leer
        while (!f.eof()){
            // Guardo el jugador leido
            jugadores[numJugadores] = jugadorLeido;
            numJugadores++;

            // Lectura de un nuevo jugador
            f.read(reinterpret_cast<char*>(&jugadorLeido), sizeof(Jugador));
        }
        // Cierre del flujo de lectura del fichero
        f.close();
    }
    else {
        cerr << " El fichero de jugadores "<< fichero << " es innacesible " << endl;
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
void mostrarClasificacion(const Jugador jugadores[], const int numJugadores, string nombreJugador){
        cout << endl << endl;
        gotoxy(50, 5);
        cout << "   RANKING DE LOS JUGADORES" << endl << endl;

        // Escritura de la cabecera de la clasificacion
        gotoxy(50, 7);
        cout << setfill(' ') << setw(14) << "JUGADOR"  << setfill(' ') << setw(14) << "PUNTUACION" << endl;
        gotoxy(50, 8);
        cout << setfill('=') << setw(14) << "=" << "  " << setfill('=') << setw(12) << "=" << endl;

        // Almacenado del ultimo jugador leido
        char nombreJug[MAX_LONG_NOMBRE];

        for (int i = 0; i < numJugadores; i++){

            // Detener sonido ring
            detenerSonidoRing();

            // Reproducir sonido del reing
            sonidoRing();

            gotoxy(50, 9 + i);
            nombre(jugadores[i], nombreJug);

            // Si el jugador esta
            if (nombreJug == nombreJugador){
                textcolor(COLOR_VERDE);

                // Mostrar los datos del jugador de la partida marcado en verde para diferenciar
                cout << i + 1 << " - " << setfill(' ') << setw(10) << nombreJug
                                   << setfill(' ') << setw(14) << puntuacion(jugadores[i]) << endl;

                textcolor(COLOR_AMARILLO);
            }
            else {
                // Mostrar los datos del jugador en cuestion
                cout << i + 1 << " - " << setfill(' ') << setw(10) << nombreJug
                                   << setfill(' ') << setw(14) << puntuacion(jugadores[i]) << endl;
            }

            // Detener ejecucion 500 milisegundos
            Sleep(1000);
        }
}
