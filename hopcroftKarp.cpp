#include <bits/stdc++.h>
using namespace std;

class HopcroftKarp {
private:
    int leftVertices, rightVertices;
    vector<vector<int>> graph;
    vector<int> leftMatching, rightMatching, distance;

    bool bfs() {
        queue<int> q;
        distance.assign(leftVertices + rightVertices + 1, INT_MAX);

        for (int i = 1; i <= leftVertices; ++i) {
            if (leftMatching[i] == 0) {
                distance[i] = 0;
                q.push(i);
            }
        }

        while (!q.empty()) {
            int leftVertex = q.front();
            q.pop();

            if (distance[leftVertex] < distance[0]) {
                for (int rightVertex : graph[leftVertex]) {
                    if (distance[rightMatching[rightVertex]] == INT_MAX) {
                        distance[rightMatching[rightVertex]] = distance[leftVertex] + 1;
                        q.push(rightMatching[rightVertex]);
                    }
                }
            }
        }

        return distance[0] != INT_MAX;
    }

    bool dfs(int leftVertex) {
        if (leftVertex != 0) {
            for (int rightVertex : graph[leftVertex]) {
                if (distance[leftMatching[leftVertex]] == distance[rightMatching[rightVertex]] + 1 &&
                    dfs(rightMatching[rightVertex])) {
                    rightMatching[rightVertex] = leftVertex;
                    leftMatching[leftVertex] = rightVertex;
                    return true;
                }
            }

            distance[leftVertex] = INT_MAX;
            return false;
        }

        return true;
    }

public:
    HopcroftKarp(int leftVertices, int rightVertices) : leftVertices(leftVertices), rightVertices(rightVertices) {
        graph.resize(leftVertices + 1);  // Vertices are 1-indexed
        leftMatching.assign(leftVertices + 1, 0);
        rightMatching.assign(rightVertices + 1, 0);
    }

    void addEdge(int leftVertex, int rightVertex) {
        graph[leftVertex].push_back(rightVertex);
    }

    int maxBipartiteMatching() {
        int matching = 0;

        while (bfs()) {
            for (int i = 1; i <= leftVertices; ++i) {
                if (leftMatching[i] == 0 && dfs(i)) {
                    matching++;
                }
            }
        }

        return matching;
    }
};

int main() {
    int leftVertices, rightVertices, edges;
    
    // Get the number of vertices on the left and right side
    cout << "Enter the number of vertices on the left side: ";
    cin >> leftVertices;
    cout << "Enter the number of vertices on the right side: ";
    cin >> rightVertices;

    // Create Hopcroft-Karp instance
    HopcroftKarp bipartiteGraph(leftVertices, rightVertices);

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

    return 0;
}
