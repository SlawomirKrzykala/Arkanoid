#pragma once
#include <SFML/graphics.hpp>
/*!
 * Obs³uguje wydarzenia dotycz¹ce okna.
 * 
 * \param window okno windowsa
 */
void checkEvent(sf::RenderWindow &window);

/*!
 * Czeka na wciœniêciê podanego klawisza
 *
 * \param window okno windowsa
 * \param key typ klawisza do wciœniêcia, typ wg SFML
 */
void waitToPress(sf::RenderWindow &window, const sf::Keyboard::Key &key);