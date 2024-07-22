#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void findSubsetSum(vector<int> &ans, vector<int> &arr, int sum, int index) {
        if (index == arr.size()) {
            ans.push_back(sum);
            return;
        }
        
        // Include the current element in the sum
        findSubsetSum(ans, arr, sum + arr[index], index + 1);
        
        // Exclude the current element from the sum
        findSubsetSum(ans, arr, sum, index + 1);
    }   
    
public:
    vector<int> subsetSums(vector<int> &arr, int n) {
        vector<int> ans;
        findSubsetSum(ans, arr, 0, 0);
        return ans;
    }


 private:
 void findSubset(vector<int>& nums,  set<vector<int>>& ans, vector<int> &temp, int index){
        if(index == nums.size()){
            ans.insert(temp);
            return;
        }
      
        temp.push_back(nums[index]);

        findSubset(nums, ans, temp, index + 1);
        
        temp.pop_back();

        findSubset(nums, ans, temp, index + 1);
        
 }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end()); 
        findSubset(nums, ans, temp, 0);

        vector<vector<int>> result(ans.begin(), ans.end());
        return result;
    }   
};

int main() {
    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    
    Solution s;
    vector<int> result = s.subsetSums(arr, n);
    
    cout << "Subset sums are: ";
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;
    
    return 0;
}
