#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 100

//LIFO last in first out....
// non dynamic stack using treditional arrray....

class Stack {
     int top;

     public:
       int a[MAX];

       Stack() {top = -1;}
       bool push(int x);
       int pop();
       int peek();
       bool isEmpty();
};


bool Stack::push(int x){
         if(top >= (MAX - 1)){
            cout << "Stack Overflow";
            return false;
         }else{
            a[++top] = x;
            cout << x << " pushed into stack\n";
            return true;
         }
}


int Stack::pop(){
    if(top < 0){
        cout << "Stack Underflow";
        return 0;
    }else{
        int x = a[top--];
        return x;
    }
}

int Stack::peek(){
    if(top < 0){
         cout << "Stack Underflow";
        return 0;
    }else{
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty(){
    return (top < 0); 
}

int main() {
    class Stack s;
    s.push(2);
    s.push(3);
    int popedEl = s.peek();
    cout << popedEl;
}
