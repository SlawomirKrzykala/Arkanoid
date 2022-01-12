#pragma once
#include <SFML/graphics.hpp>
/*!
 * Obs�uguje wydarzenia dotycz�ce okna.
 * 
 * \param window okno windowsa
 */
void checkEvent(sf::RenderWindow &window);

/*!
 * Czeka na wci�ni�ci� podanego klawisza
 *
 * \param window okno windowsa
 * \param key typ klawisza do wci�ni�cia, typ wg SFML
 */
void waitToPress(sf::RenderWindow &window, const sf::Keyboard::Key &key);