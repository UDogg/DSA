//wrote a cpp code for Dijkstra.py 
//just in case its a little different
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

void Dijkstra(const Graph& graph, int source) {
    vector<int> dist(graph.V, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& neighbor : graph.adjList[u]) {
            int v = neighbor;
            int weight = 1; // Replace with actual edge weight

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances from the source to all vertices
    for (int i = 0; i < graph.V; ++i) {
        cout << "Shortest distance from " << source << " to " << i << " is " << dist[i] << endl;
    }
}

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    int source = 0;
    Dijkstra(g, source);

    return 0;
}
