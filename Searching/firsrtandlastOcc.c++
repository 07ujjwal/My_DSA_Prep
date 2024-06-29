#include <vector>
#include <iostream>
using namespace std;

int findFirst(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int firstOccurrence = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            firstOccurrence = mid;
            right = mid - 1; // Continue to search in the left half
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return firstOccurrence;
}

int findLast(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int lastOccurrence = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            lastOccurrence = mid;
            left = mid + 1; // Continue to search in the right half
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return lastOccurrence;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result(2, -1);
    
    int first = findFirst(nums, target);
    if (first == -1) {
        return result; // Target not found
    }
    
    int last = findLast(nums, target);
    
    result[0] = first;
    result[1] = last;
    
    return result;
}

int main() {
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> result1 = searchRange(nums1, target1);
    cout << "Result: [" << result1[0] << ", " << result1[1] << "]" << endl;

    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    int target2 = 6;
    vector<int> result2 = searchRange(nums2, target2);
    cout << "Result: [" << result2[0] << ", " << result2[1] << "]" << endl;

    vector<int> nums3 = {};
    int target3 = 0;
    vector<int> result3 = searchRange(nums3, target3);
    cout << "Result: [" << result3[0] << ", " << result3[1] << "]" << endl;

    return 0;
}
