#include <bits/stdc++.h>
using namespace std;




class Solution {
//Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
// sol:   r-1Cc-1.
// where nCr = n! / (r! * (n-r)!)

   private:
   int ncr(int n, int r){
    long long res = 1;

     for(int i = 0; i<r; i++){
         res = res * (n-i);
         res = res / (i+1);
      }

      return res;
   }

   public:
    int position(int r, int c) {
       int element = ncr(r-1, c-1);
       return element;
    }

 //Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.  
 //sol: nth row of the triangle has exactly n elements...
   
   void printRow(int n){
    for(int c = 1; c<=n; c++){
        cout << ncr(n - 1, c - 1) << " ";
    }
    cout << "n";
   }
  
 //Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.

   vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int row = 1; row <=numRows ; row++){
             vector<int> temp;
             for(int col = 1; col <= row; col++){
                temp.push_back(ncr(row-1, col-1));
             }
             ans.push_back(temp);
        }
        return ans;
    }

};


int main() {
   
    int r = 5; // row number
    int c = 3; // col number
    Solution sl;
    vector<vector<int>> ans = sl.generate(r);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "n";
    }

    return 0;
}