#include "Ants.h"
#include <cmath>
#include "Game.h"

Ants::Ants(float radius, Vector2D& pos)
	:
	Wander_angle(0.0f),
	Wander_difference(20.0f),
	Ant_Radius(radius),
	Max_Speed(2.0f),
	hasfood(false),
	position(pos),
	body(radius)
	//trail(radius/2)
{
	velocity.setX(cosf(Wander_angle* PI/180)*Max_Speed);
	velocity.setY(-sinf(Wander_angle* PI / 180)*Max_Speed);

	body.setFillColor(sf::Color::Cyan);
	trail.setFillColor(sf::Color::Transparent);
	trail.setOutlineThickness(1);
	trail.setOutlineColor(sf::Color::Red);
}

Vector2D Ants::wander()
{
		float Circle_distance = 10;
		float Circle_radius = 20;
		Vector2D Circle_Centre = velocity;
		Circle_Centre.normalize();
		Circle_Centre*Circle_distance;

		Vector2D displacement(1, -1);
		displacement*Circle_radius;
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
			Vector2D diff = (other->position - position);

			diff.normalize();

			diff /= d;

			sum += diff;

			count++;
		}
	}

	if (count > 0)
	{
		sum /= count;
		sum.normalize();
		sum *= Max_Speed;
		Vector2D steer = velocity - sum;
		steer.truncate(Max_Speed);
		return Vector2D(steer);
	}
	else
	{
		return Vector2D(0, 0);
	}
}

void Ants::update(Vector2D & force)
{
	
	
		velocity += force;
		velocity.truncate(Max_Speed);
		position += velocity;

		//set trail location 

		/*Vector2D *ptrail = new Vector2D(position);
		phermon_trail.push_back(ptrail);
		if(phermon_trail.size() >= 300)
		{
			phermon_trail.empty();
		}*/

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


void Ants::followtrail()
{
		for (int i = phermon_trail.size(); i >= 0; i--)
		{
			Vector2D *f_trail = phermon_trail[i];
			position.setX(f_trail->getX());
			position.setY(f_trail->getY());
			//body.setPosition(f_trail->getX() - Ant_Radius, f_trail->getY() - Ant_Radius);
		}
}

Vector2D Ants::seeking(Vector2D &targetPos)
{
	Vector2D desired = targetPos - position;
	desired.normalize();
	desired*Max_Speed;

	Vector2D steering = desired - velocity;
	steering.truncate(Max_Speed);
	velocity += steering;
	return steering;
}

void Ants::draw(sf::RenderWindow & app)
{
	
	body.setPosition(position.getX() - Ant_Radius, position.getY() - Ant_Radius);
	float length = velocity.length()* 5;


	//draw trails

	/*for (int i = 0; i <phermon_trail.size();i++)
	{
		Vector2D *f_trail = phermon_trail[i];
		trail.setPosition(f_trail->getX() - Ant_Radius, f_trail->getY() - Ant_Radius);
		app.draw(trail);
		app.clear();

	}*/

	sf::Vertex line[] = { 
		sf::Vertex(sf::Vector2f(position.getX() , position.getY()), sf::Color::Red),
		sf::Vertex(sf::Vector2f(position.getX() + (cosf(Wander_angle*PI/180) * length),position.getY() + (-sinf(Wander_angle*PI / 180) * length)),
			sf::Color::Red)};

	/*sf::Transform t;
	Vector2D trans = velocity;
	float angleR = pointDirection(velocity.getX(), velocity.getY(),position.getX(), position.getY());
	t.rotate(angleR *  180/PI, position.getX(), position.getY());*/

	//app.draw(trail);
	//body.rotate(45);
	app.draw(body);
	app.draw(line, 4, sf::Lines);
}
