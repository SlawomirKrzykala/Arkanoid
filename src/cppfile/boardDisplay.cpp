#include "boardDisplay.h"

namespace display {

	Board::Board(const game::Board &game_board) :ball(game_board.getBall()), platform(game_board.getPlatform()), bricksCollection(game_board.getBrickCollection()) {
			ball_visible.setRadius(ball.getR());
			ball_visible.setOrigin(sf::Vector2f(ball_visible.getRadius(), ball_visible.getRadius()));
			ball_visible.setFillColor(sf::Color::Blue);

			platform_visible.setSize(sf::Vector2f(platform.getWidth(), platform.getHeigth()));
			platform_visible.setOrigin(sf::Vector2f(platform.getWidth() / 2.0, platform.getHeigth() / 2.0));
			platform_visible.setFillColor(sf::Color::Blue);

			loadBoard();
		};

		void Board::loadBoard() {
			bricks_visible.clear();
			game::Brick brick = bricksCollection.getNextBrick(1);
			while (brick != geo::Coordinates(0, 0)) {
				auto tmp = sf::RectangleShape();
				tmp.setSize(sf::Vector2f(brick.getWidth(), brick.getHeigth()));
				tmp.setOrigin(sf::Vector2f(brick.getWidth() / 2.0, brick.getHeigth() / 2.0));
				tmp.setPosition(brick.getX(), brick.getY());
				tmp.setOutlineThickness(2.0);
				tmp.setFillColor(sf::Color(brick.getColor()));
				tmp.setOutlineColor(sf::Color::Black);
				bricks_visible[std::make_pair(int(brick.getX()), int(brick.getY()))] = tmp;
				brick = bricksCollection.getNextBrick();
			}
		};

		void Board::draw(sf::RenderWindow &window) {
			ball_visible.setPosition(ball.getX(), ball.getY());
			window.draw(ball_visible);

			platform_visible.setPosition(platform.getX(), platform.getY());
			window.draw(platform_visible);

			geo::Coordinates brick = bricksCollection.getNextBrick(1);
			while (brick != geo::Coordinates(0, 0)) {
				window.draw(bricks_visible[std::make_pair(int(brick.getX()), int(brick.getY()))]);
				brick = bricksCollection.getNextBrick();
			}

		};

		Board::~Board() {
			bricks_visible.clear();
		};

}
