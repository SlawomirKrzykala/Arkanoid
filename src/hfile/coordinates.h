#pragma once
#include<string>
namespace geo {
	class Coordinates
	{
	protected:

		double x, y;

	public:
		Coordinates(const double x=0, const double y=0) : x(x), y(y) {}

		Coordinates(const Coordinates &oth) : x(oth.x), y(oth.y) {}

		virtual ~Coordinates() {}

		double getX() const {
			return x;
		}

		double getY() const {
			return y;
		}

		const Coordinates &getCord() const {
			return *this;
		}

		void setX(const double x) {
			this->x = x;
		}

		void setY(const double y) {
			this->y = y;
		}

		void setCord(const Coordinates &oth) {
			this->x = oth.x;
			this->y = oth.y;
		}

		 Coordinates& operator +=(const Coordinates &oth) {
			x += oth.x;
			y += oth.y;
			return *this;
		}

		 Coordinates operator +(const Coordinates &oth)const {
			return Coordinates(x + oth.x, y + oth.y);
		}

		 Coordinates& operator *=(const double m) {
			x *= m;
			y *= m;
			return *this;
		}

		 Coordinates& operator *=(const Coordinates &oth) {
			x *= oth.x;
			y *= oth.y;
			return *this;
		}

		 Coordinates operator *(const double d)const {
			return Coordinates((x * d), (y * d));
		}

		 Coordinates operator *(const Coordinates &oth)const {
			return Coordinates((x * oth.x), (y * oth.y));
		}

		 Coordinates& operator =(const Coordinates &oth) {
			x = oth.x;
			y = oth.y;
			return *this;
		}

		 bool operator !=(const Coordinates &oth) const {
			if ((x != oth.x) || (y != oth.y))
				return true;
			return false;
		}

		 bool operator !=(const double xy) const {
			if ((x != xy) || (y != xy))
				return true;
			return false;

		}

		std::string getTxtCord() const {
			return "X:" + std::to_string(x) + "\t Y:" + std::to_string(y);
		}
	};
}
