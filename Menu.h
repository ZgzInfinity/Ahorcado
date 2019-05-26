#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED


#include <iostream>
#include <conio.h>
#include "Audio.h"

using namespace std;


const int TECLA_ENTER = 13;

/*
 * Pre: ---
 * Post: Muestra por pantalla el mensaje "Pulse la tecla intro" hasta
 *       que se detecta la tecla
 */
void mostrarTituloParpadeante();



/*
 * Pre: ---
 * Post: Ha mostrado por pantalla el menu inicial del
 *       juego
 */
void presentarMenu();



/*
 * Pre: ---
 * Post: Ha mostrado por pantalla un menu con las posibles
 *       opciones de configuracion al usuario
 */
void menuOpciones(int& dificultad, int& pista);



#endif // MENU_H_INCLUDED
