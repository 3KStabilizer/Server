#ifndef CLIENTCONNECTION_INCLUDED
#define CLIENTCONNECTION_INCLUDED

#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>

#include "SynchronizedList.h"

/**
 * @brief Class which provide connection with the client to read the data sent
 */

class ClientConnectionReading
{
	public:
        /**
         * @brief main constructor
         * @param o pointer on list where data received will be stored
         */
        ClientConnectionReading(SynchronizedList* o);

        /**
         * @brief main destructor
         *
         */
        ~ClientConnectionReading();

        /**
         * @brief initialize all the variable for connection
         */
        void initConnection();

        /**
         * @brief loop to wait for a client to connect
         * @return true on success
         */
        bool waitForClient();
        /**
         * @brief loop which reads the data receive by the servr
         * @return true when function ends
         */
        bool waitForDataReception();

        /**
         * @brief call the previous function to assure the entire connection process
         */
        void connectionLoop();

	private:
        int sck; /**< socket of the server */
        int clientSocket; /**< socket of the client */
        int port; /**< port */
        struct sockaddr_in serv_addr; /**< address of the server */
        struct sockaddr_in cli_addr; /**< address of the client */

        SynchronizedList* obj; /**< list where all the data received are stored */
};

#endif // CLIENTCONNECTION_INCLUDED
