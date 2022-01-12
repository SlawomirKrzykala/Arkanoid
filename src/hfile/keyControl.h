#pragma once
#include "SFML/graphics.hpp"
#include "vector.h"
#include "TextCenter.h"
#include "Board.h"
#include "AutoControl.h"
#include "checkEvent.h"

/*!
 * Obs³uguje klawisze wciœniete przez uzytkownika
 * 
 * \param window okno windows
 * \param boardGame obiekt gry
 * \param instruction obiekt tekstu instrukcji
 * \return wektor ruchu platformy
 */
geo::Vector keyControl(sf::RenderWindow &window, game::Board &boardGame, const display::TextCenter &instruction);