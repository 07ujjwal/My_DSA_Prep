#include <bits/stdc++.h>
using namespace std;

//Here, we will iterate the given array with a single loop and while iterating we will add the elements in a sum variable. Now, if at any point the sum becomes less than 0, we will set the sum as 0 as we are not going to consider any subarray with a negative sum. Among all the sums calculated, we will consider the maximum one.

//Thus we can solve this problem with a single loop.

//Approach:
//The steps are as follows:

//We will run a loop(say i) to iterate the given array.
//Now, while iterating we will add the elements to the sum variable and consider the maximum one.
//If at any point the sum becomes negative we will set the sum to 0 as we are not going to consider it as a part of our answer.
//Note: In some cases, the question might say to consider the sum of the empty subarray while solving this problem. So, in these cases, before returning the answer we will compare the maximum subarray sum calculated with 0(i.e. The sum of an empty subarray is 0). And after that, we will return the maximum one.
//For e.g. if the given array is {-1, -4, -5}, the answer will be 0 instead of -1 in this case. 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {

        sum += nums[i];

        if (sum > maxi) {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    return maxi;
    }
};

// There might be more than one subarray with the maximum sum. We need to print any of them.

void printArray(vector<int> arr, int n) {
   cout << "The reversed array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
}

void reverse(vector<int> ans, int s, int e){
     if(s < e){
      swap(ans[s], ans[e]);
      reverse(ans, s+1,e-1); 
     }
}

int main() {
   int n = 5;
   vector<int> ans = { 5, 4, 3, 2, 1 };
   reverse(ans, 0, n - 1);
   printArray(ans, n);
   return 0;
}

