#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <limits>

using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> adjList;

        // Build the adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> distance_1(n, numeric_limits<int>::max());
        vector<int> distance_2(n, numeric_limits<int>::max());

        distance_1[0] = 0;

        set<pair<int, int>> st; // (time, node) pairs
        st.insert({0, 0});

        while (!st.empty()) {
            auto topNode = (*st.begin());
            st.erase(st.begin());

            int node = topNode.second;
            int nodetime = topNode.first;

            // Calculate wait time if the signal is red
            int div = nodetime / change;
            if (div % 2 == 1) {
                nodetime = change * (div + 1);
            }

            for (auto ngbr : adjList[node]) {
                int newTime = nodetime + time;

                if (newTime < distance_1[ngbr]) {
                    distance_2[ngbr] = distance_1[ngbr];
                    distance_1[ngbr] = newTime;

                    st.insert({newTime, ngbr});
                } else if (newTime > distance_1[ngbr] && newTime < distance_2[ngbr]) {
                    distance_2[ngbr] = newTime;

                    st.insert({newTime, ngbr});
                }
            }

            if (node == n - 1 && distance_2[n - 1] != numeric_limits<int>::max()) {
                return distance_2[n - 1];
            }
        }

        return -1;
    }
};
