#include <iostream>
#include <vector>
#include <algorithm> 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool linearSearch(const vector<int>& nums, int num) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == num) {
                return true;
            }
        }
        return false;
    }

    int longestConsecutiveBrute(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int n = nums.size();
        int maxcnt = 0;

        for (int i = 0; i < n; i++) { 
            int x = nums[i];
            int cnt = 1;
            while (linearSearch(nums, x + 1)) {
                x = x + 1;
                cnt++;
            }
            maxcnt = max(maxcnt, cnt);
        }

        return maxcnt;
    }

    int longestConsecutiveBetter(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        sort(nums.begin(), nums.end());
        int sm = INT16_MIN;
        int maxcnt = 0;
        int cnt = 0;
        for(int i = 0; i<nums.size(); i++){
            
            if(nums[i]-1 == sm){
                cnt++;
                sm = nums[i];
            }else{
                cnt = 1;
                sm = nums[i];
            }
            maxcnt = max(maxcnt, cnt);
        }

        return maxcnt;
    }

    int longestSuccessive(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

}
};

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2}; 
    Solution solution;
    int result = solution.longestConsecutiveBetter(nums);
    cout << "Longest consecutive sequence length: " << result << endl;
    return 0;
}
