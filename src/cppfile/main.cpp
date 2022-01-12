#define NOMINMAX
#include "board.h"
#include "SFML/graphics.hpp"
#include "rectangle.h"
#include <string>
#include "boardDisplay.h"
#include "textLabel.h"
#include "textCenter.h"

#include "player.h"
#include"waitToPress.h"
#include"sendScore.h"
#include "background.h"
#include "checkEvent.h"

int main()
{
	game::board game_board(geo::coordinates(0, 0), geo::coordinates(width, height));
	game_board.loadLevel(-1);
	display::board display_board(game_board);
	display_board.draw(window_game);

	//czekanie na akcje uzytkownika spacja=rozpoczecie
	waitToPress(window_game, sf::Keyboard::Space);//czekam na spacje

	//
	display::textLabel display_textLabel;

	while (game_player.getLevel() < 6 && window_game.isOpen()) {//while po poziomach
		game_board.loadLevel(game_player.getLevel());
		display_board.loadBoard();
		geo::vector direction_move_platform(0.0, 0.0);

		waitToPress(window_game, sf::Keyboard::Space);//czekam na spacje

		do {
			window_game.clear();
			bg.draw(window_game);

			game_board.reset();
			display_textLabel.draw(window_game, game_player);
			display_board.draw(window_game);
			window_game.display();

			waitToPress(window_game, sf::Keyboard::Space);//czekam na spacje
			game_board.normalize_speed();

			while (game_board.ballAlive() && game_board.getSizeBricks() && window_game.isOpen()) {
				checkEvent(window_game);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					window_game.close();
					return 0;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
					waitToPress(window_game, sf::Keyboard::Space);//czekam na spacje
					game_board.normalize_speed();
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
					game_instruction.draw(window_game);
					window_game.display();
					waitToPress(window_game, sf::Keyboard::Space);//czekam na spacje
					game_board.normalize_speed();
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
					direction_move_platform.setX(1.0);
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
					direction_move_platform.setX(-1.0);
				else
					direction_move_platform.setX(0.0);

				//if (!window_game.hasFocus())
					//window_game.requestFocus();
				//window_game.setVisible(1);

				game_player.addScore(game_board.nextFrame(direction_move_platform));

				window_game.clear();
				bg.draw(window_game);

				display_textLabel.draw(window_game, game_player);
				display_board.draw(window_game);
				window_game.display();
			}
			if (game_board.getSizeBricks())
				game_player.dead();
		} while (game_board.getSizeBricks() && game_player.getLife() && window_game.isOpen());

		if (game_player.getLife() && game_player.getLevel() < 6) {
			display::textCenter nextLevel_text;
			nextLevel_text.loadString(std::string("Next Level!\n" + display_textLabel.getLabel(game_player) + "\nAby kontynuowac nacisnij spacje"));
			nextLevel_text.draw(window_game);
			window_game.display();
			waitToPress(window_game, sf::Keyboard::Space);//czekam na spacje
			game_player.nextLevel();
			continue;
		}
		else {
			display::textCenter end_text;
			//sendScore(game_player.getName(), game_player.getScore(), game_player.getLevel());
			if (game_player.getLevel() == 6)
				game_player.setLevel(999);

			sf::Thread thread(&sendScore, game_player);
			thread.launch();

			end_text.loadString(std::string("Rly? End Game! \n" + display_textLabel.getLabel(game_player) + "\n Aby rozpoczac nowa gre nacisnij spacje"));
			end_text.draw(window_game);
			window_game.display();
			waitToPress(window_game, sf::Keyboard::Space);//czekam na spacje
			game_player.reset();
		}
	}
	return 0;
}