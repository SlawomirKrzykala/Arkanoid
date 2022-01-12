#include "background.h"

namespace display {

		bool Background::loadFromFile(const std::string &fileName, const unsigned int width, const unsigned int height) {
			if (texture.loadFromFile(fileName)) {
				sf::Vector2u size = texture.getSize();
				setTexture(texture);
				setScale((float)width / size.x, (float)height / size.y);
				std::clog << "Zaladowano background: " << fileName << std::endl;
				return 1;
			}
			return 0;
			std::clog << "Blad ladowania background: " << fileName << std::endl;
		}
		Background::Background(const std::string &filePath, const unsigned int width, const unsigned int height) {
			loadFromFile(filePath, width, height);
		}
		Background::~Background() {};
	
}