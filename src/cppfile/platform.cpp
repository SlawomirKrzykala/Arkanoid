#include "platform.h"

namespace game {
	
		Platform::Platform(geo::Rectangle rect, double speed) :Rectangle(rect), MoveAble(geo::Vector(0, 0), speed) {}

		Platform::Platform(const Platform &oth) :MoveAble(oth), Rectangle(oth) {}

		Platform& Platform::move(const geo::Coordinates &min_cord, const geo::Coordinates &max_cord) {
			*this += (direction * speed);

			if ((getX() - getWidth() / 2.0) < 0 || (getX() + getWidth() / 2.0) > max_cord.getX()) {
				setX((getX() - getWidth() / 2.0 < min_cord.getX()) ? (getWidth() / 2.0) : (max_cord.getX() - getWidth() / 2.0));
			}

			if ((getY() - getHeigth() / 2.0) < min_cord.getY() || (getY() + getHeigth() / 2.0) > max_cord.getY()) {
				setY((getY() - getHeigth() / 2.0 < 0) ? (getHeigth() / 2.0) : (max_cord.getY() - getHeigth() / 2.0));
			}

			return *this;
		}

		Platform& Platform::operator =(const Platform &oth) {
			this->geo::Rectangle::operator=(oth);
			this->MoveAble::operator=(oth);
			return *this;
		}

		geo::Vector Platform::checkCollision(const Ball &ball) {
			if (abs((ball.getY() - getY())) <= (ball.getR() + height / 2.0) && (abs(ball.getX() - getX())) <= ball.getR() + width / 2.0) {
				return geo::Vector((ball.getX() - getX())*height, (ball.getY() - getY())*width).normalize();
			}
			return geo::Vector(0, 0);
		}

		Platform::~Platform() {};
}