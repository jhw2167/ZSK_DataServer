#include "main.h"

/*
	Implementation file for main.h of ZSK_DataServer
*/


int main(int v, char* c[]) {
	/*
		Main method initiates server wrapper
	*/
	
	//Init DataServer
	ServerObjects::DataServer server;

	std::cout << "Starting up server in main\n";

	std::cout << "My public IP: " <<
		sf::IpAddress::getPublicAddress() << std::endl;
	std::cout << "My local IP: " <<
		sf::IpAddress::getLocalAddress() << std::endl;

	while (server.isRunning()){

		server.update();
	}
	
	return EXIT_SUCCESS;
}

