#include "Server.h"

/*void Server::handleClient(int clientSocket)
{
    // Receive data from client and echo back
    char buffer[4096];
    int bytesReceived;
    bool init = false;
    string incompleteLine;
    if ((bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0)
    {
        currLine = string(buffer);
        //for windows
        if (currLine[currLine.length()-1] == '\r')
            currLine.erase(currLine.begin() + currLine.length()-1);

        // Echo received data back to client
        send(clientSocket, buffer, bytesReceived, 0);
    }

    if (bytesReceived == -1)
    {
        std::cerr << "Receive failed " << strerror(errno) << std::endl;
    }
    // Close client socket
    close(clientSocket);
}*/

void Server::startServer()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY, sin.sin_port = htons(PORT_SERVER);
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0)
    {
        perror("error binding socket");
    }
    if (listen(sock, 5) < 0)
    {
        perror("error listening to a socket");
    }
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    while (true)
    {
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock == -1)
        {
            perror("Error listening to socket");
            break;
        }
        std::thread clientThread(&ServerClientHandler::handleClient, ServerClientHandler(client_sock));
        clientThread.detach();
    }
    close(sock);
}


