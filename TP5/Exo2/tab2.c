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

	if (tab->size > (pos - 1)) //Si la position se trouve dans le tableau
	{
		tab->elt[pos - 1] = element;
		tab->eltsCount++;
	}

	//sinon on utilise la fonction d'incrémentation pour aller jusqu'à la position pos et créer des 0 entre les deux 
	else { 
		incrementArraySize(tab, pos - tab->size); 
		tab->elt[pos - 1] = element;
		tab->eltsCount++;
	}
	return pos - 1;
}

// renvoie -1 si erreur, sinon 0
// startPos >= EndPos n’est pas un cas d’erreur et doit être traité.
int displayElements(TABLEAU* tab, int startPos, int endPos) {
	if (tab->elt == NULL || startPos < 1 || endPos < 1 || startPos > tab->size || endPos > tab->size)
		return -1;
	if (startPos <= endPos) {
		for (int* i = tab->elt + startPos - 1; i < tab->elt + endPos; ++i) {
			int j = 0;
			if ((j % 10 == 0) && (j != 0)) printf("\n");
			printf(" %d ", *i);
			j++;
		}
	}
	else {
		for (int* i = tab->elt + startPos - 1; i > tab->elt + endPos - 2; --i) {
			int j = 0;
			if ((j % 10 == 0) && (j != 0)) printf("\n");
			printf(" %d ", *i);
			j++;
		}
	}
	printf("\n");
	return 0;
}



// renvoie -1 si erreur, sinon la nouvelle taille du tableau
// startPos >= EndPos n’est pas un cas d’erreur et doit être traité.
int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	if (tab->elt == NULL || startPos < 1 || endPos < 1 || startPos > tab->size || endPos > tab->size)	//on vérifie les erreurs possibles
		return -1;


	if (endPos < startPos) {	//si endPos<startpos, alors on inverse les deux 
		int tmp = endPos;
		endPos = startPos;
		startPos = tmp;
	}


	int nb = endPos - startPos + 1;	//nommbre entre les deux positions choisies
	if (nb == tab->size) {	//si le nombre de valeurs à détruire fait la taille du tableau
		free(tab->elt);		//on détruit le tableau
		tab->elt = NULL;
		tab->size = 0;
		tab->eltsCount = 0;
		return tab->size;
	}
	
	for (int i = startPos - 1; i < tab->size - endPos; i++) {
		tab->elt[i] = tab->elt[i + nb];							//on décale vers la gauche du nombre d'élément supprimé 
	}


	//destruction de la mémoire plus utilisée
	int* save = tab->elt;
	tab->elt = (int*)realloc(tab->elt, ((size_t)tab->size - (size_t)nb) * sizeof(int));
	if (tab->elt == NULL){
		tab->elt = save; 
		return -1; 
	}
	
	tab->size -= nb;
	if (startPos <= tab->eltsCount)
		tab->eltsCount -= (endPos <= tab->eltsCount) ? nb : (tab->eltsCount - startPos + 1);
	return tab->size;
}