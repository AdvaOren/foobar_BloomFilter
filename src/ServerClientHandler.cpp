#include "ServerClientHandler.h"
#include "App.h"

ServerClientHandler::ServerClientHandler(int clientSocket)
{
    this->clientSocket = clientSocket;
}


void ServerClientHandler::getLine()
{
    char buffer[4096];
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesReceived > 0)
    {
        currLine = string(buffer);
        //for windows
        if (currLine[currLine.length() - 1] == '\r')
        {
            currLine.erase(currLine.begin() + currLine.length() - 1);
        }
    }
    else if (bytesReceived == -1)
    {
        std::cerr << "Receive failed " << strerror(errno) << std::endl;
        currLine.clear();
        close(clientSocket);
    }
    else if (bytesReceived == 0)
    {
        close(clientSocket);
        currLine.clear();
    }
}

void ServerClientHandler::handleClient()
{
    do
    {
        if (factory.isBfInit()) {
            break;
        }
        getLine();
        sendResult("$");
    } while(currLine.length() > 0 && !inputHandler.checkLineValidation(currLine,INIT_LINE_TYPE));
    if (currLine.length() > 0 || factory.isBfInit())
        App::run(this);
}

std::string ServerClientHandler::getURL()
{
    return inputHandler.getURL(currLine);
}

std::vector<int> ServerClientHandler::getInitParm()
{
    return inputHandler.getInitParm(currLine);
}

int ServerClientHandler::getNextTask()
{
    bool valid;
    do
    {
        getLine();
        if (currLine.empty())
            return ERROR;
        valid = inputHandler.checkLineValidation(currLine,inputHandler.getType(currLine));
        if (!valid)
            sendResult("$");
    } while (!valid);
    return inputHandler.getType(currLine);
}

void ServerClientHandler::sendResult(std::string result)
{

    send(clientSocket, result.c_str(), result.length(), 0);
}


