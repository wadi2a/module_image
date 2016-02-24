/**
@brief Fichier .c du Module Image
Fichier qui comporte tout la définition des fonction de ce module
@author BEN AISSA OUADIE
@file Image.c
@version 1.0
@date 2016/02/10
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Image.h"

void imInit(Image *im,const int dimx,const int dimy )
{
    int i;

    assert(dimx>0 && dimy>0);
    im->tab=malloc(dimy * sizeof(Pixel*));
    for(i=0;i<dimy;i++)
    {
        im->tab[i]=(Pixel*)malloc(dimy*sizeof(Pixel));
    }
    im->dimx=dimx;
    im->dimy=dimy;
 
}

void imLibere(Image *im)
{   int i;
    for(i=0;i<im->dimy;i++)
    {
        free(im->tab[i]);
    }

    im->dimx=0;
    im->dimy=0;
}
Image * imCreer(const int dimx,const int dimy)
{
    Image * im=malloc( sizeof(Image));

    imInit(im,dimx,dimy);
    return im;
}

void imDetruire(Image *pim)
{
    imLibere(pim);
    free(pim);


}
Pixel getPix(const Image *im,const int x,const int y)
{

    assert(x<im->dimx && y<im->dimy);
    return im->tab[x][y];

}

void setPix(Image *im ,const int  x,const int y, Pixel couleur)
{
    assert((x<im->dimx) && (y<im->dimy) && (x>=0) & (y>=0));

    im->tab[x][y]=couleur;


}

void imDessineRectangle(Image *im ,const int Xmin,const int Ymin,const int Xmax,const int Ymax, Pixel couleur)
{   int i=0,j=0;
    assert((Xmin>=0) && (Xmax<im->dimx) && (Ymin>=0) && (Ymax<im->dimy));
    /*
    pour dessiner un triangle vide a l'interieur
    for(i=Xmin;i<=Xmax;i++) setPix(im,i,Ymin,couleur);
    for(i=Ymin;i<=Ymax;i++) setPix(im,Xmin,i,couleur);
    for(i=Xmin;i<=Xmax;i++) setPix(im,i,Ymax,couleur);
    for(i=Ymin;i<=Ymax;i++) setPix(im,Xmax,i,couleur);*/
    for(i=Xmin;i<=Xmax;i++)
    {
        for(j=Ymin;j<=Ymax;j++)
        {
            setPix(im,i,j,couleur);
        }
    }
}
void imEffacer(Image * im,const Pixel  couleur)
{

    imDessineRectangle(im,0,0,im->dimx-1,im->dimy-1,couleur);

}

void imSauver(const Image *pIm, const char filename[]) {
    FILE* f;
	Pixel pix;
	int x,y;

    f = fopen(filename, "w");
    if (f==NULL) {
        printf("Erreur lors de l'ouverture de %s\n", filename);
        assert( f );
    }
    fprintf( f , "P3\n");                           /*P3 = ascii avec 3 composantes RGB*/
    fprintf( f , "%d %d\n", pIm->dimx, pIm->dimy);  /* dimension de l'image*/
    fprintf( f , "255\n");                          /* chaque composante est comprise entre 0 et 255*/

    for(y=0;y<pIm->dimy;++y)
        for(x=0;x<pIm->dimx;++x) {
            pix = getPix(pIm,x++,y);
            fprintf(f, "%d %d %d  ", pix.r, pix.g, pix.b);
        }
    printf("Sauvegarde de l'image %s ...OK\n", filename);
    fclose(f);
}
void imOuvrir(Image *pIm, const char filename[]) {
    FILE* f;
	Pixel pix;
	int x, y, dimx, dimy;

    f = fopen(filename, "r");
    if (f==NULL) {
        printf("Erreur lors de l'ouverture de %s\n", filename);
        assert( f );
    }

    assert( fscanf( f , "P3\n%d %d\n255\n", &dimx, &dimy) == 2 );
    imInit( pIm, dimx, dimy);

    for(y=0;y<pIm->dimy;++y)
        for(x=0;x<pIm->dimx;++x) {
            assert( fscanf(f, "%c %c %c  ", &pix.r, &pix.g, &pix.b) == 3 );
			setPix(pIm,x,y,pix);
        }
    fclose(f);
    printf("Lecture de l'image %s ...OK\n", filename);
}

void imPrintf(const Image *pIm) {
	int x,y;
	Pixel pix;

    printf( "%d %d\n", pIm->dimx, pIm->dimy);      /* dimension de l'image*/

    for(y=0;y<pIm->dimy;++y) {
        for(x=0;x<pIm->dimx;++x) {
            pix = getPix(pIm,x,y);
            printf("%d %d %d  ", pix.r, pix.g, pix.b);
        }
        printf("\n");
    }
}

void imTestRegression()
{
    Image * im;
    int dimx,dimy;int i,j;Pixel couleur2 = { 0, 0, 0 };
    Pixel couleur;couleur.b=8;couleur.r=1;couleur.g=1;

    printf("Donnez la dimension de ton image:\n dimx:");
    scanf("%d",&dimx);
    printf("dimy:");
    scanf("%d",&dimy);
    im=imCreer(dimx,dimy);
    printf("Taille de l'image :%dpx*%dpx",im->dimx,im->dimy);
     imDessineRectangle(im,4,6,12,15,couleur);printf("\n");
     for(j=0;j<im->dimy;j++)
     {
        for(i=0;i<im->dimx;i++)
        {
            couleur=getPix(im,j,i);
            if(couleur.b==8)printf("* "); else printf("- ");
        }
        printf("\n");
     }

    imEffacer(im,couleur2);
    printf("\nAffichage de l'image aprés la procedure qui efface\n");
    for(j=0;j<im->dimy;j++)
     {
        for(i=0;i<im->dimx;i++)
        {
            couleur=getPix(im,j,i);
            if(couleur.b==8)printf("* "); else printf("- ");
        }
        printf("\n");
     }
    imDetruire(im);


}
