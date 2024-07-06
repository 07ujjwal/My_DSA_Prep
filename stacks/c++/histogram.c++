#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    vector<int> nextSmallerEl(vector<int> arr, int n) {
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
                 
            if (st.empty()) {
                ans[i] = n;
            } else {
                ans[i] = st.top();
            }

            st.push(i);
        }
        return ans;
    }
   
   vector<int> nextgreatestEl(vector<int> arr, int n){
       vector<int> ans(n);
       stack<int> st;

       for (int i = n-1; i >= 0; i--)
       {
            while (!st.empty() && st.top() <= arr[i])
            {
               st.pop();
            }

            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
            
            st.push(arr[i]);
       }
       
       return ans;
   }

    vector<int> prevSmallerEl(vector<int> arr, int n) {
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }

            st.push(arr[i]);
        }
        return ans;
    }

    vector<int> prevgreatestEl(vector<int> arr, int n){
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
                 
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }

            st.push(arr[i]);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int area = 0;

        vector<int> next(n);
        next = nextSmallerEl(heights, n);

        vector<int> prev(n);
        prev = prevSmallerEl(heights, n);

        for (int i = 0; i < n; i++) {
            int l = heights[i];
            if (next[i] == n) {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newArea = l * b;

            area = max(area, newArea);
        }
        return area;
    }


// rain water trap problem.....

    int trap(vector<int>& height) {
        int n = height.size();
        int water_area = 0;

        vector<int> next(n);
        next = nextgreatestEl(height, n);

        vector<int> prev(n);
        prev = prevgreatestEl(height, n);

        for (int i = 0; i < n; i++)
        {   int minHeight = min(next[i], prev[i]);

            if (minHeight > height[i]) { // Only add to water area if minHeight > height[i]
            water_area += (minHeight - height[i]);
        }
        }
        
        return water_area;
    }

    // optimal

    int trapOpt(vector<int>& height) {
    int n = height.size();
    if (n <= 2) return 0;

    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = height[0];
    for (int i = 1; i < n; ++i) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    int water_area = 0;
    for (int i = 0; i < n; ++i) {
        water_area += max(0, min(leftMax[i], rightMax[i]) - height[i]);
    }

    return water_area;
}
};

int main() {
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    vector<int>  height = {0,1,0,2,1,0,1,3,2,1,2,1};

    Solution s;
    cout << s.trapOpt(height) << endl;

    return 0;
}
