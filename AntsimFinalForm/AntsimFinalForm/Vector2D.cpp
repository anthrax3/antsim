#include "Vector2D.h"
#include <math.h>

Vector2D::Vector2D()
{
	vec_x = 0;
	vec_y = 0;
}

Vector2D::Vector2D(float x, float y)
{
	vec_x = x;
	vec_y = y;
}
Vector2D::~Vector2D() {}

float Vector2D::getX()
{
	return vec_x;
}

float Vector2D::getY()
{
	return vec_y;
}

void Vector2D::setX(float x)
{
	vec_x = x;
}

void Vector2D::setY(float y)
{
	vec_y = y;
}

void Vector2D::setVec2D(float x, float y)
{
	setX(x);
	setY(y);
}

float Vector2D::length()
{
	return sqrt(vec_x * vec_x + vec_y * vec_y);
}

void Vector2D::normalize()
{
	float l = length();
	if (l > 0)
	{
		(*this) *= 1 / l;
	}
}

void Vector2D::truncate(float max_value)
{
	if (length() > max_value)
	{
		normalize();
		*this *= max_value;
	}
}

