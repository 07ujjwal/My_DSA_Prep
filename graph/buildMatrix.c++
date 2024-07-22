#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

// Function to perform topological sort
vector<int> topologicalSort(int k, vector<vector<int>>& conditions) {
    vector<int> indegree(k + 1, 0);
    unordered_map<int, vector<int>> graph;
    
    for (const auto& condition : conditions) {
        int u = condition[0], v = condition[1];
        graph[u].push_back(v);
        indegree[v]++;
    }
    
    queue<int> q;
    for (int i = 1; i <= k; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> order;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);
        for (int neighbor : graph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    if (order.size() == k) {
        return order;
    } else {
        return {};
    }
}

vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    vector<int> rowOrder = topologicalSort(k, rowConditions);
    vector<int> colOrder = topologicalSort(k, colConditions);
    
    if (rowOrder.empty() || colOrder.empty()) {
        return {};
    }
    
    unordered_map<int, int> rowPos, colPos;
    for (int i = 0; i < k; ++i) {
        rowPos[rowOrder[i]] = i;
        colPos[colOrder[i]] = i;
    }
    
    vector<vector<int>> matrix(k, vector<int>(k, 0));
    
    for (int num = 1; num <= k; ++num) {
        matrix[rowPos[num]][colPos[num]] = num;
    }
    
    return matrix;
}

int main() {
    int k = 3;
    vector<vector<int>> rowConditions = {{1, 2}, {3, 2}};
    vector<vector<int>> colConditions = {{2, 1}, {3, 2}};
    
    vector<vector<int>> result = buildMatrix(k, rowConditions, colConditions);
    
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
