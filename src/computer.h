#include "bar.h"
#ifndef COMPUTER_H
#define COMPUTER_H

class Computer: public Bar {
	public: 
	   Computer(int weight, int height): Bar(weight, height) {};
	   move(int t);
};

#endif

