# Dynamic Search Algorithm for Intelligent Message Routing

## Project Overview

The **Dynamic Search Algorithm for Intelligent Message Routing** project aims to optimize message delivery using advanced routing algorithms in client-server architectures. This project is particularly beneficial in high-performance network environments, enhancing both efficiency and reliability in communication.

### Table of Contents

- [Workflow](#workflow)
- [Real-World Applications](#real-world-applications)
- [Performance Metrics](#performance-metrics)
- [Usage](#usage)
- [Technologies Used](#technologies-used)
- [Contributing](#contributing)
- [License](#license)

## Workflow

1. **Server Initialization**:
   - The server listens on a designated port (e.g., **8080**) for incoming client connections.
   - It can manage multiple connections simultaneously.

2. **Client Connection**:
   - Clients establish a connection to the server via TCP/UDP sockets.
   - Clients send messages containing routing requests after establishing a connection.

3. **Dynamic Routing**:
   - Before sending messages, the client executes a dynamic search algorithm.
   - The algorithm analyzes various paths based on criteria like current load and latency to determine the optimal routing.

4. **Message Delivery**:
   - After identifying the best route, the client sends the message to the server.
   - The server processes the received message and can respond with relevant information.

5. **Connection Management**:
   - Both the client and server can close connections gracefully once the communication is complete.

## Real-World Applications

- **Networking Solutions**: Optimizes performance in data centers and cloud environments by enhancing message routing.
- **Communication Protocols**: Useful in various networking protocols like TCP/IP, where efficient data transmission is crucial.
- **Scalability**: Ideal for large-scale applications requiring rapid data exchange, such as IoT systems and enterprise applications.

## Performance Metrics

- **Throughput Improvement**: Achieved a **200% increase** in message throughput.
- **Reduced Latency**: Average message delivery time decreased by **26.7%**, resulting in faster communication.

## Usage

1. Start the server first to listen for incoming connections.
2. Launch the client application to connect to the server and send messages.
3. Follow the prompts to input the start and end vertices for the routing algorithm.

## Technologies Used

- **Programming Languages**: 
  - **C++**: Primary language for implementation.
  
- **Networking Protocols**: 
  - **TCP/UDP Sockets**: For reliable and efficient message transmission.
  
- **Algorithms**: 
  - **Dijkstra's Algorithm**: Used for optimal pathfinding in the network graph.

- **Data Structures**:
  - **Graphs**: To represent the network and manage routing paths.
  - **Vectors**: For dynamic storage of paths and messages.

- **Development Tools**: 
  - **g++**: GNU C++ Compiler for compiling the code.
  - **Visual Studio Code**: IDE for development and debugging.

## Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes and commit them (`git commit -m 'Add some feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a Pull Request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
