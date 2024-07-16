#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mpp;
        unordered_set<int> childSet;

        for (auto& dec : descriptions) {
            int parent = dec[0];
            int child = dec[1];
            int isLeft = dec[2];

            if (mpp.find(parent) == mpp.end()) {
                mpp[parent] = new TreeNode(parent);
            }

            if (mpp.find(child) == mpp.end()) {
                mpp[child] = new TreeNode(child);
            }

            if (isLeft == 1) {
                mpp[parent]->left = mpp[child];
            } else {
                mpp[parent]->right = mpp[child];
            }

            childSet.insert(child);
        }

        for (auto& dec : descriptions) {
            int parent = dec[0];

            if (childSet.find(parent) == childSet.end()) {
                return mpp[parent];
            }
        }

        return nullptr;
    }
};

// Helper function to print the binary tree (in-order traversal)
void printTree(TreeNode* root) {
    if (root == nullptr) return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main() {
    vector<vector<int>> descriptions = {
        {1, 2, 1},
        {1, 3, 0},
        {2, 4, 1}
    };

    Solution sol;
    TreeNode* root = sol.createBinaryTree(descriptions);

    cout << "In-order traversal of the constructed binary tree:" << endl;
    printTree(root); // Expected output: 4 2 1 3

    // Clean up dynamically allocated nodes
    // Note: In a real-world application, ensure to implement proper memory management
    return 0;
}
