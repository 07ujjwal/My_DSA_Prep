#include <vector>
#include <iostream>
using namespace std;

class BinarySearch {
public:
    // Iterative binary search function
    bool binarySearch(vector<int>& nums, int target) {
        int start = 0; // Start index of the search range
        int end = nums.size() - 1; // End index of the search range

        // Continue searching while the search range is valid
        while (start <= end) {
            // Calculate the mid-point of the current search range
            int mid = (start + end) / 2;

            // If the mid-point element is greater than the target, narrow the search range to the left half
            if (nums[mid] > target) {
                end = mid - 1;
            }
            // If the mid-point element is less than the target, narrow the search range to the right half
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            // If the mid-point element is equal to the target, return true
            else {
                return true;
            }
        }

        // If the target is not found, return false
        return false;
    }

    // Recursive binary search function
    bool recursive(vector<int>& nums, int low, int high, int target) {
        // Base case: if the search range is invalid, return false
        if (low > high) {
            return false;
        }

        // Calculate the mid-point of the current search range
        int mid = low + (high - low) / 2;

        // If the mid-point element is equal to the target, return true
        if (nums[mid] == target) {
            return true;
        }
        // If the target is greater than the mid-point element, search the right half
        else if (target > nums[mid]) {
            return recursive(nums, mid + 1, high, target);
        }
        // If the target is less than the mid-point element, search the left half
        else {
            return recursive(nums, low, mid - 1, target);
        }
    }

    // Function to find the floor of a given number x in a sorted vector
    int findFloor(vector<long long>& nums, long long n, long long x) {
        long long s = 0; // Start index of the search range
        long long e = n - 1; // End index of the search range
        long long ans = -1; // Variable to store the floor value

        // Continue searching while the search range is valid
        while (s <= e) {
            // Calculate the mid-point of the current search range
            long long m = s + (e - s) / 2;

            // If the mid-point element is less than or equal to x, it is a potential floor value
            if (nums[m] <= x) {
                ans = nums[m]; // Update the floor value
                s = m + 1; // Narrow the search range to the right half
            } 
            // If the mid-point element is greater than x, narrow the search range to the left half
            else {
                e = m - 1;
            }
        }

        // Return the floor value, or -1 if no floor value is found
        return ans;
    }
};


int main(){

    vector<int> nums = {1,3,5, 6,8,12};
    int num;
    
    cout << "Enter the number"<< endl;

    cin >> num;

    BinarySearch bs;

    if(bs.recursive(nums, 0, nums.size() - 1, num)){
       cout << num << " Is Present in the array";
    }else{
        cout << num << " Is not Present in the array";
    }    


    return 0;
}