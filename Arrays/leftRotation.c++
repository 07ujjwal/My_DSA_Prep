#include <bits/stdc++.h>
using namespace std;


class LeftRotation{
    public:
     void rotate(vector<int>& nums){
        int temp = nums[0];
        int n = nums.size();
        for(int i = 1; i<n; i++){
            nums[i-1] = nums[i];
        }

        nums[n-1] = temp;
     }



 void rotateByK(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return;

    k = k % n; // In case k is greater than the size of the array
    if (k == 0) return;

    vector<int> temp(k);

    // Copy the last k elements to the temporary array
    for (int i = 0; i < k; i++) {
        temp[i] = nums[n - k + i];
    }

    // Shift the remaining elements to the right
    for (int i = n - 1; i >= k; i--) {
        nums[i] = nums[i - k];
    }

    // Copy the k elements from the temporary array to the beginning of nums
    for (int i = 0; i < k; i++) {
        nums[i] = temp[i];
    }

    }

   // ....optimal solution....

   // Step 1: Reverse the last k elements of the array
   // Step 2: Reverse the first n-k elements of the array.
   // Step 3: Reverse the whole array.
  private:
    void Reverse(vector<int>& arr, int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

public:
    void rotateRight(vector<int>& arr, int k) {
        int n = arr.size();
        k = k % n; // In case k is greater than the size of the array

        if (k == 0) return;

        // Reverse first n-k elements
        Reverse(arr, 0, n - k - 1);
        // Reverse last k elements
        Reverse(arr, n - k, n - 1);
        // Reverse the whole array
        Reverse(arr, 0, n - 1);
    }
    
     void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int lastNonZeroFoundAt = 0;

        // Move all non-zero elements to the front of the array
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroFoundAt++] = nums[i];
            }
        }

        // Fill the remaining positions with zeros
        for (int i = lastNonZeroFoundAt; i < n; i++) {
            nums[i] = 0;
        }
    }
};



int main() {
  
  vector<int> arr= {1,2,3,4,5,6,7};
  LeftRotation lr;

  lr.rotateRight(arr, 4);

  for(int i : arr){
    cout << i << " ";
  }
}
