#include "bar.h"

Bar::Bar(int weight, int height) {
	this->bar.x = (weight==0) ? weight : weight-this->bar.largo-2;
	this->bar.y = height/1.5-this->bar.ancho;
}

Bar::Bar() {
}

Bar::draw() {
   rectangulo_lleno
   (
	   this->bar.x,
	   this->bar.y,
	   this->bar.x + this->bar.largo,
	   this->bar.y + this->bar.ancho
   );
}

Bar::reduceLive() {
	this->lives--;
}

Bar::addScore() {
	this->score++;
}


Bar::getLives() {
	return this->lives;
}

Bar::getScore() {
	return this->score;
}

Bar::move(int t) {
    switch(t)
    {
        case ARRIBA: this->bar.y-=10; break;
        case ABAJO: this->bar.y+=10; break;
    }
}

bool Bar::compare(float x, float y) {
	return abs(this->bar.x-x)<=38 && this->bar.y <= y && y <= this->bar.y + this->bar.ancho;
}

bool Bar::isInside(float x) {
	return x>0 && this->bar.x > x;
}
