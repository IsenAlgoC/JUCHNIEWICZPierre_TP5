#pragma once
#define TAILLEINITIALE 100 

//d�claration de la structure dans le header pour �tre utilis� dans les main_exo2.c et tab2.c
typedef struct Tableau {
	int* elt;
	int size;
	int eltsCount;
} TABLEAU;

//d�claration de la fonction newArray
TABLEAU newArray();

//d�claration de la fonction incrementArraySize
int incrementArraySize(TABLEAU* tab, int incrementValue);

//d�claration de la fonction setElement
int setElement(TABLEAU* tab, int pos, int element);

//d�claration de la fonction displayElements
int displayElements(TABLEAU* tab, int startPos, int endPos);