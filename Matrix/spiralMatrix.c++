#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = m - 1;

        vector<int> ans;

        while (top <= bottom && left <= right) {
            // Traverse from left to right along the top row
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // Traverse from top to bottom along the right column
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // Traverse from right to left along the bottom row, if needed
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Traverse from bottom to top along the left column, if needed
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    Solution solution;

    vector<int> result1 = solution.spiralOrder(matrix1);
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> result2 = solution.spiralOrder(matrix2);
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
