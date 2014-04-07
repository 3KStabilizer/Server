#include "ClientConnection.h"

ClientConnectionReading::ClientConnectionReading(SynchronizedList* o)
{
    obj = o;
}
ClientConnectionReading::~ClientConnectionReading()
{

}

void ClientConnectionReading::initConnection()
{
    sck = socket(AF_INET, SOCK_STREAM, 0);
    if (sck < 0)
        std::cout<<"ERROR opening socket";

    bzero((char *) &serv_addr, sizeof(serv_addr));
    port = 1234;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

}

bool ClientConnectionReading::waitForClient()
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
bool ClientConnectionReading::waitForDataReception()
{
    bool alreadyGotAnError = false;
    int n = 0;
    char buffer[256];
    do{
        bzero(buffer,256);
        printf("before read\n");
        //sleep(1);
        n = read(clientSocket,buffer,255);
        printf("after read\n");
        //sleep(1);
        if(n==-1 || n==0)
        {
            printf("Error while reading\n");
            if(alreadyGotAnError)
            {
                printf("client seems disconnected exiting loop\n");
                return false;
            }
            else
                alreadyGotAnError = true;

            //getchar();//wait for key strike
        }
        else
            alreadyGotAnError = false;

        printf("received : %s , n : %d\n",buffer,n);
        obj->addElement( std::string(buffer) );
    } while ( true );
    return true;
}

void ClientConnectionReading::connectionLoop()
{
    while(1)
    {
        std::cout << "launching reading process";
        sleep(1);
        initConnection();
        waitForClient();
        waitForDataReception();
    }

}

