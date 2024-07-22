#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
       
       vector<int> ans;

        for (int i = 0; i < matrix.size(); i++)
        {
            int min_el = *min_element(matrix[i].begin(), matrix[i].end());
            int minIndex = min_element(matrix[i].begin(), matrix[i].end()) - matrix[i].begin();

              bool isMaxInColumn = true;

              for (int k = 0; k < matrix.size(); k++) {
                 if (matrix[k][minIndex] > min_el) {
                    isMaxInColumn = false;
                    break;
                }
              }

               if (isMaxInColumn) {
                ans.push_back(min_el);
            }
        }
        
         return ans;
    }


    vector<int> luckyNumbersBrute(vector<vector<int>>& matrix) {
       int m = matrix.size();
       int n = matrix[0].size();
       vector<int> max_arr;
       vector<int> min_arr;
       vector<int> ans;

       for(int row = 0; row<n; row++){
           int min_element = INT16_MAX;
           for (int col = 0; col < m; col++)
           {
              min_element = min(min_element, matrix[row][col]);
           }
           min_arr.push_back(min_element);
       }

       for(int col = 0; col<m; col++){
           int max_element = INT16_MIN;
           for (int row = 0; row < n; row++)
           {
              max_element = max(max_element, matrix[row][col]);
           }
           max_arr.push_back(max_element);
       }

        for (int row = 0; row < n; row++)
        {
           for (int col = 0; col < m; col++)
           {
              if(matrix[row][col] == min_arr[row] && matrix[row][col] == max_arr[col]){
                  ans.push_back(matrix[row][col]);
              }
           }
           
        }
        
        return ans;
    }

};




   int main() {
    vector<vector<int>> matrix = {{1, 2, 5}, {3, 5, 7}, {6, 8, 9}};
    
    Solution s;
    vector<int> result1 = s.luckyNumbers(matrix);
    vector<int> result2 = s.luckyNumbersBrute(matrix);

    // Print results
    cout << "Lucky Numbers (Optimized): ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Lucky Numbers (Brute): ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
