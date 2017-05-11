#pragma once

#include <SFML\Graphics.hpp>
#include "Vector2D.h"

class Game;

class Food
{
public:
	Food(int fval, int radius, Vector2D& pos);
	void draw(sf::RenderWindow &app);
	//void update();
	Vector2D getpos();

public:
	int Food_value;
	float Detect_radius = 70;
	Vector2D food_pos;
	sf::CircleShape d_food;



};