#include<bits/stdc++.h>
#include<string>
using namespace std;


class Solution {
public:
   string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }

    // Isomorphic Strings

     bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, char> mapST;
        unordered_map<char, char> mapTS;

         for(int i = 0; i<s.length(); i++){
            char c1 = s[i];
            char c2 = t[i];

            if(mapST.find(c1) != mapST.end()){
                if(mapST[c1] != c2){
                    return false;
                }
            }else{
                mapST[c1] = c2;
            }


             if(mapST.find(c2) != mapST.end()){
                if(mapST[c2] != c1){
                    return false;
                }
            }else{
                mapST[c2] = c1;
            }
            
         }

         return true;
    }


    bool isRotated(string s, string g) {
        if (s.length() != g.length()) return false;

        int n = s.size();

        // Iterate over possible rotation positions
        for (int i = 0; i < n; ++i) {
            // Construct rotated string by shifting characters
            // (i to end) + (0 to i)
            string rotated = s.substr(i) + s.substr(0, i);

            // Check if rotated string matches g
            if (rotated == g) {
                return true;
            }
        }

        // If no match found
        return false;
    }


     bool isAnagram(string s, string t) {
      
       if(s.length() != t.length()){
           return false;
       }

        unordered_map<char, int> mpp;

        for(auto ch : s){
            mpp[ch]++;
        }

        for(auto ch : t){
            if(mpp.find(ch) != mpp.end() && mpp[ch] > 0){
                mpp[ch]--;
            }else{
                return false;
            }
        }

        return true;
    }
};


int main() {
    Solution solution;
    cout << boolalpha; // Print 'true'/'false' instead of '1'/'0'

    string s1 = "egg";
    string t1 = "add";
    cout << "Are \"" << s1 << "\" and \"" << t1 << "\" isomorphic? " << solution.isIsomorphic(s1, t1) << endl;

    string s2 = "foo";
    string t2 = "bar";
    cout << "Are \"" << s2 << "\" and \"" << t2 << "\" isomorphic? " << solution.isIsomorphic(s2, t2) << endl;

    return 0;
}