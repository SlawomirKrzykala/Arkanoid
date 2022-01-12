#pragma once
#include <cmath>
#include "coordinates.h"
namespace geo {
	class Vector :public Coordinates
	{
	public:
		Vector(const double x=0, const double y=0) : Coordinates(x, y) {}
		Vector(const Vector &oth):Coordinates(oth) {}
		Vector(const Coordinates &oth) : Coordinates(oth) {}
		virtual ~Vector() {}


		const Vector& normalize(const double dlugosc = 1) {
			if (*this!=Vector(0,0)) {
				double d = sqrt(x * x + y * y);
				x = dlugosc * x / d;
				y = dlugosc * y / d;
			}
			return *this;
		}

		Vector &operator *=(const Vector &m) {
			Coordinates::operator*=(m);
			//x = (m.getX() * x);
			//y = (m.getY() * y);
			//normalize();
			return *this;
		}

		 Vector &operator +=(const Vector &d) {
			Coordinates::operator+=(d);
			//normalize();
			return *this;
		}

		const Vector& reverseX() {
			x = -x;
			return *this;
		}

		const Vector& reverseY() {
			y = -y;
			return *this;
		}

		const Vector& reverseXY() {
			x = -x;
			y = -y;
			return *this;
		}

		Vector &operator = (const Vector &oth) {
			Coordinates::operator=(oth);
			return *this;

		}
	};
}