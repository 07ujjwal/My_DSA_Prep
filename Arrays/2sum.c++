#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        // Create a vector of pairs to keep track of the original indices after sorting
        vector<pair<int, int>> numsWithIndices;
        for (int i = 0; i < nums.size(); ++i) {
            numsWithIndices.push_back({nums[i], i});
        }

        // Sort the vector of pairs based on the first element (the value of nums)
        sort(numsWithIndices.begin(), numsWithIndices.end());

        int left = 0;
        int right = numsWithIndices.size() - 1;

        while (left < right) {
            int sum = numsWithIndices[left].first + numsWithIndices[right].first;

            if (sum > target) {
                right--;
            } else if (sum < target) {
                left++;
            } else {
                ans.push_back(numsWithIndices[left].second);
                ans.push_back(numsWithIndices[right].second);
                break;  // Break out of the loop since we found the answer
            }
        }

        return ans;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);

    cout << "Indices: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
