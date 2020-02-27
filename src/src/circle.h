#ifndef CIRCLE_H
#define CIRCLE_H

#include "raylib.h"

namespace circle
{
	class Circle
	{
		float _radius;
		float _x;
		float _y;
		Vector2 _pos;

	public:

		Circle();
		Circle(float radius, float x, float y);

		~Circle();

		void setRadius(float radius);
		float getRadius();

		void setX(float x);
		float getX();

		void setY(float y);
		float getY();

		Vector2 getPos();
	};
}

#endif // !CIRCLE_H




