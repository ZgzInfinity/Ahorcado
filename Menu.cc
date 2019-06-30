
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
void menuOpciones(int& dificultad, int& pista, string& nombre){

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
        cout << "deciphering the enigma";
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
void panelPuntuacion(int dificultad, string nombre, int puntos){
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
    cout << " PUNTUACION : " << puntos;
}

