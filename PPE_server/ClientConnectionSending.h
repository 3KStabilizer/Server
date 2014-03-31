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

/**
 * @brief provide method to connect to the client for sending purpose
 *
 */
class ClientConnectionSending
{
	public:
        /**
         * @brief main constructor
         * @param o pointer on list of data to send
         */
		ClientConnectionSending(SynchronizedList* o);
        /**
         * @brief main destructor
         *
         */
        ~ClientConnectionSending();

        /**
         * @brief initialize all the parameters for connection
         *
         */
        void initConnection();

        /**
         * @brief wait for a client to connect
         *
         * @return bool return true on connection
         */
        bool waitForClient();
        /**
         * @brief send data to client
         *
         * @return bool true when finish
         */
        bool sendData();

        /**
         * @brief call the previous function to assure the entire connection process
         *
         */
        void connectionLoop();

	private:
        int sck; /**< socket of the server */
        int clientSocket; /**< socket of the connected client */
        int port; /**< port */
        struct sockaddr_in serv_addr; /**< address of the server */
        struct sockaddr_in cli_addr; /**< address of the client */

        SynchronizedList* toSend; /**< list of data to send */
};


#endif // CLIENTCONNECTIONSENDING_INCLUDED
