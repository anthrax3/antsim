#include "Game.h"
#include <SFML\Graphics.hpp>

int main()
{
	srand(time(0));

	//Start Game
	Game game(1400, 900);
	game.gameloop();

	//Return Success
	return 0;
}