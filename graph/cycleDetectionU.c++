#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

template<typename T> 
class Graph {
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction) {
        adjList[u].push_back(v);
        if(direction == 0) {
            adjList[v].push_back(u);
        }
    }

    void printGraph() {
        for (auto i : adjList) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList) {
    unordered_map<int, int> parent;
    parent[src] = -1;
    queue<int> q;

    q.push(src);
    visited[src] = true;

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        for(auto neighbor : adjList[front]) {
            if(visited[neighbor] && neighbor != parent[front]) {
                return true;
            } else if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = front;
            }
        }
    }
    return false;
}

bool isCyclicDFS(int src,int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList) {
    unordered_map<int, int> parent;

    visited[src] = true;
    

    for(auto neighbor : adjList[src]) {
        if(!visited[neighbor]){
          bool isCycle =  isCyclicDFS(neighbor, src,visited, adjList);
           if(isCycle) return true;
        }else if(neighbor != parent){
              return true;
        }
    }

}

string cycleDetection(vector<vector<int>> &edges, int m, int n) {
    Graph<int> g;
    for(int i = 0; i < m; i++) {
        g.addEdge(edges[i][0], edges[i][1], 0);
    }
    unordered_map<int, bool> visited;

    // To handle disconnected components
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            bool ans = isCyclicBFS(i, visited, g.adjList);
            if(ans) {
                return "true";
            }
        }
    }
    return "false";
}


bool  cycleInDirGraph(int src, unordered_map<int, bool> visited, unordered_map<int, bool> dfsVisited ,unordered_map<int, list<int>> &adj){
   visited[src] = true;
   dfsVisited[src] = true;

   for(auto neighbour : adj.at(src)){
      if(!visited[neighbour]){
        bool cycleDetected = cycleInDirGraph(neighbour, visited, dfsVisited, adj);

        if(cycleDetected){
            return true;
        }
      }else if(dfsVisited[neighbour]){
            return true;
      }
   }

   dfsVisited[src] = false;

   return false;
}


int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges){
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for(auto edge: edges){
        int u = edge.first;
        int v = edge.second;

        adj[u].push_back(v);
    }

   for(int i = 1; i<=n ; i++){
      if(!visited[i]){
        bool iscycle =  cycleInDirGraph(i, visited, dfsVisited, adj);
        if(iscycle){
            return 1;
        } 
      }
   }

   return 0;

}




int main() {
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 2}, {2, 3}
    };
    int m = edges.size();
    int n = 4; // number of vertices

    string result = cycleDetection(edges, m, n);
    cout << "Cycle detected: " << result << endl;

    return 0;
}
