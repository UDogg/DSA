// Iterative implmentation of DFS
// for the graph defined in main
#include<bits/stdc++.h> 
using namespace std; 

class Graph 
{ 
  int V; // Number of vertices
  list<int> *adjList; // Adjacency list
public: 
  Graph(int V) 
  {
    this->V = V; 
    adjList = new list<int>[V]; 
  } 
  void addEdge(int v, int w) 
  { 
    adjList[v].push_back(w); // Add w to v’s list
  } 
  void DFS() 
  { 
    vector<bool> visited(V, false); // Mark all the vertices as not visited
    stack<int> stack; // Create a stack for DFS
    for (int i = 0; i < V; i++) 
      if (!visited[i]) 
        stack.push(i); // If a vertex is not visited, then push it to the stack
    while (!stack.empty()) 
    { 
      int v = stack.top(); // Pop a vertex from stack
      stack.pop(); 
      if (!visited[v]) 
      { 
        cout << v << " "; // Print the popped vertex
        visited[v] = true; // Mark the popped vertex as visited
      } 
      // Get all adjacent vertices of the popped vertex. If an adjacent has not been visited, then push it to the stack
      for (auto i = adjList[v].begin(); i != adjList[v].end(); ++i) 
        if (!visited[*i]) 
          stack.push(*i); 
    } 
  } 
}; 

int main() 
{ 
  Graph g(5); 
  g.addEdge(0, 1); 
  g.addEdge(0, 2); 
  g.addEdge(0, 3);
  g.addEdge(1, 2); 
  g.addEdge(2, 4);
  g.addEdge(3, 3); 
  g.addEdge(4, 4);

  cout << "Depth-first traversal for the given graph:"<<endl; 
  g.DFS(); // Start DFS traversal

  return 0; 
} 
