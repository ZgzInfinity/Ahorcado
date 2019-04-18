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

void seleccionarPalabra(const char fichero[], Palabra& p){
	fstream f;
	char secuencia[MAX_LETRAS];
	
	try {
		f.open(fichero);
		f.is_open();
		
		int numLineas;
		f >> numLineas;
		cout << numLineas << endl;
		
		int randomLinea = rand() % numLineas + 1;
		cout << randomLinea << endl;
		
		int direccion = sizeof(Palabra) * (randomLinea - 1);
		
		f.seekp(direccion);
		
		char linea[4] = "kkk";
		
		f << linea << endl;
		
		f.getline(secuencia, 128,'\n') ;
		
		p = Palabra(secuencia, int(strlen(secuencia)));
	}
	catch (exception e) {
		cerr << " El fichero " << fichero << " no esta disponible " << endl;
	}
}


/*
 * Secuenvia de pruebas basicas para probar el TAD Palabra
 */
int main(){
	
	srand(time(NULL));
	
	char sec1[MAX_LETRAS] = "domingo";
	char sec2[MAX_LETRAS] = "bicicleta";
	
	const char fichero[MAX_LONG_FICHERO] = "palabras_rae.txt";
	
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
	
	strcpy(sec1,"\0");
	
	Palabra p = Palabra(sec1, 0);
	
	seleccionarPalabra(fichero, p);
	
	cout << " Fin del programa " << endl;
	return 0;
}