#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
      int numSubarraysWithSum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        int sum = 0;
        int count = 0;
        
        // Initialize with sum 0 count as 1
        prefixSumCount[0] = 1;
        
        for (int num : nums) {
            sum += num;
            
            // Check if there is a prefix sum that we can subtract to get sum k
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }
            
            // Increment the count of the current prefix sum
            prefixSumCount[sum]++;
        }
        
        return count;
    }

     int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0;
        int oddCount = 0;
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;  // base case: there's one way to have zero odd numbers (an empty subarray)

        for (int num : nums) {
            // If the number is odd, increase the odd count
            if (num % 2 == 1) {
                oddCount++;
            }

            // If there have been (oddCount - k) odd numbers before, it means there is a subarray that ends here with exactly k odd numbers
            if (prefixCount.find(oddCount - k) != prefixCount.end()) {
                count += prefixCount[oddCount - k];
            }

            // Increment the count of the current number of odd numbers in the prefix
            prefixCount[oddCount]++;
        }

        return count;
    }

    int numberOfSubarraysSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int oddCount = 0;
        int left1 = 0, left2 = 0;
        int result = 0;

        for (int right = 0; right < n; ++right) {
            if (nums[right] % 2 != 0) {
                oddCount++;
            }

            // Move left1 to maintain exactly k odd numbers in the window
            while (oddCount > k) {
                if (nums[left1] % 2 != 0) {
                    oddCount--;
                }
                left1++;
            }

            // Move left2 to maintain at least k odd numbers in the window
            left2 = left1;
            while (oddCount == k) {
                if (nums[left2] % 2 != 0) {
                    break;
                }
                left2++;
            }

            // The number of subarrays ending at `right` with exactly k odd numbers
            result += left2 - left1;
        }

        return result;
    }
};