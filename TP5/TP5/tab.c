#pragma once
#include <stdio.h>
#include <stdlib.h>
#define ADDSIZE 50

//implémentation de la fonction 'initTab'
int initTab(int *tab,int size) {

//retourne -1 si la taille est négative ou la tab est un pointeur NULL
	if (tab == NULL || size < 0) {
		return -1;
	}

//sinon, remplissage de tab par des 0 et retourne size
	else {
		for (int i = 0; i < size; ++i) {
			tab[i] = 0;
		}
		return size;	
	}
}


//implémentation de la fonction 'afficheTab'
int afficheTab(int* tab, int size, int nbElts) {
	if (tab == NULL || size < 0 || size < nbElts) {
		return -1;
	}
	else {
		for (int i = 0; i < nbElts; ++i) {
			if ((i % 10 == 0) && (i != 0)) {
				printf("\n");
			}
			if (i < 9) {
				printf(" %d  |", tab[i]);
			}
			else {
				printf(" %d |", tab[i]);
			}
			
		}
		return 0;
	}
}

//implémentation de la fonction 'ajoutElementDansTableau'
int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element){
	if (size < 0 || tab == NULL || size < *nbElts) {
		return  NULL;
	}
	//si le tableau est déjà rempli, on lui alloue de la mémoire
	if (*nbElts == *size) {
		*size += ADDSIZE;
		int* tmp = tab;
		tab = (int*)realloc(tab, *size * sizeof(int));

		if (tab == NULL) {
			tab = tmp;
			return NULL;
		}

		else {
			*nbElts += 1;
			*(tab + *nbElts) = element;
			return tab;
		}

	}
	else {
		*nbElts += 1;
		*(tab + *nbElts) = element;
		return tab;
	}
}