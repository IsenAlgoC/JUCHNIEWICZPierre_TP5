#pragma once
#define TAILLEINITIALE 100 

//déclaration de la structure dans le header pour être utilisé dans les main_exo2.c et tab2.c
typedef struct Tableau {
	int* elt;
	int size;
	int eltsCount;
} TABLEAU;

//déclaration de la fonction newArray
TABLEAU newArray();

//déclaration de la fonction incrementArraySize
int incrementArraySize(TABLEAU* tab, int incrementValue);

//déclaration de la fonction setElement
int setElement(TABLEAU* tab, int pos, int element);

//déclaration de la fonction displayElements
int displayElements(TABLEAU* tab, int startPos, int endPos);