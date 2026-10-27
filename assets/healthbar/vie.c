#include "vie.h"

int additionner_vie(int a, int b) {
    return a + b;
}

int soin(int vie, int Soin, int vie_max){
	if(vie + Soin <= vie_max){
		return vie + Soin;
	}
	else{
		return vie_max;
	}
}
