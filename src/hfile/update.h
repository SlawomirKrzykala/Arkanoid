#pragma once
#include <SFML/Network.hpp>
#include <sstream>
#include <iostream>

/*!
 * Sprawdza czy dostêpna jest aktualizacja na serwerze.
 * 
 * \param version Wersja uruchomionego oprogramowania
 * \return True => aktualizacja jest dostêpna. False => nie ma aktualizacji lub brak odpowiedzi serwera.
 */
bool isAvailableUpdate(const std::string &version);