#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
        
        for (int num : nums) {
            actualSum += num;
        }
        
        return expectedSum - actualSum;
    }

    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxfreq = 0;
        int freq = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                freq++;
                maxfreq = max(maxfreq, freq);
            }
            else{
                freq = 0;
            }
        }

        return maxfreq;
    }


    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        for (auto& num : mpp) {
            if (num.second == 1) {
                return num.first;
            }
        }

        return -1; 
    }
  
  // union of two sorted arrays
   
  vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
    set<int> tempAns;
    int i = 0;
    int j = 0;
    int n = arr1.size();
    int m = arr2.size();

    while (i < n && j < m) {
        if (arr1[i] == arr2[j]) {
            tempAns.insert(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] > arr2[j]) {
            tempAns.insert(arr2[j]);
            j++;
        } else {
            tempAns.insert(arr1[i]);
            i++;
        }
    }

    // Insert remaining elements from arr1
    while (i < n) {
        tempAns.insert(arr1[i]);
        i++;
    }

    // Insert remaining elements from arr2
    while (j < m) {
        tempAns.insert(arr2[j]);
        j++;
    }

    // Convert set to vector
    vector<int> ans(tempAns.begin(), tempAns.end());
    return ans;
}

vector < int > OptimisedUnion(int arr1[], int arr2[], int n, int m) {
  int i = 0, j = 0; // pointers
  vector < int > Union; // Uninon vector
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) // Case 1 and 2
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    } else // case 3
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n) // IF any element left in arr1
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}


};

// Test the function
int main() {
    vector<int> nums = {3, 0, 1};
    Solution sol;
    int missing = sol.missingNumber(nums);
    cout << "Missing number: " << missing << endl;
    return 0;
}
