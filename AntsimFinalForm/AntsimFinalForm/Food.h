#pragma once

#include <SFML\Graphics.hpp>
#include "Vector2D.h"

class Game;

class Food
{
public:
	int Food_value;
	float Detect_radius;
	Vector2D food_pos;
	sf::CircleShape d_food;
	Game *f_manager;

	Food() = default;
	Food(Game * manager);
	void draw();
	void update();

};