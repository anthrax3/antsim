#include "Ants.h"
#include "Game.h"
#include <iostream>


#define ANT_RADIUS 3
#define MAX_SPEED 2


Ants::Ants(Game * m_manager, Vector2D & pos)
	:
	position(pos),
	Wander_angle(0.0f),
	Wander_difference(20.0f),
	manager(m_manager),
	body(ANT_RADIUS),
	trail(ANT_RADIUS)
{
	float direction = rand() % 360;
	velocity.setX(lengthDirX(MAX_SPEED, direction));
	velocity.setY(lengthDirY(MAX_SPEED, direction));

	body.setFillColor(sf::Color::Green);
	trail.setFillColor(sf::Color::Blue);
}

Ants::Ants(Game * m_manager)
	:
	Wander_angle(0.0f),
	Wander_difference(20.0f),
	manager(m_manager),
	body(ANT_RADIUS),
	trail(ANT_RADIUS)


{
	if (manager == nullptr)
	{
		return;
	}

	position.setX( m_manager->window.getSize().x / 2);
	position.setY( m_manager->window.getSize().y / 2);

	float direction = rand() % 360;
	velocity.setX(lengthDirX(MAX_SPEED, direction));
	velocity.setY(lengthDirY(MAX_SPEED, direction));

	body.setFillColor(sf::Color::Black);
	trail.setFillColor(sf::Color::Blue);

	
}

Ants::~Ants()
{
}

Vector2D Ants::wander()
{
	const float circle_dist = 5;
	const float circle_radius = 3;

	//Create a circle in front of the player
	//to create some displacement
	Vector2D circle_origin = velocity;
	circle_origin.normalize();
	circle_origin *= circle_dist;

	//Create Some Displacement for turning left
	//and right
	Vector2D displace(0, -1);
	displace *= circle_radius;
	float length = pointDistance(0, 0, displace.getX(), displace.getY());
	displace.setVec2D(cosf(Wander_angle*PI / 180) / length, -sinf(Wander_angle*PI / 180) / length);

	Wander_angle += divf((rand() % 10 - rand() % 10), 10) * Wander_difference;
	return circle_origin + displace;
}

void Ants::update()
{
	Vector2D wand = wander();
	velocity = velocity + wand;
	velocity.truncate(MAX_SPEED);
	position = position + velocity;

	if (position.getX() < 0)
	{
		position.setX(manager->Screen_width);
	}

	if (position.getX() > manager->Screen_width)
	{
		position.setX(0);
	}

	if (position.getY() < 0)
	{
		position.setY(manager->Screen_height);
	}

	if (position.getY() > manager -> Screen_height)
	{
		position.setY(0);
	}

	Vector2D *pt = new Vector2D(position);
	phermon_trail.push_back(pt);

}

void Ants::draw()
{
	body.setPosition(position.getX() - ANT_RADIUS, position.getY() - ANT_RADIUS);
	manager->window.draw(body);

	/*for (int i = 0; i < phermon_trail.size(); i++)
	{
		float posx = phermon_trail[i]->getX() - ANT_RADIUS;
		float posy = phermon_trail[i]->getY() - ANT_RADIUS;
		trail.setPosition(posx, posy);
		manager->window.draw(trail);	
	}*/

	float length = velocity.length() * 5;
	float direction = pointDirection(0, 0, velocity.getX(), velocity.getY());

	sf::Vertex line[] = { sf::Vertex(sf::Vector2f(position.getX(), position.getY()), sf::Color::Red),
		sf::Vertex(sf::Vector2f(position.getX() + lengthDirX(length,direction), position.getY() + lengthDirY(length,direction)), sf::Color::Red) };

	manager->window.draw(line, 2, sf::Lines);
}


