#include <stdio.h>
#include "assets/carte/carte.h"
#include "assets/vie/vie.h"

int main(){
	printf("La faille du sorcier c'est vraiment trop bien enfaite\n") ;
	printf("vie de 5 + soin de 5 avec vie max de 7 = %d\nvie de 1 + soin de 5 avec vie max de 7 = %d\n",soin(5,5,7),soin(1,5,7));
	int map1[TAILLE_Y][TAILLE_X];
	creation_carte(map1);
	affiche(map1);
	map1[0][0] = 1;
	map1[5][8] = 2;
	printf("\n");
	map1[TAILLE_Y-1][TAILLE_X-1] = 5;
	affiche(map1);
	return 0 ;
}
