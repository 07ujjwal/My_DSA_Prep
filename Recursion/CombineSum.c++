#include<iostream>
#include<bits/stdc++.h>

using namespace std;


// something of the kind combination will always have recursion in it....
// in a problem having array... given to find a combination
// alwayse use pick and non pick procedure

class Solution {
public:
   void findCombination1(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
       if(index == arr.size()){
          if(target == 0){
            ans.push_back(ds);
          }
          return;
       }


       if(arr[index] <= target){
           ds.push_back(arr[index]);
           findCombination1(index, target - arr[index], arr, ans, ds);
           ds.pop_back();
       }

       findCombination1(index+1, target, arr, ans, ds);
   }

        void findCombination2(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = index; i < arr.size(); i++) {
            // Skip duplicates
            if (i > index && arr[i] == arr[i - 1]) continue;

            // If the current element is greater than the remaining target, break the loop
            if (arr[i] > target) break;

            // Include the current element
            ds.push_back(arr[i]);
            findCombination2(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();  // Backtrack
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector < vector < int >> ans;
      vector < int > ds;
      findCombination1(0, target, candidates, ans, ds);
      return ans;
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end()); 
        findCombination2(0, target, candidates, ans, ds);
        return ans;
    }
};


int main() {
  Solution obj;
  vector < int > v {2,3,6,7};
  int target = 7;

  vector < vector < int >> ans = obj.combinationSum(v, target);
  cout << "Combinations are: " << endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }
}
