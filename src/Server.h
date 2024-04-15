#ifndef FOOBAR_DT_SSERVER_H
#define FOOBAR_DT_SSERVER_H
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <thread>
#include "IMenu.h"
#include "InputHandler.h"
#include "ServerClientHandler.h"
#include <sstream>

#define PORT_SERVER 5555
using std::string;

class Server
{
private:
    void handleClient(int clientSocket);

public:
    static void startServer();

};


#endif //FOOBAR_DT_SERVER_H
