#include "assets/carte/carte.h"

#define VICTOIRE 5


int move(int map[TAILLE_Y][TAILLE_X], char dir){
	int pos_x = 0;
	int pos_y = 0;
	int tmp_y = 0;
	int tmp_x = 0;
	for(int y = 0 ; y < TAILLE_Y ; y++){
		for(int x = 0 ; x < TAILLE_X ; x++){
			if(map[y][x] == 1){
				pos_y = y;
				pos_x = x;
				tmp_y = y;
				tmp_x = x;
				map[y][x] = 0;
				break;
			}
		}
	}
	switch(dir){
		case 'G' : pos_x -= 1;
			   break;
		case 'D' : pos_x += 1;
			   break;
		case 'H' : pos_y -= 1;
			   break;
		case 'B' : pos_y += 1;
			   break;
		default : pos_y = pos_y;
	}
	if((pos_x < 0 || pos_x >= TAILLE_X) || (pos_y < 0 || pos_y >= TAILLE_Y) || (map[pos_y][pos_x] != 0 && map[pos_y][pos_x] != VICTOIRE)){   //valeur de victoire (modifiable ici)
		map[tmp_y][tmp_x] = 1;
		return 2;
	}
	else{
		map[pos_y][pos_x] = 1;
		return 1;
	}
}
