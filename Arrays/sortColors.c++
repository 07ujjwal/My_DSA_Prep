#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;

        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                cnt0++;
            }else if(nums[i] == 1){
                cnt1++;
            }else{
                cnt2++;
            }
        }

        for(int i = 0; i<cnt0; i++){
            nums[i] = 0;
        }
         for(int i = cnt0; i<cnt0+cnt1; i++){
            nums[i] = 1;
        }

        for(int i = cnt0+cnt1; i<n; i++){
            nums[i] = 2;
        }
    }

    // Dutch National Flag Algo......

//intution.....
//[0 .... low-1]... should be 0;
//[low .... mid-1]... should be 1;
//[mid .... high-1]... should be 2;

 void DNF(vector<int>& nums){
       int low = 0;
       int high = nums.size()-1;
       int mid = 0;

       while(mid <= high){
           if(nums[mid] == 0){
               swap(nums[mid], nums[low]);
               mid++;
               low++;
           }else if(nums[mid] == 1){
              mid++;
           }else{
              swap(nums[mid], nums[high]);
              high--;
           }
       }
 }

};

int main() {

   vector<int> ans = {1, 2, 2, 0, 0, 1, 1, 0, 2 , 2 ,1 , 0};
   Solution sl;

   sl.DNF(ans);

   for(auto i : ans){
      cout << i << " ";
   }

    return 0;
}
