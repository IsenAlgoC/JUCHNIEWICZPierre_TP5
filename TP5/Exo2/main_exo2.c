#include <stdio.h>
#include <stdlib.h>
#include "tab2.h"


int main() {
	printf("Initialisation du tableau de %d elements par setElement : \n", TAILLEINITIALE);
	printf("\n");
	TABLEAU tab = newArray();
	for (int i = 0; i < 50; i++)
		setElement(&tab, i + 1, i + 1);

	for (int i = 0; i < TAILLEINITIALE; ++i) {
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
	printf("jusqu'à laquelle ? --> ");
	scanf_s("%d", &portionmax);
	printf("Votre tableau de la valeur numero %d au numero %d est : ",portionmin,portionmax);
	printf("\n");
	displayElements(&tab, portionmin, portionmax);

	printf("\n\n");
	deleteElements(&tab, 60, 100);
	printf("tab.size = %d\n", tab.size);


	return EXIT_SUCCESS;
}