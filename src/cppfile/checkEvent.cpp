#include "checkEvent.h"

void checkEvent(sf::RenderWindow &window) {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			window.close();
			exit(0);
		}

	}
}

void waitToPress(sf::RenderWindow &window, const sf::Keyboard::Key &key) {
	do {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || !window.isOpen()) {
			window.close();
			exit(0);
		}
		checkEvent(window);
	} while (!sf::Keyboard::isKeyPressed(key));
}