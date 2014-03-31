#include "ClientConnection.h"
#include "ClientConnectionSending.h"
#include "HardwareCommunication.h"
#include <pthread.h>

void* readingThread(void* ptr)
{
    ClientConnectionReading* obj = (ClientConnectionReading*)ptr;
	obj->connectionLoop();
	return NULL;
}

void* sendingThread(void* ptr)
{
	ClientConnectionSending* obj = (ClientConnectionSending*)ptr;
	obj->connectionLoop();
	return NULL;
}

int main()
{
    std::cout<<"start sever"<<std::endl;
    pthread_t t_send,t_receive;
    SynchronizedList* actionList = new SynchronizedList();
    SynchronizedList* sendList = new SynchronizedList();
	ClientConnectionReading* read = new ClientConnectionReading(actionList);
	ClientConnectionSending* send = new ClientConnectionSending(sendList);
    HardwareCommunication hwCom;

	pthread_create(&t_send,NULL,sendingThread,send);
	pthread_create(&t_receive,NULL,readingThread,read);
	std::cout << "thread launch, entering main loop"<<std::endl;
	while(1) //main thread of the app
	{
        if(sendList->isEmpty())
        {
            sleep(1);
        }
        else
        {
            std::string val = sendList->getFirstElement();
            std::string head = val.substr(0,2);
            if(head.compare("x:"))
            {
                std::string strOffset = val.substr(2);
                hwCom.setXaxis( atoi(strOffset.c_str()) );
            }
            if(head.compare("y:"))
            {
                std::string strOffset = val.substr(2);
                hwCom.setYaxis( atoi(strOffset.c_str()) );
            }
            if(head.compare("z:"))
            {
                std::string strOffset = val.substr(2);
                hwCom.setZaxis( atoi(strOffset.c_str()) );
            }
        }
	}
	delete read;
	return 0;
}
