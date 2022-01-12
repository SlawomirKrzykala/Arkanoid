#include "ball.h"

namespace game {

		Ball::Ball(const geo::Circle &position, const geo::Vector &direction, const double speed, const double damage) :
			Circle(position), damage(damage), MoveAble(direction, speed) {
			this->direction.normalize();
		}

		Ball::Ball(const Ball &oth) :Circle(oth), damage(oth.damage), MoveAble(oth) {}

		double Ball::getDamage() const {
			return damage;
		}

		void Ball::setDamage(const double d) {
			damage = d;
		}

		Ball& Ball::move(const geo::Coordinates &min_cord, const geo::Coordinates &max_cord) {
			*this += direction * speed;

			if ((x - r) < 0 || (x + r) > max_cord.getX()) {
				direction.reverseX();
				setX((x - r < min_cord.getX()) ? (r) : (max_cord.getX() - r));
			}

			if ((y - r) < min_cord.getY() || (y + r) > max_cord.getY()) {
				direction.reverseY();
				setY((y - r) < 0 ? (r) : (max_cord.getY() - r));
			}
			return *this;
		}

		Ball::~Ball() {}

}