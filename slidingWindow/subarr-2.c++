#include <bits/stdc++.h>
using namespace std;



// Count Subarrays Where Max Element Appears at Least K Times

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        int max = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int j = 0;

        long long result = 0;
        int count = 0;

        while(j<n){
            if(nums[j] == max){
                 count++;
            }

            while(count == k){
                result += n-j;

                if(nums[i] == max) {
                    count--;
                }

                i++;
            }

            j++;
        }

      return result;
    }


     int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> flipped(n,0);
        int flip_count = 0;
        int flip_indicator = 0;

        for(int i = 0; i<n ;i++){
                if(i >= k){
                    flip_indicator ^= flipped[i-k];
                }

                if(nums[i] ^ flip_indicator == 0){
                     if (i + k > n) {
                      return -1;
                     }

                    flip_count++;
                    flip_indicator ^= 1;
                    flipped[i] = 1;

                }
        }

         return flip_count;
    }
};


int main() {
    Solution sol;
    
    vector<int> nums1 = {1, 3, 2, 3, 1};
    int k1 = 2;
    cout << "Test Case 1: " << sol.countSubarrays(nums1, k1) << endl;  // Output should be calculated based on the logic

    vector<int> nums2 = {4, 4, 4, 4};
    int k2 = 1;
    cout << "Test Case 2: " << sol.countSubarrays(nums2, k2) << endl;  // Output should be calculated based on the logic

    vector<int> nums3 = {2, 1, 4, 4, 2, 4};
    int k3 = 3;
    cout << "Test Case 3: " << sol.countSubarrays(nums3, k3) << endl;  // Output should be calculated based on the logic

    return 0;
}