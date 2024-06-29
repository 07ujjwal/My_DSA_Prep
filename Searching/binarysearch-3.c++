#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int divisorSum(const vector<int>& nums, int mid) {
    int sum = 0;
    for (int num : nums) {
        sum += ceil((double)num / mid);
    }
    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (divisorSum(nums, mid) <= threshold) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}


// next question.....
// Capacity To Ship Packages Within D Days

int calculateDays(vector<int>& weights, int midWt, int n) {
        int days = 1; // Start with one day
        int temp = 0;

        for (int i = 0; i < n; i++) {
            if (temp + weights[i] > midWt) {
                days++;
                temp = 0;
            }
            temp += weights[i];
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int lowestWt = *max_element(weights.begin(), weights.end()); // The minimum possible weight capacity is the max weight in the array
        // int highestWt = accumulate(weights.begin(), weights.end(), 0); // The maximum possible weight capacity is the sum of all weights

        while (lowestWt <= highestWt) {
            int midWt = lowestWt + (highestWt - lowestWt) / 2;

            if (calculateDays(weights, midWt, n) <= days) {
                highestWt = midWt - 1;
            } else {
                lowestWt = midWt + 1;
            }
        }

        return lowestWt;
    }

// ...aggressive cows.....
// min/max type.....

bool canWePlace(vector<int> &stalls, int dist, int cows, int n) {
  int cntCow = 1;
  int prev = stalls[0];
  for(int i = 0; i<n; i++){
    int current = stalls[i];

    if(current - prev >= dist){
        cntCow++;
        prev = stalls[i];
    }

    if (cntCow >= cows) return true;
  }
 
 return false;

}

int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size(); 
   
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k, n) == true) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}


// book allocation....

int countStudents(vector<int> &arr, int pages) {
    int n = arr.size(); //size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            //add pages to current student
            pagesStudent += arr[i];
        }
        else {
            //add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    //book allocation impossible:
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}


int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}
