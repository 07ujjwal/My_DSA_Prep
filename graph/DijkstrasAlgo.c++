#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <limits>

using namespace std;

// Function to implement Dijkstra's algorithm for single-source shortest paths
vector<int> dijkstra(const vector<vector<int>>& graph, int vertices, int source) {
    // Create an adjacency list representation of the graph
    unordered_map<int, vector<pair<int, int>>> adjList;
    for (int i = 0; i < vertices; i++) {
        int u = graph[i][0];
        int v = graph[i][1];
        int w = graph[i][2];
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w)); // Add edges in both directions for undirected graphs
    }

    // Initialize distance vector with infinity for all nodes except source
    vector<int> dist(vertices, numeric_limits<int>::max());
    dist[source] = 0;

    // Create a set to store nodes based on their distances for efficient priority queue-like behavior
    set<pair<int, int>> st;  // (distance, node) pairs
    st.insert(make_pair(0, source));

    // Dijkstra's algorithm:
    while (!st.empty()) {
        auto topNode = *(st.begin());
        st.erase(st.begin());

        int nodeDist = topNode.first;
        int node = topNode.second;

        // Relax edges (update distances if shorter paths are found)
        for (auto neighbor : adjList[node]) {
            int neighborNode = neighbor.first;
            int weight = neighbor.second;

            if (nodeDist + weight < dist[neighborNode]) {
                // Update distance if necessary
                dist[neighborNode] = nodeDist + weight;

                // Update priority in the set (if the node is already present)
                auto it = st.find(make_pair(dist[neighborNode], neighborNode));
                if (it != st.end()) {
                    st.erase(it);  // Remove the old entry with potentially outdated distance
                }
                st.insert(make_pair(dist[neighborNode], neighborNode));  // Insert with updated distance
            }
        }
    }

    return dist;
}

int main() {
    // Sample graph (modify as needed)
    int vertices = 5; // Number of vertices
    vector<vector<int>> graph = {
        {0, 1, 4},
        {0, 2, 8},
        {1, 2, 11},
        {1, 3, 7},
        {2, 4, 2},
        {3, 4, 9}
    };
    int source = 0; // Starting node

    // Call Dijkstra's algorithm and print the shortest distances
    vector<int> distances = dijkstra(graph, vertices, source);
    for (int i = 0; i < vertices; i++) {
        cout << "Distance from source " << source << " to node " << i << ": ";
        if (distances[i] == numeric_limits<int>::max()) {
            cout << "UNREACHABLE" << endl;
        } else {
            cout << distances[i] << endl;
        }
    }

    return 0;
}
