#include "brick.h"

namespace game {
	
		Brick::Brick(const geo::Coordinates &cord, const int width, const int heigth, const unsigned int color, const unsigned int life) :
			geo::Rectangle(cord, width, heigth), life(life), color(color) {};
		Brick::~Brick() {};

		const unsigned int Brick::getColor() const {
			return color;
		}

		/*geo::Vector Brick::checkCollision(const game::Ball &ball) {
				if (abs((ball.getY() - getY())) <= (ball.getR() + height / 2.0) && (abs(ball.getX() - getX())) <= ball.getR() + width / 2.0) {
					return(geo::Vector (ball)).reverseX();
				}
				return geo::Vector(0, 0);
			}*/

		geo::Vector Brick::checkCollision(const Ball &ball) {
			if (abs(ball.getY() - y) <= (ball.getR() + height / 2.0) && abs(ball.getX() - x) <= (ball.getR() + width / 2.0)) {
				if (abs(ball.getY() - y) >= (height / 2.0))
					return geo::Vector(ball.getDirection()).reverseY();
				else
					return geo::Vector(ball.getDirection()).reverseX();

			}
			return geo::Vector(0, 0);
		}
}

