#include <stdio.h>
#include "assets/carte/carte.h"
#include "assets/vie/vie.h"
#include "mvt/joueur/joueur.h"

int main(){
	printf("La faille du sorcier c'est vraiment trop bien enfaite\n") ;
	printf("vie de 5 + soin de 5 avec vie max de 7 = %d\nvie de 1 + soin de 5 avec vie max de 7 = %d\n",soin(5,5,7),soin(1,5,7));
	int map1[TAILLE_Y][TAILLE_X];
	creation_carte(map1);
	map1[0][0] = 1;
	map1[5][8] = 2;
	printf("\n");
	map1[TAILLE_Y-1][TAILLE_X-1] = 5;
	affiche(map1);
	int i = -1;
	int mv = 0;
	int c;
	int fonctionne;
	while(i != 0){
		printf("Direction de déplacement :\n4. Gauche\n6. Droite\n2. Bas\n8. Haut\n0. Sortir\n");
		printf("mv = %d\n",mv);
		printf("choix : ");
		fonctionne = scanf("%d",&i);
		printf("\n\n");
		if(!fonctionne){
            		while ((c = getchar()) != '\n' && c != EOF) {
			}
		}
		if(i == 0){
			printf("Au revoir\n\n");
			return 0;
		}
		switch(i){
			case 4 : mv += move(map1,'G');
				 affiche(map1);
				 break;
			case 6 : mv += move(map1,'D');
				 affiche(map1);
				 break;
			case 2 : mv += move(map1,'B');
				 affiche(map1);
				 break;
			case 8 : mv += move(map1,'H');
				 affiche(map1);
				 break;
			default : printf("Mauvais choix\n\n");
				  mv += 2;
				  affiche(map1);
		}
		printf("\n\n");
	}
	return 0 ;
}
