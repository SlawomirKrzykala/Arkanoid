#pragma once
#include <SFML/graphics.hpp>
#include "checkEvent.h"
/*!
 * Czeka na wci�ni�ci� podanego klawisza
 * 
 * \param window okno windowsa
 * \param key typ klawisza do wci�ni�cia, typ wg SFML
 */
void waitToPress(sf::RenderWindow &window, const sf::Keyboard::Key &key) {
	do {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || !window.isOpen()) {
			window.close();
			exit(0);
		}
		checkEvent(window);
	} while (!sf::Keyboard::isKeyPressed(key));
}