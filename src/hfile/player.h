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
		 * \return True => pomy�lnie utworzono i za�adowano FP. False => Nie utworzono/za�adowano FP.
		 */
		bool createFingerPrint();

		/*!
		 * Odczytuje Finger Print dla danej instalacji systemu z pliku do zmiennej fingerPrint.
		 * 
		 * \return True => pomy�lnie odczytano FP. False => Nie odczytano FP.
		 */
		bool loadFingerPrint();

		/*!
		 * Odczytuje nazwe obecnie zalogowanego u�ytkownika Windows do zmiennej name.
		 * Je�eli odczyt si� nie powiedzie ustawia "NoName".
		 */
		void loadWindowsName();

	public:
		/*!
		 * Konstruktor ustawia poczatkowe parametry. Odczytuje/Tworzy Finger Print.  
		 * 
		 * \param version uruchomiona wersja
		 * \param life liczba �y� - domy�lnie 3
		 * \param level poziom - domy�lnie 1
		 * \param score liczba punkt�w - domy�lnie 0
		 * \param name nazwa gracza - domy�lnie pobierana nazwa zalogowanego u�ytkownika
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
		 * Odejmuje jedno �ycie.
		 * 
		 * \return liczba �y� po dekrementacji
		 */
		bool dead();

		/*!
		 * Resetuje statystyki gracza do podanych warto�ci.
		 * 
		 * \param life domy�lnie 3
		 * \param level domy�lnie 1
		 * \param score domy�lnie 0
		 */
		void resetStat(unsigned int life = 3, const unsigned int level = 1, const unsigned int score = 0);

		/*!
		 * Inkrementuje level.
		 * 
		 * \return Level po inkrementacji.
		 */
		int nextLevel();

		/*!
		 * Przesy�a wynik na serwer.
		 * 
		 * \return True => pomy�lnie przes�ano. False => Niepowodzenie, brak odpowiedzi serwera.
		 */
		bool sendScore() const;

		~Player();
	};
}