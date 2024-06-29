#include <bits/stdc++.h>
using namespace std;


class SolutionN2{
    public:
     int bruteForce(vector<int>& nums) {
         int n = nums.size()-1;
         int el = 0;

         for(int i = 0; i<n; i++){
            int count = 0;
            for(int j = 0; j<n; j++){
              if(nums[j] == nums[i]){
                count++;
              }
            }
            
          if(count > (n/2)){
            el = nums[i];
          }
         }

        return el;
    }

    int betterSol(vector<int>& nums){
        unordered_map<int, int> freq;
        int n = nums.size();

        for(int i = 0; i<n; i++){
           freq[nums[i]]++;
        }

        for(auto i : freq){
            if(i.second > (n/2)){
                return i.first;
            }
        }

        return -1;
    }

    // Moore’s Voting Algorithm:

    int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
  }
};


class Elementnby3{
    public:
    vector<int> majorityBrute(vector<int> v) {
    int n = v.size(); //size of the array
    vector<int> ls; // list of answers

    for (int i = 0; i < n; i++) {
        //selected element is v[i]:
        // Checking if v[i] is not already
        // a part of the answer:
        if (ls.size() == 0 || ls[0] != v[i]) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                // counting the frequency of v[i]
                if (v[j] == v[i]) {
                    cnt++;
                }
            }

            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                ls.push_back(v[i]);
        }

        if (ls.size() == 2) break;
    }

    return ls;
  }

  
};


int main() {
    vector<int> ans = {1, 2, 2, 2};
   SolutionN2 sl;

   int i =   sl.majorityElement(ans);

   
      cout << i << " ";


    return 0;
}