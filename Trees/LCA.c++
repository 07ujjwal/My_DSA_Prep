#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// creating a tree node

class Node{

    public:
      int data;
      Node* left;
      Node* right;

      Node(int data1){
        data = data1;
        left = nullptr;
        right = nullptr;
      }
};


Node* arrayToBinarytree(vector<int> arr){
    if(arr.empty()){
        return NULL;
    }

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int index = 1;
    int n = arr.size();

    while(!q.empty() && index < n){
        Node* current = q.front();
        q.pop();

        if(index < n && arr[index] != -1){
            current->left = new Node(arr[index]);
            q.push(current->left);
        }

        index++;

        if(index < n && arr[index] != -1){
            current->right = new Node(arr[index]);
            q.push(current->right);
        }

        index++;
    }

    return root;
}


// .......LCA of B tree......... //


Node* LCA(Node* root, Node* n1, Node* n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1->data || root->data == n2->data){
        return root;
    }

    Node* LeftAns = LCA(root->left, n1, n2);
    Node* RightAns = LCA(root->right, n1, n2);

    if(LeftAns != NULL && RightAns != NULL){
        return root;
    }

    else if(LeftAns != NULL && RightAns == NULL){
        return LeftAns;
    }

     else if(LeftAns == NULL && RightAns != NULL){
        return RightAns;
    }

    else {
        return NULL;
    }

}


//............ Kth Path Sum.................//
// given a  binery tree and an integer k . we need to find number of paths.
// in the tree which have their sum equals to k..
// A path may start from any node and end at any node int the downwards direction..


class SolutionKthPath{
    private: 
      void solve(Node* root, int k, int count, vector<int> path){
          if(root == NULL){
            return;
          }

          path.push_back(root->data);

          solve(root->left, k, count, path);
          solve(root->left, k, count, path);

       int size = path.size();
       int sum = 0;

          for(int i = size-1; i>=0; i--){
            sum += path[i];
            if(sum == k){
                count++;
            }
          }

          path.pop_back();
      }
  
    public:
      int sumK(Node* root, int k){
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
      }

};


// ........Kth Ancestor of a B-tree.........
// 1) pushing the path on a vector approch...


class solutionKthAncestoe{
 private: 
   void solve(Node* root, int k, int ancestor, int node, vector<int> path){
         if(root == NULL){
            return;
         }

         path.push_back(root->data);

        if(root->data == node){
          int size = path.size();
          if(size < k){
            ancestor= -1;
          }else{
            ancestor = path[size - k];
          }
      }

       solve(root->left, k, node, ancestor, path);
       solve(root->right, k, node, ancestor, path);

      path.pop_back();

   }
  

 public: 
   int kthAncestor(Node* root, int k, int node){
        vector<int> path;
        int ancestor = 0;
        
        // Perform DFS to find the kth ancestor
        solve(root, k, node, ancestor, path);
        
        return ancestor;
}
};
   
// .... 2nd approch......//


class Optimal : public solutionKthAncestoe{
private:
    Node* solve(Node* root, int &k, int node) {
        if (root == nullptr)
            return nullptr;

        if (root->data == node)
            return root;

        Node* leftAns = solve(root->left, k, node);
        Node* rightAns = solve(root->right, k, node);

        if (leftAns != nullptr && rightAns == nullptr) {
            k--;
            if (k == 0) {
                k = INT_MAX; // to lock the current state of k so that it never becomes 0 again during any other process...
                return root;
            } else {
                return leftAns;
            }
        }

        if (leftAns == nullptr && rightAns != nullptr) {
            k--;
            if (k == 0) {
                k = INT_MAX;
                return root;
            } else {
                return rightAns;
            }
        }

        return nullptr;
    }

public:
    int kthAncestor2(Node* root, int k, int node) {
        if (root == nullptr)
            return -1; // No ancestor found

        // Call the solve function to find the kth ancestor
        Node* ancestorNode = solve(root, k, node);
        
        // If kth ancestor exists, return its data; otherwise, return -1
        return (ancestorNode != nullptr) ? ancestorNode->data : -1;
    }
};




int main() {
    vector<int> arr = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4}; // Example array representing binary tree
    Node* root = arrayToBinarytree(arr);

    // Find nodes whose LCA needs to be found
    Node* node1 = root->left->left; // Node with data 6
    Node* node2 = root->left->right->right; // Node with data 2

    // Node* lcaNode = LCA(root, node1, node2);
    // if (lcaNode != NULL) {
    //     cout << "Lowest Common Ancestor of " << node1->data << " and " << node2->data << " is " << lcaNode->data << endl;
    // } else {
    //     cout << "Lowest Common Ancestor not found." << endl;
    // }


    Optimal optimalSolution;

    int kthAncestor = optimalSolution.kthAncestor2(root, 4, 1);

    // Output the result
    cout << "Kth ancestor: " << kthAncestor << endl;
    return 0;
}