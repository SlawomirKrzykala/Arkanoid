#pragma once
#include "rectangle.h"
#include "collisionAble.h"

namespace game {
	class Brick : public geo::Rectangle, public game::CollisionAble
	{
		int life;
		unsigned int color;

	public:

		Brick(const geo::Coordinates &cord, const int width, const int heigth, const unsigned int color, const unsigned int life = 1);

		~Brick();

		const unsigned int getColor() const;

		/*geo::Vector checkCollision(const game::Ball &ball);*/

		geo::Vector checkCollision(const Ball &ball);
	};
}

