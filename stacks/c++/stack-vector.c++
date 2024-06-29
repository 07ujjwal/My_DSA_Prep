#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// dynamic stack using non traditional vectors....

class Stack{
    vector<int> a;

    public:
    Stack() = default;


    bool push(int x){
        a.push_back(x);
        cout << x << " pushed into stack\n";
        return true;
    }

    int pop() {
        if(isEmpty()){
            cout << "stack UnderFlow";
            return 0;
        }else{
            int  x = a.back();
            a.pop_back();
            return x;
        }
    }

    int top (){
        if(isEmpty()){
            cout << "stack UnderFlow";
            return 0;
        }else{
           return a.back();
        }
    }

    bool isEmpty() const {
        return a.empty();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.pop() << " Popped from stack\n";

    // Print top element of stack after popping
    cout << "Top element is : " << s.top() << std::endl;

    // Print all elements in the stack
    cout << "Elements present in stack : ";
    while (!s.isEmpty()) {
        // Print top element in stack
        cout << s.top() << " ";
        // Remove top element in stack
        s.pop();
    }

    return 0;
}