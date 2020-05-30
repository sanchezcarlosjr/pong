#include "game.h"

Game::Game() {
   this->width = obtenerAncho();
   this->height = obtenerLargo()-70;
   this->player = new Bar(0,this->height);
   this->computer = new Computer(this->width,this->height);
   this->ball = new Ball(player, computer);
}

Game::play() {
   mensaje("Por Dahiana, futura física.  UABC :)");
   vredimensiona(this->width, this->height );
   int t;
   while ((t = tecla()) != ESCAPE && this->player->getLives() > 0 && this->computer->getLives() > 0) {
   	  borra();
      this->player->move(t);
      this->ball->move();
      this->ball->draw();
      this->computer->move(this->ball->getNextCollision());
      this->player->draw();
      this->computer->draw();
      this->drawBanner();
      refresca();
      espera(4);
   }
   mensaje("GAME OVER");
   vcierra();
}

Game::drawBanner() {
	stringstream txtStream;
    color(NEGRO);
    rectangulo_lleno(0, 0, this->width, 50);
    color(AZUL);
    txtStream.str("");
    texto(600, 10, txtStream.str());
    txtStream.str("");
    txtStream << "HUMANO vidas: " << this->player->getLives() << "  puntaje: " << this->player->getScore() << "   - IA vidas: " << this->computer->getLives() << "  puntaje: " << this->computer->getScore();
    texto(600, 30, txtStream.str());
}
