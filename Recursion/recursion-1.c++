#include <iostream>
#include <vector>

using namespace std;

void printNumber(int count, int n) {
    if(count > n) {
        return;
    }
    cout << count << endl;
    printNumber(count + 1, n);
}

void printNumberReverse(int n) {
    if(n == 0) {
        return;
    }
    cout << n << endl;
    printNumberReverse(n - 1);
}

void printNumberBacktrack(int n) {
    if(n == 0) {
        return;
    }
    printNumberBacktrack(n - 1);
    cout << n << endl;
}

void printReverseBacktrack(int count,int n){
    if(count > n){
        return;
    }
    
    printReverseBacktrack(count + 1, n);
    cout << count << endl;

}


int main() {
    cout << "Print numbers from 1 to 5:" << endl;
    printNumber(1, 5);

    cout << "\nPrint numbers from 5 to 1:" << endl;
    printNumberReverse(5);

    cout << "\nPrint numbers from 1 to 5 using backtracking:" << endl;
    printNumberBacktrack(5);

    cout << "\nPrint numbers from 5 to 1 using backtracking:" << endl;
    printReverseBacktrack(1,5);

    return 0;
}
