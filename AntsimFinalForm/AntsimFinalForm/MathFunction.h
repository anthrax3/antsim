#pragma once
#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

#include <math.h>

#ifndef DEF_MY_TYPES
#define DEF_MY_TYPES
typedef unsigned short	ushort;
typedef unsigned int	uint;
#endif //DEF_MY_TYPES

#ifndef PI
#define PI 3.14159
#endif

inline float pointDistance(float x1, float y1, float x2, float y2)
{
	return sqrtf((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

inline float pointDirection(float x1, float y1, float x2, float y2)
{
	return atan2f(y1 - y2, x2 - x1) * 180 / PI;
}

inline float lengthDirX(float length, float direction)
{
	return (cosf(direction*PI / 180)*length);
}

inline float lengthDirY(float length, float direction)
{
	return (-sinf(direction*PI / 180)*length);
}

inline float maxf(float x, float y)
{
	return (y > x ? y : x);
}

inline float minf(float x, float y)
{
	return (y < x ? y : x);
}

inline float roundf2dp(float value)
{
	return (roundf(value * 100)) / 100;
}

inline uint divu(uint val1, uint val2)
{
	return (val1 == 0 || val2 == 0) ? 0 : val1 / val2;
}

inline float divf(float val1, float val2)
{
	return (val1 == 0 || val2 == 0) ? 0 : val1 / val2;
}

// ***** Line Intersection ***** //
#define COLINEAR 0
#define CLOCKWISE 1
#define COUNTERCLOCK 2

inline bool onSegment(float x1, float y1, float x2, float y2, float x3, float y3)
{
	//Checks whether (x2,y2) lies on line segment (x1,y1) (x3,y3)
	if (x2 <= maxf(x1, x3) &&
		x2 >= minf(x1, x3) &&
		y2 <= maxf(y1, y3) &&
		y2 >= minf(y1, y3))
	{
		return true;
	}

	return false;
}

inline int orientation(float x1, float y1, float x2, float y2, float x3, float y3)
{
	//Returns whether the points triplet is colinear or counterclock or clockwise
	int val = (y2 - y1) * (x3 - x2) -
		(x2 - x1) * (y3 - y2);

	if (val == 0)	return COLINEAR;
	if (val > 0)	return CLOCKWISE;
	/*val is >0*/	return COUNTERCLOCK;
}

inline bool lineIntersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	//Returns whether or not line (x1,y1)(x2,y2) intersects with line (x3,y3)(x4,y4)

	//Four Orientation cases we need
	int o1 = orientation(x1, y1, x2, y2, x3, y3);
	int o2 = orientation(x1, y1, x2, y2, x4, y4);
	int o3 = orientation(x3, y3, x4, y4, x1, y1);
	int o4 = orientation(x3, y3, x4, y4, x2, y2);

	//General Case
	if (o1 != o2 && o3 != o4)
		return true;

	//Special Cases
	if (o1 == COLINEAR && onSegment(x1, y1, x3, y3, x2, y2))
		return true;
	if (o2 == COLINEAR && onSegment(x1, y1, x4, y4, x2, y2))
		return true;
	if (o3 == COLINEAR && onSegment(x3, y3, x1, y1, x4, y4))
		return true;
	if (o4 == COLINEAR && onSegment(x3, y3, x2, y2, x4, y4))
		return true;

	return false;
}

#endif // MATH_FUNCTIONS_H
