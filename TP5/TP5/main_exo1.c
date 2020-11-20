#include <stdio.h>
#include <stdlib.h>
#include "tab.h"
#define TAB1SIZE 10
#define NBELMTS 7
#define TAB2SIZE 100
#define NBELMTS2 20


int main() {

	//INITIALISATION ET AFFICHAGE DE 'MyTab1'
	printf("MyTab1 = \n");
	int myTab1[TAB1SIZE];
	initTab(myTab1, TAB1SIZE);	//initTab(int *tab,size)
	afficheTab(myTab1, TAB1SIZE, NBELMTS);	//afficheTab(int *tab,size,nbElts)

	printf("\n");




	//INITIALISATION ET AFFICHAGE DE 'MyTab2'
	printf("\nMyTab2 = ");

	//Déclaration du ptr et variables mémorisant taille tableau et nb de valeurs rangées
	int* myTab2 = NULL;
	int tabSize = TAB2SIZE;
	int nbelts = 0;

	//Allocation de la mémoire
	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));
	if (myTab2 != NULL) { initTab(myTab2, tabSize); }
	else { printf("mémoire insuffisante"); return(-1); }
	
	//Test initalisation à 0 
	printf("\nTest d'initialisation des valeurs 0 de 'myTab2' : \n");
	for (int i = 0; i < TAB2SIZE; ++i) {
		if ((i % 10 == 0) && (i != 0)) {
			printf("\n");
		}
		printf(" %d |", myTab2[i]);
	}

	//Remplissage de 'myTab2'
	for (int i = 0; i < NBELMTS2; ++i) {
		myTab2[i] = i+1;
	}

	//Affichage de 'myTab2'
	printf("\n");
	printf("\nAffichage de 'myTab2' rempli de 1 a 20 : \n");
	afficheTab(myTab2, TAB2SIZE, NBELMTS2);

	//Si le nombre d'élément > la capacité du tableau, alors on augmente la capacité du tableau 
	int nbElts = 100;
	ajoutElementDansTableau(myTab2, &tabSize, &nbElts, 40);
	printf("\n");
	printf("\nTaille du tableau : %d \nNombre d'elements : %d \n", tabSize, nbElts);

	//Destruction de 'myTab2'
	free(myTab2);
}