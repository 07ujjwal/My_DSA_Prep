#include <bits/stdc++.h>
#include <string>
using namespace std;
class Solution {
public:
     long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
         const int INF = 1e9;
         vector<vector<int>> dist(26, vector<int>(26, INF));

         // Initialize the distance to zero for same characters
        for (int i = 0; i < 26; ++i) {
            dist[i][i] = 0;
        }

        // Populate the initial distances based on the given transformations
        for (int i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]);
        }
        
        // Floyd-Warshall algorithm to find shortest paths between all pairs of nodes
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long totalCost = 0;

        // Calculate the minimum cost to convert source to target
        for (int i = 0; i < source.size(); ++i) {
            int src = source[i] - 'a';
            int tgt = target[i] - 'a';

            if (dist[src][tgt] == INF) {
                return -1;  // If tgt is not reachable from src
            }

            totalCost += dist[src][tgt];
        }

        return totalCost;
    }
};

//498-434-226-459

int main() {
    Solution sol;
    string source = "abcd";
    string target = "acbe";
    vector<char> original = {'a', 'b', 'c', 'c', 'e', 'd'};
    vector<char> changed = {'b', 'c', 'b', 'e', 'b', 'e'};
    vector<int> cost = {2, 5, 5, 1, 2, 20};

    long long result = sol.minimumCost(source, target, original, changed, cost);
    if (result != -1) {
        cout << "Minimum cost: " << result << endl;
    } else {
        cout << "Transformation not possible" << endl;
    }

    return 0;
}
