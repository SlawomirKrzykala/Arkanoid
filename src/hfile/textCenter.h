#pragma once
#include <iostream>
#include<string>
#include <SFML/graphics.hpp>
#include <fstream>

namespace display {
	class TextCenter
	{
	private:
		sf::Font font;
		sf::Text txt;
		sf::Text created_by;

		void addCreatedBy();

		void setProp();

	public:

		TextCenter();

		bool loadFromFile(const std::string &fileName);

		void loadString(const std::string str);

		void draw(sf::RenderWindow &window) const;

		~TextCenter();
	};
}