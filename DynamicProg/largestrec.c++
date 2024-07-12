#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int max_area = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                   if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
         max_area = max(max_area, largestRectangleArea(heights));
        }

        return max_area;
    }

private:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0); 
        int max_area = 0;

        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int h = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                max_area = max(max_area, h * width);
            }
            s.push(i);
        }

        heights.pop_back();
        return max_area;
    }
};
