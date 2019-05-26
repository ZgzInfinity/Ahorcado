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


// valores de color de fondo y fuente

const int FONDO_AZUL = 1;
const int COLOR_VERDE = 10;
const int COLOR_ROJO = 12;
const int COLOR_AMARILLO = 14;
const int COLOR_BLANCO = 15;

const int DIFICULTAD_MINIMA = 1;
const int DIFICULTAD_MAXIMA = 3;


// longitud maxima del nombre de un fichero

const int MAX_LONG_FICHERO = 100;
const int TECLA_ESC = 27;
const int RETARDO = 600;


/*
 * Pre: ---
 * Post: Ha preguntado al usuario si desea jugar o no una nueva partida
 *       Si presiona la tecla ESC finaliza la partida y si pulsa la tecla INTRO
 *       comienza una nueva
 */
void controlFinDelJuego(bool& terminado){
    // Muestra las posibles teclas a pulsar al usuario
    cout << endl << endl;
    cout << "Presione la tecla INTRO si desea jugar una nueva partida " << endl;
    cout << "Presione la tecla ESC si desea salir del juego " << endl;

    // Control de tecla pulsada
    bool pulsada = false;
    // Capturar tecla pulsada

    unsigned char tecla;

    while (!pulsada){
        // No se ha pusado la tecla
        tecla = getch();

        // Comprobacion de tecla ENTER
        if (int(tecla) == TECLA_ENTER || int(tecla) == TECLA_ESC){
            // Es la tecla ENTER
            pulsada = true;

            // Comprobacion de la tecla
            if (int(tecla == TECLA_ESC)){
                // Fin del juego
                cout << "OK" << endl;
                terminado = true;
            }
        }
        else {
            cerr << " Tecla no valida" << endl;
        }
    }
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
 * Secuenvia de pruebas basicas para probar el TAD Palabra
 */
int main(){

    // Ajustar dimensiones automaticas de la consola
    system("mode con: cols=130 lines=30");

	// Semilla generadora de numeros aleatorios
	srand(time(NULL));

	// configurar color de la terminal
    textbackground(FONDO_AZUL);

    // configurar color de la fuente
    textcolor(COLOR_AMARILLO);

    // Presentacion del menu inicial del juego
    presentarMenu();

    // Mostrar el rotulo que parpadea
    mostrarTituloParpadeante();

    // Borrado de pantalla
    system("cls");

    int dificultad, pista;

    // Mostrar menu de opciones
    menuOpciones(dificultad, pista);


    // Borrado de pantalla
    system("cls");

	// Ficheros de trabajo
	const char f1[MAX_LONG_FICHERO] = "palabras_rae.txt";
	const char f2[MAX_LONG_FICHERO] = "palabras_bin.bin";

	// Contador de filas del fichero de texto de palabras
	int numLineas;

	// Palabra seleccionada para guardar
	Palabra palabraSeleccionada;

	// Lectura del fichero de palabras y generacion del fichero binario
	crearFicheroPalabrasBinario(f1, f2, numLineas);

	// Control del fin del juego
	bool fin = false;

	// Estado inicial del juego
    int estado = 1;

	// Numero de letras descubiertas de la palabra
	int letrasVolteadas = 0;

	// Letra con la que jugar al usuario
	char letra;

	// Control del final del juego
	bool terminado = false;

	// Control de existencia de letra en palabra
	bool encontrado;

	// Control de partidas
	while (!terminado){
        // limpieza de pantalla
        system("cls");

        // seleccion de nueva palabra con la que se va a jugar
        seleccionarPalabra(f2, numLineas, palabraSeleccionada);

        // Numero de letras de la palabra seleccionada
        int numLetras = obtenerLetras(palabraSeleccionada);

        gotoxy(1,1);
        char linea[MAX_LETRAS];
        obtenerPalabra(linea, palabraSeleccionada);
        cout << linea << endl;

        // Muestreo de los huecos de la palabra a averiguar
        mostrarHuecosPalabra(palabraSeleccionada);

        // Reproducir el sonido de la partida
        tocarMusicaPartida(pista);

        // Dibujo de la horca
        dibujarHorca();

        // Mientras queden letras por descubir y no se haya terminado el juego
        while (!fin && letrasVolteadas != numLetras){
            // Se vuelve a pedir letra nueva
            pedirLetra(letra);


            // Posicionamiento en la pantalla
            // Comprobar si la letra esta o no en la palara
            existeLetra(palabraSeleccionada, letra, letrasVolteadas, encontrado);

            if(encontrado){
                // Sustitucion de los huecos por las letras correctas
                textcolor(COLOR_VERDE);
                gotoxy(4,5);
                cout << " La letra " << letra << " es correcta" << endl;

            }
            else {
                // Dibujo correspondiente del monigote
                dibujoParteMonigote(estado, dificultad, fin);
                textcolor(COLOR_ROJO);
                gotoxy(4,5);
                cout << "La letra " << letra << " no esta contenida" << endl;

            }

            // Esperar un tiempo y limpiar la linea
            // usleep(RETARDO);
            system("pause");
            clreol();
            // Cambio de color de la fuente
            textcolor(COLOR_AMARILLO);

            encontrado = false;
        }

        // Fin de la partida y pregunta al usuario si desea jugar
        controlFinDelJuego(terminado);
    }

	// Posicionamiento al final de la pantalla para el fin de ejecucion
	gotoxy(1,24);
	cout << " Fin del programa " << endl;
	return 0;
}
