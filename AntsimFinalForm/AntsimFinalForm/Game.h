#ifndef GAME_H
#define GAME_H

class Ants;
class Food;

#include <SFML/Graphics.hpp>
#include <vector>
#include "MathFunction.h"



class Game
{
public:
	sf::RenderWindow window;
	sf::Texture m_Background;
	sf::Sprite Background;
	std::vector<Ants*> ants;

	Game(int w, int h);
	~Game();

	void gameloop();
	void update();
	void draw();

	float Screen_width;
	float Screen_height;
};

#endif