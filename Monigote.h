/*
 * -----------------------------------
 * Proyecto: Juego del Ahorcado  -----
 * Autor: Ruben Rodriguez ------------
 * Fecha: 19-4-19 --------------------
 * -----------------------------------
 */

#ifndef MONIGOTE_H
#define MONIGOTE_H


/*
 * Fichero de interfaz del modulo de dibujo del monigote
 */

 #include <iostream>
#include <conio.h>


using namespace std;


const int DIMENSION = 15;
const int ESQUINA_SUP_IZQ = 218;
const int ESQUINA_SUP_DER = 191;
const int ESQUINA_INF_IZQ = 192;
const int ESQUINA_INF_DER = 217;
const int LINEA_HORIZONTAL = 196;
const int LINEA_VERTICAL = 179;
const int TRI_LAT_IZQ = 195;
const int TRI_LAT_INF = 193;
const int TRI_LAT_SUP = 194;
const int TRI_LAT_DER = 180;
const int CRUZ = 197;



/*
 * Pre: ---
 * Post: Ha dibujado por pantalla la horca donde se va a
 *       ahorcar al monigote
*/
void dibujarHorca();



/*
 * Pre: ---
 * Post: Ha dibujado la cabeza del monigote
 */
void dibujoCabeza();



/*
 * Pre: ---
 * Post: Ha dibujado el cuello del monigote
 */
void dibujarCuello();



/*
 * Pre: ---
 * Post: Ha dibujado el brazo izquierdo del monigote
 */
void dibujarBrazoIzq();



/*
 * Pre: ---
 * Post: Ha dibujado el brazo derecho del monigote
 */
void dibujarBrazoDer();



/*
 * Pre: ---
 * Post: Ha dibujado el cuerpo del monigote
 */
void dibujarCuerpo();



/*
 * Pre: ---
 * Post: Ha dibujado la pierna izquierdo del monigote
 */
void dibujarPiernaIzq();



/*
 * Pre: ---
 * Post: Ha dibujado la pierna derecho del monigote
 */
void dibujarPiernaDer();



/*
 * Pre: <<estado>> almacena el estado actual del juego, <<dificultad>> guarda el
 *       nivel de doficultad introducido por el usuario y <<fin>> controla el final
 *       de la partida y toma de valor <<false>>
 * Post: Ha dibujado la parte correspondiente del monigote en funcion del
 *       estado del juego. Si el jugador ha consumido todos los intentos <<fin>>
 *       tomar el valor de <<true>> y finaliza la partida. En caso contario
 *       continua a <<false>> y permitira futuros intentos
 */
void dibujoParteMonigote(int& estado, const int dificultad, bool& fin);


#endif // MONIGOTE_H


