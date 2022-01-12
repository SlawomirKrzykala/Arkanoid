#pragma once
#include "Coordinates.h"
#include "Vector.h"
class AutoControl
{
	static bool status;
	AutoControl() {};
	~AutoControl() {};
public:
	static void enable() {
		status = 1;
	}

	static void disable() {
		status = 0;
	}

	static geo::Vector getMovePlatform (const geo::Coordinates &ball, const geo::Coordinates &platform) {
		if (status == 1 && abs(ball.getX() - platform.getX())>26)
			return geo::Vector(ball.getX()-platform.getX(), 0).normalize(2);
		else
			return geo::Vector(0, 0);
	}

};
bool AutoControl::status = 0;
