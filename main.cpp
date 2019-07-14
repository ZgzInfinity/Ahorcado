/*
 * -------------------------------
 * Juego del Ahorcado en C++ -----
 * Autor: Rubén Rodríguez --------
 * Fecha: 14-4-19 ----------------
 * -------------------------------
 */

#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <unistd.h>
#include "Palabra.h"
#include "Monigote.h"
#include "Menu.h"
#include "Arranque.h"
#include "Jugador.h"


// valores de color de fondo y fuente

const int FONDO_AZUL = 1;
const int COLOR_ROJO = 12;
const int COLOR_BLANCO = 15;

const int DIFICULTAD_MINIMA = 1;
const int DIFICULTAD_MAXIMA = 3;


// longitud maxima del nombre de un fichero

const int MAX_LONG_FICHERO = 100;
const int TECLA_ESC = 27;
const int RETARDO = 6000;
const int MAX_JUGADORES = 100;


/*
 * Pre: ---
 * Post: Ha preguntado al usuario si desea jugar o no una nueva partida
 *       Si presiona la tecla ESC finaliza la partida y si pulsa la tecla INTRO
 *       comienza una nueva
 */
void controlFinDelJuego(bool& terminado){

    // Reproducir sonido del reloj
    tocarSonidoReloj();

    // Control de la orden introducida por el usuario
    int orden;

    // Presentar el rotulo de final de juego
    presentarFinal();

    // Dibujo de la cuadricula
    dibujoCuadricula();

    // Muestra las posibles teclas a pulsar al usuario
    gotoxy(35, 15);
    cout << "ORDENES DISPONIBLES" << endl;

    gotoxy(35, 16);
    cout << "1 - Nueva partida " << endl;

    gotoxy(35, 17);
    cout << "2 - Salir del juego " << endl << endl;

    gotoxy(35, 19);
    cout << "Introduzca una orden --> " << flush;
    cin >> orden;

    // Control de tecla pulsada
    bool pulsada = false;

    while (!pulsada){
        // Comprobacion de tecla 1 o 2
        if (orden == 1 || orden == 2){
            // Es la tecla ENTER
            pulsada = true;

            // Comprobacion de la tecla
            if (orden == 2){
                // Fin del juego
                terminado = true;
            }
        }
        else {
            gotoxy(35, 21);
            cerr << " Tecla no valida" << endl;
        }
    }

    // Detener sonido del reloj
    detenerSonidoReloj();
}



/*
 * Pre: ---
 * Post: Ha guardado en <<letra>> la letra introducida por el
 *       usuario a traves del teclado
 */
void pedirLetra(char& letra){
	// Peticion al usuario del caracter por teclado
	gotoxy(5,3);
	// Borrado del contenido de la linea
	clreol();
	cout << "Introduzca la letra a comprobar: " << flush;
	cin >> letra;

	// Comprobacion de si el caracter introducido por el usuario es una letra
	while (!isalpha(letra)){
		// El caracter no es el adecuado y lo vuelve a pedir
		cout << "El caracter introducido no es una letra" << endl;
		Sleep(RETARDO);
		gotoxy(5,4);
		clreol();
		gotoxy(5,3);
		cout << "Introduzca la letra a comprobar: " << flush;
		cin >> letra;
	}

	// Comprueba si el caracter es una letra mayuscula
	if (isupper(letra)){
		// Si es mayuscula la convierte a minuscula
		letra = tolower(letra);
	}
}



/*
 * Secuencia de pruebas basicas para probar el TAD Palabra
 */
int main(){

    sonidoMenuPrincipal();

    // Ajustar dimensiones automaticas de la consola
    system("mode con: cols=128 lines=25");

	// Semilla generadora de numeros aleatorios
	srand(time(NULL));

	// configurar color de la terminal
    textbackground(FONDO_AZUL);

    // configurar color de la fuente
    textcolor(COLOR_AMARILLO);

    // Presentacion del menu inicial del juego
    presentarMenu();

    // Mostrar el rotulo que parpadea
    string orden = "comenzar";
    mostrarTitulo(orden);

    // Borrado de pantalla
    system("cls");

    int dificultad, pista, puntos, puntosPalabra;
    string mensajePartida, tipoDificultad;

    char nombreJugador[MAX_LONG_NOMBRE];

    // Detener banda sonora del menu principal
    detenerSonidoMenu();

    // Reproducir sonido del menu de opciones
    sonidoMenuOpciones();

    // Mostrar menu de opciones
    menuOpciones(dificultad, pista, nombreJugador);

    // Establecer cirterio de puntos a ganar por palabra
    if (dificultad == 1){
        // Dificultad minima
        puntosPalabra = 10;
    }
    else if (dificultad == 2){
        // Dificultad intermedia
        puntosPalabra = 30;
    }
    else{
        // Dificultad maxima
        puntosPalabra = 50;
    }

    // Borrado de pantalla
    system("cls");

    // Detener sonido del menu de opciones
    detenerSonidoOpciones();

	// Ficheros de trabajo
	const char ficheroPalabras[MAX_LONG_FICHERO] = "Datos\\palabras_rae.txt";
	const char ficheroPalabrasBinario[MAX_LONG_FICHERO] = "Datos\\palabras_bin.bin";
	const char ficheroJugadoresBinario[MAX_LONG_FICHERO] = "Datos\\jugadores_bin.bin";


	// Contador de filas del fichero de texto de palabras
	int numLineas;

	// Palabra seleccionada para guardar
	Palabra palabraSeleccionada;

	// Lectura del fichero de palabras y generacion del fichero binario
	crearFicheroPalabrasBinario(ficheroPalabras, ficheroPalabrasBinario, numLineas);

	// Control del fin del juego
	bool fin = false, acertada = false;

	// Estado del juego
    int estado;

	// Numero de letras descubiertas de la palabra
	int letrasVolteadas = 0;

	// puntuacion total del jugador
	puntos = 0;

	// Letra con la que jugar al usuario
	char letra;

	// Control del final del juego y de letra existente en palabra
	bool terminado = false, encontrado = false, letraYaDicha = false;;

	// Crear fichero de jugadores si no existe
	comprobarExistenciaFichero(ficheroJugadoresBinario);

	// Control de partidas
	while (!terminado){
        // Estado inicial del juego
        estado = 1;

        // total de letras volteadas
        letrasVolteadas = 0;

        // limpieza de pantalla
        system("cls");

        // seleccion de nueva palabra con la que se va a jugar
        seleccionarPalabra(ficheroPalabrasBinario, numLineas, palabraSeleccionada);

        char pal[MAX_LETRAS];
        obtenerPalabra(pal, palabraSeleccionada);
        cout << pal << endl;

        // Numero de letras de la palabra seleccionada
        int numLetras = obtenerLetras(palabraSeleccionada);

        // Muestreo de los huecos de la palabra a averiguar
        mostrarHuecosPalabra(palabraSeleccionada);

        // Reproducir el sonido de la partida
        tocarMusicaPartida(pista);

        // Dibujo de la horca del monigote
        dibujarHorca();

        // Obtener la dificultad
        tipoDificultad = mostrarDificultad(dificultad);

        // Dibujar panel de puntuacion
        panelPuntuacion(tipoDificultad, nombreJugador, puntos, acertada);

        // La palabra de la partida actual todavia no ha sido acertada
        acertada = false;

        // Mientras queden letras por descubir y no se haya terminado el juego
        while (!fin && letrasVolteadas != numLetras){

            // Se vuelve a pedir letra nueva
            pedirLetra(letra);

            // Posicionamiento en la pantalla
            // Comprobar si la letra esta o no en la palara
            existeLetra(palabraSeleccionada, letra, letrasVolteadas, encontrado, letraYaDicha);

            // Comprobar que la letra ya se habia probado antes
            if (letraYaDicha){
                // La letra ya se habia probado
                gotoxy(4,5);
                cout << " La letra " << letra << " ya se ha probado" << endl;
                letraYaDicha = false;
            }
            else if (encontrado){
                // Sustitucion de los huecos por las letras correctas
                textcolor(COLOR_VERDE);
                gotoxy(4,5);
                cout << " La letra " << letra << " es correcta" << endl;

                // Reproducir sonido CORRECTO
                tocarSonidoCorrecto();

            }
            else {
                // Dibujo correspondiente del monigote
                dibujoParteMonigote(estado, dificultad, fin);
                textcolor(COLOR_ROJO);
                gotoxy(4,5);
                cout << " La letra " << letra << " no esta contenida" << endl;

                // Reproducir sonido INCORRECTO
                tocarSonidoIncorrecto();
            }

            // Esperar un tiempo y limpiar la linea
            Sleep(2000);
            gotoxy(4,5);
            clreol();

            // Cambio de color de la fuente
            textcolor(COLOR_AMARILLO);

            encontrado = false;
        }

        // Detener banda sonora de la partida
        detenerSonidoPartida(pista);

        // Comprobar que la palabra se ha resuelto
        if (!fin){
            textcolor(COLOR_VERDE);

            mensajePartida = "VCTORIA";

            // Sumar puntos acumulados
            puntos += puntosPalabra;

            // Detener el sonido Game Over
            detenerSonidoFindOut();

            // Reproducir sonido Game Over
            tocarSonidoFindOut();

            // Mostrar mensaje de victoria
            mostrarMensaje(mensajePartida);

            // La palabra ha sido acertada
            acertada = true;
        }
        else {
            textcolor(COLOR_ROJO);

            mensajePartida = "DERROTA";

            // Detener el sonido Game Over
            detenerSonidoGameOver();

            // Reproducir sonido Game Over
            tocarSonidoGameOver();

            // Para poder volver a jugar
            fin = false;

            // Mostrar mensaje de derrota
            mostrarMensaje(mensajePartida);
        }

        textcolor(COLOR_AMARILLO);

         // Dormir 2 segundos
        Sleep(2000);

        // Limpiar la pantlla
        system("cls");

        Jugador jugador;
        crearJugador(nombreJugador, puntos, jugador);

        // Sumar o anyadir nuevo jugador
        anyadirJugador(ficheroJugadoresBinario, jugador);

        // Fin de la partida y pregunta al usuario si desea jugar
        controlFinDelJuego(terminado);

        // Detener sonido del reloj
        detenerSonidoReloj();

        // Limpiar la pantlla
        system("cls");
    }

    // Reproducir sonido de ranking
    tocarSonidoRanking();

    // Cargar los jugadores almacenados en el fichero
    Jugador listadoJugadores[MAX_JUGADORES];
    int numJugadores;
    leerJugadores(ficheroJugadoresBinario, listadoJugadores, numJugadores);

    // Ordenar los jugadores por orden decreciente de puntuacion
    ordenarJugadores(listadoJugadores, 0, numJugadores - 1);

    // Mostrar la clasificacion actual de los jugadores
    mostrarClasificacion(listadoJugadores, numJugadores, nombreJugador);

    Sleep(3000);

    system("cls");

    // Reproducir sonido de los creditos
    tocarSonidoCreditos();

    // Nostrar creditos finales
    creditos();

    // Detener sonido creditos
    detenerSonidoCreditos();

	// Posicionamiento al final de la pantalla para el fin de ejecucion
	gotoxy(1, 24);
	cout << " Fin del juego " << endl;
	return 0;

}
