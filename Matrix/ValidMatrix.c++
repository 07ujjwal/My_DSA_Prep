#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> ans(n, vector<int>(m, 0));

        int i = 0;
        int j = 0;

        while (i < n && j < m) {
            ans[i][j] = min(rowSum[i], colSum[j]);

            rowSum[i] -= ans[i][j];
            colSum[j] -= ans[i][j];

            if (rowSum[i] == 0) {
                i++;
            }

            if (colSum[j] == 0) {
                j++;
            }
        }
        
        return ans;
    }
};

int main() {
    vector<int> rowSum = {3, 8, 7};
    vector<int> colSum = {5, 7, 6};

    Solution s;
    vector<vector<int>> result = s.restoreMatrix(rowSum, colSum);

    cout << "Restored Matrix:" << endl;
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
