#include <stdio.h>
#include <stdlib.h>

#include "Image.h"
/**
@brief Fichier .c le main du projet
Fichier qui comporte le code du projet
@author BEN AISSA OUADIE
@file main.c
@version 1.0
@date 2016/02/10
\mainpage Bienvenue dans la documentation du module image
\section Introduction
<div style="border:1px solid #ff0000;"> Je vous présente le module image, un module pour manipuler une image donnée en utilisant des differentes tâches classiques (auteur BEN AISSA OUADIE P1512099).
Code écrit en C, géré par CodeBlocks.</div>
\section Compilation
<div style="border:1px solid #ff0000;">Tester sous Linux(Ubuntu) et sur Windows.</br>
Vous pouvez utilisé >$ make 11512099 pour compiler le programme d'image ou >$ make 11512099test pour compiler le test de regression  ou bien vous pouvez tout simplement le compiler à l'aide de codeblocks en utlisant la touche F9</div>
\section Exécution
<div style="border:1px solid #ff0000;">Pour acceder a l'executable, vous trouvez le fichier 11512099.out alors vous pouvez faire >$ ./11512099.out pour l'executer de la même manière vous pouvez executer le test de regression dans le fichier 11512099test.out 
</div>
*/


int main()
{
    
      Image im; Image imb;
    Pixel color = { 255, 255, 255 };
    Pixel color2 = { 255, 128, 255 };
    Pixel color3 = { 0, 128, 255 };

    imInit(&im, 500, 500);
    imEffacer(&im, color);

    imDessineRectangle( &im, 00, 0, 250, 499, color2);
    setPix(&im, 2, 2, color2); /* change le pixel (2,2) */
    imSauver(&im, "./data/toto.ppm"); /* voir section suivante : Debug */

    imOuvrir( &imb, "./data/toto.ppm");
    imDessineRectangle( &imb, 5, 5, 15, 10, color3);
    imDessineRectangle( &imb, 25, 25, 35, 45, color3);
    imSauver( &imb, "./data/titi.ppm"); /* voir section suivante : Debug */

    imLibere(&im);
    imLibere(&imb);

return 0;
}
