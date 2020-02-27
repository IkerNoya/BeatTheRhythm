#include "circle.h"


namespace circle 
{
	Circle::Circle()
	{
		_radius = 1;
		_x = 1.0f;
		_pos.x = 1.0f;
		_y = 1.0f;
		_pos.y = 1.0f;
	}

	Circle::Circle(int radius, float x, float y)
	{
		_radius = radius;
		_x = x;
		_pos.x = x;
		_y = y;
		_pos.y = y;
	}

	Circle::~Circle()
	{

	}

	void Circle::setRadius(int radius)
	{
		_radius = radius;
	}

	int Circle::getRadius()
	{
		return _radius;
	}

	void Circle::setX(float x)
	{
		_x = x;
		_pos.x = x;
	}

	float Circle::getX()
	{
		return _x;
	}

	void Circle::setY(float y)
	{
		_y = y;
		_pos.y = y;
	}

	float Circle::getY()
	{
		return _y;
	}

	Vector2 Circle::getPos()
	{
		return _pos;
	}

}