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
#include <windows.h>
#include "Palabra.h"
#include "Monigote.h"

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
const int RETARDO = 60000;

const int TECLA_ENTER = 13;
const int TECLA_ESC = 27;




/*
 * Pre: <<tipo>> es un identificador del sonido a reproducir
 * Post: Ha reproducido el sonido con identificador <<tipo>>
 */
void reproducirSonido(const int tipo){
    if (tipo == 0){
        PlaySound("menu.wav", NULL, SND_ASYNC);
    }
    else if (tipo == 1){
        PlaySound("correcto.wav", NULL, SND_ASYNC);
    }
    else if (tipo == 2) {
        PlaySound("incorrecto.wav", NULL, SND_ASYNC);
    }
    else {
        PlaySound(NULL, NULL, 0);
    }
}



/*
 * Pre: ---
 * Post: Muestra por pantalla el mensaje "Pulse la tecla intro" hasta
 *       que se detecta la tecla
 */
void controlPulsoEnter(){
    bool pulsada = false;

    // Capturar codigo de la tecla ENTER
    while (!pulsada){
         gotoxy(38,18);
         cout << "Pulsa la tecla INTRO para comenzar" << flush;

         // Capturar tecla pulsada
         unsigned char tecla = getch();

         // Comprobacion de tecla ENTER
         if (int(tecla) == TECLA_ENTER){
            // Es la tecla ENTER
            pulsada = true;
         }
    }
}





/*
 * Pre: ---
 * Post: Ha mostrado por pantalla el menu inicial del
 *       juego
 */
void presentarMenu(){
    // Datos del creador
    gotoxy(43,15);
    cout << " ZgzInfinity - 2019 " << endl;

    // Control del pulso de la tecla INTRO
    controlPulsoEnter();
}





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

        cout << int(tecla) << endl;
        // Comprobacion de tecla ENTER
        if (int(tecla) == TECLA_ENTER || int(tecla == TECLA_ESC)){
            // Es la tecla ENTER
            pulsada = true;

            // Comprobacion de la tecla
            if (int(tecla == TECLA_ENTER)){
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
 * Pre: <<estado>> almacena el estado actual del juego, <<dificultad>> guarda el
 *       nivel de doficultad introducido por el usuario y <<fin>> controla el final
 *       de la partida y toma de valor <<false>>
 * Post: Ha dibujado la parte correspondiente del monigote en funcion del
 *       estado del juego. Si el jugador ha consumido todos los intentos <<fin>>
 *       tomar el valor de <<true>> y finaliza la partida. En caso contario
 *       continua a <<false>> y permitira futuros intentos
 */
void dibujoParteMonigote(int& estado, const int dificultad, bool& fin){
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
                    // Fin de la partida actual
                    fin = true;
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
                    dibujarPiernaIzq();
                    dibujarPiernaDer();
                    // Fin de la partida actual
                    fin = true;
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
                    dibujarPiernaIzq();
                    dibujarPiernaDer();
                    // Fin de la partida actual
                    fin = true;
                    break;
                default:
                    cerr << "Estado desconocido " << endl;
            }
            break;
         // Niguno de los modos de dificultad coincide
        default:
            cerr << "Dificutad no admitida " << endl;
    }
    estado++;
}


/*
 * Pre: ---
 * Post: Ha guardado en <<dificultad>> el tipo de dificultad introducida
 *       por el usuario
 */
void pedirDificultad(int& dificultad){
    // Modo de dificultad por defecto
	gotoxy(4, 2);
	cout << " Introduzca el nivel de dificultad con el que desea jugar: " << flush;
	cin >> dificultad;

	// Repetir hasta que la dificultad este entre los limites permitidos
	while (dificultad < DIFICULTAD_MINIMA || dificultad > DIFICULTAD_MAXIMA){
        cout << " Nivel de dificultad no valido " << endl;
        // Modo de dificultad por defecto
        gotoxy(4, 2);
        cout << " Introduzca el nivel de dificultad con el que desea jugar: " << flush;
        cin >> dificultad;
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
		usleep(RETARDO);
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

    // Ajustar dimensiones automaticas de la consola
    system("mode con: cols=110 lines=24");

	// Semilla generadora de numeros aleatorios
	srand(time(NULL));

	// configurar color de la terminal
    textbackground(FONDO_AZUL);

    // configurar color de la fuente
    textcolor(COLOR_AMARILLO);

    // Sonido del menu del juego
    reproducirSonido(0);

    // Presentacion del menu inicial del juego
    presentarMenu();

    // Detener la ejecución del sonido del menu
    reproducirSonido(3);

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

	// Numero de letras de la palabra seleccionada
	int numLetras = obtenerLetras(palabraSeleccionada);

	// Estado inicial del juego
    int estado = 1;

    int dificultad;

    // Pedir dificultad al usuario
    pedirDificultad(dificultad);

	// Numero de letras descubiertas de la palabra
	int letrasVolteadas = 0;

	// Letra con la que jugar al usuario
	char letra;

	// Controlador de sonidos
	int tipo;

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

        gotoxy(1,1);
        char linea[MAX_LETRAS];
        obtenerPalabra(linea, palabraSeleccionada);
        cout << linea << endl;

        // Muestreo de los huecos de la palabra a averiguar
        mostrarHuecosPalabra(palabraSeleccionada);

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

                // Sonido correcto
                tipo = 1;
                reproducirSonido(tipo);
            }
            else {
                // Dibujo correspondiente del monigote
                dibujoParteMonigote(estado, dificultad, fin);
                textcolor(COLOR_ROJO);
                gotoxy(4,5);
                cout << "La letra " << letra << " no esta contenida" << endl;

                // Sonido incorrecto
                tipo = 2;
                reproducirSonido(tipo);
            }

            // Esperar un tiempo y limpiar la linea
            // usleep(RETARDO);
            system("pause");
            clreol();
            // Cambio de color de la fuente
            textcolor(COLOR_AMARILLO);
        }

        // Fin de la partida y pregunta al usuario si desea jugar
        controlFinDelJuego(terminado);
    }

	// Posicionamiento al final de la pantalla para el fin de ejecucion
	gotoxy(1,24);
	cout << " Fin del programa " << endl;
	return 0;
}
