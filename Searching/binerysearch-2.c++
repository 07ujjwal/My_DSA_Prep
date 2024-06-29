#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// magnetic forc between two balls...... wala questions
// binary search on answers......
// pattern type == min/max

class Solution {
public:
    bool isPossibleToPlace(vector<int>& position, int mid,int m){  
        int prev = position[0];
        int cntBall = 1;

        for(int i = 0; i<position.size(); i++){
            int current = position[i];

            if(current - prev > mid){
                 cntBall++;
                 prev = current;
            }
        }
     
     return cntBall == m;

    }

    int maxDistance(vector<int>& position, int m) {
        int mindist = 0;
   
        sort(position.begin(), position.end());

        int low = 1;
        int high = position.end() - position.begin();

        while (low <= high)
        {
            int mid = low + (high - low)/2;

            if(isPossibleToPlace(position, mid, m)){
                mindist = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return mindist;
        
    }

      long long int floorSqrtbrute(long long int x) 
    {
        long long int ans = 1;

         for(int i = 0; i<x; i++){
            if(i*i <= x){
                ans = i;
            }else{
                break;
            }
         }

         return ans;
    }

    long long int floorSqrtopt(long long int x) 
    {
     long long int low = 1;
     long long int high = x;

     while (low <= high)
     {
        long long int mid = low + (high - low)/2;

        if(mid * mid > x){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
     }

     return high;
     
    }

    // another question...
   
   int NthRoot(int n, int m)
	{
	 int low = 1;
     int high = m;

     while (low <= high)
     {
         int mid = low + (high - low)/2;

         if(pow(mid,n)==m){
         return mid;
        }
        if(pow(mid,n)>m){
           high=mid-1;
        }
        else{
           low=mid+1;
         }
     }

     return -1;
	} 

    // koko eating bananas....

   int checkTime(vector<int>& piles, int speed) {
    int sum = 0;
    for(int i = 0; i < piles.size(); i++) {
        sum += ceil(static_cast<double>(piles[i]) / speed);
    }
    return sum;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int mintime = 1;  // Minimum possible speed is 1
    int maxtime = *max_element(piles.begin(), piles.end());  // Maximum possible speed is the largest pile

    while (mintime <= maxtime) {
        int midtime = mintime + (maxtime - mintime) / 2;

        if (checkTime(piles, midtime) <= h) {
            maxtime = midtime - 1;
        } else {
            mintime = midtime + 1;
        }
    }

    return mintime;
}


//minimum dayas to make m bouquets....

int sumByD(vector<int> &arr, int div) {
    int n = arr.size(); //size of array
    //Find the summation of division values:
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}

int smallestDivisor(vector<int>& arr, int limit) {
        int n = arr.size();
    if (n > limit) return -1;
    int low = 1, high = *max_element(arr.begin(), arr.end());

    while (low <= high) {
        int mid = (low + high) / 2;
        if (sumByD(arr, mid) <= limit) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}


};


int main() {
   
   vector<int> piles = {3,6,7,11};

    Solution s;

   cout <<  s.minEatingSpeed(piles, 8);
  
    return 0;
}