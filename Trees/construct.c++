#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class TreeNode{
   
   public:
      int data;
      TreeNode* left;
      TreeNode* right;

      TreeNode(int data1){
        data = data1;
        left = NULL;
        right = NULL;
      }

};



// construct a tree from inorder and preorder traversal....
//

// Helper function to find the position of an element in the inorder array
int findPos(vector<int>& inorder, int element, int n) {
    for (int i = 0; i < n; i++) {
        if (inorder[i] == element) {
            return i;
        }
    }
    return -1;
}

// Recursive function to build the tree
TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& index, int inorderStart, int inorderEnd) {
    // Base case
    if (index >= preorder.size() || inorderStart > inorderEnd) {
        return NULL;
    }

    // Get the current element from preorder and increment the index
    int element = preorder[index++];
    TreeNode* root = new TreeNode(element);

    // Find the position of the current element in the inorder array
    int findPosition = findPos(inorder, element, inorder.size());

    // Recursively build the left and right subtrees
    root->left = solve(preorder, inorder, index, inorderStart, findPosition - 1);
    root->right = solve(preorder, inorder, index, findPosition + 1, inorderEnd);

    return root;
}

// Main function to build the tree from preorder and inorder arrays
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preOrderIndex = 0;
    TreeNode* ans = solve(preorder, inorder, preOrderIndex, 0, inorder.size() - 1);
    return ans;
}

void createMaping(vector<int>& inorder, map<int, int> nodeToIndex, int n) {
    for (int i = 0; i < n; i++) {
        nodeToIndex[inorder[i]] = i;
    }

}

TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder){
    int preOrderIndex = 0;
    map<int, int> nodeToIndex;
    createMaping(inorder, nodeToIndex, inorder.size());
    TreeNode* ans = solve(preorder, inorder, preOrderIndex, 0, inorder.size() - 1);
    return ans;
}


//.......time taken to burn a tree........///


class BurnTree{
    public: 
    TreeNode* createParentMapping(TreeNode* &root,  int target ,map<TreeNode*, TreeNode*> &nodeTpParent){
          TreeNode* res = NULL;
          queue<TreeNode*> q;
          q.push(root);
         
         while (!q.empty())
         {
            TreeNode* front = q.front();
            q.pop();

            if(front->data == target){
                res = front;
            }

          if(front->left){
            nodeTpParent[front->left] = front;
            q.push(front->left);
          }
  
  
          if(front->right){
            nodeTpParent[front->right] = front;
            q.push(front->right);
          }
         


         }
         return res;

    }

     int burnTree(TreeNode* &root, map<TreeNode*, TreeNode*> &nodeTpParent){
        map<TreeNode*, bool> visited;
          queue<TreeNode*> q;
          q.push(root);
          visited[root] = true;

          int ans = 0;

          while (!q.empty())
          {  
             bool flag = true;
             int size = q.size();
             for (int i = 0; i < size; i++)
             {
                TreeNode* front = q.front();
                q.pop();

                if(front->left && !visited[front->left]){
                    flag = 0;
                    q.push(front->left);
                    visited[front->left] = 1;
                }

                if(front->right && !visited[front->right]){
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = 1;
                }

                if(nodeTpParent[front] && !visited[nodeTpParent[front]]){
                    flag = 1;
                    q.push(nodeTpParent[front]);
                    visited[nodeTpParent[front]] = 1;
                }
             }

             if(flag == 1){
                ans++;
             }
             
          }
          
          return ans;

     }

     int minTree(TreeNode* root, int target){
        int ans = 0;
        map<TreeNode*, TreeNode*> nodeTpParent;
        TreeNode* targetNode = createParentMapping(root, target, nodeTpParent);

        ans =  burnTree(targetNode, nodeTpParent);

        return ans;
     }

};