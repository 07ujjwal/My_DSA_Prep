#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data1) {
        this->data = data1;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& list){

        if(root == NULL) return;
        
        inorder(root->left, list);
        list.push_back(root->data);
        inorder(root->right, list);

    }
    
    TreeNode* construct(int l, int r, vector<int>& list){
        if(l > r) return NULL;
         int mid = l + (r - l)/2;
        TreeNode* root = new TreeNode(list[mid]);

        root->left = construct(l, mid-1, list);
        root->right = construct(mid+1, r, list);

        return root;

    }
   

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> list;
        
        inorder(root, list);

        int l = 0;
        int r = list.size() - 1;

        return construct(l,r,list);
    }
};


void printPreorder(TreeNode* root) {
    if (root == nullptr) return;
     cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    // Creating an unbalanced BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->left->left = new TreeNode(0);
    root->left->right = new TreeNode(7);
    root->left->right->left = new TreeNode(6);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(20);

    Solution sol;
    TreeNode* balancedRoot = sol.balanceBST(root);

    cout << "Inorder traversal of the balanced BST: ";
    printPreorder(balancedRoot);
    cout << endl;

    return 0;
}