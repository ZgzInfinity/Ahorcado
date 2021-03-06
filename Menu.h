#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED


#include <iostream>
#include <thread>
#include <conio.h>
#include "Audio.h"

using namespace std;


const int TECLA_ENTER = 13;
const int COLOR_VERDE = 10;
const int COLOR_AMARILLO = 14;
const int MAX_DIFICULTADES = 3;
const int RETARDO = 6000;


/*
 * Pre: ---
 * Post: Muestra por pantalla el mensaje "Pulse la tecla intro" hasta
 *       que se detecta la tecla
 */
void mostrarTitulo(string deseo);


/*
 * Pre: ---
 * Post: Ha devuelto el tipo de dificultad del modo de juego
 */
string mostrarDificultad(int& dificultad);


/*
 * Pre: ---
 * Post: Ha mostrado por pantalla un rotulo cuyo contenido es "FINAL"
 */
void presentarFinal();



/*
 * Pre: ---
 * Post: Ha mostrado por pantalla el menu inicial del
 *       juego
 */
void presentarMenu();



/*
 * Pre: ---
 * Post: Ha dibujado por pantalla una cuadricula pequenya
 */
void dibujoCuadricula();



/*
 * Pre: ---
 * Post: Ha mostrado por pantalla un menu con las posibles
 *       opciones de configuracion al usuario
 */
void menuOpciones(int& dificultad, int& pista, char nombre[]);



/*
 * Pre: ---
 * Post: Ha mostrado por pantalla un panel con la informacion de la partida actual del usuario.
 *       En el lateral izquierdo se ha informado de la dificultad actual del modo de juego, en el centro
 *       se encuentra el nombre del jugador actual, y en la derecha figura el total de ountos que lleva actualmente
 */
void panelPuntuacion(string dificultad, string nombre, int puntos, bool& actualizar);



/*
 * Pre: ---
 * Post: Ha mostrado por terminal los caracteres que componen la cadena
 *          <<mensaje>> con un intervalo de separacion de 100 milisegundos
 */
void mostrarMensaje(const string mensaje);




/*
 * Pre: ---
 * Post: Muestra por pantalla los creditos del juego
 */
void creditos();


#endif // MENU_H_INCLUDED
