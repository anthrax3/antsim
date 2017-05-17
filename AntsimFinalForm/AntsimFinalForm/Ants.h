#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2D.h"
#include <vector>
#include <list>
#include "MathFunction.h"

class Game;

class Ants
{

public:
	
	Ants(float radius, Vector2D& pos);

	//Determine the random wander motion
	Vector2D wander();

	//moves or seeks a given co-ordinate/ vector point
	Vector2D seeking(Vector2D &targetPos);

	//avoid colission with other memberrs
	Vector2D seperate(std::list<Ants*> members);

	void update(Vector2D & force);
	void followtrail();
	void draw(sf::RenderWindow& app);

private:

	Vector2D position;
	Vector2D velocity;

	std::vector<Vector2D*> phermon_trail;

	float Wander_angle;
	float Wander_difference;
	float Ant_Radius;
	float Max_Speed;

	bool hasfood;

	sf::CircleShape  body;
	sf::CircleShape  trail;

	//Game *dimensions;
	
};