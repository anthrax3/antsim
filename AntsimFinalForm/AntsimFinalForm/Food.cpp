#include "Food.h"

#define FOOD_RADIUS 100


Food::Food(int fval, int radius, Vector2D & pos)
	:
	Food_value(fval),
	Detect_radius(radius),
	food_pos(pos),
	d_food(radius)
{
	d_food.setFillColor(sf::Color::Yellow);
}

void Food::draw(sf::RenderWindow &app)
{
	d_food.setPosition(food_pos.getX() - Detect_radius, food_pos.getY() - Detect_radius);
	//d_food.tr(food_pos.getX() , food_pos.getY());

	app.draw(d_food);
}
