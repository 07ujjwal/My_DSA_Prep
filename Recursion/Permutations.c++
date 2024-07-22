#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    void findPermutation(vector<vector<int>> &ans, vector<int> &nums, vector<int> &temp, vector<int> &indexArr, int index) {
        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (indexArr[i] == 0) {
                temp.push_back(nums[i]);
                indexArr[i] = 1;

                findPermutation(ans, nums, temp, indexArr, index + 1);

                indexArr[i] = 0;
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> indexArr(nums.size(), 0);

        findPermutation(ans, nums, temp, indexArr, 0);

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.permute(nums);

    for (const auto &perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
