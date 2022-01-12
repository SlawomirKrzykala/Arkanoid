#include "player.h"

namespace game {

		bool Player::createFingerPrint() {
			std::system("@reg query \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\" /v ProductID > %appdata%\\ID_ArkanoidC6.c6");
			std::string filePath;
			#pragma warning(suppress : 4996)
			filePath = getenv("APPDATA");
			filePath += "\\ID_ArkanoidC6.c6";
			std::fstream file(filePath, std::ios::in);
			if (file.good()) {
				std::string idKey;
				file.seekg(-28, std::ios_base::end);
				file >> idKey;
				file.close();
				fingerPrint = idKey;

				std::fstream file2(filePath, std::ios::out | std::ios::trunc);
				if (file2.good()) {
					file2 << idKey;
					file2.close();
					std::clog << "Utworzono i zaladowano finger print: " << fingerPrint << std::endl;
					return 1;
				}
				else {
					std::clog << "Blad podczas ladowania finger print: " << fingerPrint << std::endl;
					return 0;
				}
			}

			std::clog << "Blad podczas tworzenia finger print: " << fingerPrint << std::endl;
			return 0;
		}

		bool Player::loadFingerPrint() {
			std::string file_path;
			#pragma warning(suppress : 4996)
			file_path = getenv("APPDATA");
			file_path += "\\ID_ArkanoidC6.c6";
			std::fstream file(file_path, std::ios::in);
			if (file.good()) {
				file >> fingerPrint;
				std::clog << "Zaladowano finger print: " << fingerPrint << std::endl;
				return 1;
			}

			std::clog << "Blad podczas ladowania finger print: " << fingerPrint << std::endl;
			return 0;
		}

		void Player::loadWindowsName() {
			#pragma warning(suppress : 4996)
			char * winName = getenv("USERNAME");
			winName == NULL ? name = std::string("NoName") : name = std::string(winName);
			std::clog << "Wczytano nazwe gracza: " << name << std::endl;
		}

		Player::Player(const std::string &version, unsigned int life, const int level, const int score, const std::string &name) : version(version), life(life), level(level), score(score), name(name) {
			if (!loadFingerPrint()) {
				createFingerPrint();
			}
			if (name == "") {
				loadWindowsName();
			}
		}

		void Player::setPlayerName(const std::string &name) {
			this->name = name;
		}

		const std::string& Player::getName() const {
			return name;
		}

		const std::string& Player::getFingerPrint() const {
			return fingerPrint;
		}

		const std::string& Player::getVersion() const {
			return version;
		}

		int Player::getScore() const {
			return score;
		}

		int Player::getLevel() const {
			return level;
		}

		int Player::getLife() const {
			return life;
		}

		void Player::setLevel(int lev) {
			level = lev;
		}

		void Player::addScore(int add_score) {
			score += add_score;
		}

		bool Player::dead() {
			return --life;
		}

		void Player::resetStat(unsigned int life, const unsigned int level, const unsigned int score) {
			this->life = life;
			this->level = level;
			this->score = score;
		}

		int Player::nextLevel() {
			return ++level;
		}

		bool Player::sendScore() const {
			const std::string REQUEST_SERVER = "http://www.arkanoid.cichy06.xyz";
			const std::string REQUEST_PATH = "/addScore.php";
			sf::Http::Request request(REQUEST_PATH, sf::Http::Request::Post);

			std::clog << "Wysylanie wynikow" << std::endl;;

			std::ostringstream stream;
			stream << "name=" << getName() << "&score=" << getScore() << "&level=" << getLevel() << "&finger_print=" << getFingerPrint() << "&ver=" << getVersion();

			request.setBody(stream.str());

			sf::Http http("http://www.arkanoid.cichy06.xyz");
			for (int i = 0; i < 3; i++) {
				std::clog << "Proba [" << i + 1 << "] - ";
				sf::Http::Response response = http.sendRequest(request);
				if (response.getStatus() == sf::Http::Response::Ok)
				{
					std::clog << "Odpowiedz serwera:" << response.getBody() << std::endl;
					return 1;
				}
				else
				{
					std::clog << " Brak odpowiedzi serwera" << std::endl;
				}
			}

			return 0;
		}

		Player::~Player() {};

}