#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
      int data;
      Node* left;
      Node* right;

      Node(int data1){
        data = data1;
        left = NULL;
        right =NULL;
      }
};



// Sum of Longest Root to Leaf of Path 

void solve(Node* root, int sum, int &maxSum, int len, int &maxLen) {
    if (root == NULL) {
        if (len > maxLen) {
            maxLen = len;
            maxSum = sum;
        } else if (len == maxLen) {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum += root->data;

    solve(root->left, sum, maxSum, len + 1, maxLen);
    solve(root->right, sum, maxSum, len + 1, maxLen);
}

int sumOfLongRootToLeafofPath(Node* root) {
    if (root == NULL) return 0;

    int len = 0;
    int maxLen = 0;
    int sum = 0;
    int maxSum = INT_MIN;

    solve(root, sum, maxSum, len, maxLen);

    return maxSum;
}



int main() {
    
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->right->left = new Node(11);

    cout << "Maximum sum of the path from root to leaf: " << sumOfLongRootToLeafofPath(root) << endl;

    
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}