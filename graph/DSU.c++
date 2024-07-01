#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <limits>

using namespace std;

int find(int i, vector<int> &parent){
    if(i == parent[i]){
        return i;
    }

    // path compression.....
    return parent[i] = find(parent[i], parent);

};




void unionXY(int x, int y, vector<int> &rank , vector<int> &parent) {
     int x_parent = find(x, parent);
     int y_parent = find(y, parent);
     
     if(x_parent == y_parent){
        return;
     }

     if(rank[x_parent] > rank[y_parent]){
        parent[y_parent] = x_parent;
     }else if(rank[x_parent] < rank[y_parent]){
        parent[x_parent] =y_parent;
     }else{
        parent[x_parent] = y_parent;
        rank[y_parent]++;
     }
}


