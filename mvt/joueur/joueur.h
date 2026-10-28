#ifndef JOUEUR_H
#define JOUEUR_H

/**
*entrée map : [int][int]
*entrée dir : char
*pré-cond : map est de taille TAILLE_Y*TAILLE_X, dir est dans {'G','D','H','B'}
*sortie : int
*post-cond : move déplace le joueur dans la direction de dir, renvoie 1 si le joueur s'est déplacé, 2 si le joueur se prend un mur
*/


int move(int map[TAILLE_Y][TAILLE_X], char dir);

#endif
