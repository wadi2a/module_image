/**
@brief Fichier .h du Module Image
Fichier qui comporte tout la déclaration des fonctions de ce module
@author BEN AISSA OUADIE
@file Image.h
@version 1.0
@date 2016/02/10
*/
#ifndef _Image_h
#define _Image_h
#include "Pixel.h"

struct Image
{
    Pixel **tab ;
    int dimx,dimy;


};
typedef struct Image Image;
/*************************************************************************/
/**
@brief imInit initialise dimx et dimy (après vérification) de la structure Image
puis alloue le tableau de pixel dans le tas

@param [in,out] im la structure image à initialisé
@param [in] dimx Entier qui désigne la largeur de l'image
@param [in] dimy Entier qui désigne la hauteur de l'image
@return none.

@code
imInit(&im,500,500);
@endcode
@warning les dimension de l'image doivent etre dimx>0 et dimy>0

*/
void imInit(Image *im,const int dimx,const int dimy );

/*************************************************************************/
/**
@brief  imLibere Libère la mémoire du tableau de pixels et met les
champs dimx et dimy de la structure à 0

@param [in,out] im la structure image à initialisé.
@return none.
@code
void imLibere(&im);
@endcode
*/
void imLibere(Image *im);
/*************************************************************************/
/**

@brief imCreer  alloue dans le tas une structure Image puis l'initialise
avec imInit avant de la retourner
@param [in] dimx Entier qui désigne la largeur de l'image.
@param [in] dimy Entier qui désigne la hauteur de l'image.
@return lien sur image.
@code
imCreer(500,500);
@endcode
@warning les dimension de l'image doivent etre dimx>0 et dimy>0

*/
Image * imCreer(const int dimx,const int dimy);
/*************************************************************************/

/**
@brief  imDetruire Libere le tableau de pixel en appelant imLibere puis détruit
 la structure image

@param [in,out] im la structure image à détruire.
@return none.
@code
imDetruire(Image *pim);
@endcode
*/
void imDetruire(Image *pim);
/*************************************************************************/

/**
@brief getPix récupère le pixel de coordonnées (x,y) en vérifiant leur validité

@param [in,out] im la structure image
@param [in] x Entier qui désigne les cordonnée de l'image sur l'axe des x
@param [in] y Entier qui désigne les cordonnée de l'image sur l'axe des y
@return lien vers une pixel.

@code
getPix(&im,200,352);
@endcode
@warning x et y doivent etre inclu dans l'intervalle des dimensions

*/
Pixel getPix(const Image *im, const int x,const int y);
/*************************************************************************/
/**
@brief setPix modifie le pixel de coordonnées (x,y)

@param [in,out] im la structure image
@param [in] x Entier qui désigne les cordonnée de l'image sur l'axe des x
@param [in] y Entier qui désigne les cordonnée de l'image sur l'axe des y
@return none.

@code
setPix(&im,200,352);
@endcode
@warning x et y doivent etre inclu dans l'intervalle des dimensions

*/
void setPix(Image *im ,const int  x,const int y, Pixel couleur);
/*************************************************************************/
/**
@brief imDessineRectangle dessine un rectangle de couleur dans l'image en utilisant setPix

@param [in,out] im la structure image
@param [in] Xmin Entier qui désigne le début du rectangle sur l'axe des x
@param [in] Xmax Entier qui désigne la fin du rectangle sur l'axe des x
@param [in] Ymin Entier qui désigne le début du rectangle sur l'axe des y
@param [in] Ymax Entier qui désigne la fin du rectangle sur l'axe des x
@param [in] couleur Pixel qui contient les valeurs du couleurs que nous allons l'affecté au triangle
@return none.

@code
imDessineRectangle(&im,100,100,200,352,couleur);
@endcode
@warning Xmin,Xmax,Ymin,Ymax doivent etre inclu dans l'intervalle des dimensions

*/
void imDessineRectangle(Image *im ,const int Xmin,const int Ymin,const int Xmax,const int Ymax,const Pixel couleur);
/*************************************************************************/

/**
@brief imEffacer efface l'image en appelant imDessineRectangle avec le bon rectangle

@param [in,out] im la structure image
@param [in] couleur Pixel qui contient les valeurs du couleurs que nous allons l'affecté au triangle
@return none.

@code
imEffacer(&im,couleur);
@endcode

*/
void imEffacer(Image * im,const Pixel couleur);
/*************************************************************************/

/**
@brief imSauver Enregistre l'image

@param [in,out] im la structure image
@param [in] chaine de caractère qui désigne l'emplacement de l'image
@return none.

@code
imSauver(&im,"./data/toto.ppm");
@endcode
@warning l'image doit etre crée avant l'execution de cette procedure
*/
void imSauver(const Image *pIm, const char filename[]) ;
/*************************************************************************/
/**
@brief imOuvrir ouvre l'image

@param [in,out] im la structure image
@param [in] chaine de caractère qui désigne l'emplacement de l'image
@return none.

@code
imOuvrir(&im,"./data/toto.ppm");
@endcode
@warning l'image doit etre crée avant l'execution de cette procedure
*/
void imOuvrir(Image *pIm, const char filename[]);
/*************************************************************************/
/**
@brief imPrintf affiche le contenue de chaque pixel dans l'image

@param [in,out] im la structure image
@return none.

@code
imPrintf(&im);
@endcode
@warning l'image doit etre crée avant l'execution de cette procedure
*/
void imPrintf(const Image *pIm);
/*************************************************************************/

/**
@brief imTestRegression Effectue une série de tests vérifiant que le module fonctionne et que les
champs de la structure sont conformes

@param  none
@return none.

@code
imTestRegression();
@endcode

*/
void imTestRegression();
/*************************************************************************/
#endif
