#include <bits/stdc++.h> 
#include<iostream>
using namespace std;

bool findRedundantBrackets(string &s){
     int n = s.length();
     stack<char> st;

     for(int i = 0; i<n; i++){
        if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] =='/'){
           st.push(s[i]);
        }else{
            if(s[i] == ')'){
                 bool isred = true;
                  while (st.top() != '(')
                  {
                    char top = st.top();

                    if(top == '+' || top ==  '-' || top ==  '*' || top == '/'){
                        isred = false;
                    }

                     st.pop();
                  }

                  if(isred == true){
                    return true;
                  }
                  st.pop(); 
            }
        }
     }

    return false;

}



// Minimum Cost To Make String Valid

int findMinimumCost(string str) {
 
 int n = str.length();

  if(n%2!=0){
    return -1;
  }

}



// next-smaller-el.......

vector<int> nextSmallerElement(vector<int> &arr, int n)
{  
   vector<int> ans;
   stack<int> st;
   st.push(-1);

   for(int i = n; i>=0; i--){
       while (st.top() >= arr[i]) {
            st.pop();
        }

         ans[i] = st.top();

         st.push(arr[i]);
   }

 return ans; 
}
