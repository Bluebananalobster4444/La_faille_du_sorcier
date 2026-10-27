#ifndef VIE_H
#define VIE_H

/**
*entrée vie, Soin, vie_max
*pré-cond : vie >= 0, Soin > 0, vie_max > 0
*sortie : int
*post-cond : soin renvoie la vie après application du soin
*/
int soin(int vie, int Soin, int vie_max);

/**
*entrée vie, deg : int
*pré-cond : vie > 0, deg > 0
*sortie : int
*post-cond : degats renvoie la vie après application des dégâts
*/
int degats(int vie, int deg);

#endif
