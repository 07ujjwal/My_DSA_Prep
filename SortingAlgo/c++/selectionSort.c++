#include<iostream>
#include<bits/stdc++.h>

using namespace std;

 void selection_sort(int arr[], int n){
      
      for(int i = 0; i<n; i++){
        int mini = i;
        for(int j = i + 1; j<n; j++){
            if(arr[j] < arr[mini]){
                mini = j;
            }
         }

         swap(arr[i], arr[mini]);
       }
}

void bubble_sort(int arr[], int n){
      for(int i = n; i>=0; i--){
        for(int j = 0; j<i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
      }
   }

void bubble_sort_rec(int arr[], int n) {
    // Base Case: range == 1.
    if (n == 1) return;

    for (int j = 0; j <= n - 2; j++) {
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
        }
    }

    //Range reduced after recursion:
    bubble_sort(arr, n - 1);
}

void insertion_sort(int arr[], int n){
    for(int i = 0; i<n ;i++){
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[i]){
                swap(arr[j], arr[i]);
            }
        }
    }
}

void insertion_sort_inc(int arr[], int i,int n){

  if (i == n) return;

   for(int j = i+1; j<n; j++){
            if(arr[j] < arr[i]){
                swap(arr[j], arr[i]);
            }
    }

    insertion_sort_inc(arr, i + 1, n);
}


int main() {
  int arr[] = {13,46,24,52,20,9};
  int n = sizeof(arr) / sizeof(arr[0]);
   cout << "Before selection sort: " << "\n";
   for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  insertion_sort_inc(arr, 0,n);

  cout << "After selection sort: " << "\n";
   for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}