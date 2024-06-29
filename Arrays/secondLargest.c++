#include <bits/stdc++.h>
using namespace std;

int findSecondLargest(int n, vector<int> &arr) {
    if (n < 2)
        return -1;

    int large = INT_MIN, second_large = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > large) {
            second_large = large;
            large = arr[i];
        } else if (arr[i] > second_large && arr[i] != large) {
            second_large = arr[i];
        }
    }

    return (second_large == INT_MIN) ? -1 : second_large;
}



// Remove duplicates from Sorted array...

class RemoveDuplicates{
    public:
     
     int bruteForce(vector<int>& arr){
        set<int> hashSet;

        for(int i = 0; i<arr.size(); i++){
             hashSet.insert(arr[i]);
        }

       int k = hashSet.size();
       int j = 0;
          for (int x: hashSet) {
           arr[j++] = x;
          }
          return k;
     }


     int optimalSol(vector<int>& arr) {
         int i = 0;
        for(int j = 1; j<arr.size(); j++){
            if(arr[i] != arr[j]){
                i++;
                arr[i] = arr[j];
            }
        }
      
      return i + 1;
    }
};

// Minimum Increment to Make Array Unique....

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                int increment = nums[i - 1] - nums[i] + 1;
                nums[i] += increment;
                count += increment;
            }
        }

        return count;
    }

    int minIncrementForUniqueMap(vector<int>& nums) {
       unordered_map<int, int> index;
       int count = 0;
       int n = nums.size();
       for(int i = 0; i < n; i++){
        int temp = nums[i];
        while (index.find(temp) != index.end())
        {
            temp++;
            count++;
        }
        index[temp] = 1;

       }

       return count;
    }
};



int main(){
   vector<int> nums = {3,2,1,2,1,7};

   Solution s;
  int ans = s.minIncrementForUniqueMap(nums);
   cout<< ans;

   return 0;
}