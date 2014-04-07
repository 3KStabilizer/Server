#include <iostream>

#include <pthread.h>
#include "ClientConnection.h"

static void* receivingThread (void * p_data)
{
	SynchronizedList* queue = (SynchronizedList*)p_data;
	ClientConnection client(queue);
	client.connectionLoop();

	return NULL;
}

class Server
{
	public:
		Server()
		{
			actions = new SynchronizedList();
		}
		~Server()
		{
			delete actions;
		}

		void executionLoop()
		{
			pthread_t client;
			pthread_create(&client,NULL,receivingThread,actions);
			while(true)
			{
				if(actions->empty)
				{
					sleep(10); //if we have nothing we wait to avoid checking the queue too rapidly
				}
				else
				{
					std::string act = actions->getFirstElement();
					std::cout<<"debug execute : "<<act;
				}
			}
			//pthread_join (client, NULL);
		}

	private:
		SynchronizedList* actions;
};
