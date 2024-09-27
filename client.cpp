// Client.cpp

/****************************************************************************\
*  This implementation will connect to the server, send messages, and        *
*  display the server's response.                                            *
\****************************************************************************/

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cout << "Socket creation error" << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cout << "Invalid address / Address not supported" << std::endl;
        return -1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "Connection failed" << std::endl;
        return -1;
    }

    // Input start and end vertices from the user
    int startVertex, endVertex;
    std::cout << "Enter start vertex (0-4): ";
    std::cin >> startVertex;
    std::cout << "Enter end vertex (0-4): ";
    std::cin >> endVertex;

    // Prepare the message to send
    std::string message = std::to_string(startVertex) + " " + std::to_string(endVertex);
    
    // Send the message to the server
    send(sock, message.c_str(), message.size(), 0);
    std::cout << "Message sent: " << message << std::endl;

    // Receive the response from the server
    int valread = read(sock, buffer, BUFFER_SIZE);
    buffer[valread] = '\0';
    std::cout << "Response from server: " << buffer << std::endl;

    // Close the socket
    close(sock);
    return 0;
}
