#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class MinStack {
private:
  stack<int> main;
  stack<int> mini;

public:
    MinStack() {
        mini.push(INT_MAX);
    }
    
    void push(int val) {
        main.push(val);
        if(val <= mini.top()){
            mini.push(val);
        }
    }
    
    void pop() {
        if(main.empty()){
            return;
        }

        if(main.top() == mini.top()){
            mini.pop();
        }

        main.pop();
    }
    
    int top() {
        if(main.empty()){
            return -1;
        }

        return main.top();
    }
    
    int getMin() {
        return mini.top();
    }
};

// function you've written for checking if a string containing parentheses is valid has a few issues. 
//The main problem is that it returns true immediately after finding a matching pair of parentheses,
// rather than continuing to check the rest of the string.

class Solution2 {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                }

                char ch = st.top();
                st.pop();
                if ((s[i] == ')' && ch != '(') || (s[i] == '}' && ch != '{') || (s[i] == ']' && ch != '[')) {
                    return false;
                }
            }
        }

        return st.empty();
    }


    string reverse(string s){
        string ans;

        stack<char> st;

        for(auto ch : s){
            st.push(ch);
        }

        while(!st.empty()){
            char temp = st.top();
            st.pop();
            ans += temp; 
        }

        return ans;
    }

};



int main(){
    string s = "ujjwal";

    Solution2 sol;

    string s2 = sol.reverse(s);

    cout << s2 << endl;

    return 0;
}

