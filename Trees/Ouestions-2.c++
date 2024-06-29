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

//.........ZiqZag Traversal of binary tree.......//

vector<int> ZigZagTraversal(Node* root){
    vector<int> result;

    if(root == NULL){
        return result;
    }

    queue<Node*> q;
    q.push(root);
   
    bool flagLToR = true;

     while (!q.empty())
     {
        int size = q.size();
        vector<int> ans;

        for(int i = 0; i<size; i++){
            Node* frontNode = q.front();
            q.pop();

            int index = flagLToR ? i : size - i + 1;

            ans[index] = frontNode->data;

            if(frontNode->left){
                q.push(frontNode->left);
            }

             if(frontNode->right){
                q.push(frontNode->right);
            }
        }
     
     flagLToR = !flagLToR;

     for(auto i : ans){
        result.push_back(i);
     }
   }

   return result;  
}

//.............Boundary Traversal.............//
// hard problem,,,,
// here you have to traverse through the boundries of a tree...
//        (1)
//        / \
//      (2) (3)
//     / \   / \ 
//   (4)  5  6  (7)
//   /   /   \    / \
// (8) (9)  (10)(11)(12)


void traverseLeft(Node* root, vector<int>& ans) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return;
    }

    ans.push_back(root->data);

    if (root->left) {
        traverseLeft(root->left, ans);
    } else {
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(Node* root, vector<int>& ans) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node* root, vector<int>& ans) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return;
    }

    if (root->right) {
        traverseRight(root->right, ans);
    } else {
        traverseRight(root->left, ans);
    }

    ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node* root) {
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }

    ans.push_back(root->data); // Add root to answer

    traverseLeft(root->left, ans);
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
    traverseRight(root->right, ans);

    return ans;
}


////.................................................../////
/// .....virtical Order Traversal Of a Tree.........


vector<int> verticalOrderTraversal(Node* root){
    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node*, pair<int, int>>> q;
    vector<int> ans;
    
    if(root == NULL){
        return ans;
    } 

    q.push(make_pair(root, make_pair(0,0)));

    while (!q.empty())
    {
        pair<Node*, pair<int, int>> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if(frontNode->left){
            q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
        }
    }


    for(auto i : nodes){
        for(auto j : i.second){
            for(auto k : j.second){
                ans.push_back(k);
            }
        }
    }
    
  return ans;
}



//.............Top View of Binary Tree...............//



vector<int> topView(Node* root) {
    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    map<int, int> topNode;
    queue<pair<Node*, int>> q;

    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;
       
        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        }

        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    for (auto i : topNode) {
        ans.push_back(i.second);
    }

    return ans; 
}


//.....left View of binary tree.....//

void solveLeft(Node* root, vector<int> &ans, int level){

    if(root == NULL){
        return;
    }

    if(level == ans.size()){
        ans.push_back(root->data);
    }

      solveLeft(root->left, ans, level+1);
    
      solveLeft(root->right, ans, level+1);
   
} 


vector<int> leftView (Node* root){
   vector<int> ans;
   solveLeft(root, ans, 0);
   return ans;

}




int main() {
    // Create a sample binary tree
    Node* root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);

    // Perform boundary traversal
    vector<int> result =  leftView(root);

    // Print the result
    cout << "Boundary Traversal of the binary tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}