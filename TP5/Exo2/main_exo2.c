#include <stdio.h>
#include <stdlib.h>
#include "tab2.h"


int main() {
	printf("Initialisation du tableau de %d + 19 [0] + 1 [15] a la place '120' = 120 elements par setElement : \n", TAILLEINITIALE);
	printf("\n");
	TABLEAU tab = newArray();
	setElement(&tab, 15, 120);
	setElement(&tab, 120, 15);
	for (int i = 0; i < TAILLEINITIALE+20; ++i) {
		if ((i % 10 == 0) && (i != 0)) printf("\n");
		printf("| %d  ", (tab.elt)[i]);
	}

	int tailleajout = 0;
	printf("\n");
	printf("\n");
	printf("Combien de nouveaux elements voulez-vous inclure dans votre tableau ? --> ");
	scanf_s("%d", &tailleajout);
	printf("\nTest de rajout de %d places au tableau : \n",tailleajout);

	//on test le rajout de tailleajout places = 100+2
	incrementArraySize(&tab, tailleajout);
	printf("tab.size = %d\n", tab.size);
	printf("\n");

	int portionmin = 0, portionmax = 0;
	printf("A partir de quelle valeur voulez-vous afficher votre tableau ? --> ");
	scanf_s("%d", &portionmin);
	printf("jusqu'� laquelle ? --> ");
	scanf_s("%d", &portionmax);
	printf("Votre tableau de la valeur numero %d au numero %d est : ",portionmin,portionmax);
	printf("\n");
	displayElements(&tab, portionmin, portionmax);


	printf("\n\nEn retirant les 20 premiers elements du tableau : \n");;
	deleteElements(&tab, 1, 20);
	printf("tab.size = %d\n", tab.size);
	for (int i = 0; i < TAILLEINITIALE+tailleajout; ++i) {
		if ((i % 10 == 0) && (i != 0)) printf("\n");
		printf("| %d  ", (tab.elt)[i]);
	}

	return EXIT_SUCCESS;
}