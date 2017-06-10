#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2D.h"
#include <vector>
#include <list>
#include "MathFunction.h"
 

class Ants
{

public:
	
	//constructor
	Ants(float radius, Vector2D& pos);

	//Determine the random wander motion
	Vector2D wander();

	//avoid colission with other memberrs
	Vector2D seperate(std::list<Ants*> members);

	//alignment function with other memners
	Vector2D align(std::list<Ants*> members);

	//cohesive behaviour in relation to other members
	Vector2D cohesion (std::list<Ants*>members);

	//applys behaviour 
	void applyBehaviour(std::list<Ants*>members);

	//updates every member
	void update(std::list<Ants*> members);

	//draws members
	void draw(sf::RenderWindow& app);

private:

	Vector2D position;
	Vector2D velocity;
	Vector2D acceleration;

	float Wander_angle; //wander angle
	float Wander_difference; //wandering angle difference
	float Ant_Radius; //radius of memebrs
	float Max_Speed; //max speed of members

	sf::CircleShape  body;  //draws body shape


	
};