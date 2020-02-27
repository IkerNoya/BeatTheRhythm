#ifndef CIRCLE_H
#define CIRCLE_H

#include "raylib.h"

namespace circle
{
	class Circle
	{
		int _radius;
		float _x;
		float _y;
		Vector2 _pos;

	public:

		Circle();
		Circle(int radius, float x, float y);

		~Circle();

		void setRadius(int radius);
		int getRadius();

		void setX(float x);
		float getX();

		void setY(float y);
		float getY();

		Vector2 getPos();
	};
}

#endif // !CIRCLE_H




