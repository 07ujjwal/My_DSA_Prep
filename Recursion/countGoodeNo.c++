#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
   
const int MOD = 1e9 + 7;

  int numberOfGoodPartitions(vector<int>& nums) {
        int M = 1e9 + 7;  // Define the modulus correctly
        int n = nums.size();

        unordered_map<int, int> last_index;

        // Populate the last index of each number
        for (int i = 0; i < n; i++) {
            last_index[nums[i]] = i;
        }

        int i = 0;
        int j = 0;
        j = max(j, last_index[nums[0]]);

        int result = 1;

        while (i < n) {
            if (i > j) {
                result = (result * 2) % M;  // Add missing semicolon
            }

            j = max(j, last_index[nums[i]]);
            i++;
        }

        return result;
    }

   long long modExp(long long base, long long exp, int mod){
     long long result = 1;
     while (exp > 0)
     {
        if(exp % 2 == 1){
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;

     }
      return result;
   }


    int countGoodNumbers(long long n) {
        int even_positions = (n+1)/2;
        int odd_positions = n/2;

        long long even_count = modExp(5, even_positions, MOD);
        long long odd_count = modExp(4, odd_positions, MOD);

        return (even_count * odd_count) % MOD;
    }
  
};