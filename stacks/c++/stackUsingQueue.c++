#include<iostream>
#include<bits/stdc++.h>
using namespace std;



class Stack{
    private:
      queue<int> q1, q2;

    public:
      void push(int x){
        
        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1,q2);
        
      }  


    int pop(){
        if(q1.empty()){
            return -1;
        }

        int topEl = q1.front();
         q1.pop();

        return topEl;
    }  


    int top(){
        if(q1.empty()){
            return -1;
        }

        return q1.front();
    }


    bool isEmpty(){
        return q1.empty();
    }
};



int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    cout << stack.top() << endl; // 2
    cout << stack.pop() << endl; // 2
    cout << stack.top() << endl; // 1
    cout << stack.isEmpty() << endl; // 0 (false)
    cout << stack.pop() << endl; // 1
    cout << stack.isEmpty() << endl; // 1 (true)

    return 0;
}