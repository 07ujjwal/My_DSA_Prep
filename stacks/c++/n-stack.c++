#include <bits/stdc++.h>
using namespace std;

class NStack
{
    int *arr;    // Array to store stack elements
    int *top;    // Array to store indexes of top elements of stacks
    int *next;   // Array to store next entry in all stacks and free list
    int n, s;    // Number of stacks and total size of array
    int freespot; // Index of the first free spot

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // Initialize all stacks as empty
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        // Initialize all spaces as free
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        next[s - 1] = -1; // -1 indicates the end of the free list

        freespot = 0; // First free spot is at index 0
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Check for stack overflow
        if (freespot == -1)
        {
            return false;
        }

        // Find the index to push the element
        int index = freespot;

        // Update freespot to the next available spot
        freespot = next[index];

        // Insert the element into the array
        arr[index] = x;

        // Update next to point to the previous top element of the stack
        next[index] = top[m - 1];

        // Update top to the current index
        top[m - 1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Check for stack underflow
        if (top[m - 1] == -1)
        {
            return -1;
        }

        // Find the index to pop the element
        int index = top[m - 1];

        // Update top to the next element in the stack
        top[m - 1] = next[index];

        // Update next to point to the current freespot
        next[index] = freespot;

        // Update freespot to the current index
        freespot = index;

        return arr[index];
    }

    // Destructor to clean up allocated memory.
    ~NStack()
    {
        delete[] arr;
        delete[] top;
        delete[] next;
    }
};

int main() {
    NStack ns(3, 6); // 3 stacks, total size 6
    cout << ns.push(10, 1) << endl; // Push 10 into stack 1
    cout << ns.push(20, 1) << endl; // Push 20 into stack 1
    cout << ns.push(30, 2) << endl; // Push 30 into stack 2
    cout << ns.pop(1) << endl; // Pop from stack 1, should return 20
    cout << ns.pop(2) << endl; // Pop from stack 2, should return 30
    cout << ns.pop(1) << endl; // Pop from stack 1, should return 10
    cout << ns.pop(1) << endl; // Pop from stack 1, should return -1 (stack empty)

    return 0;
}
