#include "vie.h"

int soin(int vie, int Soin, int vie_max){
	if(vie + Soin <= vie_max){
		return vie + Soin;
	}
	else{
		return vie_max;
	}
}

int degats(int vie, int deg){
	if(vie < deg){
		return 0;
	}
	else{
		return vie - deg;
	}
}


