#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        long long total_time = 0;
        long long total_cooking_time = 0; 

        for(int i = 0; i < n; ++i) {
            if (i == 0) {
                total_time = customers[i][0];
            } else {
                total_time = max(total_time, static_cast<long long>(customers[i][0]));
            }
            total_time += customers[i][1];
            long long cooking_time = total_time - customers[i][0];
            total_cooking_time += cooking_time;
        }

        double ans = static_cast<double>(total_cooking_time) / n;
        return ans;
    }
};
