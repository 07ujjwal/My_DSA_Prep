#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;



class Solution {
public:

  // brute////

    int findCenter(vector<vector<int>>& edges) {
         
         int n = edges.size();
        unordered_map<int, int> adj;

        for (const auto &e : edges) {
        int u = e[0];
        int v = e[1];

        adj[u]++;
        adj[v]++;
    }

    for(auto &it : adj){
         if(it.second == n){
            return it.first;
         }
    }

    return -1;

    }


    // optimal....


     int findCenter2(vector<vector<int>>& edges) {
         
         int n = edges.size();
        unordered_map<int, int> adj;

        for (const auto &e : edges) {
        int u = e[0];
        int v = e[1];

        adj[u]++;
        adj[v]++;
    }

    for(auto &it : adj){
         if(it.second == n){
            return it.first;
         }
    }

    return -1;

    }



    long long maximumImportance(int n, vector<vector<int>>& roads) {
          
          vector<int> degree(n,0);

          for(auto edge : roads){
               int u = edge[0];
               int v = edge[1];

               degree[u]++;
               degree[v]++;
          }


          sort(degree.begin(), degree.end());

          long long value = 1;
          long long sum = 0;

          for (int i = 0; i < n; i++)
          {
              sum += (degree[i] * value);
              value++;
          }
          
       return value;
          
    }


     ///All Ancestors of a Node in a Directed Acyclic Graph

    // bruteforce.... 

      vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
          unordered_map<int, int> adj;


          
       }

// better solution

   void DFS(int ancestor, unordered_map<int, vector<int>> &adj, int i, vector<vector<int>>& result){
     for (auto ngbr : adj[i])
     {
          if(result[ngbr].empty() || result[ngbr].back() != ancestor){
               result[ngbr].push_back(ancestor);
                DFS(ancestor, adj, ngbr, result);
          }
     } 
     
   }

    vector<vector<int>> getAncestorsBetter(int n, vector<vector<int>>& edges) {
          unordered_map<int, vector<int>> adj;
          vector<vector<int>> result(n);

           for(auto edge : edges){
               int u = edge[0];
               int v = edge[1];

               adj[u].push_back(v);
           }


           for(int i = 0; i<n; i++){
               int ancestor = i;

               DFS(ancestor, adj, i, result);
           }

           return result;
          
       }


  // optimal...

   vector<vector<int>> getAncestorsOpt(int n, vector<vector<int>>& edges) {
          unordered_map<int, vector<int>> adj;
          vector<vector<int>> result(n);

           for(auto edge : edges){
               int u = edge[0];
               int v = edge[1];

               adj[u].push_back(v);
           }


           for(int i = 0; i<n; i++){
              vector<int> ancestors;
              vector<int> visited(n, false);
          //     DFS()

           }

           return result;
          
       }

       

};