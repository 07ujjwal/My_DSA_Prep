#include <iostream>
#include <string>
#include <algorithm> 
#include <stack>  

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> balance;

        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                balance.push(i);
            }else if(s[i] == ')'){
                int start = balance.top();
                balance.pop();
                reverse(s.begin() + start + 1, s.begin() + i);
            }
        }

        string result;
        for(char ch : s){
            if( ch != '(' && ch != ')'){
                result += ch;
            }
        }

        return result;
    }
};