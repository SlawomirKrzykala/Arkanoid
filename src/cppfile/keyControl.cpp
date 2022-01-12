#include "keyControl.h"


geo::Vector keyControl(sf::RenderWindow &window, game::Board &boardGame, const display::TextCenter &instruction) {
	checkEvent(window);
	geo::Vector direction_move_platform(AutoControl::getMovePlatform(boardGame.getBall(), boardGame.getPlatform()));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		window.close();
		exit(0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
		waitToPress(window, sf::Keyboard::Space);//czekam na spacje
		boardGame.normalizeSpeed();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
		instruction.draw(window);
		window.display();
		waitToPress(window, sf::Keyboard::Space);//czekam na spacje
		boardGame.normalizeSpeed();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		direction_move_platform.setX(1.0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		direction_move_platform.setX(-1.0);

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) && sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) && sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		AutoControl::enable();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		AutoControl::disable();
	return direction_move_platform;
}