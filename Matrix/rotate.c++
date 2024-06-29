#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotateBrute(vector<vector<int>>& matrix) {
  
        int n = matrix.size();
        if(n == 0) return;
        vector<vector<int>> temp(n, vector<int>(n));

      // Perform the rotation by copying elements to the temporary matrix
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
              temp[j][n - 1 - i] = matrix[i][j];
            }
        }

       for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                matrix[i][j] = temp[i][j];
            }
       }

    }

 void rotate(vector < vector < int >> & matrix) {
    int n = matrix.size();
    //transposing the matrix
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
    }
    //reversing each row of the matrix
    for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
    }
  }

  // findingPeekOfmatix......

  

  
     vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0, high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int maxCol = 0;
            // Find the column index of the maximum element in the mid row
            for (int j = 0; j < n; ++j) {
                if (mat[mid][j] > mat[mid][maxCol]) {
                    maxCol = j;
                }
            }
            
            // Compare with the element above
            bool isTopGreater = mid > 0 && mat[mid - 1][maxCol] > mat[mid][maxCol];
            // Compare with the element below
            bool isBottomGreater = mid < m - 1 && mat[mid + 1][maxCol] > mat[mid][maxCol];
            
            // If the current element is greater than both above and below, it's a peak
            if (!isTopGreater && !isBottomGreater) {
                return {mid, maxCol};
            }
            // If the element above is greater, move to the upper half
            else if (isTopGreater) {
                high = mid - 1;
            }
            // If the element below is greater, move to the lower half
            else {
                low = mid + 1;
            }
        }
        return {-1, -1}; // This line will never be reached because there's guaranteed to be a peak
    

    }

};



int main() {
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    Solution sl;

    sl.rotateBrute(mat);
    cout<< "[";
    for(auto row : mat){
        cout<< "[";
        for(auto r : row){
            cout << " " << r << " ";
        }

        cout << "]";
    }
     cout << "]";

    return 0;
}