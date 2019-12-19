
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0) 
[![windows](https://img.shields.io/badge/Windows%20-compatible-1df31a.svg)](https://www.microsoft.com/es-es/windows) 
[![Version](https://img.shields.io/badge/Version%20-1.0-0101DF.svg)](https://github.com/ZgzInfinity/Ahorcado/releases)

# Ahorcado
Juego del Ahorcado 

![alt text](https://i.ibb.co/JFYvqyS/unnamed.png)

## 1 - Descripción

El ahorcado es un juego de adivinanzas para dos o más jugadores. Un jugador piensa en una palabra, frase u oración y el otro
trata de adivinarla según lo que sugiere por letras o números. En este caso, no se enfrentan dos jugadores físicos, se enfrentan
una persona y la máquina. Inicialmente, la máquina propone una palabra al jugador contrario, y éste último debe adivinarla, en
una cantidad limitada de movimientos que varía en función de la dificultad seleccionada a comienzo del juego en el menú de
opciones. Por cada palabra acertada el jugador gana una determinada cantidad de puntos, que al igual que en el caso anterior,
también depende de la dificultad. En caso de no acertarla, el jugador no gana ninguna bonificación.

## 2 - Diseño

### 2.1 - Menú principal

Al arrancar el juego, comienza saliendo el menú principal donde se detalla el nombre del juego, el desarrollador y el año 
correspondiente a la fecha de desarrollo. Posteriormente, se muesra un mensaje al usuario para que presione la tecla INTRO para
poder continuar. El juego permanece en ese menú hasta que el usuario presiona dicha tecla. A continuación se muestra una captura 
de la apariencia que tiene el menú principal.

![alt text](https://i.ibb.co/ZKb4pmL/9.jpg)

### 2.2 - Menú de opciones

Seguidamente, se le presenta al usuario un menú de opciones donde debe introducir por teclado la dificultad con la que desea 
jugar, introduciendo un valor entre 0, 1, o 2, correspondidos con los niveles de dificultad fácil, intermedio y difícil 
respectivamente.

Posteriormente se le pide al usuario que seleccione una banda sonora con la que jugar o si por el contrario desea jugar en modo
muteado, es decir, sin audio de fondo. Para escoger la música el usuario debe introducir por teclado el valor correspondiente
al número de pista, el cual oscila entre 0 y 3. Finalmente le pide que introduzca su nombre para poder gestionar el guardado de
los puntos, explicado más adelante.

A continuación, se muestran dos capturas, una del menú de opciones antes de introducir los datos solicitados y otra después de 
haberlos rellenado.

![alt text](https://i.ibb.co/pQdqLtn/0.png)

![alt text](https://i.ibb.co/rdvprZY/1.png)

### 2.3 - Pantalla de juego principal

Una vez introducidos los datos de juego, la máquina selecciona una palabra aleatoria del castellano, sin tildes y sin eñes,
mostrando por cada letra un guión bajo o underscore. Al mismo tiempo se dibuja una ahorca donde se irán dibujando las diferentes
partes del muñeco según el usuario vaya fallando al probar letras de la palabra. Además, en la parte inferior de la pantalla se
muestra un panel de información donde se recoge la dificultad de la partida, el jugador que juega y la puntuación que lleva 
ganada hasta el momento. La siguiente imagen muestra la apariencia que tiene la pantalla de juego.

![alt text](https://i.ibb.co/BGsF5Wt/0.jpg)

El usuario debe introducir la letra con la que desea probar suerte a través del teclado. Posteriormente se procede a verificar
si esa letra reside o no en la palabra. Si la letra figura en la palabra, se muestra un mensaje en verde afirmandolo, y acto 
seguido se sustituyen las rayas bajas o underscores por las letra en cuestión. Si la letra no está, se muestra en rojo un 
mensaje en cuestión informando del error al usuario y se dibuja la parte del muñeco que corresponda en la ahorca. No obstante,
si la letra ya ha sido probada antes muestra un mensaje informando de ello y se limita a pedir otra letra de nuevo. A
continuación se muestran tres capturas para evidenciar la retroalimentación anterior.

![alt text](https://i.ibb.co/7pkV2z3/6.png)

![alt text](https://i.ibb.co/HHNTn7Q/7.png)

![alt text](https://i.ibb.co/9swRYRk/8.png)

Tras agotar todos los intentos o adivinar la palabra, se muesta un mensaje de victoria o derrota según corresponda tal y como se
puede ver en las siguientes imágenes.

![alt text](https://i.ibb.co/LSZ8K2d/5.png)

![alt text](https://i.ibb.co/bBmfCBr/4.png)

### 2.4 - Pantalla de retorno de juego

Una vez finalizada la partida, se muestra un menú al usuario para preguntarle si desea volver a jugar o no. Para ello, el 
usuario debe introducir por medio del teclado una orden, 1 o 2, para poder volver a jugar de nuevo o salir respectivamente. Si 
el usuario introduce la orden 1 vuelve a aparecer la pantalla de juego principal, actualizandose en el panel de puntuación, en 
la sección de puntos, los puntos que ya tenía junto con los que ha ganado en la partida anterior si es que acertó la palabra. En 
caso contario, la puntuación permanece invariante. La siguiente imagen muestra la apariencia de dicho menú.

![alt text](https://i.ibb.co/5vRnPS6/2.png)

### 2.5 - Pantalla de clasificación de los jugadores

Tras dar la orden de que no se desea volver a jugar, se muestra una tabla informativa con los datos de todos los jugadores que
están registrados en ese momento. Para cada usuario se muestra su nombre y la puntuación. El jugador que ha terminado de jugar
aparece puesto en la clasificación con un color diferente al resto para poder facilitar que éste se encuentre con mayor 
facilidad. Los jugadores aparecen ordenados por orden decreciente de puntos de modo que el más alto se encuentra en la primera
posición y el peor en la última. Seguidamente se muestra una captura de una clasificación de ejemplo.

![alt text](https://i.ibb.co/d5yHnHc/10.png)

### 2.6 - Pantalla de créditos y agradecimientos

Finalmente se muestra una sección de agradecimientos y crédutos donde figura el nombre del juego, el tiempo de su desarrollo y 
el creador. Adicionalmente se muestran los diferentes juegos, así como la plataforma para la que salieron, a los que pertenecen
los efectos de sonido y bandas sonoras que se han empleado en la implementación del juego. A continuación se muestran dos 
imágenes donde se puede observar lo explicado anteriormente.

![alt text](https://i.ibb.co/vVYB5rG/11.png)

![alt text](https://i.ibb.co/wCmHRgy/3.png)

### 2.7 - Tratamiento de puntos

Como ya se ha dicho anteriormente, los puntos es un aspecto que al igual que el número de intentos depende de la dificultad con
la que se está jugando. Si se juega en modo difícil y se acierta una palabra se ganan 50 puntos, si se juega en modo intermedio
y se adivina la palabra se ganan 30 puntos y si se juega en modo fácil por cada palabra acertada se ganan 20 puntos. Por cada
letra fallida no se quitan puntos. 

## 3 - Tecnologías, librerías y compatibilidad

### 3.1 - Entorno de programación

Para poder programar el juego del Ahorcado se ha empleado como IDE de programación el entorno de CodeBoclks, concretamente la
versión 17.12

### 3.2 - Bandas sonoras y efectos de sonido

La incorporación de los efectos de sonido y las bandas sonoras se ha realizado incorporando la biblioteca "windows.h", que 
contiene una amplia gama de métodos y funciones de la biblioteca Windows API, todas las macros utilizadas por los programadores
de aplicaciones para Windows, y todas las estructuras de datos utilizadas en gran cantidad de funciones y subsistemas. 

Adicionalmente se ha tenido también que trabajar con una biblioteca para poder trabajar con sonidos de windows llamada
winmm.dll, el cual es un módulo para el Windows Multimedia API, que contiene funciones bajas del audio y de la palanca de mando.
En internet se proporciona documentación suficiente de como funciona todo el material empleado y como configurarlo para 
diferentes entornos de programación como CodeBlocks, Dev-C++, entre otros.

### 3.3 - Compatibilidad 

El juego del Ahorcado solo tiene compatibilidad con Windows y sus diferentes versiones. Si se desea correr en otros sistemas
se deberá recurrir a recursos adicionales como el empleo de máquinas virtuales o aplicaciones que puedan ejecutar programas de
Windows en otros sistemas operativos. 

## 4 - Documentación y ficheros

Esta versión del Ahorcado solo trabaja con palabras del lenguaje castellano, de las que se han eliminado todas aquellas que 
tienen tildes en vocales o que contienen la letra eñe. Las palabras se encuentran almacenadas en un fichero binario porque así 
la selección de la palabra se hace de forma más eficiente. Dicho fichero se denomina "palabras_bin.bin", que es generado a su 
vez de otro fichero de texto denominado "palabras.txt" que almacena las palabras del castellano descritas anteriormente, a razón
de una por línea, tal y como muestra la siguiente imagen.

![alt text](https://i.ibb.co/7nqJXGV/0.png)

## 5 - Jerarquía de directorios

Dada la gran cantidad de archivos por los que se encuentra compuesto el juego del Ahorcado, se ha optado por establecer una 
agrupaión de los ficheros de implementación y el sonido, así como el ejecutable en diferentes carpetas para poder tener mejor
estructura la información. Los archivos de sonido se encuentran en la carpeta "Audio", los ficheros de las palabras y la 
documentación en la carpeta "Datos", y los ficheros de implementación en la ráiz del directorio proyecto.

## 6 - Release 

El release proporcionado es un fichero con extenión zip donde se hayan comprimidos la carpeta "Datos", la carpeta "Audio" y el 
archivo ejecutable del juego. No se deben borrar ni las carpetas ni nada que éstas guardan porque de lo contrario el juego 
no funcionará correctamente.
























