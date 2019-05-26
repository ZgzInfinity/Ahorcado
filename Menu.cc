
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
         gotoxy(45 ,25);
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
    cout << "                                                       ******  ****                                                    " << endl;
    cout << "                                                       ******  ****                                                    " << endl;
    cout << "                                                       ***     ****                                                    " << endl;
    cout << "                                                       ******  ****                                                    " << endl;
    cout << "                                                       ******  ****                                                    " << endl;
    cout << "                                                       ***     ****                                                    " << endl;
    cout << "                                                       ******  *******                                                 " << endl;
    cout << "                                                       ******  *******                                                 " << endl << endl << endl;

    cout << "                *****         ****  ****  ********  *******      ********         *****         ******      ********   " << endl;
    cout << "               *******        ****  ****  ********  ********     ********        *******        *******     ********   " << endl;
    cout << "              ***   ***       ****  ****  ***  ***  ***  ***     ****           ***   ***       *** ****    ***  ***   " << endl;
    cout << "             ***     ***      **********  ***  ***  *******      ****          ***     ***      ***  ****   ***  ***   " << endl;
    cout << "            *************     **********  ***  ***  ********     ****         *************     ***   ***   ***  ***   " << endl;
    cout << "           ***************    ****  ****  ***  ***  ***   ***    ****        ***************    ***  ***    ***  ***   " << endl;
    cout << "          ****         ****   ****  ****  ********  ***    ***   ********   ****         ****   *******     ********   " << endl;
    cout << "         ****          *****  ****  ****  ********  ***     ***  ********  ****          *****  ******      ********   " << endl << endl << endl;

    gotoxy(52, 23);
    cout << " ZgzInfinity - 2019 " << endl;
}


/*
 * Pre: ---
 * Post: Ha mostrado por pantalla un menu con las posibles
 *       opciones de configuracion al usuario
 */
void menuOpciones(int& dificultad, int& pista){

    // Reproduccion de la banda sonora del menu de opciones
    sonidoMenuOpciones();

    cout << endl << endl;
    cout << "                               ******  ******  *******  ***  ******  ***   ***  ******  ******* " << endl;
    cout << "                               ******  ******  *******  ***  ******  ****  ***  ******  ******* " << endl;
    cout << "                               **  **  **  **  ***      ***  **  **  ***** ***  **      **      " << endl;
    cout << "                               **  **  ******  ***      ***  **  **  *********  ******  ******* " << endl;
    cout << "                               **  **  ******  ***      ***  **  **  *********  ******  ******* " << endl;
    cout << "                               **  **  **      ***      ***  **  **  *** *****  **           ** " << endl;
    cout << "                               ******  **      *******  ***  ******  ***  ****  ******  ******* " << endl;
    cout << "                               ******  **      *******  ***  ******  ***   ***  ******  ******* " << endl;

    gotoxy(35, 15);
    cout << "Dificultad con la que jugar (1 - 3) --> " << flush;
    cin >> dificultad;

    //Reproduce sonido correcto
    sonidoCorrecto();

    gotoxy(35, 18);
    cout << "Banda sonora (0 - 3) --> " << flush;
    cin >> pista;

    //Reproduce sonido correcto
    sonidoCorrecto();
}

