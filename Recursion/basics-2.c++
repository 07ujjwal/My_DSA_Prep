#include <iostream>
#include <bits/stdc++.h>

using namespace std;


// paramaterised way.....
void sumOfNNumbersParameter(int n, int sum){
    if(n < 1){
        cout << sum;
        return;
    };
     
   sumOfNNumbersParameter(n-1, sum + n);
}


int sumOfNNumbersFunctionsl(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sumOfNNumbersFunctionsl(n - 1);
}


void reverseAnArray(vector<int> &nums, int i) {
    int n = nums.size();
    if (i >= n / 2) {
        return;
    }

    swap(nums[i], nums[n - i - 1]);
    
    reverseAnArray(nums, i + 1);
}


bool isPallindrome(string s, int i){
     int n = s.length();
     if(s[i] >= n/2){
        return false;
     }
     
     if(s[i] != s[n-i-1]){
        return false;
     }

    return isPallindrome(s, i + 1);
}


int fibonacchi(int n){
    if(n == 0){
        return 0;
    }

    if(n == 1){
        return 1;
    }

    return fibonacchi(n-1) + fibonacchi(n-2);
}


void printSubSequence(int ind, vector<int> &ds, int arr[], int n) {
    if(ind == n){
        for(auto it : ds) {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    // Include the current element in the subsequence
    ds.push_back(arr[ind]);
    printSubSequence(ind + 1, ds, arr, n);
    
    // Backtrack and do not include the current element in the subsequence
    ds.pop_back();
    printSubSequence(ind + 1, ds, arr, n);
}



int main() {
    // int n = 10; 
    // //int sum = sumOfNNumbersFunctionsl(n);
    //  sumOfNNumbersParameter(n, 0);
    // //cout << "The sum of the first " << n << " natural numbers is: " << sum << endl;
    // return 0;

    // vector<int> nums = {1, 2, 3, 4, 5};
    
    // cout << "Original array: ";
    // for (int num : nums) {
    //     cout << num << " ";
    // }
    // cout << endl;

    // reverseAnArray(nums, 0);
    
    // cout << "Reversed array: ";
    // for (int num : nums) {
    //     cout << num << " ";
    // }d

    // return 0;

    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ds;
    printSubSequence(0, ds, arr, n);
    return 0;
}

