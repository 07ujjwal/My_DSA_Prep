#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void markRow(vector<vector<int>>& matrix, int m, int i) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0 && matrix[i][j] != INT_MIN) {
                matrix[i][j] = INT_MIN;
            }
        }
    }

    void markCol(vector<vector<int>>& matrix, int n, int j) {
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] != 0 && matrix[i][j] != INT_MIN) {
                matrix[i][j] = INT_MIN;
            }
        }
    }

public:
    void setZeroesBrute(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = 0;
        if (n > 0) {
            m = matrix[0].size();
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    markRow(matrix, m, i);
                    markCol(matrix, n, j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == INT_MIN) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

   void setZeroesBetter(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;

        int m = matrix[0].size();
        vector<int> row(n, 0);
        vector<int> col(m, 0);

        // Mark rows and columns that need to be zeroed
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Set the marked rows and columns to zero
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    void setZeroesBetter(vector<vector<int>>& matrix) {
         int n = matrix.size();
        int m = matrix[0].size();

        bool firstRowHasZero = false;
        bool firstColHasZero = false;

        // Check if the first row has any zeros
        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == 0) {
                firstRowHasZero = true;
                break;
            }
        }

        // Check if the first column has any zeros
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                firstColHasZero = true;
                break;
            }
        }

        // Use the first row and column to mark zeros
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Zero out cells based on marks in the first row and column
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero out the first row if needed
        if (firstRowHasZero) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Zero out the first column if needed
        if (firstColHasZero) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};


int main() {
    vector<vector<int>> mat = {{1,1,1},{1,0,1},{1,1,1}};
    Solution sl;

    sl.setZeroesBetter(mat);
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