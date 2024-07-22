#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void findCombination(int target, int k, vector<int>& temp, vector<vector<int>>& result, int start) {
        if (temp.size() == k) {
            if (target == 0) {
                result.push_back(temp);
            }
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (i > target) {
                break;  
            }
            temp.push_back(i);
            findCombination(target - i, k, temp, result, i + 1);
            temp.pop_back();  
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp;
        findCombination(n, k, temp, result, 1);
        return result;
    }
};

int main() {
    Solution s;
    
    vector<pair<int, int>> testCases = {
        {3, 7}, // Example 1
        {3, 9}, // Example 2
        {4, 1}  // Example 3
    };

    for (const auto& testCase : testCases) {
        int k = testCase.first;
        int n = testCase.second;
        vector<vector<int>> result = s.combinationSum3(k, n);
        
        cout << "Combinations for k = " << k << ", n = " << n << " are:" << endl;
        for (const auto& combination : result) {
            cout << "[";
            for (int num : combination) {
                cout << num << " ";
            }
            cout << "]" << endl;
        }
        cout << endl;
    }

    return 0;
}
