#pragma once
#include <string>
#include <iostream>
#include <SFML/graphics.hpp>



namespace display {
	/*!
	 * T³o z skalowaniem, dziedziczenie z SFML 
	 * 
	 */
	class Background : public sf::Sprite
	{
		sf::Texture texture;

	public:
		/*!
		 *
		 *
		 * \param filePath Nazwa pliku graficznego do wczytania.
		 * \param width Szerokoœæ do jakiej ma byæ przeskalowany.
		 * \param height Wysokoœæ do jakiej ma byæ przeskalowany.
		 */
		Background(const std::string &filePath, const unsigned int width, const unsigned int height);

		~Background();

		/*!
		 * Konstruktor ³aduje i skaluje plik graficzny do daych rozmiarów.
		 * 
		 * \param fileName Nazwa pliku graficznego do wczytania.
		 * \param width Szerokoœæ do jakiej ma byæ przeskalowany.
		 * \param height Wysokoœæ do jakiej ma byæ przeskalowany.
		 * \return True => za³adowano pomyœlnie. False => B³ad ³adowania.
		 */
		bool loadFromFile(const std::string &fileName, const unsigned int width, const unsigned int height);

	};
}