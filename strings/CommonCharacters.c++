#include <vector>
#include <string>
#include<stack>
#include <algorithm>
#include <iostream>
using namespace std;



class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
       if(words.empty()){
        return {};
       }

       vector<int> minfrequency(26,0);
       for(auto  character : words[0]){
          minfrequency[character - 'a']++;
       }

       for(int i = 0; i<words.size(); ++i){
           vector<int> frequency(26, 0);
           for(auto character : words[i]){
              frequency[character - 'a']++;
           }

           for(int j = 0; j<26; ++j){
             minfrequency[j] = min(minfrequency[j], frequency[j]);
           }
       }

       vector<string> ans;
       for(int i = 0; i<26; ++i){
        for(int j = 0; j<minfrequency[i]; ++j){
            ans.push_back(string(1, 'a' + i));
        }
       }

       return ans;
    }


    //Remove Outermost Parentheses

     string removeOuterParentheses(string s) {
        int n = s.length();
        int balance = 0;
        int start = 0;
        string ans;

        for (int i = 0; i < n; i++)
        {
            if(s[i] == '('){
                if(balance == 0){
                    start = i;
                }

                ++balance;
            }else{
                --balance;

                if(balance == 0){
                    ans += s.substr(start + 1, i-start-1);
                }
            }
        }

        return ans;
        
    }


    //Reverse Words in a String

    string reverseWords(string s) {
        stack<string> st;
        int n = s.length();
        string temp = "";

        for (int i = 0; i <= n; i++)
        {
            if(s[i] == ' '){
                st.push(temp);
                temp = "";
            }else{
                temp += s[i];
            }
        }


        if (!temp.empty()) {
        st.push(temp);
         }
    
       temp = "";

      while(st.size() != 1){
          temp += st.top();
          st.pop();
      } 

      temp+=st.top();

     return temp;

    }
    
     string largestOddNumber(string num) {
         // Iterate over the string from the end to the beginning
    for (int i = num.length() - 1; i >= 0; --i) {
        // Check if the current character is an odd digit
        if ((num[i] - '0') % 2 != 0) {
            // Return the substring from the start to the current character (inclusive)
            return num.substr(0, i + 1);
        }
    }
    // If no odd digit is found, return an empty string
    return "";
        
    }

};


// int main() {
//     string s1 = "(()())(())";
//     string s2 = "(()())(())(()(()))";
//     string s3 = "()()";

//     Solution s;

//     cout << "Output 1: " << s.removeOuterParentheses(s1) << endl;  // Expected: "()()()"
//     cout << "Output 2: " << s.removeOuterParentheses(s2) << endl;  // Expected: "()()()()(())"
//     cout << "Output 3: " << s.removeOuterParentheses(s3) << endl;  // Expected: ""

//     return 0;
// }

int main() {
    string s1 = "the sky is blue";
    string s2 = "  hello world  ";
    string s3 = "a good   example";
    string s4 = "";

    Solution s;

    cout << "Reversed: '" << s.reverseWords(s1) << "'" << endl;  // Expected: "blue is sky the"
    cout << "Reversed: '" << s.reverseWords(s2) << "'" << endl;  // Expected: "world hello"
    cout << "Reversed: '" << s.reverseWords(s3) << "'" << endl;  // Expected: "example good a"
    cout << "Reversed: '" << s.reverseWords(s4) << "'" << endl;  // Expected: ""

    return 0;
}