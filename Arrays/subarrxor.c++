#include <bits/stdc++.h>
using namespace std;


int subarraysWithXorKbetter(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        int xorr = 0;
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            xorr = xorr ^ a[j];

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}


int subarraysWithXorKOpt(vector<int> a, int k) {
     
     unordered_map<int, int> index;
     int n = a.size();
     int xorr = 0;
     index[xorr];
     int count = 0;

     for(int i = 0; i<n; i++){
       
       xorr = xorr ^ a[i];

       int x = xorr ^ k;

       count += index[x];

       index[x]++;
          
     }

     return count;

}

// merge intervals....

vector<vector<int>> merge(vector<vector<int>>& intervals) {
     if (intervals.empty()) return {};

        vector<vector<int>> ans;
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        // Initialize with the first interval
        ans.push_back(intervals[0]);

         for (int i = 1; i < n; ++i){
            int current_start = intervals[i][0];
            int current_end = intervals[i][1];

            int last_end = ans.back()[1];

            if (current_start <= last_end) {
                // Merge intervals
                ans.back()[1] = max(last_end, current_end);
            } else {
                // Add non-overlapping interval to the result
                ans.push_back(intervals[i]);
            }

         }

           return ans;
}


int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorKOpt(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}