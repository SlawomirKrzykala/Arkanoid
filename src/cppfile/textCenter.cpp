#include "textCenter.h"

namespace display {

		void TextCenter::addCreatedBy() {
			created_by.setString("ArkanoidC6 BETA 1.0.3 created by Slawomir Krzykala");
			created_by.setFont(font);
			created_by.setCharacterSize(24);
			created_by.setStyle(sf::Text::Bold);
			created_by.setFillColor(sf::Color::Red);
			sf::FloatRect textRect2 = created_by.getLocalBounds();
			created_by.setOrigin(textRect2.left + textRect2.width,
				textRect2.top + textRect2.height);
			created_by.setPosition(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
		}

		void TextCenter::setProp() {
			txt.setFont(font);
			txt.setCharacterSize(48);
			txt.setStyle(sf::Text::Bold);
			txt.setFillColor(sf::Color::Red);
			sf::FloatRect textRect = txt.getLocalBounds();
			txt.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			txt.setPosition(sf::VideoMode::getDesktopMode().width *0.5, sf::VideoMode::getDesktopMode().height*0.4);
		}

		TextCenter::TextCenter() {
			if (!font.loadFromFile("joystix_monospace.ttf"))
				font.loadFromFile("arial.ttf");
			addCreatedBy();
		}

		bool TextCenter::loadFromFile(const std::string &fileName) {
			std::string str_txt;
			std::fstream file(fileName, std::ios::in);
			if (file.good()) {
				std::getline(file, str_txt, (char)-1);
			}
			else {
				std::clog << "Blad wczytywania pliku: " << fileName << std::endl;
				return false;
			}

			txt.setString(str_txt);
			setProp();
			std::clog << "Wczytano plik: " << fileName << std::endl;
			return true;
		}

		void TextCenter::loadString(const std::string str) {
			txt.setString(str);
			setProp();
		}

		void TextCenter::draw(sf::RenderWindow &window) const {
			window.draw(txt);
			window.draw(created_by);
		}

		TextCenter::~TextCenter() {};
}