#pragma once
#include "coordinates.h"
#include "vector.h"
#include "circle.h"
namespace geo {
	class Rectangle : public Coordinates
	{
	protected:
		double width;
		double height;
	public:

		Rectangle(const Coordinates &cord, double width, double height) : Coordinates(cord), width(width), height(height) {}
		Rectangle(const Rectangle &oth) : Coordinates(oth), width(oth.width), height(oth.height) {}
		virtual ~Rectangle() {}

		double getWidth() const {
			return width;
		}

		double getHeigth() const {
			return height;
		}

		void setWidth(const double width) {
			this->width = width;
		}

		void setHeight(const double heigth) {
			this->height = heigth;
		}

	};
}