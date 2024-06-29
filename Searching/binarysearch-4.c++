#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;



class Solution {
public:
    // int countPartitions(vector<int> &a, int maxSum) {
    //     int n = a.size();
    //     int countSubarr = 1;
    //     int current = 0;

    //     for(int i = 0; i<n; i++){
    //         if(current + a[i] <= maxSum){
    //             current += a[i];
    //         }else{
    //             countSubarr++;
    //             current = a[i];
    //         }
    //     }

    //     return countSubarr;
    // }

    // int splitArray(vector<int>& nums, int k) {
    //      int low = *max_element(nums.begin(), nums.end());
    //     //  int high = accumulate(nums.begin(), nums.end(), 0);

    // //     while (low <= high) {
    // //        int mid = (low + high) / 2;
    // //        int partitions = countPartitions(nums, mid);
    // //       if (partitions > k) {
    // //         low = mid + 1;
    // //       }
    // //        else {
    // //          high = mid - 1;
    // //       }
    // //    }
    // // return low;
    // }

    double findMedianSortedArraysBrute(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> temp;  
        int i = 0, j = 0;

        // Merge the two sorted arrays
        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                temp.push_back(nums1[i]);
                i++;
            } else {
                temp.push_back(nums2[j]);
                j++;
            }
        }

        // Add remaining elements from nums1, if any
        while (i < n) {
            temp.push_back(nums1[i]);
            i++;
        }

        // Add remaining elements from nums2, if any
        while (j < m) {
            temp.push_back(nums2[j]);
            j++;
        }

       int totalSize = n + m;
        double ans = 0.0;

        if (totalSize % 2 == 0) {
            // If the total size is even, median is the average of the two middle elements
            ans = ((double)temp[totalSize / 2 - 1] + (double)temp[totalSize / 2]) / 2.0;
        } else {
            // If the total size is odd, median is the middle element
            ans = temp[totalSize / 2];
        }

        return ans;  
        
    }


     double findMedianSortedArraysOpt(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

            

     }
   
};


int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    Solution s;
    cout << "The median of two sorted array is " 
         << s.findMedianSortedArraysBrute(a, b) << '\n';

         return 0;
}