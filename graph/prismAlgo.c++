#include <iostream>
#include <bits/stdc++.h>
#include <list>

using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for(int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // Start from the first node (assuming 1-based indexing)
    key[1] = 0;
    parent[1] = -1;

    for(int i = 0; i < n; i++) {
        int mini = INT_MAX;
        int u;

        // Find the node with the minimum key value that is not yet included in MST
        for(int v = 1; v <= n; v++) {
            if(mst[v] == false && key[v] < mini) {
                mini = key[v];
                u = v;
            }
        }

        // Mark the picked node as included in MST
        mst[u] = true;

        // Update key values and parent index of the adjacent vertices
        for(auto it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if(mst[v] == false && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;

    // Construct the answer vector from parent array and key array
    for(int i = 2; i <= n; i++) {
        ans.push_back({{parent[i], i}, key[i]});
    }

    return ans;
}

int main() {
    // Example usage
    int n = 5; // Number of nodes
    int m = 7; // Number of edges
    vector<pair<pair<int, int>, int>> g = {
        {{1, 2}, 2},
        {{1, 3}, 3},
        {{2, 3}, 1},
        {{2, 4}, 4},
        {{3, 4}, 5},
        {{3, 5}, 6},
        {{4, 5}, 7}
    };

    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, g);

    cout << "Edges in MST are:" << endl;
    for(auto edge : mst) {
        cout << edge.first.first << " - " << edge.first.second << " with weight " << edge.second << endl;
    }

    return 0;
}
