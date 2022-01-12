#pragma once
#include "coordinates.h"
namespace geo {
	class Circle :public Coordinates
	{
	protected:
		double r;
	public:
		Circle(const double x, const double y, const double r = 1) : Coordinates(x, y), r(r) {}
		Circle(const Coordinates &oth, const double r = 1) : Coordinates(x, y), r(r) {}
		Circle(const Circle &oth) : Coordinates(oth), r(oth.r) {}
		virtual ~Circle() {};

		double getR() const {
			return r;
		}

		void setR(const double r) {
			this->r = r;
		}
	};
}