
#include "Menu.h"

/*
 * Pre: ---
 * Post: Muestra por pantalla el mensaje "Pulse la tecla intro" hasta
 *       que se detecta la tecla
 */
void mostrarTitulo(const string deseo){
    // Capturar codigo de la tecla ENTER
    bool pulsada = false;

    // Capturar codigo de la tecla ENTER
    while (!pulsada){
         gotoxy(45 , 22);
         cout << "Pulsa la tecla INTRO para " + deseo << flush;

         // Capturar tecla pulsada
         unsigned char tecla = getch();

         // Comprobacion de tecla ENTER
         if (int(tecla) == TECLA_ENTER){
            // Es la tecla ENTER
            pulsada = true;
         }
    }
}



/*
 * Pre: ---
 * Post: Ha devuelto el tipo de dificultad del modo de juego
 */
string mostrarDificultad(const int& dificultad){
    // Control de dificultad
    string tipoDificultad;

    // Muestra la dificultad seleccionada al jugador
    if (dificultad == 1){
        // Modo facil
        tipoDificultad = "Facil";
    }
    else if (dificultad == 2){
        // Modo intermedio
        tipoDificultad = "Intermedio";
    }
    else {
        // Modo dificil
        tipoDificultad = "Dificil";
    }
    return tipoDificultad;
}

/*
 * Pre: ---
 * Post: Ha mostrado por pantalla un rotulo cuyo contenido es "FINAL"
 */
void presentarFinal(){
    cout << endl << endl;
    cout << "                            *********  ***  ***   ***         *****         ***" << endl;
    cout << "                            *********  ***  ****  ***        *******        ***" << endl;
    cout << "                            ***        ***  ***** ***       ***   ***       ***" << endl;
    cout << "                            *********  ***  *********      ***     ***      ***" << endl;
    cout << "                            *********  ***  *********     *************     ***" << endl;
    cout << "                            ***        ***  *** *****    ***************    ***" << endl;
    cout << "                            ***        ***  ***  ****   ****         ****   ********" << endl;
    cout << "                            ***        ***  ***   ***  ****          *****  ********" << endl;
}


/*
 * Pre: ---
 * Post: Ha mostrado por pantalla el menu inicial del
 *       juego
 */
void presentarMenu(){

    cout << endl << endl;
    cout << "                *****         ****  ****  ********  *******      ********         *****         ******      ********   " << endl;
    cout << "               *******        ****  ****  ********  ********     ********        *******        *******     ********   " << endl;
    cout << "              ***   ***       ****  ****  ***  ***  ***  ***     ****           ***   ***       *** ****    ***  ***   " << endl;
    cout << "             ***     ***      **********  ***  ***  *******      ****          ***     ***      ***  ****   ***  ***   " << endl;
    cout << "            *************     **********  ***  ***  ********     ****         *************     ***   ***   ***  ***   " << endl;
    cout << "           ***************    ****  ****  ***  ***  ***   ***    ****        ***************    ***  ***    ***  ***   " << endl;
    cout << "          ****         ****   ****  ****  ********  ***    ***   ********   ****         ****   *******     ********   " << endl;
    cout << "         ****          *****  ****  ****  ********  ***     ***  ********  ****          *****  ******      ********   " << endl << endl << endl;

    gotoxy(52, 17);
    cout << " ZgzInfinity - 2019 " << endl;
}


/*
 * Pre: ---
 * Post: Ha dibujado por pantalla una cuadricula pequenya
 */
void dibujoCuadricula(){
    // Dibujo de las lineas horizontales
    for (int i = 33; i < 80; i++){
        gotoxy(i, 13);
        printf("%c",205);
        gotoxy(i, 23);
        printf("%c",205);
    }


    // Dibujo de las lineas verticales
    for (int i = 14; i < 23; i++){
        gotoxy(32, i);
        printf("%c",186);
        gotoxy(80, i);
        printf("%c",186);
    }


    // Dibujo de las esquinas de la cuadricula
    gotoxy(32, 13); printf("%c", 201);
    gotoxy(80, 13); printf("%c", 187);
    gotoxy(32, 23); printf("%c", 200);
    gotoxy(80, 23); printf("%c", 188);
}

/*
 * Pre: ---
 * Post: Ha mostrado por pantalla un menu con las posibles
 *       opciones de configuracion al usuario
 */
void menuOpciones(int& dificultad, int& pista, char nombre[]){

    // Reproduccion de la banda sonora del menu de opciones
    // sonidoMenuOpciones();

    cout << endl << endl;
    cout << "                         ******  ******  *******  ***  ******  ***   ***  ******  ******* " << endl;
    cout << "                         ******  ******  *******  ***  ******  ****  ***  ******  ******* " << endl;
    cout << "                         **  **  **  **  ***      ***  **  **  ***** ***  **      **      " << endl;
    cout << "                         **  **  ******  ***      ***  **  **  *********  ******  ******* " << endl;
    cout << "                         **  **  ******  ***      ***  **  **  *********  ******  ******* " << endl;
    cout << "                         **  **  **      ***      ***  **  **  *** *****  **           ** " << endl;
    cout << "                         ******  **      *******  ***  ******  ***  ****  ******  ******* " << endl;
    cout << "                         ******  **      *******  ***  ******  ***   ***  ******  ******* " << endl;

    // Dibujo de la cuadricula
    dibujoCuadricula();

    gotoxy(35, 15);
    cout << "Dificultad de juego (1 - 3) --> " << flush;
    cin >> dificultad;

    // Reproducir sonido de correcto
    tocarSonidoCorrecto();

    // Gestion de dificultad
    string tipoDificultad = mostrarDificultad(dificultad);

     // Informa de la dificultad seleccionada
    gotoxy(67, 15);
    cout << tipoDificultad << endl;

    // Peticion de la banda sonora de partida
    gotoxy(35, 18);
    cout << "Banda sonora (0 - 3) --> " << flush;
    cin >> pista;

    // Reproducir sonido de correcto
    tocarSonidoCorrecto();

    // Mostrar la banda sonora seleccionada
    gotoxy(60, 18);

    if (pista == 0){
        cout << "The art of war";
    }
    else if (pista == 1){
        cout << "The enigmatic puzle";
    }
    else if (pista == 2){
        cout << "Chess Master";
    }
    else {
        cout << "Modo muteado";
    }

    gotoxy(35,21);
    cout << "Nombre de jugador --> " << flush;
    cin >> nombre;

    // Reproducir sonido de correcto
    tocarSonidoCorrecto();
}




/*
 * Pre: ---
 * Post: Ha mostrado por pantalla un panel con la informacion de la partida actual del usuario.
 *       En el lateral izquierdo se ha informado de la dificultad actual del modo de juego, en el centro
 *       se encuentra el nombre del jugador actual, y en la derecha fiura el total de ountos que lleva actualmente
 */
void panelPuntuacion(string dificultad, string nombre, int puntos, bool& actualizar){
    // Borde horizontal superior
    for (int i = 1; i <= 128; i++){
        if (i % 43 == 0){
            // Escritura de la interseccion
            gotoxy(i, 23);
            printf("%c", 203);

            // Escritura de la linea vertical para subidivir el primer fragmento
            if (i < 80){
                for (int j = 1; j <= 2; j++){
                    gotoxy(i, 23 + j);
                    printf("%c", 186);
                }
            }
        }
        else {
            // Escritura de la linea horizontal
            gotoxy(i, 23);
            printf("%c", 205);
        }
    }


    // Escritura del segundo fragmento del cuadro
    for (int j = 1; j < 3; j++){
        gotoxy(80, 23 + j);
        for (int k = 81; k < 126; k++){
            if (k == 87){
                // Linea vertical de subdivision
                printf("%c", 186);
            }
            else{
                cout << " ";
            }
        }
    }

    // Muestra la difcicutad del juego
    gotoxy(15, 24);
    cout << " DIFICULTAD : " << dificultad;

    // Muestra el nombre del jugador
    gotoxy(55, 24);
    cout << " JUGADOR : " << nombre;

    // Tercer fragmento del panel de puntuacion
    gotoxy(80, 24);
    for (int k = 81; k < 101; k++){
        // Escritura de linea vertical para el tercer fragmento
        if (k == 87){
            printf("%c", 186);
        }
        else{
            cout << " ";
        }
    }
    // Mostrar los puntos
    cout << " PUNTUACION : ";

    if (actualizar){
        // Actualizar puntos de la partida anterior
        // Reproducir sonido de bonus y mostrar los nuevos puntos
        tocarSonidoBonusLife();
        // Dormir ejecucion 30 milisegundos y reanudar
        Sleep(30);
    }
    // Mantiene los ountos de antes
    cout << puntos;
}




/*
 * Pre: ---
 * Post: Ha mostrado por terminal los caracteres que componen la cadena
 *          <<mensaje>> con un intervalo de separacion de 100 milisegundos
 */
void mostrarMensaje(const string mensaje){
    int dim = mensaje.length();
    gotoxy(64, 20);
    printf("%c", 33);
    for (int i = 0; i < dim; i++){
        gotoxy(65 + i, 20);
        cout << mensaje.at(i) << " ";
        Sleep(100);
    }
    gotoxy(65 + dim, 20);
    printf("%c", 173);
}




/*
 * Pre: ---
 * Post: Muestra por pantalla los creditos del juego
 */
void creditos(){
    // Creditos finales del juego
    string orden = "terminar";
    gotoxy(50, 5);
    cout << " CREDITOS FINALES " << endl;
    gotoxy(49, 6);
    cout << " ==================" << endl;

    // Dormir 1 segundo y mostrar titulo del juego
    Sleep(2000);
    gotoxy(49, 9);
    cout << " Juego del Ahorcado " << endl;

    // Dormir 1 segundo y mostrar autor del juego
    Sleep(2000);
    gotoxy(52, 11);
    cout << " ZgzInfinity " << endl;

    // Dormir 1 segundo y duracion del proyecto
    Sleep(2000);
    gotoxy(47, 14);
    cout << " Marzo 2019 - Julio 2019 " << endl;

    // Dormir 2 segundos
    Sleep(2000);

    // Limpiar pantalla y seguir con los creditos
    system("cls");
    gotoxy(50, 3);
    cout << " Bandas sonoras del juego " << endl;
    gotoxy(49, 4);
    cout << "===========================" << endl;


    Sleep(2000);
    gotoxy(47, 6);
    cout << "Golden axe 1991 (GENESIS) Music " << endl;

    Sleep(2000);
    gotoxy(45, 8);
    cout << "Streets of Rage 1991 (GENESIS) Music " << endl;

    Sleep(2000);
    gotoxy(50, 10);
    cout << "Alien 3 (GENESIS) Music " << endl;

    Sleep(2000);
    gotoxy(43, 12);
    cout << "Sonic the hedgehog 1991 (GENESIS) Music " << endl;

    Sleep(2000);
    gotoxy(47, 14);
    cout << "Final fantasy X 2001 (ps2) Music " << endl;

    Sleep(2000);
    gotoxy(50, 16);
    cout << "Chessmaster 2002 (ps2)" << endl;

    Sleep(2000);
    gotoxy(33, 18);
    cout << " Todos los sonidos y bandas sonoras empleadas son propiedad " << endl;
    gotoxy(35, 19);
    cout << " de las empresas desarrolladoras de dichos videojuegos" << endl;

    // Pulsar ENTER para finalizar
    mostrarTitulo(orden);
}

