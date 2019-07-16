
/*
 * -----------------------------------
 * Proyecto: Juego del Ahorcado  -----
 * Autor: Ruben Rodriguez ------------
 * Fecha: 19-4-19 --------------------
 * -----------------------------------
 */


/*
 * Fichero de implementación del modulo de dibujo del monigote
 */

#include "Monigote.h"


/*
 * Pre: ---
 * Post: Ha dibujado por pantalla la horca donde se va a
 *       ahorcar al monigote
*/
void dibujarHorca(){

    gotoxy(5, 7);
    // Muestra la esquina superior izquierda
    printf("%c", ESQUINA_SUP_IZQ);

    // Dibujo del palo vertical
    for (int i = 0; i < DIMENSION; i++){
        printf("%c", LINEA_HORIZONTAL);
    }

    // Dibujo de la esquina superior derecha
    printf("%c", ESQUINA_SUP_DER);

    // Muestra la columna de la horca por la pantalla
    for (int i = 1; i <= DIMENSION - 2; i++){
        gotoxy(5, 7 + i);
        printf("%c", LINEA_VERTICAL);
        if (i <= 1){
            // Dibujo de la cuerda
            gotoxy(5 + DIMENSION + 1, 7 + i);
            printf("%c", LINEA_VERTICAL);
        }
    }

    // Saca por pantalla la base de la horca
    gotoxy(3, 7 + DIMENSION - 1);
    for (int i = 0; i < DIMENSION + 15; i++){
        if (i == 2){
            printf("%c", TRI_LAT_INF);
        }
        else {
            printf("%c", LINEA_HORIZONTAL);
        }
    }
}



/*
 * Pre: ---
 * Post: Ha dibujado la cabeza del monigote
 */
void dibujoCabeza(){

    // Dibujo de las lineas verticales de la izquierda
    gotoxy(DIMENSION + 3, DIMENSION - 5);
    printf("%c", LINEA_VERTICAL);
    gotoxy(DIMENSION + 3, DIMENSION - 4);
    printf("%c", LINEA_VERTICAL);

    // Dibujo de las lineas verticales de la derecha
    gotoxy(DIMENSION + 9, DIMENSION - 5);
    printf("%c", LINEA_VERTICAL);
    gotoxy(DIMENSION + 9, DIMENSION - 4);
    printf("%c", LINEA_VERTICAL);

    // Muestra la parte superior de la cabeza
    for (int i = DIMENSION - 3; i <= DIMENSION + 3; i++){
        gotoxy(i + 6, DIMENSION - 6);
        if (i == DIMENSION - 3){
            // Esquina superior izquierda
            printf("%c", ESQUINA_SUP_IZQ);
        }
        else if (i == DIMENSION){
            // Trinagulo inferior
            printf("%c", TRI_LAT_INF);
        }
        else if (i == DIMENSION + 3){
            // Esquina superior derecha
            printf("%c", ESQUINA_SUP_DER);
        }
        else {
            // Linea horizontal
            printf("%c", LINEA_HORIZONTAL);
        }

        // Muestra la parte inferior de la cabeza
        gotoxy(i + 6, DIMENSION - 3);
        if (i == DIMENSION - 3){
            // Esquina inferior izquierda
            printf("%c", ESQUINA_INF_IZQ);
        }
        else if (i == DIMENSION){
            // Trinagulo superior
            printf("%c", TRI_LAT_SUP);
        }
        else if (i == DIMENSION + 3){
            // Esquina inferior derecha
            printf("%c", ESQUINA_INF_DER);
        }
        else {
            // Linea horizontal
            printf("%c", LINEA_HORIZONTAL);
        }
    }
}



/*
 * Pre: ---
 * Post: Ha dibujado el cuello del monigote
 */
void dibujarCuello(){
    // Dibujo del cuello
    gotoxy(DIMENSION + 6 ,DIMENSION - 2);
    printf("%c", CRUZ);
}




/*
 * Pre: ---
 * Post: Ha dibujado el brazo izquierdo del monigote
 */
void dibujarBrazoIzq(){
    for (int i = 0; i <= 5; i++){
        gotoxy(DIMENSION + i, DIMENSION - 2);
        // Brazo izquierdo
        printf("%c", LINEA_HORIZONTAL);
    }
}




/*
 * Pre: ---
 * Post: Ha dibujado el brazo derecho del monigote
 */
void dibujarBrazoDer(){
    for (int i = 0; i <= 5; i++){
        gotoxy(DIMENSION + i + 7, DIMENSION - 2);
        // Brazo derecho
        printf("%c", LINEA_HORIZONTAL);
    }
}




/*
 * Pre: ---
 * Post: Ha dibujado el cuerpo del monigote
 */
void dibujarCuerpo(){
    for (int i = 0; i <= 3; i++){
        gotoxy(DIMENSION + 6, DIMENSION - 1 + i);
        if (i == 3){
            // Dibujo de la interseccion del cuerpo y las piernas
            printf("%c", TRI_LAT_INF);
        }
        else {
            // Tronco
            printf("%c", LINEA_VERTICAL);
        }
    }
}




/*
 * Pre: ---
 * Post: Ha dibujado la pierna izquierdo del monigote
 */
void dibujarPiernaIzq(){
     for (int i = 0; i <= 5; i++){
        gotoxy(DIMENSION + i, DIMENSION + 2);
        if (i == 0){
            // Rodilla
            printf("%c", ESQUINA_SUP_IZQ);
        }
        else {
            // Linea horizontal
            printf("%c", LINEA_HORIZONTAL);
        }
    }

    // Linea Vertical
    gotoxy(DIMENSION, DIMENSION + 3);
    printf("%c", LINEA_VERTICAL);
}




/*
 * Pre: ---
 * Post: Ha dibujado la pierna derecho del monigote
 */
void dibujarPiernaDer(){
     for (int i = 0; i <= 5; i++){
        gotoxy(DIMENSION + i + 7, DIMENSION + 2);
        if (i == 5){
            // Rodilla
            printf("%c", ESQUINA_SUP_DER);
        }
        else{
            // Linea horizontal
            printf("%c", LINEA_HORIZONTAL);
        }
    }
    // Linea vertical
    gotoxy(DIMENSION + 12 , DIMENSION + 3);
    printf("%c", LINEA_VERTICAL);
}




/*
 * Pre: <<estado>> almacena el estado actual del juego, <<dificultad>> guarda el
 *       nivel de doficultad introducido por el usuario y <<fin>> controla el final
 *       de la partida y toma de valor <<false>>
 * Post: Ha dibujado la parte correspondiente del monigote en funcion del
 *       estado del juego. Si el jugador ha consumido todos los intentos <<fin>>
 *       tomar el valor de <<true>> y finaliza la partida. En caso contario
 *       continua a <<false>> y permitira futuros intentos
 */
void dibujoParteMonigote(int& estado, const int dificultad, bool& fin){
    // Control de la dificultad del juego
    switch (dificultad){
        // Dificultad en modo novato
        case 0:
            // Seleccion del estado de control del juego
            switch(estado){
            case 1:
                    // Dibujo de la cabeza del monigote
                    dibujoCabeza();
                    break;
            case 2:
                    // Dibujo del cuello del monigote
                    dibujarCuello();
                    break;
            case 3:
                    // Dibujo del cuerpo del monigote
                    dibujarCuerpo();
                    break;
            case 4:
                    // Dibujo del brazo izquierdo
                    dibujarBrazoIzq();
                    break;
            case 5:
                    // Dibujo del brazo derecho
                    dibujarBrazoDer();
                    break;
            case 6:
                    // Dibujo de la pierna izquierda
                    dibujarPiernaIzq();
                    break;
            case 7:
                    // Dibujo de la pierna derecha
                    dibujarPiernaDer();
                    // Fin de la partida actual
                    fin = true;
                    break;
            default:
                    // Estado desconocido del juego
                    cerr << "Estado desconocido" << endl;
            }
            break;
        // Dificultad en modo intermedio
        case 1:
            switch(estado){
                case 1:
                    // Dibujo de la cabeza y del cuello
                    dibujoCabeza();
                    dibujarCuello();
                    break;
                case 2:
                    // Dibujo del brazo izquierdo
                    dibujarBrazoIzq();
                    break;
                case 3:
                    // Dibujo del brazo derecho
                    dibujarBrazoDer();
                    break;
                case 4:
                    // Dibujo del cuerpo
                    dibujarCuerpo();
                    break;
                case 5:
                    // Dibujo de las dos piernas
                    dibujarPiernaIzq();
                    dibujarPiernaDer();
                    // Fin de la partida actual
                    fin = true;
                    break;
                default:
                    cerr << "Estado desconocido " << endl;
            }
            break;
        // Dificultad en modo maestro
        case 2:
            switch(estado){
                case 1:
                    // Dibujo de la cabeza y del cuello
                    dibujoCabeza();
                    dibujarCuello();
                    break;
                case 2:
                    // Dibujo de los dos brazos
                    dibujarBrazoIzq();
                    dibujarBrazoDer();
                    break;
                case 3:
                    // Dibujo del cuerpo
                    dibujarCuerpo();
                    break;
                case 4:
                    // Dibujo de las dos piernas
                    dibujarPiernaIzq();
                    dibujarPiernaDer();
                    // Fin de la partida actual
                    fin = true;
                    break;
                default:
                    cerr << "Estado desconocido " << endl;
            }
            break;
         // Niguno de los modos de dificultad coincide
        default:
            cerr << "Dificutad no admitida " << endl;
    }
    estado++;
}



