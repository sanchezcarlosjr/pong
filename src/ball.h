#include "bar.h"
#include "miniwin.h"
#include <stdlib.h>
#include <time.h>
using namespace miniwin;
#ifndef BALL_H
#define BALL_H

struct Pelota {
  	float x, y;
   	int dx, dy;
   	int radio;
};

class Ball {
	private:
	   Pelota pelota;
	   Bar* bar;
	   Bar* bar2;
	public:
	   Ball(Bar* bar, Bar* bar2);
	   move();
	   int getNextCollision();
	   draw();
};

#endif
