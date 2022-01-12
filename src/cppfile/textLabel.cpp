#include "textLabel.h"

namespace display {

	TextLabel::TextLabel() {
			if (!font.loadFromFile("joystix_monospace.ttf"))
				font.loadFromFile("arial.ttf");

			//txt_fps.setFont(font);
			//txt_fps.setCharacterSize(12);
			//txt_fps.setStyle(sf::Text::Bold);
			//txt_fps.setFillColor(sf::Color::Red);
			//txt_fps.setPosition(6, sf::VideoMode::getDesktopMode().height - 24);

			//txt_cord_ball.setFont(font);
			//txt_cord_ball.setCharacterSize(12);
			//txt_cord_ball.setStyle(sf::Text::Bold);
			//txt_cord_ball.setFillColor(sf::Color::Red);
			//txt_cord_ball.setPosition(0, sf::VideoMode::getDesktopMode().height - 24);

			txt_info.setFont(font);
			txt_info.setCharacterSize(16);
			txt_info.setStyle(sf::Text::Bold);
			txt_info.setFillColor(sf::Color::Red);
			txt_info.setPosition(6, 0);
		};

		void TextLabel::draw(sf::RenderWindow &window, const game::Player &player) {
			txt_info.setString(player.getName() + "\t" + "Life: " + std::to_string(player.getLife()) + "\t" + "Level: " + std::to_string(player.getLevel()) + "\t" + "Score: " + std::to_string(player.getScore()));

			window.draw(txt_info);
		}

		std::string TextLabel::getLabel(const game::Player &player) const {
			return player.getName() + "\t" + "Life: " + std::to_string(player.getLife()) + "\t" + "Level: " + std::to_string(player.getLevel()) + "\t" + "Score: " + std::to_string(player.getScore());
		}
		TextLabel::~TextLabel() {};

}
