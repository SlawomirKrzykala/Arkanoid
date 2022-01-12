#define NOMINMAX

#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Audio/Music.hpp"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"
#include "update.h"
#include "Background.h"
#include "TextCenter.h"
#include "TextLabel.h"
#include "Player.h"
#include "BoardDisplay.h"
#include "keyControl.h"
#include "checkEvent.h"



int main()
{
	const std::string VERSION = "BETA 1.1.0";
	const std::string WINDOW_TITLE = "Arkanoid C6";
	const std::string BACKGROUND_PATH = "bg.jpg";
	const std::string INSTRUCTION_PATH = "instrukcja.txt";
	const std::string BACKGROUND_MUSIC_PATH = "Crypt_of_the_Necrodancer_OST-Grave_Throbbing.ogg";
	const std::string HIT_SOUND_PATH = "hit.ogg";
	

	const auto WINDOW_MODE = sf::Style::Fullscreen;
	const unsigned short FPS_MAX = 120;

	if (isAvailableUpdate(VERSION)) {
		//dostepna aktualizacja
		system("start http://arkanoid.cichy06.xyz");
		exit(0);
	}

	//pobieranie rozdzielczosci
	unsigned short widthWindow = sf::VideoMode::getDesktopMode().width;
	unsigned short heightWindow = sf::VideoMode::getDesktopMode().height;
	std::clog << "Rozdzielczosc: " << widthWindow << " x " << heightWindow << std::endl;

	//tworzenie, ustawienia okna, muzyka
	sf::RenderWindow window(sf::VideoMode(widthWindow, heightWindow), WINDOW_TITLE, WINDOW_MODE);
	window.setFramerateLimit(FPS_MAX);
	window.setVerticalSyncEnabled(1);
	window.setMouseCursorVisible(0);
	sf::Music backgroundMusic;
	backgroundMusic.openFromFile(BACKGROUND_MUSIC_PATH);
	backgroundMusic.setLoop(1);
	backgroundMusic.play();

	sf::SoundBuffer soundBuffer;
	soundBuffer.loadFromFile(HIT_SOUND_PATH);
	sf::Sound hitSound;
	hitSound.setBuffer(soundBuffer);

	//£adowanie t³a, instrukcji
	display::Background backgroundWindow(BACKGROUND_PATH, widthWindow, heightWindow);
	display::TextCenter instruction;
	instruction.loadFromFile(INSTRUCTION_PATH);
	display::TextLabel textLabel;
	display::TextCenter end_text;
	display::TextCenter nextLevel_text;


	//Tworzenie gracza, planszy
	game::Player player(VERSION);
	game::Board boardGame(geo::Coordinates(0, 0), geo::Coordinates(widthWindow, heightWindow));
	display::Board boardDisplay(boardGame);

	//Intro
	window.clear();
	window.draw(backgroundWindow);
	boardDisplay.draw(window);
	instruction.draw(window);
	window.display();

	waitToPress(window, sf::Keyboard::Space);//czekam na spacje

	while (true) { //while po poziomach

		//£adowanie poziomu
		boardGame.loadLevel(player.getLevel());
		boardDisplay.loadBoard();
		waitToPress(window, sf::Keyboard::Space);//czekam na spacje

		do {//rozgrywka na danym poziomie
			window.clear();
			window.draw(backgroundWindow);
			boardGame.reset();
			textLabel.draw(window, player);
			boardDisplay.draw(window);
			window.display();

			waitToPress(window, sf::Keyboard::Space);//czekam na spacje
			boardGame.normalizeSpeed();

			while (boardGame.ballAlive() && boardGame.getSizeBricks()) {//rozgrywka	na danym ¿yciu	
				//sterowanie, mechanika gry
				int add_score = boardGame.nextFrame(keyControl(window, boardGame, instruction));
				player.addScore(add_score);
				if(add_score)	
					hitSound.play();
				
				//wyswietlanie 
				window.clear();
				window.draw(backgroundWindow);
				textLabel.draw(window, player);
				boardDisplay.draw(window);
				window.display();
			}
			if (boardGame.getSizeBricks())
				player.dead();
		} while (boardGame.getSizeBricks() && player.getLife());


		if (player.getLife() && player.getLevel() < 6) {//strata pilki
			nextLevel_text.loadString(std::string("Next Level!\n" + textLabel.getLabel(player) + "\nAby kontynuowac nacisnij spacje"));
			nextLevel_text.draw(window);
			window.display();
			waitToPress(window, sf::Keyboard::Space);//czekam na spacje
			player.nextLevel();
			continue;
		}
		else {//koniec gry
			player.sendScore();
			end_text.loadString(std::string("Rly? End Game! \n" + textLabel.getLabel(player) + "\n Aby rozpoczac nowa gre nacisnij spacje"));
			end_text.draw(window);
			window.display();
			waitToPress(window, sf::Keyboard::Space);//czekam na spacje
			player.resetStat();
		}
	}

	return 0;
}