#include <iostream>
#include <string>
#include <algorithm> 
#include <stack>  

using namespace std;


class Solution {
public:
    int maximumGainBrute(string s, int x, int y) {
    int score = 0;
    string aFirst = "ab", bFirst = "ba";

    if (x < y) {
        swap(x, y);
        swap(aFirst, bFirst);
    }

    // First pass for higher score pair
    int i = 0;
    while (i < s.length() - 1) {
        if (i + 1 < s.length() && s.substr(i, 2) == aFirst) {
            score += x;
            s.erase(i, 2);
            i = max(0, i - 1);  // Reset i to handle overlapping patterns
        } else {
            i++;
        }
    }

    // Second pass for lower score pair
    i = 0;
    while (i < s.length() - 1) {
        if (i + 1 < s.length() && s.substr(i, 2) == bFirst) {
            score += y;
            s.erase(i, 2);
            i = max(0, i - 1);  // Reset i to handle overlapping patterns
        } else {
            i++;
        }
    }

    return score;
}


    int maximumGainOpt(string s, int x, int y) {
    int score = 0;
    stack<char> stk;
    string aFirst = "ab", bFirst = "ba";

    if (x < y) {
        swap(x, y);
        swap(aFirst, bFirst);
    }

    // Process for higher score pair
    for (char c : s) {
        if (!stk.empty() && stk.top() == aFirst[0] && c == aFirst[1]) {
            score += x;
            stk.pop();  // Remove the first character of the pair from the stack
        } else {
            stk.push(c);
        }
    }

    // Now, process the remaining string for the lower score pair
    string remaining;
    while (!stk.empty()) {
        remaining += stk.top();
        stk.pop();
    }
    reverse(remaining.begin(), remaining.end());

    for (char c : remaining) {
        if (!stk.empty() && stk.top() == bFirst[0] && c == bFirst[1]) {
            score += y;
            stk.pop();  // Remove the first character of the pair from the stack
        } else {
            stk.push(c);
        }
    }

    return score;
}

};


int main(){
   
   string s = "cdbcbbaaabab";

   Solution sol;

  int ans = sol.maximumGainBrute(s, 4, 5);

   cout << ans << endl;
 
    return 0;
}