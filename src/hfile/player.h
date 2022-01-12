#pragma once

#include "platform.h"
#include "ball.h"
#include "coordinates.h"
#include "board.h"
#include <SFML/Network.hpp>
#include <string>
#include <sstream>

namespace game {
	class Player
	{
	private:
		unsigned int level = 1;
		int score = 0;
		unsigned short int life = 3;
		std::string name;
		std::string fingerPrint;
		std::string version;

	public:
		/*!
		 * Na podstawie danych z Windowsa tworzy Finger Print dla danej instalacji systemu.
		 * Zapisuje do pliku oraz zmiennej fingerPrint.
		 * 
		 * \return True => pomyœlnie utworzono i za³adowano FP. False => Nie utworzono/za³adowano FP.
		 */
		bool createFingerPrint();

		/*!
		 * Odczytuje Finger Print dla danej instalacji systemu z pliku do zmiennej fingerPrint.
		 * 
		 * \return True => pomyœlnie odczytano FP. False => Nie odczytano FP.
		 */
		bool loadFingerPrint();

		/*!
		 * Odczytuje nazwe obecnie zalogowanego u¿ytkownika Windows do zmiennej name.
		 * Je¿eli odczyt siê nie powiedzie ustawia "NoName".
		 */
		void loadWindowsName();

	public:
		/*!
		 * Konstruktor ustawia poczatkowe parametry. Odczytuje/Tworzy Finger Print.  
		 * 
		 * \param version uruchomiona wersja
		 * \param life liczba ¿yæ - domyœlnie 3
		 * \param level poziom - domyœlnie 1
		 * \param score liczba punktów - domyœlnie 0
		 * \param name nazwa gracza - domyœlnie pobierana nazwa zalogowanego u¿ytkownika
		 */
		Player(const std::string &version, unsigned int life = 3, const int level = 1, const int score = 0, const std::string &name = "");

		void setPlayerName(const std::string &name = "NoName");

		const std::string &getName() const;

		const std::string &getFingerPrint() const;

		const std::string &getVersion() const;

		int getScore() const;

		int getLevel() const;

		int getLife() const;

		void setLevel(int lev);

		void addScore(int add_score = 0);

		/*!
		 * Odejmuje jedno ¿ycie.
		 * 
		 * \return liczba ¿yæ po dekrementacji
		 */
		bool dead();

		/*!
		 * Resetuje statystyki gracza do podanych wartoœci.
		 * 
		 * \param life domyœlnie 3
		 * \param level domyœlnie 1
		 * \param score domyœlnie 0
		 */
		void resetStat(unsigned int life = 3, const unsigned int level = 1, const unsigned int score = 0);

		/*!
		 * Inkrementuje level.
		 * 
		 * \return Level po inkrementacji.
		 */
		int nextLevel();

		/*!
		 * Przesy³a wynik na serwer.
		 * 
		 * \return True => pomyœlnie przes³ano. False => Niepowodzenie, brak odpowiedzi serwera.
		 */
		bool sendScore() const;

		~Player();
	};
}