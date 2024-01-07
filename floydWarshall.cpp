#include <bits/stdc++.h>
using namespace std;

// Function to perform Floyd-Warshall algorithm
void floydWarshall(int** graph, int vertices) {
    // Initialize the dist matrix with the given graph
    int dist[vertices][vertices];
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Perform the Floyd-Warshall algorithm
    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Display the final shortest distances
    cout << "Shortest distances between vertices:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (dist[i][j] == INT_MAX) {
                cout << "INF\t";
            } else {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main() {
    int vertices;

    // Get the number of vertices from the user
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    // Allocate memory for the adjacency matrix
    int** graph = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        graph[i] = new int[vertices];
    }

    // Get the adjacency matrix from the user
    cout << "Enter the adjacency matrix (INF for infinity):\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == -1) {
                // Represent infinity as INT_MAX
                graph[i][j] = INT_MAX;
            }
        }
    }

    // Perform Floyd-Warshall algorithm
    floydWarshall(graph, vertices);

    // Deallocate memory
    for (int i = 0; i < vertices; i++) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
