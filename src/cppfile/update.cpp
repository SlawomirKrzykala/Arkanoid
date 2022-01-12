#include "update.h"

bool isAvailableUpdate(const std::string &version) {
	const std::string SERVER_REQUEST = "http://www.arkanoid.cichy06.xyz";
	const std::string PATH_REQUEST = "/checkVersion.php";

	sf::Http::Request request(PATH_REQUEST, sf::Http::Request::Post);

	std::ostringstream stream;
	stream << "version=" << version;

	request.setBody(stream.str());
	std::clog << "Sprawdzanie aktualizacji" << std::endl;;

	sf::Http http(SERVER_REQUEST);
	for (int i = 0; i < 3; i++) {
		std::clog << "Proba [" << i + 1 << "] - ";
		sf::Http::Response response = http.sendRequest(request);
		if (response.getStatus() == sf::Http::Response::Ok)
		{
			std::clog << "Odpowiedz serwera: " << response.getBody();
			if (response.getBody() == version) {
				std::clog << " - Brak dostepnej aktualizcji" << std::endl;
				return 0; //nie ma aktualizacji
			}
			else {
				std::clog << " - Jest dostepna aktualizcji" << std::endl;
				return 1; //jest aktualizacja
			}
			break;
		}
		else
		{
			std::clog << " Brak odpowiedzi serwera" << std::endl;
		}
	}
	return 0; //Brak odpowiedzi // throw
}