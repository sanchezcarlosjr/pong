#include "miniwin.h"
#include <stdlib.h>
#include <time.h>
using namespace miniwin;
#ifndef BAR_H
#define BAR_H

struct Barra
{
    int x           = 0;
    int y           = 200;
    int largo       = 20;
    int ancho       = 200;
    int color       = 3;    // NEGRO, ROJO, VERDE, AZUL, AMARILLO, MAGENTA, CYAN, BLANCO
};

class Bar {
	protected:
	    Barra bar;
	    int lives = 3;
	    int score = 0; 
	public:
		Bar(int weight, int height);
		Bar();
		draw();
		getLives();
		getScore();
		reduceLive();
		addScore();
		bool isInside(float x);
		move(int t);
		bool compare(float x, float y);
};

#endif
