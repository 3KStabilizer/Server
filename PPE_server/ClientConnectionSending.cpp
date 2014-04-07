#include "ClientConnectionSending.h"


ClientConnectionSending::ClientConnectionSending(SynchronizedList* o)
{
    toSend = o;
}
ClientConnectionSending::~ClientConnectionSending()
{

}

void ClientConnectionSending::initConnection()
{
    sck = socket(AF_INET, SOCK_STREAM, 0);
    if (sck < 0)
        std::cout<<"ERROR opening socket";

    bzero((char *) &serv_addr, sizeof(serv_addr));
    port = 1235;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

}

bool ClientConnectionSending::waitForClient()
{
    int clilen;
    if (bind(sck,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        std::cout << "ERROR on binding";
    std::cout << "waiting for client";
    listen(sck,5);
    clilen = sizeof(cli_addr);
    clientSocket = accept(sck, (struct sockaddr *) &cli_addr, (socklen_t*)&clilen);
    return true;
}
bool ClientConnectionSending::sendData()
{
    bool alreadyGotAnError = false;
    int n = 0;
    char buffer[256];
    do{
        if(!toSend->isEmpty())
        {
            bzero(buffer,256);
            std::string send = toSend->getFirstElement();
            std::strcpy(buffer,send.c_str() );
            n = write(clientSocket,buffer,255);
            if(n==-1 || n==0)
            {
                printf("error while writing");
                if(alreadyGotAnError)
                {
                    printf("Client seems disconnected exiting loop \n");
                    return false;
                }
                else
                    alreadyGotAnError = true;
            }
            else
                alreadyGotAnError = false;

            printf("send: %s",buffer);
        }

    } while ( true );
    return true;
}

void ClientConnectionSending::connectionLoop()
{
    while(1)
    {
        std::cout << "launching sending process";
        sleep(1);
        initConnection();
        waitForClient();
        sendData();
    }

}
