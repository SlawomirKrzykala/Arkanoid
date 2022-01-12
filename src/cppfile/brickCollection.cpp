#include "brickCollection.h"

namespace game {
	
		void BrickCollection::addBrick(unsigned int color, bool reset) {
			static int Xcord_brick = width / 2;
			static int Ycord_brick = height;
			if (!reset) {
				if (color != 0) {
					if (color == 256)
						color = Xcord_brick * Ycord_brick + 1000;
					collection.push_back(Brick(geo::Coordinates(Xcord_brick, Ycord_brick), width*0.88, height*0.86, color));
				}
				Xcord_brick += width;
				if (Xcord_brick > max_coord.getX()) {
					Ycord_brick += height;
					Xcord_brick = width / 2;
				}
			}
			else {
				Xcord_brick = width / 2;
				Ycord_brick = height;
			}
		}

		BrickCollection::BrickCollection(const geo::Coordinates &max_coord) :max_coord(max_coord), height(max_coord.getY()*0.03), width(max_coord.getX()*0.05) {};

		BrickCollection::~BrickCollection() { collection.clear(); };

		void BrickCollection::loadDefaultBricks() {
			collection.clear();
			addBrick(1, 1);

			for (int Y = 1; Y <= 18; Y++)
				for (int X = 1; X <= 20; X++)
					addBrick();
		}

		bool BrickCollection::loadBricks(const std::string &fileName) {
			collection.clear();
			addBrick(1, 1);

			std::fstream file(fileName, std::ios::in);
			if (file.good()) {
				while (!file.eof()) {
					std::string brick_color;
					file >> brick_color;
					if (brick_color != "")
						addBrick(std::stoul(brick_color, nullptr, 16));
				}
				return true;
			}
			else
				return false;
		}

		geo::Vector BrickCollection::checkCollision(const Ball &ball) {
			for (auto i = collection.begin(); i != collection.end(); i++) {
				geo::Vector collision_place = i->checkCollision(ball);
				if (collision_place != geo::Vector(0, 0)) {
					collection.erase(i);
					return collision_place;
				}
			}
			return geo::Vector(0, 0);
		};

		const Brick& BrickCollection::getNextBrick(const bool reset) const {
			static auto i = collection.begin();
			if (reset == 1)
				i = collection.begin();
			if (i == collection.end())
				return Brick(geo::Coordinates(0, 0), 0, 0, 0);
			return *i++;
		};

		int BrickCollection::getSize() const {
			return collection.size();
		}
}