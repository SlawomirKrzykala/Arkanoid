#pragma once
#include "circle.h"
#include "MoveAble.h"
namespace game {
	class Ball : public geo::Circle, public game::MoveAble  {
	private:
		double damage;

	public:
		Ball(const geo::Circle &position, const geo::Vector &direction = geo::Vector(0.0, 1.0), const double speed = 1, const double damage = 1);

		Ball(const Ball &oth);
		
		double getDamage() const;

		void setDamage(const double d = 1);

		Ball &move(const geo::Coordinates &min_cord, const geo::Coordinates &max_cord);

		~Ball();
	};
}