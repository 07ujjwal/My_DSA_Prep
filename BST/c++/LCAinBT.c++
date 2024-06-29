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

// Function to find the Lowest Common Ancestor in a BST
TreeNode* LCA(TreeNode* root, TreeNode* n1, TreeNode* n2) {
    if (root == NULL) {
        return NULL;
    }

    // If both n1 and n2 are smaller than root, then LCA lies in left
    if (root->data > n1->data && root->data > n2->data) {
        return LCA(root->left, n1, n2);
    }

    // If both n1 and n2 are greater than root, then LCA lies in right
    else if (root->data < n1->data && root->data < n2->data) {
        return LCA(root->right, n1, n2);
    }

    // If root is the split point, then it is the LCA
    else {
        return root;
    }
}



bool search(TreeNode* root, int value, TreeNode* excludeNode) {
    TreeNode* temp = root;
    
    while (temp != NULL) {
        if (temp->data == value && temp != excludeNode) {
            return true;
        }

        if (temp->data > value) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    return false;
}

bool findPair(TreeNode* root, TreeNode* current, int k) {
    if (current == NULL) {
        return false;
    }

    // Check if there exists a value such that current->data + value = k
    if (search(root, k - current->data, current)) {
        return true;
    }
    
    // Recursively check in left and right subtrees
    return findPair(root, current->left, k) || findPair(root, current->right, k);
}

bool TwoSumInBST(TreeNode* root, int k) {
    if (root == NULL) {
        return false;
    }
    
    return findPair(root, root, k);
}

// Helper function to insert a new node in BST
TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) {
        return new TreeNode(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }

    return root;
}


//optimised......

class Solution {
private:
    vector<int> inOrder(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }

        vector<int> left = inOrder(root->left);
        ans.insert(ans.end(), left.begin(), left.end());
        ans.push_back(root->data);
        vector<int> right = inOrder(root->right);
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }

public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorderList = inOrder(root);
        int i = 0;
        int j = inorderList.size() - 1;

        while (i < j) {
            int sum = inorderList[i] + inorderList[j];
            if (sum == k) {
                return true;
            }
            if (sum < k) {
                i++;
            } else {
                j--;
            }
        }

        return false;
    }
};


////////////////////////////////////
// Flatain BST To an sorted Linked List......

void Inorder(TreeNode* root, vector<int>& list) {
    if (root == NULL) {
        return;
    }

    Inorder(root->left, list);
    list.push_back(root->data);
    Inorder(root->right, list);
}


TreeNode* arrToList(const vector<int>& list) {
    if (list.empty()) return NULL;
    
    TreeNode* root = new TreeNode(list[0]);
    TreeNode* mover = root;

    for (int i = 1; i < list.size(); i++) {
        TreeNode* temp = new TreeNode(list[i]);
        mover->right = temp;
        mover->left = NULL;
        mover = temp;
    }

    return root;
}

TreeNode* flatten(TreeNode* root) {
    vector<int> inOrderList;
    Inorder(root, inOrderList);
    return arrToList(inOrderList);
}


int main() {
    TreeNode* root = NULL;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 9);

    int k = 12;

    if (TwoSumInBST(root, k)) {
        std::cout << "Found a pair with sum " << k << std::endl;
    } else {
        std::cout << "No pair with sum " << k << " found" << std::endl;
    }

    return 0;
}