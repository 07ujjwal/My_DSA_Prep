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


// .....using list (vector) approch......

vector<int> mergedArr(vector<int> &arr1, vector<int> &arr2) {
    vector<int> result;
    int i = 0, j = 0;
    
  
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            result.push_back(arr1[i++]);
        } else {
            result.push_back(arr2[j++]);
        }
    }
    

    while (i < arr1.size()) {
        result.push_back(arr1[i++]);
    }
    
    
    while (j < arr2.size()) {
        result.push_back(arr2[j++]);
    }
    
    return result;
}

// Perform in-order traversal and store elements in an array
void inOrder(TreeNode *root, vector<int> &arr) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

// Merge two BSTs and return a sorted array of their elements
vector<int> mergeBST1(TreeNode *root1, TreeNode *root2) {
    vector<int> inOrder1, inOrder2, mergedInOrder;
    
    inOrder(root1, inOrder1);
    inOrder(root2, inOrder2);

    mergedInOrder = mergedArr(inOrder1, inOrder2);

    return mergedInOrder;
}


// ......using link-list approch.......

// Convert BST to sorted doubly linked list
void BSTtoLL(TreeNode* root, TreeNode*& head) {
    if (root == NULL) {
        return;
    }

    // Convert the right subtree first
    BSTtoLL(root->right, head);

    // Insert root at the beginning of the linked list
    root->right = head;
    if (head != NULL) {
        head->left = root;
    }
    head = root;

    // Convert the left subtree
    BSTtoLL(root->left, head);
}

// Merge two sorted doubly linked lists
TreeNode* mergeLL(TreeNode* head1, TreeNode* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    TreeNode* head = NULL;
    TreeNode* tail = NULL;

    // Initial step to set up the head and tail of the merged list
    if (head1->data < head2->data) {
        head = head1;
        head1 = head1->right;
    } else {
        head = head2;
        head2 = head2->right;
    }
    tail = head;

    // Merge the rest of the lists
    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
        } else {
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }
    }

    // Append the remaining nodes from either list
    if (head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
    } else if (head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
    }

    return head;
}

// Get the count of nodes in the linked list
int countNodes(TreeNode* head) {
    int count = 0;
    TreeNode* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->right;
    }
    return count;
}

// Convert sorted doubly linked list to BST
TreeNode* LLtoBST(TreeNode*& head, int n) {
    if (n <= 0 || head == NULL) {
        return NULL;
    }

    // Recursively construct the left subtree
    TreeNode* left = LLtoBST(head, n / 2);

    // head now points to the middle node
    TreeNode* root = head;
    root->left = left;

    // Move head to the next node in the list
    head = head->right;

    // Recursively construct the right subtree with the remaining nodes
    root->right = LLtoBST(head, n - n / 2 - 1);

    return root;
}

// Merge two BSTs and return the merged BST
TreeNode* mergeBST2(TreeNode* root1, TreeNode* root2) {
    TreeNode* head1 = NULL;
    TreeNode* head2 = NULL;

    // Convert both BSTs to sorted doubly linked lists
    BSTtoLL(root1, head1);
    BSTtoLL(root2, head2);

    // Merge the two sorted doubly linked lists
    TreeNode* mergedHead = mergeLL(head1, head2);

    // Count the number of nodes in the merged list
    int totalNodes = countNodes(mergedHead);

    // Convert the merged sorted doubly linked list back to a BST
    return LLtoBST(mergedHead, totalNodes);
}

// Utility function to print in-order traversal of the BST
void inOrderPrint(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
}

int main() {
    // Create two sample BSTs
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(5);

    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(6);

    // Merge the two BSTs
    TreeNode* mergedRoot = mergeBST2(root1, root2);

    // Print in-order traversal of the merged BST
    cout << "Merged BST in-order: ";
    inOrderPrint(mergedRoot);
    cout << endl;

    return 0;
}