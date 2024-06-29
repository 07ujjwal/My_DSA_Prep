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




void LevelOrderTraversal(Node* root){

  //keeping a check on the current node while traversing
  //the list through the queue...

   queue<Node*> q;
   q.push(root);
  
   // seperator...

   q.push(NULL);

   while (!q.empty())
   {
      Node* current = q.front();
      q.pop();

   if(current == NULL){
    
    // after complete traversal of a level

    cout << endl;

    if(!q.empty()){
       
    // if queue if still not empty.... 
         q.push(NULL);
    }
   }else{

     cout << current->data << " ";

      if(current->left){
        q.push(current->left);

      }

      if(current->right){
        q.push(current->right);
      }
   }
 }
}


// finding height of an Tree.....


int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
}


// iterative method of finding a height......


int IterativeHeight(Node* root){
    if(root == NULL){
        return 0;
    }
   
   queue<Node*> q;
   q.push(root);
   int height = 0;

   while (!q.empty())
   {
       int nodeCount = q.size();

       height++;

       while (nodeCount > 0)
       {
        Node* current = q.front();
         q.pop();

            // Enqueue left child if exists
            if (current->left)
                q.push(current->left);

            // Enqueue right child if exists
            if (current->right)
                q.push(current->right);

            nodeCount--;
       }
       
   }
   return height;

}

//....................................................................//

pair<int, int> diameterFast(Node* root){
     if(root == NULL){
         pair<int, int> p = make_pair(0,0);
         return p;
      }

     pair<int , int> left = diameterFast(root->left);
     pair<int, int> right = diameterFast(root->right);
     
     int opt1 = left.first;
     int opt2 = right.first;
     int opt3 = left.second + right.second + 1;

     pair<int, int> ans;

     ans.first = max(opt1, max(opt2, opt3));
     ans.second = max(left.second, right.second);

     return ans;
};

int diameter1(Node* root){
    return diameterFast(root).first;
}


int main() {
    vector<int> arr = {1, 2, 3, 4, -1, 5, 6, 7, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    Node* root = arrayToBinarytree(arr);
    int h = height(root);

    cout << "Level Order Traversal of the constructed binary tree: ";
    LevelOrderTraversal(root);
    cout << endl;
    cout << "height: " << height << endl;

    return 0;
}