#include "ServerClientHandler.h"

/**
 * Constructor for ServerClientHandler class.
 * Initializes the clientSocket member variable.
 *
 * Input: clientSocket: The socket file descriptor of the client connection.
 * Output: None
 */
ServerClientHandler::ServerClientHandler(int clientSocket)
{
    this->clientSocket = clientSocket;
}

/**
 * Reads a line of data from the client connection.
 * Stores the read line in the currLine member variable.
 *
 * Input: None
 * Output: None
 */
void ServerClientHandler::getLine()
{
    char buffer[4096] = {0};
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesReceived > 0)
    {
        currLine = string(buffer);
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

/**
 * Handles the client connection.
 * Receives input from the client and sends responses back.
 *
 * Input: None
 * Output: None
 */
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

/**
 * Parses and retrieves the URL from the current line of input.
 *
 * Input: None
 * Output: Returns the URL extracted from the current line.
 */
std::string ServerClientHandler::getURL()
{
    return inputHandler.getURL(currLine);
}

/**
* Parses and retrieves the initialization parameters from the current line of input.
*
* Input: None
* Output: Returns a vector containing the initialization parameters.
*/
std::vector<int> ServerClientHandler::getInitParm()
{
    return inputHandler.getInitParm(currLine);
}

/**
 * Retrieves the type of the next task to be performed based on the input from the client.
 *
 * Input: None
 * Output: Returns the type of the next task.
 */
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

/**
 * Sends a result back to the client.
 *
 * Input: result: The result to be sent back to the client.
 * Output: None
 */
void ServerClientHandler::sendResult(std::string result)
{
    send(clientSocket, result.c_str(), result.length(), 0);
}


