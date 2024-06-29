#include <iostream>
#include <bits/stdc++.h>
#include <list>

using namespace std;

template <typename T> class graph {
public:
    unordered_map<T, list<T>> adj;

    void addEdge(int u, int v, bool direction) {
        // direction = 0 for undirected graph
        // direction = 1 for directed graph

        // create an edge from u to v
        adj[u].push_back(v);

        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    void printAdjList() {
        for (auto i : adj) {
            cout << i.first << "->";
            for (auto j : i.second) {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};



void prepareAdjacencyList(const vector<pair<int, int>> &edge, unordered_map<int, vector<int>> &adj) {
    for (const auto &e : edge) {
        int u = e.first;
        int v = e.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs(const unordered_map<int, vector<int>> &adj, vector<int> &ans, unordered_map<int, bool> &visited, int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();

        // Store frontNode into ans vector
        ans.push_back(frontNode);

        // Traverse all neighbors of frontNode
        for (int i : adj.at(frontNode)) { // Using .at() for safety
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, const vector<pair<int, int>> &edge) {
    unordered_map<int, vector<int>> adj;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjacencyList(edge, adj);

    for (int i = 0; i < vertex; ++i) {
        if (!visited[i]) {
            bfs(adj, ans, visited, i);
        }
    }

    return ans;
}


// ....dfs.....

// DFS function to traverse the graph
void dfs(const unordered_map<int, vector<int>> &adj, vector<int> &temp, vector<bool> &visited, int u) {
    visited[u] = true;
    temp.push_back(u);

    // Recursive call for every unvisited neighbor
    if (adj.find(u) != adj.end()) { // Check if the node has neighbors
        for (int neighbor : adj.at(u)) {
            if (!visited[neighbor]) {
                dfs(adj, temp, visited, neighbor);
            }
        }
    }
}

// Main function to perform DFS on all components of the graph
vector<vector<int>> DFShead(int V, const vector<pair<int, int>> &edges) {
    unordered_map<int, vector<int>> adjList;
    vector<bool> visited(V, false);
    vector<vector<int>> ans;

    // Prepare the adjacency list
    prepareAdjacencyList(edges, adjList);

    // Perform DFS for each component
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            vector<int> temp;
            dfs(adjList, temp, visited, i);
            ans.push_back(temp);
        }
    }

    return ans;
}

// Example usage
int main() {
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}
    };
    int vertexCount = 5;

    vector<vector<int>> dfsResult = DFShead(vertexCount, edges);

    // Print DFS traversal order for each component
    cout << "DFS Traversal Order:" << endl;
    for (const auto &component : dfsResult) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}



// int main() {
//     int vertex = 5;
//     vector<pair<int, int>> edges = {{0, 1}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4}};

//     vector<int> bfsResult = DFShead(vertex, 7,edges);

//     for (int node : bfsResult) {
//         cout << node << " ";
//     }

//     return 0;
// }




// int main() {
//     int n;
//     cout << "Enter the number of nodes: ";
//     cin >> n;

//     int m;
//     cout << "Enter the number of edges: ";
//     cin >> m;

//     graph<int> g;

//     cout << "Enter edges (u v): " << endl;
//     for (int i = 0; i < m; i++) {
//         int u, v;
//         cin >> u >> v;
//         g.addEdge(u, v, 0);  
//     }

//     g.printAdjList();

//     return 0;
// }

