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
#include <conio.h>

using namespace std;

// Longitud de la palabra mas larga conocida
const int MAX_LETRAS = 33;

struct Palabra {
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
		friend void crearPalabra(char secuencia[], int nLetras, Palabra& p);


		/*
		 * Pre: ---
		 * Post: Ha copiado en <<palabra>> la secuencia de caracteres
		 *       almacenados en <<cadena>>
		 */
		friend void obtenerPalabra(char palabra[], Palabra& p);


		/*
		 * Pre: ---
		 * Post: Ha devuelto el total de letras de la palabra
		 */
		friend int obtenerLetras(Palabra& p);


		/*
		 * Pre: ---
		 * Post: Ha devuelto la i-esima letra de la palabra <<p>>
		 */
		friend char devolverLetra(Palabra& p, const int i);


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
		 friend void mostrarHuecosPalabra(Palabra& p);


		/*
		 * Pre: <<p>> es una secuencia de caracteres que describe la
		 *       estructura de una palabra
		 * Post: Ha devuelto <<true>> si y solo si la letra <<l>> esta dentro
		*       de la palabra <<p>> y ha reemplazada en la posicion correspondiente
		*       el caracter "_" por el valor de la letra <<l>>
		*/
		friend void existeLetra(Palabra& p, const char l, int& letrasVoltedas, bool& encontrado);

};

#endif
