#include "Ants.h"
#include <cmath>

Ants::Ants(float radius, Vector2D& pos)
	:
	Wander_angle(0.0f),
	Wander_difference(20.0f),
	Ant_Radius(radius),
	Max_Speed(2.0f),
	Has_food(false),
	position(pos),
	body(radius)
{
	velocity.setX(cosf(Wander_angle* PI/180)*Max_Speed);
	velocity.setY(-sinf(Wander_angle* PI / 180)*Max_Speed);

	body.setFillColor(sf::Color::Cyan);
}

Vector2D Ants::wander()
{
	float Circle_distance = 10;
	float Circle_radius = 20;
	Vector2D Circle_Centre = velocity;
	Circle_Centre.normalize();
	Circle_Centre*Circle_distance;

	Vector2D displacement(0, -1);
	displacement*Circle_radius;
	float length = pointDistance(0, 0, displacement.getX(), displacement.getY());
	displacement.setVec2D(cosf(Wander_angle*PI / 180) / length, -sinf(Wander_angle*PI / 180) / length);


	Wander_angle += divf((rand() % 10 - rand() % 10), 10) *Wander_difference;

	return Circle_Centre + displacement;
}

void Ants::update()
{
	Vector2D wand = wander();
	velocity += wand;
	velocity.truncate(Max_Speed);
	position += velocity;
}

void Ants::draw(sf::RenderWindow & app)
{
	body.setPosition(position.getX() - Ant_Radius, position.getY() - Ant_Radius);
	float length = velocity.length()* 5;


	sf::Vertex line[] = { 
		sf::Vertex(sf::Vector2f(position.getX() , position.getY()), sf::Color::Red),
		sf::Vertex(sf::Vector2f(position.getX() + (cosf(Wander_angle*PI/180) * length),position.getY() + (-sinf(Wander_angle*PI / 180) * length)),
			sf::Color::Red)};


	app.draw(body);
	app.draw(line, 4, sf::Lines);
}
