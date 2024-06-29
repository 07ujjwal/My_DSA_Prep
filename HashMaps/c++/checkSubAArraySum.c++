#include <vector>
#include<iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool checkSubarraySum1(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Outer loop starts from each element in the array
        for (int i = 0; i < n; ++i) {
            int sum = nums[i];  // Initialize sum with the current element
            
            // Inner loop extends the subarray to include more elements
            for (int j = i + 1; j < n; ++j) {
                sum += nums[j];  // Add the next element to the sum
                
                // Check if the sum of the current subarray is divisible by k
                if (k == 0) {
                    if (sum == 0) {
                        // If k is 0, check if the sum is 0
                        return true;
                    }
                } else {
                    if (sum % k == 0) {
                        // If k is not 0, check if the sum is divisible by k
                        return true;
                    }
                }
            }
        }
        
        return false;  // Return false if no such subarray is found
    }


   // hashmap sol....

     bool checkSubarraySum2(vector<int>& nums, int k) {
        // HashMap to store the first occurrence of the remainder
        unordered_map<int, int> remainderIndexMap;
        remainderIndexMap[0] = -1; // Handle edge case where subarray starts from the beginning
        int cumSum = 0; // Cumulative sum

        for (int i = 0; i < nums.size(); ++i) {
            cumSum += nums[i]; // Add current element to cumulative sum
            int remainder = (k == 0) ? cumSum : (cumSum % k); // Compute remainder of cumulative sum

            // Check if this remainder has been seen before
            if (remainderIndexMap.find(remainder) != remainderIndexMap.end()) {
                // If the subarray length is at least 2, return true
                if (i - remainderIndexMap[remainder] > 1) {
                    return true;
                }
            } else {
                // Store the index of the first occurrence of this remainder
                remainderIndexMap[remainder] = i;
            }
        }

        return false; // Return false if no such subarray is found
    }
};



//sub arraysum equals to k....

// bruteforce......

int subArrSum(vector<int>& nums, int k){
    int n = nums.size();
    int count = 0;

    for(int i = 0; i<n; i++){

        int sum = nums[i];

        for(int j = i+1; j<n; j++){
        
        sum += nums[j];

        // for(int k = i; k <= j; k++){
        //     sum += nums[k];
        // }

        if(sum % k == 0){
         count++;
        }

        }
    }

    return count;
}

// using prefix count method.....










// longest subarr with sum = k... bruitforce method...


class LongestSubArrWithSumEqualsK {
public:
    int bruteForce(vector<int> &nums, int k) {
        int n = nums.size();
        int len = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;  // Reset sum for each new starting index i

            for (int j = i; j < n; j++) {
                sum += nums[j];

                if (sum == k) {
                    len = max(len, j - i + 1);
                }
            }
        }

        return len;
    }

// optimal if we have 0; -ve and +ve numbers...
    int betterSol(vector<int> a, int k) {
    unordered_map<int, int> prefixSumMpp;
    int maxlen = 0;
    int sum = 0;
    
    for (int i = 0; i < a.size(); i++) {
        sum += a[i];
        
        // Check if the current sum equals to k
        if (sum == k) {
            maxlen = i + 1;
        }

        // Check if there exists a prefix sum that makes the current sum equal to k
        int rem = sum - k;
        if (prefixSumMpp.find(rem) != prefixSumMpp.end()) {
            int length = i - prefixSumMpp[rem];
            maxlen = max(maxlen, length);
        }

        // Add the current sum to the map if it is not already present
        if (prefixSumMpp.find(sum) == prefixSumMpp.end()) {
            prefixSumMpp[sum] = i;
        }
    }

    return maxlen;
  }

   // just for 0 and +ve values

   // two pointer approch..... trim the subarr if the sum 
   // goes beyond k

  int optSol(vector<int>& a, int k){
     
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    int sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
  }
};

int main() {
    vector<int> arr = {1, 4, 5, 6, 7};

    LongestSubArrWithSumEqualsK solution;
    int count = solution.optSol(arr, 5);
    cout << count << endl;  // Output: length of the longest subarray with sum = 5

    return 0;
}
