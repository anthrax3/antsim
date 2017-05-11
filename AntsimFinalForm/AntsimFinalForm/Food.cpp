#include "Food.h"

#define FOOD_RADIUS 100


Vector2D Food::getpos()
{
	return Vector2D(food_pos);
}

Food::Food(int fval, int radius, Vector2D & pos)
	:
	Food_value(fval),
	food_pos(pos),
	d_food(Detect_radius)
{
	d_food.setFillColor(sf::Color::Transparent);
	d_food.setOutlineThickness(2);
	d_food.setOutlineColor(sf::Color::Red);
}

void Food::draw(sf::RenderWindow &app)
{
	d_food.setPosition(food_pos.getX() - Detect_radius, food_pos.getY() - Detect_radius);
	app.draw(d_food);
}
