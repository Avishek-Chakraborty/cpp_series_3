#include <bits/stdc++.h>

using namespace std;

class EulerianPathCircuit {
 private:
  int vertices;
  vector<vector<int>> adjList;

  void dfs(int vertex, vector<bool>& visited, stack<int>& path) {
    visited[vertex] = true;

    for (int neighbor : adjList[vertex]) {
      if (!visited[neighbor]) {
        dfs(neighbor, visited, path);
      }
    }

    path.push(vertex);
  }

 public:
  EulerianPathCircuit(int vertices) : vertices(vertices) {
    adjList.resize(vertices);
  }

  void addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  bool hasEulerianCircuit() {
    for (int i = 0; i < vertices; ++i) {
      if (adjList[i].size() % 2 != 0) {
        return false;  // Eulerian circuit doesn't exist
      }
    }
    return true;
  }

  bool hasEulerianPath() {
    int oddDegreeCount = 0;

    for (int i = 0; i < vertices; ++i) {
      if (adjList[i].size() % 2 != 0) {
        oddDegreeCount++;
      }
    }

    return oddDegreeCount == 0 || oddDegreeCount == 2;
  }

  void findEulerianPathCircuit() {
    if (!hasEulerianPath()) {
      cout << "Eulerian path or circuit does not exist.\n";
      return;
    }

    vector<bool> visited(vertices, false);
    stack<int> path;

    for (int i = 0; i < vertices; ++i) {
      if (adjList[i].size() > 0) {
        dfs(i, visited, path);
        break;
      }
    }

    // Print the Eulerian path or circuit
    cout << "Eulerian Path or Circuit: ";
    while (!path.empty()) {
      cout << path.top() << " ";
      path.pop();
    }
    cout << endl;
  }
};

int main() {
  int vertices, edges;

  // Get the number of vertices and edges
  cout << "Enter the number of vertices: ";
  cin >> vertices;
  cout << "Enter the number of edges: ";
  cin >> edges;

  // Create EulerianPathCircuit instance
  EulerianPathCircuit eulerianGraph(vertices);

  // Input edges
  cout << "Enter the edges (u v):\n";
  for (int i = 0; i < edges; ++i) {
    int u, v;
    cin >> u >> v;
    eulerianGraph.addEdge(u, v);
  }

  // Find and display Eulerian path or circuit
  eulerianGraph.findEulerianPathCircuit();

  return 0;
}
