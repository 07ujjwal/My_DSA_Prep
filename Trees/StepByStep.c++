#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool findPath(TreeNode* root, int target, string& path) {
    if (!root) return false;
    if (root->val == target) return true;

    path.push_back('L');
    if (findPath(root->left, target, path)) return true;
    path.pop_back();

    path.push_back('R');
    if (findPath(root->right, target, path)) return true;
    path.pop_back();

    return false;
}

string getDirections(TreeNode* root, int startValue, int destValue) {
    string pathToStart, pathToDest;
    findPath(root, startValue, pathToStart);
    findPath(root, destValue, pathToDest);

    // Find the first non-matching position
    int i = 0;
    while (i < pathToStart.size() && i < pathToDest.size() && pathToStart[i] == pathToDest[i]) {
        i++;
    }

    // Construct the final path
    string result(pathToStart.size() - i, 'U');  // Steps to LCA
    result += pathToDest.substr(i);  // Steps from LCA to destValue

    return result;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(4);

    int startValue = 3;
    int destValue = 6;

    cout << getDirections(root, startValue, destValue) << endl;  // Output: "UURL"

    return 0;
}
