#pragma once
#include "vector.h"
#include "ball.h"

namespace game {

	class CollisionAble{

	public:

		CollisionAble(){}

		virtual geo::Vector checkCollision(const Ball &ball) = 0;

		virtual ~CollisionAble() {};
	};
}
