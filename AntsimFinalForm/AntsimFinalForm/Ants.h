#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2D.h"
#include <vector>
#include <list>
#include "MathFunction.h"


class Ants
{

public:
	
	Ants(float radius, Vector2D& pos);

	//Determine the random wander motion
	Vector2D wander();
	void update();
	void draw(sf::RenderWindow& app);

private:

	Vector2D position;
	Vector2D velocity;

	std::vector<Vector2D*> phermon_trail;

	float Wander_angle;
	float Wander_difference;
	float Ant_Radius;
	float Max_Speed;

	bool Has_food;

	sf::CircleShape  body;
	sf::CircleShape  trail;
	
};