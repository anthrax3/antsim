#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2D.h"
#include <vector>
#include "MathFunction.h"


class Game;

class Ants
{
public:

	Vector2D position;
	Vector2D velocity;
	std::vector<Vector2D*> phermon_trail;

	float Wander_angle;
	float Wander_difference;
	bool Has_food;

	Game* manager;
	sf::CircleShape  body;
	sf::CircleShape  trail;

	Ants(Game* m_manager, Vector2D& pos);
	Ants(Game* m_manager);
	~Ants();

	Vector2D wander();
	//void follow_trail();

	void update();
	void draw();

};