// Server.cpp

/****************************************************************************\
*  This implementation will handle incoming client connections, utilize the  *
*  Graph class, and process messages.                                        *
\****************************************************************************/

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include "graph.h"

#define PORT 8080
#define BUFFER_SIZE 1024

void setupGraph(Graph &graph)
{
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    graph = Graph(numVertices);

    cout << "Enter the edges in the ffromat 'from to weight' (type 'end' to stop):" << endl;

    int from, to, weight;
    while(true)
    {
        string input;
        cin >> input;
        if(input == "end") break;

        istringstream iss(input);
        iss >> from >> to >> weight;
        graph.addEdge(from, to, weight);
    }
}

int main()
{
    Graph graph(0); //  Placeholder for graoh initialization
    setupGraph(graph); // Getgraph input from user

    int server_fd, new_socket;
    struct sockaddr_in address;

    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    //Create socket file descriptor
    if((server_fd = socket(AF_INET, SOCK-STREAM, 0)) == 0)
    {
        perror("Socket failed");
        exit(EXIT_FAILUE);
    }

    // Attach socket to the port
    if(setsocket(server_fd, SOL_SOKET, SO_REUSEADDR, &opt, sizeof(opt)))
    {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if(bind(server_fd, (struct sockaddr *)&addreess, sizeof(address)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if(listen(server_fd, 3) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    cout << "Server is listening on port " << PORT << endl;

    //Accept a connection from a client
    while((new_socket = accept(server_fd, (struct sockaddr *)address, (socklen_t*)&addrlen)) >= 0)
    {
        cout << "Client connected" << endl;

        //Read message from clinet
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        buffer[valread] = '\0';
        cout << "Message received: " << buffer << endl;

        //Extract start and vertices from the message
        int startVertex = buffer[0] - '0'; // Assume single digit for simplicity
        int endVertex = buffer[2] - '0'; // Assume singe digit for simplicity

        //Find the optiimal path using Dijkstra's algorithm
        vector<int> path = graph.dijkstra(startVertex, endVertex);

        // Prepare the response
        string respose = "Path: ";
        for(int v : path)
            response += to_string(v) + " ";

        // Send response back to client
        send(new_socket, response.c_str(), response.size(), 0);
        cout << "Response sent: " << response << endl;

        //Close the connection
        close(new_socket);
    }
    return 0;
} 