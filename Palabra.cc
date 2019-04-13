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
Palabra::Palabra(char secuencia[], int nLetras){
	strcpy(cadena, secuencia);
	numLetras = nLetras;
}



/*
 * Pre: ---
 * Post: Ha copiado en <<palabra>> la secuencia de caracteres
 *       almacenados en <<cadena>>
 */
void Palabra::obtenerPalabra(char palabra[]){
	strcpy(palabra, this->cadena);
}



/*
 * Pre: ---
 * Post: Ha devuelto el total de letras de la palabra
 */
int Palabra::obtenerLetras(){
	return numLetras;
}