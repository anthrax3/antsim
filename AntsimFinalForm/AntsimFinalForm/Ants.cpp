#include "Ants.h"
#include <cmath>

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

	Vector2D displacement(0, -1);
	displacement*Circle_radius;
	float length = pointDistance(0, 0, displacement.getX(), displacement.getY());
	displacement.setVec2D(cosf(Wander_angle*PI / 180) / length, -sinf(Wander_angle*PI / 180) / length);


	Wander_angle += divf((rand() % 10 - rand() % 10), 10) *Wander_difference;

	return Circle_Centre + displacement;
}

void Ants::update()
{
	if (!hasfood)
	{
		Vector2D wand = wander();
		velocity += wand;
		velocity.truncate(Max_Speed);
		position += velocity;

		//set trail location 

		/*Vector2D *ptrail = new Vector2D(position);
		phermon_trail.push_back(ptrail);
		if(phermon_trail.size() >= 300)
		{
			phermon_trail.empty();
		}*/
	}
	
}

bool Ants::Has_food(Ants * ants,Food * food)
{
	if (   ants->position.getX() + ants->Ant_Radius >= food->food_pos.getX() - food->Detect_radius
		&& ants->position.getX() - ants->Ant_Radius >= food->food_pos.getX() + food->Detect_radius
		&& ants->position.getY() + ants->Ant_Radius >= food->food_pos.getY() - food->Detect_radius
		&& ants->position.getY() - ants->Ant_Radius >= food->food_pos.getY() + food->Detect_radius)

	{
		hasfood = true;
		return true;
	}

	else
	{
		return false;
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

	//app.draw(trail);
	app.draw(body);
	app.draw(line, 4, sf::Lines);
}
