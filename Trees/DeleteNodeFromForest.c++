#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data1) {
        val = data1;
        left = NULL;
        right = NULL;
    }
};

class Solution {
private:
    TreeNode* deleteNodes(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& result) {
        if(root == NULL) {
            return NULL;
        }

        root->left = deleteNodes(root->left, st, result);
        root->right = deleteNodes(root->right, st, result);

        if(st.find(root->val) != st.end()) {
            if(root->left != NULL) {
                result.push_back(root->left);
            }
            if(root->right != NULL) {
                result.push_back(root->right);
            }
            return NULL;
        } else {
            return root;
        }
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        unordered_set<int> st(to_delete.begin(), to_delete.end());

        root = deleteNodes(root, st, result);

        if(root != NULL) {
            result.push_back(root);
        }

        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> to_delete = {3, 5};

    Solution sol;
    vector<TreeNode*> result = sol.delNodes(root, to_delete);

    cout << "Remaining trees' roots: ";
    for(TreeNode* tree : result) {
        cout << tree->val << " ";
    }

    return 0;
}
