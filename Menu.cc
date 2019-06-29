
#include "Menu.h"

/*
 * Pre: ---
 * Post: Muestra por pantalla el mensaje "Pulse la tecla intro" hasta
 *       que se detecta la tecla
 */
void mostrarTituloParpadeante(){
    // Capturar codigo de la tecla ENTER
    bool pulsada = false;

    // Capturar codigo de la tecla ENTER
    while (!pulsada){
         gotoxy(45 , 22);
         cout << "Pulsa la tecla INTRO para comenzar" << flush;

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
 * Post: Ha mostrado por pantalla el menu inicial del
 *       juego
 */
void presentarMenu(){

    // Reproduccion de la banda sonora del menu principal
    sonidoMenuPrincipal();

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
 * Post: Ha mostrado por pantalla un menu con las posibles
 *       opciones de configuracion al usuario
 */
void menuOpciones(int& dificultad, int& pista, string& nombre){

    // Reproduccion de la banda sonora del menu de opciones
    // sonidoMenuOpciones();

    cout << endl << endl;
    cout << "                               ******  ******  *******  ***  ******  ***   ***  ******  ******* " << endl;
    cout << "                               ******  ******  *******  ***  ******  ****  ***  ******  ******* " << endl;
    cout << "                               **  **  **  **  ***      ***  **  **  ***** ***  **      **      " << endl;
    cout << "                               **  **  ******  ***      ***  **  **  *********  ******  ******* " << endl;
    cout << "                               **  **  ******  ***      ***  **  **  *********  ******  ******* " << endl;
    cout << "                               **  **  **      ***      ***  **  **  *** *****  **           ** " << endl;
    cout << "                               ******  **      *******  ***  ******  ***  ****  ******  ******* " << endl;
    cout << "                               ******  **      *******  ***  ******  ***   ***  ******  ******* " << endl;


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

    gotoxy(35, 15);
    cout << "Dificultad de juego (1 - 3) --> " << flush;
    cin >> dificultad;

    // Informa de la dificultad seleccionada
    gotoxy(67, 15);

    // Muestra la dificultad seleccionada al jugador
    if (dificultad == 1){
        cout << "Facil";
    }
    else if (dificultad == 2){
        cout << "Intermedio";
    }
    else {
        cout << "Dificil";
    }

    //Reproduce sonido correcto
    tocarSonidoCorrecto();

    gotoxy(35, 18);
    cout << "Banda sonora (0 - 3) --> " << flush;
    cin >> pista;

    // Mostrar la banda sonora seleccionada
    gotoxy(60, 18);

    if (pista == 0){
        cout << "The art of war";
    }
    else if (pista == 1){
        cout << "deciphering the enigma";
    }
    else if (pista == 2){
        cout << "Chess Master";
    }
    else {
        cout << "Modo muteado";
    }


    //Reproduce sonido correcto
    tocarSonidoCorrecto();

    gotoxy(35,21);
    cout << "Nombre de jugador --> " << flush;
    cin >> nombre;

    //Reproduce sonido correcto
    tocarSonidoCorrecto();
}


void monigoteOpciones(){
    gotoxy(5,15);
    cout << "  :::::::::::::::::::::::" << endl;
    cout << "  ::                   ::" << endl;
    cout << "  ::                 ::::::" << endl;
    cout << "  ::                 ::  ::" << endl;
    cout << "  ::                 ::::::" << endl;
    cout << "  ::               ::::::::::" << endl;
    cout << "  ::                   ::" << endl;
    cout << "  ::                   ::" << endl;
    cout << "  ::                 ::::::" << endl;
    cout << "  ::                 ::  ::" << endl;
    cout << "  ::" << endl;
    cout << "  ::" << endl;
    cout << "  ::" << endl;
    cout << "::::::::::::" << endl;
}



void monigoteOpcionesInvertido(){
    gotoxy(5,15);
    cout << "    :::::::::::::::::::::::" << endl;
    cout << "    ::                   ::" << endl;
    cout << "  ::::::                 ::" << endl;
    cout << "  ::  ::                 ::" << endl;
    cout << "  ::::::                 ::" << endl;
    cout << "::::::::::               ::" << endl;
    cout << "    ::                   ::" << endl;
    cout << "    ::                   ::" << endl;
    cout << "  ::::::                 ::" << endl;
    cout << "  ::  ::                 ::" << endl;
    cout << "                         ::" << endl;
    cout << "                         ::" << endl;
    cout << "                         ::" << endl;
    cout << "                 ::::::::::::" << endl;
}
