#include "MoveAble.h"
namespace game {

		MoveAble::MoveAble(const geo::Vector &direction, const double speed) : direction(direction), speed(speed) {}

		MoveAble::MoveAble(const MoveAble &oth) : direction(oth.direction), speed(speed) {}

		MoveAble::~MoveAble() {}

		void MoveAble::setDirection(const geo::Vector &d) {
			direction = d;
			direction.normalize();
		}

		const geo::Vector& MoveAble::getDirection() const {
			return direction;
		}

		void MoveAble::setSpeed(const double s) {
			speed = s;
		}

		double MoveAble::getSpeed() const {
			return speed;
		}

		MoveAble& MoveAble::operator =(const MoveAble &oth) {
			direction = oth.direction;
			speed = oth.speed;
			return *this;
		}

}
