#pragma once
#ifndef VECTOR_2D
#define VECTOR_2D

class Vector2D
{
public:
	Vector2D();
	Vector2D(float x, float y);
	virtual ~Vector2D();

	float 	getX();
	float 	getY();

	void 	setX(float x);
	void 	setY(float y);
	void 	setVec2D(float x, float y);

	float 	length();
	void 	normalize();
	void 	truncate(float max_value);

	//====================
	// Operators
	//====================
	Vector2D operator+(const Vector2D &v2) const
	{
		return Vector2D(vec_x + v2.vec_x, vec_y + v2.vec_y);
	}
	friend Vector2D& operator+=(Vector2D &v1, const Vector2D &v2)
	{
		v1.vec_x += v2.vec_x;
		v1.vec_y += v2.vec_y;

		return v1;
	}
	Vector2D operator*(float scalar)
	{
		return Vector2D(vec_x * scalar, vec_y * scalar);
	}
	Vector2D& operator*= (float scalar)
	{
		vec_x *= scalar;
		vec_y *= scalar;

		return *this;
	}
	Vector2D operator-(const Vector2D& v2) const
	{
		return Vector2D(vec_x - v2.vec_x, vec_y - v2.vec_y);
	}
	friend Vector2D& operator-=(Vector2D &v1, const Vector2D &v2)
	{
		v1.vec_x -= v2.vec_x;
		v1.vec_y -= v2.vec_y;

		return v1;
	}
	Vector2D operator/(float scalar)
	{
		return Vector2D(vec_x / scalar, vec_y / scalar);
	}
	Vector2D& operator/=(float scalar)
	{
		vec_x /= scalar;
		vec_y /= scalar;

		return *this;
	}

private:
	float vec_x, vec_y;
};

#endif // VECTOR_2D
