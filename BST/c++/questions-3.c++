#include<iostream>
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

// Function to perform in-order traversal and fill the vector
void Inorder(TreeNode* root, vector<int>& list) {
    if (root == NULL) {
        return;
    }

    Inorder(root->left, list);
    list.push_back(root->data);
    Inorder(root->right, list);
}

// Function to convert sorted vector to a balanced BST
TreeNode* inOrderToBST(int s, int e, const vector<int>& inVal) {
    if (s > e) {
        return NULL;
    }

    int mid = (s + e) / 2;

    TreeNode* root = new TreeNode(inVal[mid]);
    root->left = inOrderToBST(s, mid - 1, inVal);
    root->right = inOrderToBST(mid + 1, e, inVal);
    return root;
}

// Function to balance an unbalanced BST
TreeNode* isBalanced(TreeNode* root) {
    vector<int> inOrderVal;
    Inorder(root, inOrderVal);

    return inOrderToBST(0, inOrderVal.size() - 1, inOrderVal);
}

// Function to print in-order traversal of the BST
void printInOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) {
            return -1;  // Not balanced
        }

        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) {
            return -1;  // Not balanced
        }

        if (abs(leftHeight - rightHeight) > 1) {
            return -1;  // Not balanced
        }

        return max(leftHeight, rightHeight) + 1;
    }
};


// ......preOrder to BST.......//

// approch-1 normal preOrder and postorder array to BST....


// approch-2 using the preOrder array only..


TreeNode* preOrdersolve(vector<int> &preOrderArr, int mini, int maxi, int &i){
  if(i >= preOrderArr.size()){
    return NULL;
  }

  if(preOrderArr[i] < mini || preOrderArr[i] > maxi){
    return NULL;
  }

  TreeNode* root = new TreeNode(preOrderArr[i++]);

  root->left = preOrdersolve(preOrderArr, mini, root->data, i);
  root->right = preOrdersolve(preOrderArr, root->data, maxi, i);

  return root;

}

TreeNode* preOrderTree(vector<int> &arr){
    int min = INT_MIN;
    int max = INT_MAX;
   
    int i = 0;
    return preOrdersolve(arr, min, max, i);
}




int main() {
    // Constructing an unbalanced BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->left->left->left = new TreeNode(1);

    // Print the original BST
    cout << "Original BST (In-order): ";
    printInOrder(root);
    cout << endl;

    // Balance the BST
    TreeNode* balancedRoot = isBalanced(root);

    // Print the balanced BST
    cout << "Balanced BST (In-order): ";
    printInOrder(balancedRoot);
    cout << endl;

    // Clean up memory
    delete root;
    delete balancedRoot;

    return 0;
}
