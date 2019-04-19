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


void escribirFichero (const char ficheroPalabrasTexto[], const char ficheroPalabrasBinario[]){
	ifstream f1;
	ofstream f2;
	
	f1.open(ficheroPalabrasTexto);
	if (f1.is_open()){
		
		f2.open(ficheroPalabrasBinario,ios::binary);
		
		if (f2.is_open()){
			Palabra palabraActual;
			
			char linea[128];
			f1.getline(linea, 128, '\n');
			
			crearPalabra(linea, int(strlen(linea)), palabraActual);
			
			while (!f1.eof()){
				
				f2.write(reinterpret_cast<char *>(&palabraActual), sizeof(Palabra));
				f1.getline(linea, 128, '\n');
			}
			f1.close();
			f2.close();
		}
		else {
			cerr << " El fichero " << ficheroPalabrasBinario << " es innacesible" << endl;
		}
	}
	else {
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
	
	escribirFichero(f1, f2);
	
	cout << " Fin del programa " << endl;
	return 0;
}