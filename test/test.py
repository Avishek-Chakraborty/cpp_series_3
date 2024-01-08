class EulerianPathCircuit:
    def __init__(self, vertices):
        self.vertices = vertices
        self.adj_list = [[] for _ in range(vertices)]

    def add_edge(self, u, v):
        self.adj_list[u].append(v)
        self.adj_list[v].append(u)

    def dfs(self, vertex, visited, path):
        visited[vertex] = True

        for neighbor in self.adj_list[vertex]:
            if not visited[neighbor]:
                self.dfs(neighbor, visited, path)

        path.append(vertex)

    def has_eulerian_circuit(self):
        for i in range(self.vertices):
            if len(self.adj_list[i]) % 2 != 0:
                return False  # Eulerian circuit doesn't exist
        return True

    def has_eulerian_path(self):
        odd_degree_count = sum(len(neighbors) % 2 != 0 for neighbors in self.adj_list)
        return odd_degree_count == 0 or odd_degree_count == 2

    def find_eulerian_path_circuit(self):
        if not self.has_eulerian_path():
            print("Eulerian path or circuit does not exist.")
            return

        visited = [False] * self.vertices
        path = []

        for i in range(self.vertices):
            if len(self.adj_list[i]) > 0:
                self.dfs(i, visited, path)
                break

        # Print the Eulerian path or circuit
        print("Eulerian Path or Circuit:", end=" ")
        for vertex in reversed(path):
            print(vertex, end=" ")
        print()


def main():
    vertices = int(input("Enter the number of vertices: "))
    edges = int(input("Enter the number of edges: "))

    eulerian_graph = EulerianPathCircuit(vertices)

    # Input edges
    print("Enter the edges (u v):")
    for _ in range(edges):
        u, v = map(int, input().split())
        eulerian_graph.add_edge(u, v)

    # Find and display Eulerian path or circuit
    eulerian_graph.find_eulerian_path_circuit()


if __name__ == "__main__":
    main()
