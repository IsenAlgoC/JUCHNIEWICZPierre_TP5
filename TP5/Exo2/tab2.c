#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "tab2.h"


//initialisation de la fonction newArray() :
//renvoie structure tableau avec elt = NULL si allocation �choue
//elt initi� avec des 0 et eltCounts initi� en 0 aussi
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

	// on v�rifie l'existence de pos dans le tableau 
	if (pos - 1 < tab->size) {
		*(tab->elt + pos - 1) = element;
		tab->eltsCount = max(pos, tab->eltsCount);
		return pos - 1;
	}

	//sinon on utilise la fonction d'incr�mentation pour aller jusqu'� la position pos et cr�er des 0 entre les deux 
	if (incrementArraySize(tab, pos - tab->size) != -1) {
		*(tab->elt + tab->size - 1) = element;
		tab->eltsCount = pos;
		return pos - 1;
	}
	return -1;
}

int displayElements(TABLEAU* tab, int startPos, int endPos) {
	if (tab->elt == NULL || startPos < 1 || endPos < 1 || startPos > tab->size || endPos > tab->size)
		return -1;
	if (startPos <= endPos) {
		for (int* i = tab->elt + startPos - 1; i < tab->elt + endPos; ++i) {
			if ((i % 10 == 0) && (i != 0)) printf("\n");
			printf(" %d ", *i);
		}
	}
	else {
		for (int* i = tab->elt + startPos - 1; i > tab->elt + endPos - 2; --i) {
			if ((i % 10 == 0) && (i != 0)) printf("\n");
			printf(" %d ", *i);
		}
	}
	printf("\n");
	return 0;
}

int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	if (tab->elt == NULL || startPos < 1 || endPos < 1 || startPos > tab->size || endPos > tab->size)
		return -1;
	if (endPos < startPos) {
		int tmp = endPos;
		endPos = startPos;
		startPos = tmp;
	}
	int nbDeValDansIntervalle = endPos - startPos + 1;
	/* Liberation de la memoire si tous les elements du tableau sont selectionnees */
	if (nbDeValDansIntervalle == tab->size) {
		free(tab->elt);
		tab->elt = NULL;
		tab->size = 0;
		tab->eltsCount = 0;
		return tab->size;
	}
	/* Decalage vers la gauche des valeurs positionnees situees apres la partie a supprimer
	pour qu'elles commencent a startPos. */
	for (int i = startPos - 1; i < tab->size - endPos; i++) {
		tab->elt[i] = tab->elt[i + nbDeValDansIntervalle];
	}
	/* Reduction de la memoire au minimum necessaire */
	int* buffer = tab->elt;
	tab->elt = (int*)realloc(tab->elt, ((size_t)tab->size - (size_t)nbDeValDansIntervalle) * sizeof(int));
	if (tab->elt == NULL) { tab->elt = buffer; return -1; }
	/* Mise a jour de la taille et du nombre d'elements */
	tab->size -= nbDeValDansIntervalle;
	if (startPos <= tab->eltsCount)
		tab->eltsCount -= (endPos <= tab->eltsCount) ? nbDeValDansIntervalle : (tab->eltsCount - startPos + 1);
	return tab->size;
}