#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution3Sum {
    public:
    vector<vector<int>> bruteForce(int n, vector<int> &arr){
        set<vector<int>> st;

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
               for(int k = j+1; k<n; k++){
                 if (arr[i] + arr[j] + arr[k] == 0){
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                 }
                    
               }
            }
        }
      
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

    vector<vector<int>> betterSol(int n, vector<int> &arr){
        set<vector<int>> st;

        for(int i = 0; i<n; i++){
            set<int> hashSet;
            for(int j = i+1; j<n; j++){
                int rem = -(arr[i] + arr[j]);
                if(hashSet.find(rem) != hashSet.end()){
                    vector<int> temp = {arr[i], arr[j], arr[rem]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
             hashSet.insert(arr[j]); 
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;

    }


    vector<vector<int>> OptimalSol(int n, vector<int> &arr){
      vector<vector<int>> ans;
      sort(arr.begin(), arr.end());
      for(int i = 0; i<n; i++){
      
       if (i != 0 && arr[i] == arr[i - 1]) continue;

         int right = n-1;
         int left = i+1;

         while (left < right)
         {
            int sum = arr[i] + arr[left] + arr[right];

            if(sum > 0){
               right--;
            }else if(sum < 0){
                left++;
            }else{
                vector<int> temp = {arr[i], arr[left], arr[right]};
                ans.push_back(temp);
                left++;
                right--;

                while( left < right && arr[left] == arr[left - 1]){
                     left++;
                }

                while( left < right && arr[right] == arr[right + 1]){
                     right--;
                }
            }
         }
      }
      return ans;
 }
};


class Solution4Sum{
    public:
      vector<vector<int>> bruteforce(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
      
       for (int i = 0; i < n; i++)
       {
          for (int j = i+1; j < n; j++)
          {
             for (int k = j+1; k < n ; k++)
             {
               for (int l = k + 1; l < n; l++) {
                    // taking bigger data type
                    // to avoid integer overflow:
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
             }
             
          }
        }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
    }

    vector<vector<int>> betterSol(vector<int>& nums, int target){
        set<vector<int>> st;
        int n = nums.size();

       for(int i = 0; i<n ; i++){
         for(int j = i+1; j<n; j++){
             set<long long> hashSet;
             for(int k = j+1; k<n; k++){
                long long sum = nums[i] + nums[j] + nums[k];
                long long rem = target - sum;

                if(hashSet.find(rem) != hashSet.end()){
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }

              hashSet.insert(arr[k]);  
             }
         }
       }
     vector<vector<int>> ans(st.begin(), st.end());
     return ans;
    }

    vector<vector<int>> optimalsolution(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    //calculating the quadruplets:
    for (int i = 0; i < n; i++) {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }

    return ans;
}

};




int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    
    Solution3Sum s;

    vector<vector<int>> ans = s.OptimalSol(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}