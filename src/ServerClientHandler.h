#ifndef FOOBAR_DT_SERVERCLIENTHANDLER_H
#define FOOBAR_DT_SERVERCLIENTHANDLER_H
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <vector>
#include "IMenu.h"
#include "InputHandler.h"
#include "Factory.h"

using std::string;

class ServerClientHandler : public IMenu
{
private:
    string currLine;
    int clientSocket;
    InputHandler inputHandler;
    void getLine();
    Factory& factory = Factory::getInstance();

public:
    ServerClientHandler(int client_socket);
    void handleClient();
    std::string getURL() override;
    std::vector<int> getInitParm() override;
    int getNextTask() override;
    void sendResult(std::string result) override;

};


#endif //FOOBAR_DT_SERVERCLIENTHANDLER_H
