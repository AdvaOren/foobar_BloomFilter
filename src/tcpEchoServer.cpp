#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <thread>

void handleClient(int clientSocket) {
    // Receive data from client and echo back
    char buffer[4096];
    int bytesReceived;
    while ((bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0) {
        // Echo received data back to client
        send(clientSocket, buffer, bytesReceived, 0);
    }

    if (bytesReceived == -1) {
        std::cerr << "Receive failed " << strerror(errno) << std::endl;
    }
    // Close client socket
    close(clientSocket);
}
int main(){
    const int server_port = 5555;
    int sock = socket(AF_INET, SOCK_STREAM,0);
    if (sock < 0)
    {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin,0, sizeof(sin));
    sin.sin_family= AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY,
    sin.sin_port = htons(server_port);
    if (bind(sock,(struct sockaddr *) &sin, sizeof(sin))< 0)
    {
        perror("error binding socket");
    }
    if (listen(sock,5)< 0 )
    {
        perror("error listening to a socket");
    }
    struct sockaddr_in client_sin;
    unsigned int addr_len
            = sizeof(client_sin);
    while(true) {
        int client_sock = accept(sock,(struct sockaddr*) &client_sin, &addr_len);
        if (client_sock == -1) {
            perror("Error listening to socket");
            break;
        }
        std::thread clientThread(handleClient, client_sock);
        clientThread.detach();
    }
    close(sock);
    return 0;
        }
