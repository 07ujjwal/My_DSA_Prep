#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class node{
   
   public:
      int data;
      node* left;
      node* right;

      node(int data1){
        data = data1;
        left = NULL;
        right = NULL;
      }

};


node* buildTres(node* root) {
    cout << "Enter the data" << endl;

    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    root = new node(data);

    cout << "Enter data for inserting in left of " << root->data << endl;
    root->left = buildTres(root->left);
    cout << "Enter data for inserting in right of " << root->data << endl;
    root->right = buildTres(root->right);

    return root;
}


void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    // seperator....
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}


// basic traversals...


void inOrder(node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";

    inOrder(root->right);
}

void preOrder(node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}


void postOrder(node *root){
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// build from level order...

node* buildFromLevelOrder(node* root){
    queue<node*> q;
    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout << "Enter left Node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right Node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

         if(leftData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }

    return root;
    
}



int main(){
   node* root = NULL; 
//    root = buildTres(root);
  buildFromLevelOrder(root);
   //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
   //level order...
  
//    if (root != NULL) { // Check if the root is not NULL
//        cout << "Print the level order traversal output" << endl;
//        levelOrderTraversal(root);
//        cout << "The InOrder Traversal" << endl;
//        inOrder(root);
//        cout << "The PreOrder Traversal" << endl;
//        preOrder(root);
//         cout << "The PostOrder Traversal" << endl;
//        postOrder(root);
//    } else {
//        cout << "Tree is empty" << endl;
//    }

 


   return 0;
}
