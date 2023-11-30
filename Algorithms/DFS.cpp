// Recursive implementation of DFS

#include <iostream>
#include <list>
using namespace std;

class Graph {
  int numVertices; // Number of vertices in the graph
  list<int> *adjLists; // Adjacency lists for each vertex
  bool *visited; // Array to track visited vertices

public:
  Graph(int vertices); // Constructor
  void addEdge(int src, int dest); // Function to add an edge to the graph
  void DFS(int vertex); // Function to perform DFS
};

Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
  visited = new bool[vertices];
}

void Graph::addEdge(int src, int dest) {
  adjLists[src].push_front(dest); // Add dest to src’s list
}

void Graph::DFS(int vertex) {
  visited[vertex] = true; // Mark the current node as visited
  list<int> adjList = adjLists[vertex];

  cout << vertex << " "; // Print the current node

  // Recur for all the vertices adjacent to this vertex
  list<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); ++i)
    if (!visited[*i])
      DFS(*i); // If an adjacent hasn't been visited, then call DFS function recursively
}

int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);

  g.DFS(2); // Start DFS traversal from vertex 2

  return 0;
}
