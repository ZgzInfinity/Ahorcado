/*
 * -------------------------------
 * Juego del Ahorcado en C++ -----
 * Autor: Rubén Rodríguez --------
 * Fecha: 14-4-19 ----------------
 * -------------------------------
 */

/*
 * Fichero de implementacion del modulo Palabra
 */


#include "Palabra.h"


/*
 * Pre: <<secuencia>> es una secuencia de caracteres que representa una
 *      palabra de la lengua española y <<nLetras>> es el total de letras
 *      de la cadena <<secuencia>>
 * Post: Ha creado una palabra asignado a <<cadena>> la secuencia de caracteres
 *      <<secuencia>> y a <<numLetras>> el valor de <<nLetras>>
 */
void crearPalabra(char secuencia[], int nLetras, Palabra& p){
	strcpy(p.cadena, secuencia);
	p.numLetras = nLetras;
}



/*
 * Pre: ---
 * Post: Ha copiado en <<palabra>> la secuencia de caracteres
 *       almacenados en <<cadena>>
 */
void obtenerPalabra(char palabra[], Palabra& p){
	strcpy(palabra, p.cadena);
}



/*
 * Pre: ---
 * Post: Ha devuelto el total de letras de la palabra
 */
int obtenerLetras(Palabra& p){
	return p.numLetras;
}




/*
 * Pre: ---
 * Post: Ha devuelto la i-esima letra de la palabra <<p>>
 */
char devolverLetra(Palabra& p, const int i){
	return p.cadena[i];
}




/*
 * Pre: ---
 * Post: Ha mostrado por cada letra de la palabra <<p>> un guion
 *       bajo de acuerdo al siguiente formato
 *
 *      Ejemplo:
 *      diligentemente:  _ _ _ _ _ _ _ _ _ _ _ _ _ _
 *      ababol:          _ _ _ _ _ _
 *      ganzua:          _ _ _ _ _ _
 */
void mostrarHuecosPalabra(Palabra& p){
	// Total de letras de la palabra <<p>>
	gotoxy(60, 15);
	int numLetras = obtenerLetras(p);
	// Bucle de recorrido de la palabra
	for (int i = 0; i < numLetras; i++){
		cout << "_ ";
	}
	cout << endl << endl;
}


/*
 * Pre: <<p>> es una secuencia de caracteres que describe la
 *       estructura de una palabra
 * Post: Ha devuelto <<true>> si y solo si la letra <<l>> esta dentro
 *       de la palabra <<p>> y ha reemplazada en la posicion correspondiente
 *       el caracter "_" por el valor de la letra <<l>>
 */
void existeLetra(Palabra& p, const char l, int& letrasVolteadas, bool& encontrado){
	// Total de letras de la palabra <<p>>
	int numLetras = obtenerLetras(p);
	// Control de existencia de letra
    encontrado = false;
	// Total de veces que ha aparecido la letra <<l>>
	int numVeces = 0;
	// Bucle de recorrido
	for (int i = 0; i < numLetras; i++){
		// Se compara si la letra i-ésima es igual a <<l>>
		if (devolverLetra(p, i) == l){
			// Se ha hallado una nueva letra y se voltea
			letrasVolteadas++;
			// Incremento del numero de veces que se ha hallado la letra
			numVeces++;
			// Se compara si esta mas de una vez
			if (numVeces == 1){
				// es la primera vez
				encontrado = true;
			}
			// Muestreo de la letra en la poscion correcta
			gotoxy(60 + 2 * i, 15);
            cout << l << " ";
		}
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






