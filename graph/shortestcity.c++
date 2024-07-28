#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>

using namespace std;

class Solution {
public:
    #define p pair<int, int>

    int findResultCity(int n, vector<vector<int>> &ShortestPathMatrix, int distanceThreshold) {
        int resultCity = -1;
        int lowestCount = INT16_MAX;

        for (int i = 0; i < n; i++) {
            int Count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && ShortestPathMatrix[i][j] <= distanceThreshold) {
                    Count++;
                }
            }

            if (Count <= lowestCount) {
                lowestCount = Count;
                resultCity = i;
            }
        }

        return resultCity;
    }

    void dijkstra(int n, unordered_map<int, vector<p>> &adjList, vector<int> &result, int source) {
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, source});
        result[source] = 0;

        while (!pq.empty()) {
            auto topNode = pq.top();
            pq.pop();

            int distanceNode = topNode.first;
            int node = topNode.second;

            for (auto &neighbour : adjList[node]) {
                int neighbourNode = neighbour.first;
                int weight = neighbour.second;

                if (weight + distanceNode < result[neighbourNode]) {
                    result[neighbourNode] = weight + distanceNode;
                    pq.push(make_pair(result[neighbourNode], neighbourNode));
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> ShortestPathMatrix(n, vector<int>(n, INT16_MAX));

        for (int i = 0; i < n; i++) {
            ShortestPathMatrix[i][i] = 0;
        }

        unordered_map<int, vector<p>> adjList;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        for (int i = 0; i < n; i++) {
            vector<int> result(n, INT16_MAX);
            dijkstra(n, adjList, result, i);
            ShortestPathMatrix[i] = result;
        }

        return findResultCity(n, ShortestPathMatrix, distanceThreshold);
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> edges = {
        {0, 1, 3},
        {1, 2, 1},
        {1, 3, 4},
        {2, 3, 1}
    };
    int distanceThreshold = 4;

    int city = sol.findTheCity(n, edges, distanceThreshold);
    cout << "The city with the smallest number of neighbors at a threshold distance is: " << city << endl;

    return 0;
}
