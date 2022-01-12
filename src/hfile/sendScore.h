#pragma once

#include <SFML/Network.hpp>
#include <sstream>
#include <iostream>
#include "player.h"

void sendScore(const game::Player &game_player)
{
	const std::string REQUEST_SERVER = "http://www.arkanoid.cichy06.xyz";
	const std::string REQUEST_PATH = "/addScore.php";
	sf::Http::Request request(REQUEST_PATH, sf::Http::Request::Post);

	std::clog << "Wysylanie wynikow" << std::endl;;

	std::ostringstream stream;
	stream << "name=" << game_player.getName() << "&score=" << game_player.getScore() << "&level=" << game_player.getLevel() << "&finger_print=" << game_player.getFingerPrint() << "&ver=" << game_player.getVersion();

	request.setBody(stream.str());
	//std::clog << stream.str();

	sf::Http http("http://www.arkanoid.cichy06.xyz");
	for (int i = 0; i < 3; i++) {
		std::clog << "Proba [" << i + 1 << "] - ";
		sf::Http::Response response = http.sendRequest(request);
		if (response.getStatus() == sf::Http::Response::Ok)
		{
			std::clog <<"Odpowiedz serwera:"<<  response.getBody() << std::endl;
			break;
		}
		else
		{
			std::clog << " Brak odpowiedzi serwera" << std::endl;
		}
	}
}
