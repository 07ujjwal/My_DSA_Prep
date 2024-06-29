#include <unordered_map>
#include<unordered_set>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

std::string frequencySort(std::string s) {
    std::unordered_map<char, int> mpp;
    std::string ans;

    // Count frequency of each character
    for (auto ch : s) {
        mpp[ch]++;
    }

    // Store the characters in a vector for sorting
    std::vector<std::pair<char, int>> freqVec(mpp.begin(), mpp.end());

    // Sort characters by frequency in descending order
    std::sort(freqVec.begin(), freqVec.end(), [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
        return a.second > b.second;
    });

    // Construct the result string
    for (const auto& p : freqVec) {
        ans.append(p.second, p.first);
    }

    return ans;
}



  int maxDepth(string s) {
       int n = s.length();
        int maxdepth = 0;
        int balance = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                balance++;
                maxdepth = max(maxdepth, balance);
            } else if (s[i] == ')') {
                balance--;
            }
        }

        return maxdepth;
    }


//To convert a Roman numeral string to an integer, 
//you can iterate through the string while checking for the subtractive combinations. Here's a solution in C++:

int romantoInt(string s){
     unordered_map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
     };

     int result = 0;
     int n = s.length();


     for (int i = 0; i < n; ++i){
        if(i < n-1 && roman[s[i]] < roman[s[i+1]]){
             result -= roman[s[i]];
        }else{
             result += roman[s[i]];
        }
     }

     return result;
}


int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        long long result = 0;

        // Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Handle optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Convert digits and accumulate into result
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // Check for overflow before next iteration
            if (result * sign > INT16_MAX) {
                return INT16_MAX;
            } else if (result * sign < INT16_MIN) {
                return INT16_MIN;
            }

            i++;
        }

        return result * sign;
    }


    int lengthOfLongestSubstr(string s){
        unordered_set<char> seen;
        int left = 0, right =0, maxLength = 0;

        while (right < s.length()){
             if(seen.find(s[right]) != seen.end()){
                seen.insert(s[right]);
                maxLength = max(maxLength, right-left+1);
                right++;
             }else{
                seen.erase(s[left]);
                left++;
             }
        }

        return maxLength;
    }

// Given a binary array nums and an integer k, 
// return the maximum number of consecutive 1's in the array if you can flip at most k

    int longestOnes(vector<int>& nums, int k) {
        
    }



int main() {
    std::string s = "tree";
    std::string result = frequencySort(s);
    std::cout << result << std::endl;  // Output: eert or eetr depending on sorting order of same frequency

    return 0;
}
