#pragma once
#include "Ants.h"
#include <list>
#include <string.h>

class Game
{
public:
	//constructor
	Game( int width, int height);

	//gameloop
	void gameloop();

	//draw function
	void draw();

	//update function
	void update();
	void drawText();


private:

	 sf::RenderWindow window;
	 int SCREEN_WIDTH;
	 int SCREEN_HEIGHT;
	 std::list<Ants*>ants; // list of members
};