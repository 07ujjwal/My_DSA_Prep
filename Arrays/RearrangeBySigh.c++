#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        vector<int> positive;
        vector<int> negative;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                positive.push_back(nums[i]);
            } else {
                negative.push_back(nums[i]);
            }
        }
        
        for(int i = 0; i < n / 2; i++) {
            ans.push_back(positive[i]);
            ans.push_back(negative[i]);
        }

        return ans;
    }
};