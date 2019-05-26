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
    PlaySound("menu.wav", NULL, SND_ASYNC);
}



/*
 * Pre: ---
 * Post: Ha reproducido por el microfono la banda sonora correspondiente
 *       al menu de opciones del juego
 */
void sonidoMenuOpciones(){
    PlaySound("opciones.wav", NULL, SND_ASYNC);
}



/*
 * Pre: ---
 * Post: Ha reproducido por el microfono la banda sonora correspondiente
 *       a la primera pista del juego
 */
void sonidoPistaPrimera(){
    PlaySound("main.wav", NULL, SND_ASYNC);
}



/*
 * Pre: ---
 * Post: Ha reproducido por el microfono la banda sonora correspondiente
 *       a la segunda pista del juego
 */
void sonidoPistaSegunda(){
    PlaySound("speed.wav", NULL, SND_ASYNC);
}



/*
 * Pre: ---
 * Post: Ha reproducido por el microfono la banda sonora correspondiente
 *       a la tercera pista del juego
 */
void sonidoPistaTercera(){
    PlaySound("master.wav", NULL, SND_ASYNC);
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
            cout << " Modo de juego sin audio " << endl;
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
void sonidoCorrecto(){
    PlaySound("correcto.wav", NULL, SND_ASYNC);
}



/*
 * Pre: ---
 * Post: Ha reproducido por el microfono el sonido incorrecto debido
 *       a que el usuario ha acertado una letra de la palabra
 */
void sonidoIncorrecto(){
    PlaySound("incorrecto.wav", NULL, SND_ASYNC);
}



/*
 * Pre: ---
 * Post: Ha detenido la reproduccion del sonido actual en curso
 */
void sonidoDetener(){
    PlaySound(NULL, NULL, 0);
}







