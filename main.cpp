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
 * Secuenvia de pruebas basicas para probar el TAD Palabra
 */
int main(){
	
	srand(time(NULL));
	
	char sec1[MAX_LETRAS] = "domingo";
	char sec2[MAX_LETRAS] = "bicicleta";
	
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
	
	cout << " Fin del programa " << endl;
	return 0;
}