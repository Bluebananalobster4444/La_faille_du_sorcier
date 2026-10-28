#include "carte.h"
#include <stdio.h>

void creation_carte(int map[TAILLE_Y][TAILLE_X]) {
    for (int y = 0; y<TAILLE_Y; y++) {
        for(int x = 0 ; x<TAILLE_X;x++) {
            map[x][y] = 0;
        }
    }
}

void affiche(int map[TAILLE_Y][TAILLE_X]) {
	for(int i = 0 ; i < TAILLE_Y ; i++){
		printf("| ");
		for(int j = 0 ; j < TAILLE_X ; j++){
			printf("%d | ",map[i][j]);
		}
		printf("\n");
	}
}
