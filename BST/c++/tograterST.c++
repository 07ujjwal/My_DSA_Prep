#include <iostream>
#include <vector>
#include <climits>
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
    void InOrder(TreeNode* root, vector<int>& inOrder) {
        if (root == nullptr) {
            return;
        }

        InOrder(root->left, inOrder);
        inOrder.push_back(root->data);
        InOrder(root->right, inOrder);
    }

    void PreOrder(TreeNode* root, vector<int>& preOrder) {
        if (root == nullptr) {
            return;
        }

        preOrder.push_back(root->data);
        PreOrder(root->left, preOrder);
        PreOrder(root->right, preOrder);
    }

    TreeNode* preOrderToBST(int* preorder, int& index, int key, int min, int max, int size) {
        if (index >= size) {
            return nullptr;
        }

        TreeNode* root = nullptr;

        if (key > min && key < max) {
            root = new TreeNode(key);
            index++;

            if (index < size) {
                root->left = preOrderToBST(preorder, index, preorder[index], min, key, size);
            }
            if (index < size) {
                root->right = preOrderToBST(preorder, index, preorder[index], key, max, size);
            }
        }
        return root;
    }

    TreeNode* bstToGstBrute(TreeNode* root) {
        vector<int> inOrder;
        vector<int> preOrder;

        InOrder(root, inOrder);
        PreOrder(root, preOrder);

        int n = preOrder.size();
        vector<int> greaterSum(n, 0);

        // Calculate the greater sum for each node
        for (int i = n - 2; i >= 0; --i) {
            greaterSum[i] = greaterSum[i + 1] + inOrder[i + 1];
        }

        // Replace the nodes in preOrder with their greater sum values
        for (int i = 0; i < n; ++i) {
            preOrder[i] = greaterSum[i];
        }

        // Convert the modified preorder array back to BST
        int index = 0;
        return preOrderToBST(preOrder.data(), index, preOrder[0], INT_MIN, INT_MAX, n);
    }


    /// optimised solution.....
    
    int sum;

    void convertToBST(TreeNode* root){
        if(root == nullptr) return;

        convertToBST(root->right);

        sum += root->data;
        root->data = sum;

        convertToBST(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        sum = 0;
        convertToBST(root);
        return root;
    }
};

void printInOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main() {
    int preorder[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(preorder) / sizeof(preorder[0]);

    Solution solution;
    int index = 0;
    TreeNode* root = solution.preOrderToBST(preorder, index, preorder[0], INT_MIN, INT_MAX, size);

    cout << "Inorder traversal of the original BST: ";
    printInOrder(root);
    cout << endl;

    TreeNode* gstRoot = solution.bstToGstBrute(root);

    cout << "Inorder traversal of the Greater Sum Tree: ";
    printInOrder(gstRoot);
    cout << endl;

    return 0;
}
