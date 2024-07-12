#include <iostream>
#include <string>
#include <algorithm> 
#include <stack>  

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
       stack<char> balance;
       int count = 0;

       for(int i = 0; i<s.length(); i++){
           if(s[i] == '('){
              balance.push(s[i]);
           }else{
              if(!balance.empty()){
                 balance.pop();
              }else{
                 count++;
              }
           }
       }

       if(!balance.empty()){
        count += balance.size();
       }

       return count;
    }
};