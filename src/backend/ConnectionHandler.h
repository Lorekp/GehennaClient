#ifndef CONNECTIONHANDLER_H
#define CONNECTIONHANDLER_H

#include <string>
#include <assert.h>
#include <SFML/Network.hpp>
#include <iostream>
#include <thread>
#include <fstream>

class ConnectionHandler {

public:

	ConnectionHandler();
	~ConnectionHandler();

	static ConnectionHandler* getInstance()
	{
		if (sInstance == nullptr)
		{
			sInstance = new ConnectionHandler();
		}
		return sInstance;
	}

private:

	//Connection Handler is a singleton, so only one instance can exist at a time 
	//sInstacne holds a static pointer to the single manager instance static ConnectionHandler* sInstance;

	static ConnectionHandler* sInstance;

	const unsigned short PORT;
	const std::string IPADDRESS;
	sf::TcpSocket socket;
	std::thread* receiveThread;
	std::thread* connectToServerThread;
	std::thread* updateThread;

	void receiveMessages();
	void connectToServer();
	void update();

	bool connected;
};
#endif