#pragma once
#include "board.h"
#include <map>
#include <SFML/graphics.hpp>

namespace display {
	class  Board
	{
	private:
		const game::BrickCollection const &bricksCollection;
		const game::Ball const &ball;
		const game::Platform const &platform;
		std::map < std::pair<int, int>, sf::RectangleShape> bricks_visible;
		sf::CircleShape ball_visible;
		sf::RectangleShape platform_visible;

	public:

		Board(const game::Board &game_board);
		
		void loadBoard();

		void draw(sf::RenderWindow &window);

		~Board();
	};
}
