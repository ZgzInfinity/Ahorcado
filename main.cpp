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
#include "Palabra.h"

const int MAX_LONG_FICHERO = 100;


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
	
	srand(time(NULL));
	
	char sec1[MAX_LETRAS] = "domingo";
	char sec2[MAX_LETRAS] = "bicicleta";
	
	const char f1[MAX_LONG_FICHERO] = "palabras_rae.txt";
	const char f2[MAX_LONG_FICHERO] = "palabras_bin.bin";
	
	// Priemra instancia del tipo de dato palabra
	Palabra p1;
	crearPalabra(sec1, 7, p1);
	
	// Segunda instancia del tipo de dato palabra
	Palabra p2;
	crearPalabra(sec2, 9, p2);
	
	// Cadenas de caracteres para almacenar las palabras
	char sec3[MAX_LETRAS];
	char sec4[MAX_LETRAS];
	
	// Guardado de la palabra <<p1>> en <<sec1>>
	obtenerPalabra(sec3, p1);
	
	// Guardado de la palabra <<p2>> en <<sec2>>
	obtenerPalabra(sec4, p2);
	
	cout << " La palabra " << sec3 << " tiene " << obtenerLetras(p1) << " letras " << endl;
	cout << " La palabra " << sec4 << " tiene " << obtenerLetras(p2) << " letras " << endl;
	
	// Contador de filas del fichero de texto de palabras
	int numLineas;
	
	// Palabra seleccionada para guardar
	Palabra palabraSeleccionada;
	
	// Lectura del fichero de palabras y generacion del fichero binario
	crearFicheroPalabrasBinario(f1, f2, numLineas);
	
	// seleccion de la palabra con la que se va a jugar
	seleccionarPalabra(f2, numLineas, palabraSeleccionada);
	
	// Obtencion de la palabra leida
	char palabra[MAX_LETRAS];
	obtenerPalabra(palabra, palabraSeleccionada);
	
	// Muestreo de la palabra seleccionada
	cout << "La palabra leida es " << palabra << " y tiene " << obtenerLetras(palabraSeleccionada) << endl;
	
	cout << " Fin del programa " << endl;
	return 0;
}