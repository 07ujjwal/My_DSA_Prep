#include <iostream>
#include <bits/stdc++.h>


using namespace std;


vector<int> bellmonFord(int n, int m, int source, vector<vector<int>> &edges) {
    vector<int> diatance(n+1, 1e9);
    distance[source] = 0;

    for(int i = 0; i<=n; i++){
        // formula...

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(distance[u] != le9 && (diatance[u] + w < distance[v])){
                distance[v] = distance[u] + w;
            }
        }
    }

    // negitive cycle

    bool flag = 0;
     for(int i = 0; i<=n; i++){
        // formula...

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(distance[u] != le9 && (diatance[u] + w < distance[v])){
               flag = 1;
            }
        }
    }

    if(flag == 0){
        return distance;
    }

    return -1;
}