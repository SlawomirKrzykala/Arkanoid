#pragma once
#include <SFML/graphics.hpp>
#include <string>
#include "player.h"
namespace display {
	class TextLabel
	{
	private:

		sf::Font font;
		//sf::Text txt_fps;
		//sf::Text txt_cord_ball = sf::Text();
		sf::Text txt_info;

	public:

		TextLabel();

		void draw(sf::RenderWindow &window, const game::Player &player);
		
		std::string getLabel(const game::Player &player) const;
		
		~TextLabel();
	};
}
