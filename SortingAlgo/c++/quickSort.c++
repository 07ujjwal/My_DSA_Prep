#include <bits/stdc++.h>
using namespace std;

class QuickSort {
private:
    int partition(vector<int> &arr, int low, int high) {
        int pivot = arr[low];
        int i = low;
        int j = high;

        while (i < j) {
            while (arr[i] <= pivot && i <= high - 1) {
                i++;
            }

            while (arr[j] > pivot && j >= low + 1) {
                j--;
            }

            if (i < j) {
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[low], arr[j]);

        return j;
    }

public:
    void quickSort(vector<int> &arr, int low, int high) {
        if (low < high) {
            int partitionIndex = partition(arr, low, high);
            quickSort(arr, low, partitionIndex - 1);
            quickSort(arr, partitionIndex + 1, high);
        }
    }
};

int main() {
    vector<int> arr = {1, 3, 4, 5, 6, 7, 2, 1};
    int arr_size = arr.size();

    QuickSort qs;
    qs.quickSort(arr, 0, arr_size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
