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

	Food(int fval, int radius, Vector2D& pos);
	void draw(sf::RenderWindow &app);
	void update();

};