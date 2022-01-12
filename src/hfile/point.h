#pragma once
#include "coordinates.h"
namespace geo {
	class point :public Coordinates
	{
	public:
		point() {}
		point(const double x, const double y) : Coordinates(x, y) {}
		point(const Coordinates &oth) : Coordinates(oth) {}

		~point() {}
	};
}