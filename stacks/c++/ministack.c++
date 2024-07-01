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
