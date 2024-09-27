// Graph.cpp

/****************************************************************************\
*  This implementation file will define the methods declared in Graph.h.     *
\****************************************************************************/

#include "Graph.h"

Graph::Graph(int vertices) : vertices(vertices) {}

void Graph::addEdge(int src, int dest, int weight)
{
    adjList[src].push_back(make_pair(dest, weight));
    adjList[dest].push_back(make_pair(src, weight)); //assuming undirected graph
}

vector<int> Graph::dijkstra(int startVertex, int endVertex)
{
    vector<int> distances(vertices, numeric_limits<int>::max());
    vector<int> previous(vertices, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

    distances[startVertex] = 0;
    minHeap.push(make_pair(0, startVertex));

    while(!minHeap.empty())
    {
        int currentVertex = minHeap.top().second;
        minHeap.pop();

        for(auto& neighbour : adjList[currentVertex])
        {
            int nextVertex = neighbour.first;
            int weight = neighbour.second;

            int newDist = distances[currentVertex] + weight;
            if(newDist < distances[nextVertex])
            {
                distances[nextVertex] = newDist;
                previous[nextVertex] = currentVertex;
                minHeap.push(make_pair(newDist, nextVertex));
            }
        }
    }

    // Reconstruct the path
    vector<int> path;
    for(int it = endVertex; it != -1; it = previous[it])
        path.push_back(it);

    reverse(path.begin(), path.end());
    return path;
}