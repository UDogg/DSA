#include <iostream>
#include <vector>

using namespace std;

/*
Graphs can be represented using an adjacency list,
where each vertex is associated with a list of its adjacent vertices. 
This is a common representation used in many graph algorithms.
*/
class Graph {
public:
    int V;
    vector<vector<int>> adjList;

    Graph(int V) : V(V), adjList(V) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graphs
    }
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // ... (use the graph for various algorithms or operations)
    return 0;
}
