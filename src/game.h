#include "miniwin.h"
#include <sstream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
using namespace miniwin;
using namespace std;
#include "computer.h"
#include "ball.h"
#include "bar.h"
#ifndef GAME_H
#define GAME_H

class Game {
	private:
	  int width;
	  int height;
	  int level = 5;
	  Bar* player;
	  Computer* computer;
	  Ball* ball;
	public:
		Game();
		play();
		drawBanner();
};

#endif
