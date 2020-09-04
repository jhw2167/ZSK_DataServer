#pragma once

#include "BaseCode/pch/stdafx.h"
#include "Game/NetworkFiles/NetworkObjects.h"

//using
using NetworkObjects::ipBundle;

/*
	ServerObjects namespace will hold our primary dataServer 
	class and will:
	- check for incoming connections on a series of ports
	- reroute the data to the client and host parties
	- handle adding and deleting games from the list
*/

namespace ServerObjects
{
	struct listedGame {
		sf::IpAddress hostIP;
		std::string gameCode;

		bool publicGame;
		short maxPlayers;
		std::vector<ipBundle> players;

		//Networking
		unsigned int sendPort;
		unsigned int recPort;
		sf::UdpSocket socket;

		listedGame(sf::IpAddress& host, std::string code,
			bool pubGame = true, short maxPlayer = 4,
			unsigned short send = 5000,
			unsigned short rec = 5000) :
			hostIP(host), gameCode(code),
			publicGame(pubGame), sendPort(send),
			recPort(rec)
		{

		}
	};


	class DataServer {

	private:

		//Fundamental variables
		long int numGames;
		std::vector<listedGame> games;
		bool runServer;

		//Sockets
		static unsigned short MAX_PORT;
		sf::UdpSocket newGameSocket;

		//Ports along which newGame requests will be sent
		unsigned short sendPort;
		unsigned short recPort;
		

		//Ports along which newGame requests will be sent
		unsigned short first_updateGamePort;
		unsigned short end_updateGamePort;


		/*  Private Methods  */
		void checkNewGames();
		void addGame(const sf::Packet& toAdd);
		void deleteGame(const std::string gameCode);

		/*  Maintenance  */
		void pollEvents();

	public:

			/*  Constructors  */
		DataServer();

		/*  Fundamental public functions  */
		void update();
		bool isRunning();
		

		~DataServer();

	};
}

