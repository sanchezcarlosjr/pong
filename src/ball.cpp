#include "ball.h"

int random(int max, int min)
{
	srand(time(NULL));
	int random = rand() % max + min;
	return random;
}


Ball::Ball(Bar* bar, Bar* bar2) {
    this->pelota = { random(1000, 120), 120, 2, 2, 20 };
    this->bar = bar;
    this->bar2 = bar2;
}

Ball::draw() {
   circulo_lleno(this->pelota.x, this->pelota.y, this->pelota.radio);
}

int Ball::getNextCollision() {
	return this->pelota.y;
}

Ball::move() {
   if ( abs(this->pelota.y-70) <= 21 || abs(valto()-this->pelota.y) <= 38   ) {
      this->pelota.dy = -this->pelota.dy;
   }
   if(this->bar2->compare(this->pelota.x, this->pelota.y) ||
      this->bar->compare(this->pelota.x, this->pelota.y)) {
   	    this->pelota.dx = -this->pelota.dx;
   }
   if (this->pelota.x<-25 || this->pelota.x>vancho()+30) {
   	  this->pelota.x = random(800, 120);
   	  this->pelota.y = random(200, 80);
      this->pelota.dy = abs(this->pelota.dy)+1;
   	  this->pelota.dx = abs(this->pelota.dx)+1;
   	  if (this->pelota.x<-25) {
   	  	this->bar2->addScore();
   	  	this->bar->reduceLive();
	  } else {
	  	  	this->bar2->addScore();
   	  		this->bar->reduceLive();
	  }
   }
   this->pelota.y = this->pelota.y + this->pelota.dy;
   this->pelota.x = this->pelota.x + this->pelota.dx;
}
