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
 * Pre: <<ficheroPalabrasTexto>> es un fichero de texto que almacena, a razón de una por línea,
 *      un diccionario amplio de palabras en castellano.
 * Post: Ha creado un fichero binario denominado <<ficheroPalabrasBinario>> con el contenido del
 *      fichero <<ficheroPalabrasTexto>>. En caso de que el fichero no exista lo crea, y si no,
 *      lo trunca y reemplaza su contenido
 */ 
void crearFicheroPalabrasBinario(const char ficheroPalabrasTexto[], const char ficheroPalabrasBinario[]){
	// Flujo de lectura asociado al fichero de texto
	ifstream f1;
	// Flujo de escritura asociado al fichero binario
	ofstream f2;
	
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
	
	const char f1[MAX_LONG_FICHERO] = "palabras_mod.txt";
	const char f2[MAX_LONG_FICHERO] = "palabras_bin.txt";
	
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
	
	crearFicheroPalabrasBinario(f1, f2);
	
	cout << " Fin del programa " << endl;
	return 0;
}