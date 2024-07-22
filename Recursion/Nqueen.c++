#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // This function checks if placing a queen at board[row][col] is safe
    bool isSafe1(int row, int col, vector<string> board, int n) {
        // Check upper diagonal on left side
        int duprow = row;
        int dupcol = col;

        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        // Reset row and col to original values
        col = dupcol;
        row = duprow;

        // Check left side
        while (col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        // Reset row and col to original values
        row = duprow;
        col = dupcol;

        // Check lower diagonal on left side
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }

public:
    // Recursive function to solve the N-Queens problem
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        // Base case: If all queens are placed, add the board to the result
        if (col == n) {
            ans.push_back(board);
            return;
        }

        // Try placing a queen in each row of the current column
        for (int row = 0; row < n; row++) {
            // If it's safe to place the queen at board[row][col]
            if (isSafe1(row, col, board, n)) {
                // Place the queen
                board[row][col] = 'Q';
                // Recur to place the rest of the queens
                solve(col + 1, board, ans, n);
                // Backtrack: Remove the queen and try the next position
                board[row][col] = '.';
            }
        }
    }

public:
    // Function to initialize the board and call the solver function
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; // To store the final arrangements
        vector<string> board(n); // To store the current arrangement of the board
        string s(n, '.'); // Initialize an empty row
        for (int i = 0; i < n; i++) {
            board[i] = s; // Initialize the board with empty rows
        }
        solve(0, board, ans, n); // Start solving from the first column
        return ans; // Return all the valid arrangements
    }
};

int main() {
    int n = 4; // We are taking a 4x4 grid and 4 queens
    Solution obj; // Create an instance of the Solution class
    vector<vector<string>> ans = obj.solveNQueens(n); // Get all solutions

    // Print all the arrangements
    for (int i = 0; i < ans.size(); i++) {
        cout << "Arrangement " << i + 1 << "\n";
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
