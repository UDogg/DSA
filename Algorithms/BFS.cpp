#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/*
BFS(Breadth First Search) is a graph traversal algorithm that visits all vertices in a graph at the same level before moving to the next level.
It is useful for finding shortest paths and connected components.
*/

void BFS(const Graph& graph, int start) {
    vector<bool> visited(graph.V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : graph.adjList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
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

    cout << "BFS Traversal: ";
    BFS(g, 0);
    cout << endl;

    return 0;
}
