#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t){
    unordered_map<int, list<int>> adjList;

    // Create adjacency list
    for(auto& edge : edges){
        adjList[edge.first].push_back(edge.second);
        adjList[edge.second].push_back(edge.first);
    }

    // BFS
    vector<int> visited(n, 0);
    vector<int> parent(n, -1);

    queue<int> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto neighbor : adjList[node]){
            if(!visited[neighbor]){
                visited[neighbor] = 1;
                parent[neighbor] = node;
                q.push(neighbor);
                if (neighbor == t) { // Stop BFS when target is reached
                    break;
                }
            }
        }
    }

    // Prepare the shortest path
    vector<int> ans;
    int currentNode = t;
    
    // If target is not reachable from source
    if (parent[t] == -1 && s != t) {
        return ans;
    }

    while (currentNode != -1){
        ans.push_back(currentNode);
        currentNode = parent[currentNode];
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}



// shortest path in directed asyclic graph....

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back(make_pair(v, weight));
    }

    void printGraph() {
        for (auto a : adjList) {
            cout << a.first << ": ";
            for (auto b : a.second) {
                cout << "(" << b.first << ", " << b.second << ") ";
            }
            cout << endl;
        }
    }

    void dfs(int node, vector<int>& visited, stack<int>& topo) {
        visited[node] = 1;

        for (auto neighbor : adjList[node]) {
            if (!visited[neighbor.first]) {
                dfs(neighbor.first, visited, topo);
            }
        }

        topo.push(node);
    }

    void getShortestPath(int src, vector<int>& dist, stack<int>& topo) {
        dist[src] = 0;

        while (!topo.empty()) {
            int node = topo.top();
            topo.pop();

            if (dist[node] != INT_MAX) {
                for (auto neighbor : adjList[node]) {
                    if (dist[neighbor.first] > dist[node] + neighbor.second) {
                        dist[neighbor.first] = dist[node] + neighbor.second;
                    }
                }
            }
        }
    }
};

vector<int> shortestPathDAG(vector<pair<int, pair<int, int>>> edges, int v, int s) {
    Graph g;

    for (auto& edge : edges) {
        g.addEdge(edge.first, edge.second.first, edge.second.second);
    }

    vector<int> visited(v, 0);
    stack<int> st;

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            g.dfs(i, visited, st);
        }
    }

    vector<int> dist(v, INT_MAX);
    g.getShortestPath(s, dist, st);

    return dist;
}


int main() {
    vector<pair<int, pair<int, int>>> edges = {
        {0, {1, 2}}, {0, {4, 1}}, {1, {2, 3}}, {2, {3, 6}},
        {4, {2, 2}}, {4, {5, 4}}, {5, {3, 1}}
    };
    int v = 6;
    int s = 0;

    vector<int> shortestPaths = shortestPathDAG(edges, v, s);

    for (int i = 0; i < shortestPaths.size(); i++) {
        if (shortestPaths[i] == INT_MAX) {
            cout << "INF ";
        } else {
            cout << shortestPaths[i] << " ";
        }
    }
    cout << endl;

    return 0;
}



// int main() {
//     vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {0, 4}};
//     int n = 5;
//     int m = edges.size();
//     int s = 0;
//     int t = 3;

//     vector<int> path = shortestPath(edges, n, m, s, t);
    
//     for (int node : path) {
//         cout << node << " ";
//     }

//     return 0;
// }
