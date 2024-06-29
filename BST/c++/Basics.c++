#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class TreeNode{

    public:
      int data;
      TreeNode* left;
      TreeNode* right;

      TreeNode(int data1){
        this->data = data1;
        this->left = nullptr;
        this->right = nullptr;
      }
};




// array to binary tree....// recursive....



TreeNode* insertIntoBST(TreeNode* root, int data) {
    if (root == nullptr) {
        root = new TreeNode(data);
        return root;
    }

    if (data < root->data) {
        root->left = insertIntoBST(root->left, data);
    } else {
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

bool searchInBST(TreeNode* root, int val){
    if (root == nullptr) {
        return false;
    }

    if(root->data == val){
        return true;
    }

   if (val < root->data) {
        return insertIntoBST(root->left, val);
    } else {
        return insertIntoBST(root->right, val);
    }

}

//optimized SC...

bool searchInBSTiter(TreeNode* root, int val){
    TreeNode* temp = root;

    while(temp != nullptr){
        if(temp->data == val){
            return true;
        }

        if(root->data > val){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
    return false;

}

/// min/ max.....

TreeNode* minValOfBST(TreeNode* root){

    TreeNode* temp = root;

    while (temp->left != NULL)
    {
       temp = temp->left;
    }
    
    return temp;

}


TreeNode* maxValOfBST(TreeNode* root){

    TreeNode* temp = root;

    while (temp->right != NULL)
    {
       temp = temp->right;
    }
    
    return temp;

}


// inorder predicesor/ successor......

// Helper function to insert a new node in the BST
TreeNode* insert(TreeNode* root, int data) {
    if (!root) return new TreeNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Helper function to find the node with the given key
TreeNode* findNode(TreeNode* root, int key) {
    while (root) {
        if (key < root->data) {
            root = root->left;
        } else if (key > root->data) {
            root = root->right;
        } else {
            return root;
        }
    }
    return NULL;
}

// Function to find the predecessor of a given node
TreeNode* findPredecessor(TreeNode* root, TreeNode* v) {
    TreeNode* pred = NULL;
    while (root) {
        if (v->data <= root->data) {
            root = root->left;
        } else {
            pred = root;
            root = root->right;
        }
    }
    return pred;
}

// Function to find the successor of a given node
TreeNode* findSuccessor(TreeNode* root, TreeNode* v) {
    TreeNode* succ = NULL;
    while (root) {
        if (v->data >= root->data) {
            root = root->right;
        } else {
            succ = root;
            root = root->left;
        }
    }
    return succ;
}

pair<int, int> predecessorSuccessor(TreeNode* root, int key) {
    // Find the node with the given key
    TreeNode* keyNode = findNode(root, key);
    if (!keyNode) {
        return { -1, -1 };
    }

    // Find predecessor and successor
    TreeNode* pred = findPredecessor(root, keyNode);
    TreeNode* succ = findSuccessor(root, keyNode);

    // Prepare the result
    int predVal = pred ? pred->data : -1;
    int succVal = succ ? succ->data : -1;

    return { predVal, succVal };
}

void findPreSuc(TreeNode* root, TreeNode*& pre, TreeNode*& suc, int key) {
    if (!root) return;

    if (root->data == key) {
        // the maximum value in the left subtree is predecessor
        if (root->left) {
            TreeNode* temp = root->left;
            while (temp->right)
                temp = temp->right;
            pre = temp;
        }

        // the minimum value in the right subtree is successor
        if (root->right) {
            TreeNode* temp = root->right;
            while (temp->left)
                temp = temp->left;
            suc = temp;
        }
        return;
    }

    if (root->data > key) {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    } else {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

pair<int, int> predecessorSuccessorCorrect(TreeNode* root, int key) {
    TreeNode* pre = NULL;
    TreeNode* suc = NULL;

    findPreSuc(root, pre, suc, key);

    int predVal = pre ? pre->data : -1;
    int succVal = suc ? suc->data : -1;

    return { predVal, succVal };
}


//deletion....

TreeNode* deleteFromBST(TreeNode* root, int val){
    /// base case...

    if(root == NULL){
        return root;
    }

    if(root->data == val){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //1 child
        if(root->left != NULL && root->right == NULL){
         TreeNode * temp = root->left;
         delete root;
         return temp;
        }

        if(root->left == NULL && root->right != NULL){
          TreeNode * temp = root->right;
          delete root;
          return temp;
        }

        //2 child
        if(root->left != NULL && root->right != NULL){
            int min = minValOfBST(root->right)->data;
            root->data = min;
            root->right = deleteFromBST(root->right, min);
        }
    }else if(root->data > val){
        root->left = deleteFromBST(root->left, val);
        return root;
    }else{
        root->right = deleteFromBST(root->right, val);
        return root;
    }
 return root;
}



void takeInput(TreeNode*& root) {
    int data;
    cin >> data;
    
    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    printTree(root->left);
    cout << root->data << endl;
    printTree(root->right);
}

int main() {
    TreeNode* root = nullptr;

    cout << "Enter data to create BST (-1 to stop):" << endl;
    takeInput(root);
    cout << "In-order traversal of the BST:" << endl;
    if(searchInBST(root, 14)) printTree(root);
    cout << "min val" << endl;
    int min =  minValOfBST(root);
    cout << min;
    

     
    return 0;
}