#include <stdio.h>
#include <time.h>

#include "raylib/src/raylib.h"
#include "assets/carte/carte.h"
#include "assets/vie/vie.h"
#include "Mvt/joueur/joueur.h"

#define LAR 1500
#define LON 800

int main(){

	InitWindow(LAR,LON,"Banane");
	SetTargetFPS(60);

	Rectangle joueur = { 380, 400, 40, 40 };

	int map1[TAILLE_Y][TAILLE_X];
	creation_carte(map1);
	map1[0][0] = 1;
	map1[5][8] = 2;
	printf("\n");
	map1[TAILLE_Y-1][TAILLE_X-1] = 5;
	affiche(map1);

/*
	int i = -1;
	int mv = 0;
	int c;
	int fonctionne;
*/
	while (!WindowShouldClose()){



		if (IsKeyDown(KEY_RIGHT)){
			joueur.x += 10;
		}

		if (IsKeyDown(KEY_LEFT)){
			joueur.x -= 10;
		}

		if (IsKeyDown(KEY_DOWN)){
			joueur.y += 10;
		}

		if (IsKeyDown(KEY_UP)){
			joueur.y -= 10;
		}

		if (joueur.x < 0) joueur.x = 0;
	        if (joueur.y < 0) joueur.y = 0;
            	if (joueur.x + joueur.width  >LAR) joueur.x = LAR - joueur.width;
            	if (joueur.y + joueur.height > LON) joueur.y = LON - joueur.height;

		BeginDrawing();
            	ClearBackground(BLACK);

		DrawRectangleRec(joueur, BLUE);

		EndDrawing();
		/*printf("Direction de deplacement :\n4. Gauche\n6. Droite\n2. Bas\n8. Haut\n0. Sortir\n");
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
		if(map1[TAILLE_Y-1][TAILLE_X-1] != VICTOIRE){
			printf("\n\n");
			printf("Bravo\n");
			break;
		}
		printf("\n\n");
		*/
	}
	CloseWindow();
	return 0 ;
}
