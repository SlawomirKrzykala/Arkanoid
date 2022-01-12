#pragma once
#include <list>
#include "brick.h"
#include "coordinates.h"

#include <string>
#include <fstream>
namespace game {
	class BrickCollection : public CollisionAble{

	private:

		std::list <Brick> collection;
		geo::Coordinates max_coord;
		int height, width;

		void addBrick(unsigned int color = 256, bool reset = 0);

	public:

		BrickCollection(const geo::Coordinates &max_coord);

		~BrickCollection();

		void loadDefaultBricks();

		bool loadBricks(const std::string &fileName);

		geo::Vector checkCollision(const Ball &ball);

		const Brick &getNextBrick(const bool reset = 0) const;

		int getSize() const;
	};
}