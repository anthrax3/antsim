#include "Ants.h"
#include <cmath>
#include "Game.h"

Ants::Ants(float radius, Vector2D& pos)
	:
	Wander_angle(0.0f),
	Wander_difference(20.0f),
	Ant_Radius(radius),
	Max_Speed(2.0f),
	position(pos),
	body(radius),
	acceleration(Vector2D(0,0))
{
	//sets start velocity
	velocity.setX(cosf(Wander_angle* PI/180)*Max_Speed);
	velocity.setY(-sinf(Wander_angle* PI / 180)*Max_Speed);
	
	//fill body color
	body.setFillColor(sf::Color::White);
}

Vector2D Ants::wander()
{
		float Circle_distance = 5;
		float Circle_radius = 3;

		Vector2D Circle_Centre = velocity;
		Circle_Centre.normalize();
		Circle_Centre *= Circle_distance;

		Vector2D displacement(1, -1);
		displacement *= Circle_radius;
		float length = pointDistance(0, 0, displacement.getX(), displacement.getY());
		displacement.setVec2D(cosf(Wander_angle*PI / 180) / length, -sinf(Wander_angle*PI / 180) / length);


		Wander_angle += divf((rand() % 10 - rand() % 10), 10) *Wander_difference;

		return Circle_Centre + displacement;
}

Vector2D Ants::seperate(std::list<Ants*> members)
{
	float desiredseperation = Ant_Radius * 3;
	Vector2D sum;
	int count = 0;

	for (Ants* other : members)
	{
		float d = pointDistance(position.getX(), position.getY(), other->position.getX(), other->position.getY());
		
		if ((d > 0) && (d < desiredseperation))
		{
			sum += other->position - position;
			count++;
		}
	}

	if (count > 0)
	{
		sum = sum/ count;
		sum = sum * -1;
		sum.normalize();
		return sum;
	}
	else
	{
		return Vector2D(0, 0);
	}

	
}

Vector2D Ants::align(std::list<Ants*> members)
{
	float neighbordist = 50; //an arbetery value 
	Vector2D sum(0, 0);
	int count = 0; //to keep track of other members

	for (Ants* other : members)
	{
		float d = pointDistance(position.getX(), position.getY(), other->position.getX(), other->position.getY());
		if ((d > 0) && (d < neighbordist))
		{
			sum += other->velocity;
			count++;
		}
	}

	if (count > 0)
	{
		sum = sum / count;
		sum.normalize();
		return sum;
	}

	else
	{
		return Vector2D(0, 0); //if no neighbour b=found return 0;
	}
}

Vector2D Ants::cohesion(std::list<Ants*> members)
{
	float neighbourdist = 50;
	Vector2D sum(0, 0);
	int count = 0;

	for (Ants* other : members)
	{
		float d = pointDistance(position.getX(), position.getY(), other->position.getX(), other->position.getY());

		if ((d > 0) && (d < neighbourdist))
		{
			sum += other->position; //adding all member position
			count++;
		}
	}

	if (count > 0)
	{
		sum /= count;
		Vector2D seek(sum.getX() - position.getX(), sum.getY() - position.getY() );
		seek.normalize();
		return seek;
	}
	else
	{
		return Vector2D(0,0);
	}
}

void Ants::applyBehaviour(std::list<Ants*> members)
{
	Vector2D sep = seperate(members);
	Vector2D ali = align(members);
	Vector2D coh = cohesion(members);

	sep *= 10.0;     //
	ali *= 10.0;       //          tweek this value for priorities
	coh *= 0.1;      //


	acceleration += sep + ali + coh;
	velocity += acceleration;
	velocity.truncate(Max_Speed);
	acceleration *= 0;
}

void Ants::update(std::list<Ants*> members)
{
	
	Vector2D wan = wander();

	
	acceleration += wan ;
	velocity += acceleration;
	velocity.truncate(Max_Speed);
	position += velocity;
	acceleration *= 0;


	if (position.getY()< 0)
	{
		position.setY(900);
	}
	if (position.getY() > 900)
	{
		position.setY(0);
	}
	if (position.getX() < 0 )
	{
		position.setX(1400);
	}
	if (position.getX() > 1400)
	{
		position.setX(0);
	}
}

void Ants::draw(sf::RenderWindow & app)
{
	
	body.setPosition(position.getX() - Ant_Radius, position.getY() - Ant_Radius);
	float length = velocity.length()* 5;

	app.draw(body);
}
