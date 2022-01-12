#pragma once
#include <SFML/Network.hpp>
#include <sstream>
#include <iostream>

/*!
 * Sprawdza czy dost�pna jest aktualizacja na serwerze.
 * 
 * \param version Wersja uruchomionego oprogramowania
 * \return True => aktualizacja jest dost�pna. False => nie ma aktualizacji lub brak odpowiedzi serwera.
 */
bool isAvailableUpdate(const std::string &version);