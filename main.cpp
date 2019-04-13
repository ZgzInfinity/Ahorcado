/*
 * -------------------------------
 * Juego del Ahorcado en C++ -----
 * Autor: Rubén Rodríguez --------
 * Fecha: 14-4-19 ----------------
 * -------------------------------
 */

#include "Palabra.h"


/*
 * Secuenvia de pruebas basicas para probar el TAD Palabra
 */
int main(){
	
	char sec1[MAX_LETRAS] = "domingo";
	char sec2[MAX_LETRAS] = "bicicleta";
	
	// Priemra instancia del tipo de dato palabra
	Palabra p1 = Palabra(sec1, 7);
	
	// Segunda instancia del tipo de dato palabra
	Palabra p2 = Palabra(sec2, 9);
	
	// Cadenas de caracteres para almacenar las palabras
	char sec3[MAX_LETRAS];
	char sec4[MAX_LETRAS];
	
	// Guardado de la palabra <<p1>> en <<sec1>>
	p1.obtenerPalabra(sec3);
	
	// Guardado de la palabra <<p2>> en <<sec2>>
	p2.obtenerPalabra(sec4);
	
	cout << " La palabra " << sec3 << " tiene " << p1.obtenerLetras() << " letras " << endl;
	cout << " La palabra " << sec4 << " tiene " << p2.obtenerLetras() << " letras " << endl;
	
	return 0;
}