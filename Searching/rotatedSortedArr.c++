#include <vector>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
            int low = 0;
            int high = nums.size()-1;
            int ans = -1;

            while(low <= high){
                int mid = low + (high - low)/2;

                if(nums[mid] == target){
                   ans = mid;
                }

                if(nums[low] <= nums[mid]){
                        if(nums[low] <= target && target <= nums[mid]){
                            high = mid - 1;
                        }else{
                            low = mid + 1;
                        }

                }else{
                  if(nums[mid] <= target && target <= nums[high]){
                             low = mid + 1;
                        }else{
                            high = mid - 1;
                        }
                }
            }

            return ans;
    }

 bool searchInARotatedSortedArrayII(vector<int>&arr, int k) {
    int n = arr.size(); // size of the array.
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return true;

        //Edge case:
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return false;
}

// minimum in arotated sorted array....

int findMin(vector<int>& nums) {
        int ans = INT16_MAX;

        int low = 0;
        int high = nums.size()-1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1;
            }else{
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }


// finding the point of rotation....
// index of the minimum...

int findKRotation(int arr[], int n) {
  int min_v = INT16_MAX;
  int ans = 0;
  
  int low = 0;
  int high = n-1;

  while (low <= high){
     int mid = low + (high - low)/2;

     if(arr[low] <= arr[mid]){
        min_v = min(min_v, arr[low]);
        if(arr[low] < min_v){
            ans = low;
        }
        low = mid + 1;
     }else{
        min_v = min(min_v, arr[mid]);
        if(arr[mid] < min_v){
            ans = mid;
        }
        high = mid - 1;
     }
  }

  return ans;

}

// singhle element in a sorted array.......


int singleNonDuplicate(vector<int>& nums) {
  int n = nums.size();
  int low = 1;
  int high = n-2;

  if(n == 1) return nums[0];

  if(nums[0] != nums[low]) return nums[0];

  if (nums[n - 1] != nums[n - 2]) return nums[n - 1];
  
  while(low <= high){
    int mid = low + (high - low) / 2;

    if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){
        return nums[mid];
    }

    if((mid % 2 == 1 && nums[mid] == nums[mid-1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1])){
        low = mid + 1;
    }else{
        high = mid - 1;
    }
  }
  return -1;
}


};