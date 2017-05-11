#pragma once
#include "Ants.h"
#include "Food.h"
#include <list>

class Game
{
public:
	Game( int width, int height);
	void gameloop();
	void draw();
	void update();

private:
	 sf::RenderWindow window;
	 int SCREEN_WIDTH;
	 int SCREEN_HEIGHT;
	 std::list<Ants*>ants;
	 Ants *a;
	 Food *food;
};