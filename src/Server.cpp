#include "Server.h"

/**
 * Starts the server and listens for incoming client connections.
 *
 * Input: None
 * Output: None
 */
void Server::startServer()
{
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
    }

    // Initialize server address
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY, sin.sin_port = htons(PORT_SERVER);

    // Bind socket to the server address
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0)
    {
        perror("error binding socket");
    }

    // Start listening for client connections
    if (listen(sock, 5) < 0)
    {
        perror("error listening to a socket");
    }

    // Accept incoming client connections
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

        // Create a new thread to handle the client connection
         std::thread clientThread(&ServerClientHandler::handleClient, ServerClientHandler(client_sock));
        clientThread.detach();
    }

    // Close the server socket
    close(sock);
}


