#ifndef ARRANQUE_H_INCLUDED
#define ARRANQUE_H_INCLUDED


#include <iostream>
#include <cstring>
#include <fstream>
#include "Palabra.h"


using namespace std;


/*
 * Pre: <<ficheroPalabrasTexto>> es un fichero de texto que almacena, a razón de una por línea,
 *      un diccionario amplio de palabras en castellano.
 * Post: Ha creado un fichero binario denominado <<ficheroPalabrasBinario>> con el contenido del
 *      fichero <<ficheroPalabrasTexto>>. En caso de que el fichero no exista lo crea, y si no,
 *      lo trunca y reemplaza su contenido y ha guardado en <<totalLineas>> el numero de lineas del
 *      fichero de texto
 */
void crearFicheroPalabrasBinario(const char ficheroPalabrasTexto[], const char ficheroPalabrasBinario[], int& totalLineas);


#endif // ARRANQUE_H_INCLUDED
