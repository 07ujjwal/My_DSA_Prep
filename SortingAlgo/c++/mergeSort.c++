#include <bits/stdc++.h>
using namespace std;


class MergeSort
{
    void merge(int arr[], int l, int m, int h) {
        vector<int> temp;
        int left = l;
        int right = m + 1;

        while (left <= m && right <= h) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= m) {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= h) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = l; i <= h; i++) {
            arr[i] = temp[i - l];
        }
    }

    void mergeSort(int arr[], int l, int h) {
        if (l < h) {
            int m = l + (h - l) / 2;

            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, h);
            merge(arr, l, m, h);
        }
    }
};


