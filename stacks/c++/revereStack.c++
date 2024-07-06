#include <bits/stdc++.h> 
#include<iostream>
using namespace std;



void sortedInsert(stack<int> st, int x){
    if(st.empty() || st.top() <= x){
        st.push(x);
        return;
    }


    int temp = st.top();
    st.pop();

    sortedInsert(st, x);
    
    st.push(temp);

}



void sortStack(stack<int> st){
    if(!st.empty()){

    int x = st.top();
    st.pop();

    sortStack(st);

    sortedInsert(st, x);

   }
}


void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}


int main() {
    stack<int> s;
    s.push(30);
    s.push(10);
    s.push(20);
    s.push(5);

    cout << "Original Stack: ";
    printStack(s);

    // Sort the stack
    sortStack(s);

    cout << "Sorted Stack: ";
    printStack(s);

    return 0;
}