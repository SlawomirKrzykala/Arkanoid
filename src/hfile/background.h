#pragma once
#include <string>
#include <iostream>
#include <SFML/graphics.hpp>



namespace display {
	/*!
	 * T�o z skalowaniem, dziedziczenie z SFML 
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
		 * \param width Szeroko�� do jakiej ma by� przeskalowany.
		 * \param height Wysoko�� do jakiej ma by� przeskalowany.
		 */
		Background(const std::string &filePath, const unsigned int width, const unsigned int height);

		~Background();

		/*!
		 * Konstruktor �aduje i skaluje plik graficzny do daych rozmiar�w.
		 * 
		 * \param fileName Nazwa pliku graficznego do wczytania.
		 * \param width Szeroko�� do jakiej ma by� przeskalowany.
		 * \param height Wysoko�� do jakiej ma by� przeskalowany.
		 * \return True => za�adowano pomy�lnie. False => B�ad �adowania.
		 */
		bool loadFromFile(const std::string &fileName, const unsigned int width, const unsigned int height);

	};
}