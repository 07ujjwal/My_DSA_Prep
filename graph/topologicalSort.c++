#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;


// Function to perform DFS and push nodes onto the stack in topological order
void topologicalDFS(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, stack<int> &stk, int node) {
    // Mark the current node as visited
    visited[node] = true;

    // If the node has neighbors, process each neighbor
    if (adjList.find(node) != adjList.end()) {
        for (auto neighbour : adjList[node]) {
            // If the neighbor hasn't been visited, recursively perform DFS on it
            if (!visited[neighbour]) {
                topologicalDFS(adjList, visited, stk, neighbour);
            }
        }
    }

    // Push the current node onto the stack after processing all neighbors
    stk.push(node);
}

// Function to perform topological sort on a graph represented by edges
vector<int> topologicalSort1(vector<vector<int>> &edges, int v, int e) {
    // Create an adjacency list from the given edges
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    vector<int> result;

    // Fill the adjacency list with edges
    for (int i = 0; i < e; i++) {
        adjList[edges[i][0]].push_back(edges[i][1]);
    }

    // Stack to store the topological order
    stack<int> stk;

    // Perform DFS from each vertex to cover disconnected components
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            topologicalDFS(adjList, visited, stk, i);
        }
    }

    // Extract elements from the stack to get the topological order
    while (!stk.empty()) {
        result.push_back(stk.top());
        stk.pop();
    }

    return result;
}


// Khns algorithm.... using BFS

vector<int> topologicalSort2(vector<vector<int>> &edges, int v, int e){
    unordered_map<int, list<int>> adjList;
    vector<int> result;

    // Fill the adjacency list with edges
    for (int i = 0; i < e; i++) {
        adjList[edges[i][0]].push_back(edges[i][1]);
    }

    // find aLL indegree...

    vector<int> indegree(v);

    for(auto i : adjList) {
        for(auto j : i.second){
            indegree[j]++;
        }
    }

    /// push the 0 indegree into the queue....


    queue<int> q;
    for(int i = 0; i < v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // now the bfs....

    while (!q.empty()) {
    {
       int front = q.front();
       q.pop();

       result.push_back(front);
       for(auto neighbor : adjList[front]){
            indegree[neighbor]--;
            if(indegree[neighbor] == 0){
                q.push(neighbor);
            }
       }
    }

    }
    return result;
    
}


// cycle detection using khans algo....

bool cycleDetection(vector<vector<int>> &edges, int v, int e){
    unordered_map<int, list<int>> adjList;
    int count = 0;

    // Fill the adjacency list with edges
    for (int i = 0; i < e; i++) {
        adjList[edges[i][0]].push_back(edges[i][1]);
    }

    // find aLL indegree...

    vector<int> indegree(v);

    for(auto i : adjList) {
        for(auto j : i.second){
            indegree[j]++;
        }
    }

    /// push the 0 indegree into the queue....


    queue<int> q;
    for(int i = 0; i < v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // now the bfs....

    while (!q.empty()) {
    {
       int front = q.front();
       q.pop();

       count++;
       for(auto neighbor : adjList[front]){
            indegree[neighbor]--;
            if(indegree[neighbor] == 0){
                q.push(neighbor);
            }
       }
    }

    }
   
   if(count == v){
    return false;
   }else{
    return true;
   }
    
}





int main() {
    int v = 6; // Number of vertices
    int e = 6; // Number of edges
    vector<vector<int>> edges = {
        {5, 2},
        {5, 0},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };

    vector<int> result = topologicalSort2(edges, v, e);

    cout << "Topological Sort of the given graph is: ";
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}