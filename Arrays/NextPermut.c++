#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
   vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size(); // size of the array.

    // Step 1: Find the break point:
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            // index i is the break point
            ind = i;
            break;
        }
    }

    // If break point does not exist:
    if (ind == -1) {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: reverse the right half:
    reverse(A.begin() + ind + 1, A.end());

    return A;
}


// leaders in an array..

vector<int> leaders( vector<int>& arr) {
    vector<int> leaders;
    int n = arr.size();

    int max_right = arr[n - 1]; 
    leaders.push_back(max_right);

    // Iterate from second last to first element
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= max_right) {
            leaders.push_back(arr[i]);
            max_right = arr[i];
        }
    }

    // Reverse the leaders vector to get the correct order
    reverse(leaders.begin(), leaders.end());

    return leaders;
    }

 vector<int> leadersexp(vector<int>& arr) {
    vector<int> leaders;
    int n = arr.size();

     leaders.push_back(arr[n - 1]); 
   
    // Iterate from second last to first element
    for (int i = n - 2; i >= 0; i--) {
        if (leaders[n-i] >= arr[i]) {
            leaders.push_back(arr[i]);
        }
    }

    // Reverse the leaders vector to get the correct order
    reverse(leaders.begin(), leaders.end());

    return leaders;
    }   

    
};


int main() {
    
    vector<int> arr = {5,4,3,2,1};

    Solution sl;

   vector<int> ans =  sl.leaders(arr);

   for(auto a: ans){
    cout << a << " ";
   }

    return 0;
}