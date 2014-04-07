#ifndef CLIENTCONNECTIONSENDING_INCLUDED
#define CLIENTCONNECTIONSENDING_INCLUDED

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "SynchronizedList.h"

class ClientConnectionSending
{
	public:
		ClientConnectionSending(SynchronizedList* o);
		~ClientConnectionSending();

		void initConnection();

		bool waitForClient();
		bool sendData();

		void connectionLoop();

	private:
		int sck;
		int clientSocket;
		int port;
		struct sockaddr_in serv_addr;
		struct sockaddr_in cli_addr;

		SynchronizedList* toSend;
};


#endif // CLIENTCONNECTIONSENDING_INCLUDED
