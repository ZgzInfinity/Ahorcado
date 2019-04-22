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


// valores de color de fondo y fuente
const int FONDO_AZUL = 1;
const int COLOR_VERDE = 10;
const int COLOR_ROJO = 12;
const int COLOR_AMARILLO = 14;
const int COLOR_BLANCO = 15;


// longitud maxima del nombre de un fichero
const int MAX_LONG_FICHERO = 100;
const int retardo = 100000;

/*
 * Pre: <<estado>> almacena el estado actual del juego
 * Post: Ha dibujado la parte correspondiente del monigote en funcion del
 *       estado del juego
 */
void dibujoParteMonigote(int& estado, const int dificultad){
    // Control de la dificultad del juego
    switch (dificultad){
        // Dificultad en modo novato
        case 1:
            // Seleccion del estado de control del juego
            switch(estado){
            case 1:
                    // Dibujo de la cabeza del monigote
                    dibujoCabeza();
                    break;
            case 2:
                    // Dibujo del cuello del monigote
                    dibujarCuello();
                    break;
            case 3:
                    // Dibujo del cuerpo del monigote
                    dibujarCuerpo();
                    break;
            case 4:
                    // Dibujo del brazo izquierdo
                    dibujarBrazoIzq();
                    break;
            case 5:
                    // Dibujo del brazo derecho
                    dibujarBrazoDer();
                    break;
            case 6:
                    // Dibujo de la pierna izquierda
                    dibujarPiernaIzq();
                    break;
            case 7:
                    // Dibujo de la pierna derecha
                    dibujarPiernaDer();
                    break;
            default:
                    // Estado desconocido del juego
                    cerr << "Estado desconocido" << endl;
            }
            break;
        // Dificultad en modo intermedio
        case 2:
            switch(estado){
                case 1:
                    // Dibujo de la cabeza y del cuello
                    dibujoCabeza();
                    dibujarCuello();
                    break;
                case 2:
                    // Dibujo del brazo izquierdo
                    dibujarBrazoIzq();
                    break;
                case 3:
                    // Dibujo del brazo derecho
                    dibujarBrazoDer();
                    break;
                case 4:
                    // Dibujo del cuerpo
                    dibujarCuerpo();
                    break;
                case 5:
                    // Dibujo de las dos piernas
                    dibujarBrazoIzq();
                    dibujarPiernaDer();
                    break;
                default:
                    cerr << "Estado desconocido " << endl;
            }
            break;
        // Dificultad en modo maestro
        case 3:
            switch(estado){
                case 1:
                    // Dibujo de la cabeza y del cuello
                    dibujoCabeza();
                    dibujarCuello();
                    break;
                case 2:
                    // Dibujo de los dos brazos
                    dibujarBrazoIzq();
                    dibujarBrazoDer();
                    break;
                case 3:
                    // Dibujo del cuerpo
                    dibujarCuerpo();
                    break;
                case 4:
                    // Dibujo de las dos piernas
                    dibujarBrazoIzq();
                    dibujarPiernaDer();
                    break;
                default:
                    cerr << "Estado desconocido " << endl;
            }
            break;
         // Niguno de los modos de dificultad coincide
        default:
            cerr << "Dificutad no admitida " << endl;
    }
    // Incremento del estado del juego
    estado++;
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
		usleep(retardo);
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
 * Pre: <<ficheroPalabrasBinario>> es un fichero binario que almacena una secuencia de
 *      de palabras, <<numLineas>> es el numero de lineas del fichero
 * Post: Ha seleccionado una fila aleatoria del fichero <<ficheroPalabrasBinario>> y ha guardado en
 *       <<p>> la palabra correspondiente a esa linea
 */
void seleccionarPalabra(const char ficheroPalabrasBinario[], const int numLineas, Palabra& p){
	// Flujo de lectura del fichero binario
	ifstream f;
	// Apertura del fichero de palabras
	f.open(ficheroPalabrasBinario, ios::binary);
	if (f.is_open()){
		// Seleccion aleatoria de una linea del fichero
		int lineaAleatoria = rand() % numLineas + 1;
		// Calculo de la posicion en bytes de la palabra en esa fila aleatoria
		int direccion = sizeof(Palabra) * (lineaAleatoria - 1);
		// Desplazamiento del cursor a la posicion
		f.seekg(direccion);
		// Lectura de la palabra en esa fila
		f.read(reinterpret_cast<char *>(&p), sizeof(Palabra));

		// Cierre del flujo de lectura del fichero
		f.close();
	}
	else {
		// Error en el fichero binario de palabras
		cerr << " El fichero " << ficheroPalabrasBinario << " no esta disponible " << endl;
	}
}


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
 * Secuenvia de pruebas basicas para probar el TAD Palabra
 */
int main(){

	// Semilla generadora de numeros aleatorios
	srand(time(NULL));


	// configurar color de la terminal
    textbackground(FONDO_AZUL);

    // configurar color de la fuente
    textcolor(COLOR_AMARILLO);

	// Ficheros de trabajo
	const char f1[MAX_LONG_FICHERO] = "palabras_rae.txt";
	const char f2[MAX_LONG_FICHERO] = "palabras_bin.bin";

	// Contador de filas del fichero de texto de palabras
	int numLineas;

	// Palabra seleccionada para guardar
	Palabra palabraSeleccionada;

	// Lectura del fichero de palabras y generacion del fichero binario
	crearFicheroPalabrasBinario(f1, f2, numLineas);

	// seleccion de la palabra con la que se va a jugar
	seleccionarPalabra(f2, numLineas, palabraSeleccionada);

	// Numero de letras de la palabra seleccionada
	int numLetras = obtenerLetras(palabraSeleccionada);

	// Estado inicial del juego
    int estado = 1;

	// Modo de dificultad por defecto
	int dificultad = 1;

	// PRESENTAR EL MENU DEL JUEGO

	// Numero de letras descubiertas de la palabra
	int letrasVolteadas = 0;

	// Muestreo de los huecos de la palabra a averiguar
	mostrarHuecosPalabra(palabraSeleccionada);

	// Dibujo de la horca
	dibujarHorca();

	// Peticion de letra con la que jugar al usuario
	char letra;
	pedirLetra(letra);

	// Comprobar si la letra esta o no en la palara
	if (existeLetra(palabraSeleccionada, letra, letrasVolteadas)){
        // Sustitucion de los huecos por las letras correctas
	}
	else {
        // Dibujo correspondiente del monigote
        dibujoParteMonigote(estado, dificultad);

        gotoxy(5,5);
        cout << "La letra " << letra << " esta contenida" << endl;
        usleep(retardo);
        clreol();
	}


	// Mientras queden letras por descubir
	while (letrasVolteadas != numLetras){
		// Se vuelve a pedir letra nueva
		pedirLetra(letra);

		// Comprobar si la letra nueva esta o no en la palara
		existeLetra(palabraSeleccionada, letra, letrasVolteadas);
	}

	cout << " Fin del programa " << endl;
	return 0;
}
