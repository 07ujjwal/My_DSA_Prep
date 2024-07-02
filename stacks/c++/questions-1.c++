#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(stack<int>&inputStack, int count, int N){
    if(count == N/2){
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    solve(inputStack, count+1, N);

    inputStack.push(num);
}


void deleteMiddle(stack<int>&inputStack, int N){
	
   int count = 0;
   solve(inputStack, count, N);
}


// insertion at the end of the stack....


void solveBottom(stack<int>& myStack, int x) {
    if (myStack.empty()) {
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();

    solveBottom(myStack, x);

    myStack.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) {
    solveBottom(myStack, x);
    return myStack;
}



void insertSorted(stack<int> &stack, int x) {
    // Base case: stack is empty or top element is less than x
    if (stack.empty() || x >= stack.top()) {
        stack.push(x);
        return;
    }

    // Remove the top element
    int num = stack.top();
    stack.pop();

    // Recursive call
    insertSorted(stack, x);

    // Push the top element back to stack
    stack.push(num);
}

void sortStack(stack<int> &stack) {
    // Base case: stack is empty
    if (stack.empty()) {
        return;
    }

    // Remove the top element
    int n = stack.top();
    stack.pop();

    // Recursive call to sort the remaining stack
    sortStack(stack);

    // Insert the removed element in sorted order
    insertSorted(stack, n);
}



