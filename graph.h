// Graph.h

/****************************************************************************\
*  This header file will define the structure of the Graph class,            *
*  including necessary includes, member variables, and method declarations.  *
\****************************************************************************/


#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <list>
#include <limits>
#include <utility> // for std::pair
#include <queue>
#include <iosteam>

using namespace std;

class Graph
{
public:
    Graph(int vertices);
    void addEdge(int src, int dest, int weight);
    vector<int> dijkstra(int startvertex, int endVertex);

private:
    int vertices;
    unordered_map<int, list<pair<int, int>>> adjList; // {vertex: [(neighbour, weight)]}

};

#endif // HRAPH_H