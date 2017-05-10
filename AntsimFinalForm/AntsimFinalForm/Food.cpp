#include "Food.h"
#include "Game.h"

#define FOOD_RADIUS 100

Food::Food(Game * manager)
	:
	f_manager(manager),
	d_food(FOOD_RADIUS)
{

	if (f_manager == nullptr)
	{
		return;
	}
	d_food.setFillColor(sf::Color::Yellow);
	food_pos.setX(500 - FOOD_RADIUS);
	food_pos.setY(500 -	FOOD_RADIUS);

}

void Food::draw()
{
	d_food.setPosition(food_pos.getX(), food_pos.getY());
	f_manager->window.draw(d_food);
}
