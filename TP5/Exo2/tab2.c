#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "tab2.h"


//initialisation de la fonction newArray() :
//renvoie structure tableau avec elt = NULL si allocation échoue
//elt initié avec des 0 et eltCounts initié en 0 aussi
//taille init elt = TAILLEINITIALE 
TABLEAU newArray() {
	TABLEAU elt;
	elt.size = TAILLEINITIALE;
	elt.eltsCount = 0;
	elt.elt = NULL;
	elt.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));
	for (int i = 0; i < TAILLEINITIALE; ++i) {
		(elt.elt)[i] = 0;
	}
	for (int i = 0; i < TAILLEINITIALE; ++i) {
		if ((i % 10 == 0) && (i != 0)) printf("\n");
		printf("%d",(elt.elt)[i]);
	}
	return elt;
}

//initialisation de la fonction incrementArraySize :
//renvoie -1 si erreur || renvoie nouvelle taille si OK 
int incrementArraySize(TABLEAU* tab, int incrementValue) {
	int* tmp = tab->elt;
	if (tab->size < 0 || tab->elt == NULL || incrementValue < 1) {
		return -1;
	}

	tab->elt = (int*)realloc(tab->elt, ((size_t)tab->size + (size_t)incrementValue) * sizeof(int));
	if (tab->elt == NULL){
		tab->elt = tmp; 
		return -1; 
	}

	tab->size += incrementValue;
	for (int i = 0; i < incrementValue; i++) {
		*(tab->elt + tab->size - 1 - i) = 0;
	}
	return tab->size;	//renvoie nouvelle taille 
	
}

int setElement(TABLEAU* tab, int pos, int element) {
	//renvoie -1 en cas d'erreur
	if (tab->elt == NULL || tab->size < 0 || pos < 1)
		return -1;

	// on vérifie l'existence de pos dans le tableau 
	if (pos - 1 < tab->size) {
		*(tab->elt + pos - 1) = element;
		tab->eltsCount = max(pos, tab->eltsCount);
		return pos - 1;
	}

	//sinon on utilise la fonction d'incrémentation pour aller jusqu'à la position pos et créer des 0 entre les deux 
	if (incrementArraySize(tab, pos - tab->size) != -1) {
		*(tab->elt + tab->size - 1) = element;
		tab->eltsCount = pos;
		return pos - 1;
	}
	return -1;
}

int displayElements(TABLEAU* tab, int startPos, int endPos) {

}