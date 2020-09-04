#include "main.h"

/*
	Implementation file for main.h of ZSK_DataServer
*/


int main(int v, char* c[]) {
	/*
		Main method initiates server wrapper
	*/
	// Choose an arbitrary port for opening sockets
	unsigned short port = 50000;

	// TCP, UDP or connected UDP ?
	char protocol;
	std::cout << "Do you want to use TCP (t) or UDP (u)? ";
	std::cin >> protocol;

	std::cout << "My public IP: " <<
		sf::IpAddress::getPublicAddress() << std::endl;
	std::cout << "My local IP: " <<
		sf::IpAddress::getLocalAddress() << std::endl;

	// Client or server ?
	char who;
	std::cout << "Do you want to be a server (s) or a client (c)? \n";
	std::cin >> who;

	std::cout << "What port to use?\n";
	std::cin >> port;
	std::cout << "Port is: " << port << "\n\n";

	if (protocol == 't')
	{
		// Test the TCP protocol
		if (who == 's')
			runTcpServer(port);
		else
			runTcpClient(port);
	}
	else
	{
		// Test the unconnected UDP protocol
		if (who == 's')
			runUdpServer(port);
		else
			runUdpClient(port);
	}

	// Wait until the user presses 'enter' key
	std::cout << "Press enter to exit..." << std::endl;
	std::cin.ignore(10000, '\n');
	std::cin.ignore(10000, '\n');

	return EXIT_SUCCESS;

	getchar();
}

