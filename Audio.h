/*
 * -------------------------------
 * Juego del Ahorcado en C++ -----
 * Autor: Rubén Rodríguez --------
 * Fecha: 14-4-19 ----------------
 * -------------------------------
 */

/*
 * Fichero de interfaz del modulo Audio
 */


#ifndef AUDIO_H_INCLUDED
#define AUDIO_H_INCLUDED


#include<iostream>
#include<windows.h>
#include<conio.h>



using namespace std;

/*
 * Pre: ---
 * Post: Ha reproducido por el microfono la banda sonora correspondiente
 *       al menu principal del juego
 */
void sonidoMenuPrincipal();



/*
 * Pre: ---
 * Post: Ha reproducido por el microfono la banda sonora correspondiente
 *       al menu de opciones del juego
 */
void sonidoMenuOpciones();



/*
 * Pre: ---
 * Post: Ha reproducido por el microfono la banda sonora correspondiente
 *       a la primera pista del juego
 */
void sonidoPistaPrimera();



/*
 * Pre: ---
 * Post: Ha reproducido por el microfono la banda sonora correspondiente
 *       a la segunda pista del juego
 */
void sonidoPistaSegunda();



/*
 * Pre: ---
 * Post: Ha reproducido por el microfono la banda sonora correspondiente
 *       a la tercera pista del juego
 */
void sonidoPistaTercera();



/*
 * Pre: <<pista>> es el indice de la pista musical seleccionada por
 *      el usario a reproducir
 * Post: Ha reproducido durante la partida la banda sonora con indice de pista
 *       <<pista>>
 */
void tocarMusicaPartida(int& pista);



/*
 * Pre: ---
 * Post: Ha reproducido por el microfono el sonido correcto debido
 *       a que el usuario ha acertado una letra de la palabra
 */
void tocarSonidoCorrecto();



/*
 * Pre: ---
 * Post: Ha reproducido por el microfono el sonido incorrecto debido
 *       a que el usuario ha acertado una letra de la palabra
 */
void tocarSonidoIncorrecto();



/*
 * Pre: ---
 * Post: Ha reproducido por el microfono el sonido Find_out debido
 *       a que el usuario ha descifrado la palabra
 */
void tocarSonidoFindOut();



/*
 * Pre: ---
 * Post: Ha reproducido por el microfono el sonido incorrecto debido
 *       a que el usuario ha fallado toda la palabra
 */
void tocarSonidoGameOver();




/*
 * Pre: ---
 * Post: Ha reproducido por el microfono el sonido incorrecto debido
 *       a que el usuario conteste si quiere jugar otra vez
 */
void tocarSonidoReloj();



/*
 * Pre: ---
 * Post: Ha reproducido por el microfono el sonido del ranking
 */
void tocarSonidoRanking();



/*
 * Pre: ---
 * Post: Ha detenido la reproduccion del sonido actual en curso
 */
void detenerSonidoMenu();



/*
 * Pre: ---
 * Post: Ha detenido la reproduccion del sonido del menu de opciones
 */
void detenerSonidoOpciones();



/*
 * Pre: ---
 * Post: Ha detenido la reproduccion del sonido de la primera pista
 */
void detenerSonidoPistaPrimera();



/*
 * Pre: ---
 * Post: Ha detenido la reproduccion del sonido de la segunda pista
 */
void detenerSonidoPistaSegunda();



/*
 * Pre: ---
 * Post: Ha detenido la reproduccion del sonido de la tercera pista
 */
void detenerSonidoPistaTercera();



/*
 * Pre: ---
 * Post: Ha detenido la reproduccion del sonido de Find out
 */
void detenerSonidoFindOut();



/*
 * Pre: ---
 * Post: Ha detenido la reproduccion del sonido de Game over
 */
void detenerSonidoGameOver();



/*
 * Pre: ---
 * Post: Ha detenido la reproduccion del sonido de Reloj
 */
void detenerSonidoReloj();



/*
 * Pre: ---
 * Post: Ha detenido la reproduccion del sonido del ranking
 */
void detenerSonidoRanking();




/*
 * Pre: <<pista>> es el indice de la pista musical seleccionada por
 *      el usario a reproducir
 * Post: Ha detenido la banda sonora de la partida la con indice de pista
 *       <<pista>>
 */
void detenerSonidoPartida(int& pista);

#endif
