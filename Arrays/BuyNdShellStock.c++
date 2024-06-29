#include <bits/stdc++.h>
using namespace std;


class Solution{

 public:

   int maxProfitBrut(vector<int> &arr) {
     int maxPro = 0;
     int n = arr.size();

     for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
            maxPro = max(arr[j] - arr[i], maxPro);
            }
        }
        }

     return maxPro;
    }  

    int maxProfitI(vector<int>& prices) {
        int minPrice = INT_MAX;  // Initialize to the maximum possible integer value
        int maxProfit = 0;       // Initialize max profit to 0

        for (auto price : prices) {
            if (price < minPrice) {
                minPrice = price;  // Update the minimum price
            }

            int profit = price - minPrice;  // Calculate the profit if we sell at the current price

            if (profit > maxProfit) {
                maxProfit = profit;  // Update the maximum profit
            }
        }

        return maxProfit;
    }


};