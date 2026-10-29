#include <stdio.h>
#include <unistd.h>

#include "raylib/src/raylib.h"
#include "assets/carte/carte.h"
#include "assets/vie/vie.h"
#include "Mvt/joueur/joueur.h"

#define LAR 800
#define LON 800

#define DODO 100000

#define LIM_MV 999

#define CADRE_WIND 160

int main(){

	InitWindow(LAR+CADRE_WIND,LON+CADRE_WIND,"La_faille_du_sorcier");
	SetTargetFPS(60);
	int cell = 0.1*LON;
	int lar_j = 0.1*LAR;
	int lon_j = 0.1*LON;
	int en_mouvement = 0;

	Rectangle joueur = { CADRE_WIND / 2, 0 , lar_j, lon_j };

	int map1[TAILLE_Y][TAILLE_X];
	creation_carte(map1);
	map1[0][0] = 1;
	map1[5][8] = 2;
	printf("\n");
	map1[TAILLE_Y-1][TAILLE_X-1] = 5;

	int mv = 0;
	int et = 1;

	while (!WindowShouldClose()){



		if (IsKeyDown(KEY_RIGHT)){
			joueur.x += 0.1*LAR;
			mv += 1;
			if(!en_mouvement){
				usleep(DODO);
			}
			en_mouvement = 1;
		}

		if (IsKeyDown(KEY_LEFT)){
			joueur.x -= 0.1*LAR;
			mv += 1;
			if(!en_mouvement){
                                usleep(DODO);
                        }
                        en_mouvement = 1;
		}

		if (IsKeyDown(KEY_DOWN)){
			joueur.y += 0.1*LON;
			mv += 1;
			if(!en_mouvement){
                                usleep(DODO);
                        }
                        en_mouvement = 1;
		}

		if (IsKeyDown(KEY_UP)){
			joueur.y -= 0.1*LON;
			mv += 1;
			if(!en_mouvement){
                                usleep(DODO);
                        }
                        en_mouvement = 1;
		}

		if(IsKeyDown(KEY_A)){                    //Q sur AZERTY (probable différence entre AZERTY et QWERTY)
			mv = 0;
		}
		en_mouvement = 0;

		if (joueur.x < CADRE_WIND / 2){
			joueur.x = CADRE_WIND / 2;
			mv -= 1;
		}
	        if (joueur.y < 0){
			joueur.y = 0;
			mv -= 1;
		}
            	if (joueur.x + joueur.width  >LAR - CADRE_WIND / 2 + 2*joueur.width){
			joueur.x = LAR  - CADRE_WIND / 2 + joueur.width;
			mv -= 1;
		}
            	if (joueur.y + joueur.height > LON){
			joueur.y = LON - joueur.height;
			mv -= 1;
		}
		if(mv >= LIM_MV){
			mv = LIM_MV;
		}

		BeginDrawing();
            	ClearBackground(BLACK);

		for (int x = CADRE_WIND / 2; x <= LAR + (CADRE_WIND / 2); x += cell) {
            		DrawLine(x, 0, x, LON, LIGHTGRAY);
        	}

		for (int y = 0 ; y <= LON; y += cell) {
                        DrawLine(CADRE_WIND / 2, y, LAR + (CADRE_WIND / 2), y, LIGHTGRAY);
                }

		DrawRectangleRec(joueur, BROWN);
		DrawText(TextFormat("Mouv : %d", mv), LAR + CADRE_WIND -150, LON + CADRE_WIND-24, 24, RED);
		DrawText(TextFormat("Etage : %d",et),LAR + CADRE_WIND -150,LON-48 + CADRE_WIND,24,YELLOW);
		EndDrawing();
	}
	CloseWindow();
	return 0 ;
}
