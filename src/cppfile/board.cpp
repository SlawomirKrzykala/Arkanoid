#include "board.h"

namespace game {

		Board::Board(geo::Coordinates begin_board, geo::Coordinates end_board) :
			default_ball(geo::Circle(end_board.getX() / 2.0, end_board.getY() / 1.6, 10.0)),
			game_ball(default_ball),
			default_platform(geo::Rectangle(geo::Coordinates(end_board.getX() / 2.0, end_board.getY()* 0.9), end_board.getX() / 10.0, end_board.getY() / 60.0), 4),
			game_platform(default_platform),
			brick_collection(end_board), begin_board(begin_board), end_board(end_board) {
			loadLevel(-1);
		};

		void Board::loadLevel(const int lev) {
			if (!brick_collection.loadBricks("p" + std::to_string(lev) + ".c6"))
				brick_collection.loadDefaultBricks();
			default_ball.setSpeed(lev*0.5 + 3);
			reset();
		}

		void Board::reset() {
			game_ball = default_ball;
			game_platform = default_platform;
			clock.restart();
		}

		int Board::nextFrame(geo::Vector direction_move_platform) {
			normalizeSpeed();
			game_ball.move(begin_board, end_board);
			game_platform.setDirection(direction_move_platform);
			game_platform.move(begin_board, end_board);

			geo::Vector platform_collision_vector = game_platform.checkCollision(game_ball);
			if (platform_collision_vector != geo::Vector(0, 0)) {
				game_ball.setY(game_platform.getY() - game_ball.getR() - game_platform.getHeigth() / 2.0); //redukcja Y do postaci w³aœciwej(poza platforme) po odbiciu
				game_ball.setDirection(platform_collision_vector + direction_move_platform);
			}

			geo::Vector brick_collision_vector = brick_collection.checkCollision(game_ball);
			if (brick_collision_vector != geo::Vector(0, 0)) {
				game_ball.setDirection(brick_collision_vector);
				return 10;
			}
			return 0;
		}

		bool Board::ballAlive() const {
			return 2 * game_ball.getR() < (end_board.getY() - game_ball.getY());
		}

		void Board::normalizeSpeed() {
			double ratio_speed = clock.getElapsedTime().asMilliseconds() / 6.6;
			game_ball.setSpeed(default_ball.getSpeed()*ratio_speed);
			game_platform.setSpeed(default_ball.getSpeed()*ratio_speed);
			clock.restart();
		}

		const Ball& Board::getBall() const {
			return game_ball;
		}
		const Platform& Board::getPlatform() const {
			return game_platform;
		}
		const BrickCollection& Board::getBrickCollection() const {
			return brick_collection;
		}
		int Board::getSizeBricks() const {
			return brick_collection.getSize();
		}
		Board::~Board() {};

}