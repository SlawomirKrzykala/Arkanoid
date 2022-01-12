#pragma once
#include "Vector.h"
namespace game {
	class MoveAble
	{
	protected:
		geo::Vector direction;
		double speed;

	public:
		MoveAble(const geo::Vector &direction, const double speed);

		MoveAble(const MoveAble &oth);

		virtual ~MoveAble() = 0;

		virtual MoveAble &move(const geo::Coordinates &min_cord, const geo::Coordinates &max_cord) = 0;
		
		void setDirection(const geo::Vector &d = geo::Vector(0, 0));

		const geo::Vector& getDirection() const;

		void setSpeed(const double s = 1);

		double getSpeed() const;

		virtual MoveAble &operator =(const MoveAble &oth);
	};
}
