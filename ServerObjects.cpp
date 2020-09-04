#include "ServerObjects.h"


/*
	Implementation file for serverObjects namespace objects
*/

namespace ServerObjects {


		/*  Class DataServer  */
	unsigned short DataServer::MAX_PORT = 32765;

	/*  Private Methods  */

	void DataServer::checkNewGames()
	{
		/*
			Check for new Game requests sent by clients
			to the server to list and online, multiplayer
			game
		*/

		//Check for signal on nonblocking socket, if no
		//response, then return
		sf::Packet pkt;
		sf::IpAddress sender;
		unsigned short port;

		if (newGameSocket.receive(pkt, sender, port) 
			!= sf::Socket::Done) {
			cout << "socket NOT done, returning" << endl;
			return;
		}

		cout << "socket done, proceeding to add game" << endl;
		addGame(pkt);

	}


	void DataServer::addGame(const sf::Packet& toAdd)
	{
	}

	void DataServer::deleteGame(const std::string gameCode)
	{
	}

	void DataServer::pollEvents()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			cout << "Exiting program\n";
			runServer = false;
		}
	}

	/*  Constructors  */
	DataServer::DataServer()
	{
		runServer = true;

		//Set port values
		recPort = 5500;
		sendPort = 3001;

		//bind sockets
		newGameSocket.bind(5500);
		newGameSocket.setBlocking(false);
	}

	/*  Public Methods  */

	void DataServer::update()
	{
		checkNewGames();
		pollEvents();
	}

	bool DataServer::isRunning() {
		return runServer;
	}




	/*  Destructors  */
	DataServer::~DataServer()
	{
	}

}