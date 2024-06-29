#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class TreeNode{

    public:
      int data;
      TreeNode* left;
      TreeNode* right;

      TreeNode(int data1){
        this->data = data1;
        this->left = nullptr;
        this->right = nullptr;
      }
};


// .....validate BST..... //
// using .....sorted array property....

void inOrderTraversal(TreeNode* node, vector<int>& inOrderList) {
    if (node == NULL) {
        return;
    }
    inOrderTraversal(node->left, inOrderList);
    inOrderList.push_back(node->data);
    inOrderTraversal(node->right, inOrderList);
}


bool validateBST(TreeNode* root) {
    vector<int> inOrderList;
    inOrderTraversal(root, inOrderList);
    
    for (size_t i = 1; i < inOrderList.size(); i++) {
        if (inOrderList[i] <= inOrderList[i - 1]) {
            return false;
        }
    }
    return true;
}

// methid-2

bool isBST(TreeNode* root, int min, int max){
    if(root == NULL){
        return true;
    }

    if(root->data >= min && root->data <= max){
       bool left = isBST(root->left, min, root->data);
       bool right = isBST(root->right, root->data, max);
       return left && right;
    }else{
        return false;
    }

}


// kth largest and kth smallest elemnet in a btree....

void reverseInOrder(TreeNode* root, int& k, int& result) {
    if (root == NULL || k <= 0) {
        return;
    }
    // Traverse the right subtree first
    reverseInOrder(root->right, k, result);
    // Decrement k for each node visited
    k--;
    // If k becomes 0, we've found the k-th largest element
    if (k == 0) {
        result = root->data;
        return;
    }
    // Traverse the left subtree
    reverseInOrder(root->left, k, result);
}

int KthLargestNumber(TreeNode* root, int k) {
    int result = -1;
    reverseInOrder(root, k, result);
    return result;
}

int solve(TreeNode* root, int& i, int k) {
    if (root == NULL) {
        return -1;
    }

    int left = solve(root->left, i, k);

    if (left != -1) {
        return left;
    }

    i++;

    if (i == k) {
        return root->data;
    }

    return solve(root->right, i, k);
}

int kthSmallest(TreeNode* root, int k) {
    int i = 0; 
    return solve(root, i, k);
}

/////////////////////////////////////////////////////

void inorder(TreeNode* root, int& k, int& result) {
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree
    inorder(root->left, k, result);

    // Decrement k for each node visited
    k--;

    // If k becomes 0, we've found the k-th smallest element
    if (k == 0) {
        result = root->data;
        return;
    }

    // Traverse the right subtree
    inorder(root->right, k, result);
}


int kthSmallest(TreeNode* root, int k) {
    int result = -1;
    inorder(root, k, result);
    return result;
}




