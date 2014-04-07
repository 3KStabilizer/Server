#ifndef CLIENTCONNECTION_INCLUDED
#define CLIENTCONNECTION_INCLUDED

#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>

#include "SynchronizedList.h"

class ClientConnectionReading
{
	public:
		ClientConnectionReading(SynchronizedList* o);
		~ClientConnectionReading();

		void initConnection();

		bool waitForClient();
		bool waitForDataReception();

		void connectionLoop();

	private:
		int sck;
		int clientSocket;
		int port;
		struct sockaddr_in serv_addr;
		struct sockaddr_in cli_addr;

		SynchronizedList* obj;
};

#endif // CLIENTCONNECTION_INCLUDED
