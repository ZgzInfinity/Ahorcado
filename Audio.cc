/*
 * -------------------------------
 * Juego del Ahorcado en C++ -----
 * Autor: Rubén Rodríguez --------
 * Fecha: 14-4-19 ----------------
 * -------------------------------
 */

/*
 * Fichero de implementacion del modulo Audio
 */

#include "Audio.h"


/*
 * Pre: ---
 * Post: Ha reproducido por el microfono la banda sonora correspondiente
 *       al menu principal del juego
 */
void sonidoMenuPrincipal(){
    mciSendString("open menu.wav alias MENU", NULL, 0, NULL);
    mciSendString("play MENU", NULL, 0, NULL);
}



/*
 * Pre: ---
 * Post: Ha reproducido por el microfono la banda sonora correspondiente
 *       al menu de opciones del juego
 */
void sonidoMenuOpciones(){
    mciSendString("open opciones.wav alias OPTIONS", NULL, 0, NULL);
    mciSendString("play OPTIONS", NULL, 0, NULL);
}



/*
 * Pre: ---
 * Post: Ha reproducido por el microfono la banda sonora correspondiente
 *       a la primera pista del juego
 */
void sonidoPistaPrimera(){
    mciSendString("open main.wav alias FIRST_TRACK", NULL, 0, NULL);
    mciSendString("play FIRST_TRACK", NULL, 0, NULL);
}



/*
 * Pre: ---
 * Post: Ha reproducido por el microfono la banda sonora correspondiente
 *       a la segunda pista del juego
 */
void sonidoPistaSegunda(){
    mciSendString("open speed.wav alias SECOND_TRACK", NULL, 0, NULL);
    mciSendString("play SECOND_TRACK", NULL, 0, NULL);
}



/*
 * Pre: ---
 * Post: Ha reproducido por el microfono la banda sonora correspondiente
 *       a la tercera pista del juego
 */
void sonidoPistaTercera(){
    mciSendString("open master.wav alias THIRD_TRACK", NULL, 0, NULL);
    mciSendString("play THIRD_TRACK", NULL, 0, NULL);
}



/*
 * Pre: <<pista>> es el indice de la pista musical seleccionada por
 *      el usario a reproducir
 * Post: Ha reproducido durante la partida la banda sonora con indice de pista
 *       <<pista>>
 */
void tocarMusicaPartida(int& pista){
    switch(pista){
        // Reproducir primera pista a modo de prueba
        case 0 :
            sonidoPistaPrimera();
        break;
        // Reproducir segunda pista a modo de prueba
        case 1 :
            sonidoPistaSegunda();
        break;
        // Reproducir tercera pista a modo de prueba
        case 2 :
            sonidoPistaTercera();
        break;
            // Reproducir tercera pista a modo de prueba
        case 3 :
            // El audio del juego esta silenciado
        break;
        default:
            cerr <<" La pista " << pista << " es desconocida " << endl;
    }
}



/*
 * Pre: ---
 * Post: Ha reproducido por el microfono el sonido correcto debido
 *       a que el usuario ha acertado una letra de la palabra
 */
void tocarSonidoCorrecto(){
    mciSendString("open correcto.wav alias CORRECT", NULL, 0, NULL);
    mciSendString("play CORRECT", NULL, 0, NULL);
}



/*
 * Pre: ---
 * Post: Ha reproducido por el microfono el sonido incorrecto debido
 *       a que el usuario ha acertado una letra de la palabra
 */
void tocarSonidoIncorrecto(){
    mciSendString("open incorrecto.wav alias INCORRECT", NULL, 0, NULL);
    mciSendString("play INCORRECT", NULL, 0, NULL);
}



/*
 * Pre: ---
 * Post: Ha detenido la reproduccion del sonido actual en curso
 */
void sonidoDetener(){
    PlaySound(NULL, NULL, 0);
}







