#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int find_min(vector<int> &temp) {
        int min_val = INT16_MAX;
        for (int i = 0; i < temp.size(); i++) {
            min_val = min(min_val, temp[i]);
        }
        return min_val;
    }

    int sumSubarrayMinsBrute(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {  
                vector<int> temp(arr.begin() + i, arr.begin() + j + 1);  
                int min = find_min(temp);
                sum += min;
            }
        }
        return sum;
    }
   
   int sumSubarrayMins(vector<int>& arr){
      int n = arr.size();
      vector<int> ple(n, -1);
      vector<int> nle(n, n);
      stack<int> s;

      for (int i = 0; i < n; i++)
      {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
           s.pop();
        }

        if(!s.empty()){
            ple[i] = s.top();
        }
        s.push(i);
      }

      while(!s.empty()) s.pop();

      for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                nle[i] = s.top();
            }
            s.push(i);
        }

        long long sum = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            int left = i - ple[i];
            int right = nle[i] - i;
            sum = (sum + (long long)arr[i] * left * right) % mod;
        }
        return (int)sum;
      
   }

  //Sum of Subarray Ranges
  
  long long subArrayRanges(vector<int>& nums) {
     int n = nums.size();
     vector<int> ple(n ,-1);
     vector<int> nle(n,n);
  }


};

int main() {
    Solution solution;
    vector<int> arr = {3, 1, 2, 4};
    int result = solution.sumSubarrayMinsBrute(arr);
    cout << "The sum of subarray minimums is: " << result << endl;
    return 0;
}

