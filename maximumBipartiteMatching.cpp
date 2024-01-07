#include <iostream>
#include <vector>

using namespace std;

class BipartiteMatching {
 private:
  int leftVertices, rightVertices;
  vector<vector<int>> graph;
  vector<int> rightMatching;
  vector<bool> visited;

  bool dfs(int leftVertex) {
    if (visited[leftVertex]) {
      return false;
    }
    visited[leftVertex] = true;

    for (int i = 0; i < graph[leftVertex].size(); ++i) {
      int rightVertex = graph[leftVertex][i];
      if (rightMatching[rightVertex] == -1 || dfs(rightMatching[rightVertex])) {
        rightMatching[rightVertex] = leftVertex;
        return true;
      }
    }

    return false;
  }

 public:
  BipartiteMatching(int leftVertices, int rightVertices)
      : leftVertices(leftVertices), rightVertices(rightVertices) {
    graph.resize(leftVertices);
    rightMatching.assign(rightVertices, -1);
  }

  void addEdge(int leftVertex, int rightVertex) {
    graph[leftVertex].push_back(rightVertex);
  }

  int maxBipartiteMatching() {
    int matching = 0;
    for (int i = 0; i < leftVertices; ++i) {
      visited.assign(leftVertices, false);
      if (dfs(i)) {
        matching++;
      }
    }
    return matching;
  }

  vector<int> getMatching() { return rightMatching; }
};

int main() {
  int leftVertices, rightVertices, edges;

  // Get the number of vertices on the left and right side
  cout << "Enter the number of vertices on the left side: ";
  cin >> leftVertices;
  cout << "Enter the number of vertices on the right side: ";
  cin >> rightVertices;

  // Create BipartiteMatching instance
  BipartiteMatching bipartiteGraph(leftVertices, rightVertices);

  // Get the number of edges
  cout << "Enter the number of edges: ";
  cin >> edges;

  // Input edges
  cout << "Enter the edges (leftVertex rightVertex):\n";
  for (int i = 0; i < edges; ++i) {
    int leftVertex, rightVertex;
    cin >> leftVertex >> rightVertex;
    bipartiteGraph.addEdge(leftVertex, rightVertex);
  }

  // Find maximum bipartite matching
  int maxMatching = bipartiteGraph.maxBipartiteMatching();

  cout << "Maximum Bipartite Matching: " << maxMatching << endl;

  // Display the matching pairs
  vector<int> matchingPairs = bipartiteGraph.getMatching();
  cout << "Matching pairs: ";
  for (int i = 0; i < rightVertices; ++i) {
    if (matchingPairs[i] != -1) {
      cout << "(" << matchingPairs[i] << "," << i << ") ";
    }
  }
  cout << endl;

  return 0;
}
