#include <iostream>
#include <vector>
using namespace std;

// Function to extract digits from a number
vector<int> extractDigits(int number) {
    vector<int> digits;
    while (number > 0) {
        int digit = number % 10; // Get the last digit
        digits.push_back(digit); // Add it to the list of digits
        number /= 10; // Remove the last digit
    }
    return digits;
}
//DVA1E2M58BP8U6WNHCW2KCB7 recovary code twellow

int combineDigit(vector<int> nums) {
    int ans = 0;

    for (int i = 0; i < nums.size(); i++) {
        ans = ans * 10 + nums[i];
    }

    return ans;
}


int main() {
    // int number;
    // cout << "Enter an integer: ";
    // cin >> number;

    // // Handle negative numbers
    // if (number < 0) {
    //     number = -number;
    // }

    // vector<int> digits = extractDigits(number);

    // cout << "Digits in the number: ";
    // for (int i = digits.size() - 1; i >= 0; --i) {
    //     cout << digits[i] << " ";
    // }
    // cout << endl;

   
     vector<int> arr = {8,4,2};

     cout <<  combineDigit(arr);


    return 0;
}
