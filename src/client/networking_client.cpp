//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#include "networking_client.h"
#include "player.h"
#include "base.h"

#include <iostream>
#include <winsock2.h>

void SendPosition(CPlayer& player)
{
	WSADATA WSAData;
	SOCKET server;
	SOCKADDR_IN addr;

	WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);

	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(5555);

	connect(server, (SOCKADDR *)&addr, sizeof(addr));
	std::cout << "Connected to server!" << std::endl;

	char buffer[1024];
	str_format(buffer, sizeof(buffer), "%d", player.PosX);

	send(server, buffer, sizeof(buffer), 0);
	std::cout << "send: " << buffer << std::endl;
	std::cout << "Message sent!" << std::endl;

	closesocket(server);
	WSACleanup();
	std::cout << "Socket closed." << std::endl << std::endl;
}