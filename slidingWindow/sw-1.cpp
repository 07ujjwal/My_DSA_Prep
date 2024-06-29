#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {

//Grumpy Bookstore Owner...
//sliding window approch....

   public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int maxSatisfied = 0;
    int maxUnsatisfied = 0;
    int currentUnsatisfied = 0;

    // Calculate the initial satisfaction without using the special technique
    for (int i = 0; i < customers.size(); i++) {
        if (grumpy[i] == 0) {
            maxSatisfied += customers[i];
        }
    }

    // Calculate the initial window of size 'minutes'
    for (int i = 0; i < minutes; i++) {
        if (grumpy[i] == 1) {
            currentUnsatisfied += customers[i];
        }
    }

    maxUnsatisfied = currentUnsatisfied;

    // Use sliding window technique to find the maximum additional satisfaction
    for (int i = minutes; i < customers.size(); i++) {
        if (grumpy[i] == 1) {
            currentUnsatisfied += customers[i];
        }
        if (grumpy[i - minutes] == 1) {
            currentUnsatisfied -= customers[i - minutes];
        }
        maxUnsatisfied = max(maxUnsatisfied, currentUnsatisfied);
    }

    return maxSatisfied + maxUnsatisfied;
}
};

int main() {
    // Test case
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;
    
    Solution sl;

    int result = sl.maxSatisfied(customers, grumpy, minutes);
    cout << "Maximum satisfied customers: " << result << endl;

    return 0;
}