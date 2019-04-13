/*
 * -------------------------------
 * Juego del Ahorcado en C++ -----
 * Autor: Rubén Rodríguez --------
 * Fecha: 14-4-19 ----------------
 * -------------------------------
 */

#ifndef PALABRA_H
#define PALABRA_H

/* 
 * Fichero de interfaz del módulo palabra
 */
 
 
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

// Longitud de la palabra mas larga conocida
const int MAX_LETRAS = 33;
 
class Palabra {
	private:
		// Estructura interna del tipo de dato Palabra
		char cadena[MAX_LETRAS];	// vector de caracteres que representa las letras de la palabra
		int numLetras;				// numero de letras de la palabra
	public:
		
		/*
		 * Pre: <<secuencia>> es una secuencia de caracteres que representa una 
		 *      palabra de la lengua española y <<nLetras>> es el total de letras 
		 *      de la cadena <<secuencia>>
		 * Post: Ha creado una palabra asignado a <<cadena>> la secuencia de caracteres
		 *      <<secuencia>> y a <<numLetras>> el valor de <<nLetras>>
		 */
		Palabra(char secuencia[], int nLetras);
		
		
		/*
		 * Pre: ---
		 * Post: Ha copiado en <<palabra>> la secuencia de caracteres
		 *       almacenados en <<cadena>>
		 */
		void obtenerPalabra(char palabra[]);
		
		
		/*
		 * Pre: ---
		 * Post: Ha devuelto el total de letras de la palabra
		 */
		int obtenerLetras();
};

#endif