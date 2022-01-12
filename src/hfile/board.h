#pragma once
#include "ball.h"
#include "coordinates.h"
#include "circle.h"
#include "platform.h"
#include "rectangle.h"
#include "brickCollection.h"
#include <iostream>
#include "player.h"
#include <SFML/graphics.hpp>

namespace game {
	class Board{

	private:
		Ball default_ball;
		Ball game_ball;
		Platform default_platform;
		Platform game_platform;
		geo::Coordinates begin_board;
		geo::Coordinates end_board;
		BrickCollection brick_collection;
		sf::Clock clock;

	public:

		Board(geo::Coordinates begin_board, geo::Coordinates end_board);

		void loadLevel(const int lev);

		void reset();

		int nextFrame(geo::Vector direction_move_platform = geo::Vector(0.0, 0.0));

		bool ballAlive() const;

		void normalizeSpeed();

		const Ball &getBall() const;

		const Platform &getPlatform() const;

		const BrickCollection &getBrickCollection() const;

		int getSizeBricks() const;

		~Board();
	};
}