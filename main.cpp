// main.cpp

/****************************************************************************\
*  This implementation will handle initializing the server and incorporating *
*  the graph functionality.                                                  *
\****************************************************************************/

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include "graph.h"

#define PORT 8080
#define BUFFER_SIZE 1024

void handleClient(int new_socket, Graph &graph) {
    char buffer[BUFFER_SIZE];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int valread = read(new_socket, buffer, sizeof(buffer));

        if (valread == 0) {
            // Client disconnected
            break;
        }

        std::string command(buffer);
        if (command.find("ADD_VERTEX") == 0) {
            std::string vertex = command.substr(11); // Extract the vertex
            graph.addVertex(vertex);
            std::cout << "Vertex added: " << vertex << std::endl;
        } else if (command.find("ADD_EDGE") == 0) {
            std::string edge = command.substr(9); // Extract the edge
            std::string start = edge.substr(0, edge.find(' '));
            std::string end = edge.substr(edge.find(' ') + 1);
            graph.addEdge(start, end);
            std::cout << "Edge added: " << start << " -> " << end << std::endl;
        }
    }
    close(new_socket);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cout << "Socket creation error" << std::endl;
        return -1;
    }

    // Attach socket to the port
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        std::cout << "Bind failed" << std::endl;
        return -1;
    }

    // Start listening for connections
    if (listen(server_fd, 3) < 0) {
        std::cout << "Listen failed" << std::endl;
        return -1;
    }

    std::cout << "Server listening on port " << PORT << std::endl;

    Graph graph; // Create a graph instance

    while (true) {
        // Accept a new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            std::cout << "Accept failed" << std::endl;
            continue;
        }

        // Handle client in a separate function
        handleClient(new_socket, graph);
    }

    return 0;
}
