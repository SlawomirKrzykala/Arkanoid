#pragma once
#include "rectangle.h"
#include "moveAble.h"
#include "collisionAble.h"

namespace game {
	class Platform : public geo::Rectangle, public game::MoveAble, public game::CollisionAble
	{

	public:
		Platform(geo::Rectangle rect, double speed = 1);

		Platform(const Platform &oth);

		Platform &move(const geo::Coordinates &min_cord, const geo::Coordinates &max_cord);

		Platform &operator =(const Platform &oth);

		geo::Vector checkCollision(const Ball &ball);

		~Platform();
	};
}