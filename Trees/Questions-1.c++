#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
      int data;
      Node* left;
      Node* right;

      Node(int data1){
        data = data1;
        left = NULL;
        right =NULL;
      }
};


Node* arrrayToBinarytree(vector<int> arr){
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


// height of a binary tree....


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

// diameter of a binary tree...
// here the TC of diameter function call is O(n) also
// we are calling the height function having TC of O(n)
// so in combination the TC becomes O(n^2) which needs to be optimised..


int Diameter0(Node* root){
    
    if(root == NULL){
        return 0;
    }

    int opt1 = Diameter0(root->left);
    int opt2 = Diameter0(root->right);
    int opt3 = height(root->left) + height(root->right) + 1;

    int ans = max(opt1, max(opt2, opt3));

    return ans;
}


// optimised code....
// return the diameter and height at the same time to 
// restrict the TC to O(n)


pair<int, int> diameterFast(Node* root){
    
    // base case...
    if(root == NULL){
        pair<int, int> p = make_pair(0,0);
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + right.second ;

    pair<int,int> ans;
    ans.first = max(opt1, max(opt2, opt3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
    
}

int diameter1(Node* root){
    return diameterFast(root).first;
}


// check for the balanced tree....
// ie difference betwwen height of left subtree and right subtree should  
// not be more than 1


bool isBalanced(Node* root){
      if(root == NULL){
        return true;
      }

      bool left = isBalanced(root->left);
      bool right = isBalanced(root->right);

      bool diff = abs(height(root->left)-height(root->right)) <= 1;

      if(left && right && diff){
         return 1;
      }else{
        return false;
      }

}

// this solution is also having the same problem of TC = O(n^2);

pair<bool, int> isBalancedFast(Node* root) {
    if (root == NULL) {
        return make_pair(true, 0);
    }

    pair<bool, int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);

    bool LeftAns = left.first;
    bool rightAns = right.first;

    int diff = abs(left.second - right.second);

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if (LeftAns && rightAns && diff <= 1) {
        ans.first = true;
    } else {
        ans.first = false;
    }

    return ans;
}

bool isBalancedOpt(Node* root) {
    return isBalancedFast(root).first;
}


// ..........check for the identical trees...........

bool isSimiler(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }

    if(root1 == NULL && root2 != NULL){
        return false;
    }

    if(root1 != NULL && root2 == NULL){
        return false;
    }
    
    bool left = isSimiler(root1->left, root2->left);
    bool right = isSimiler(root1->right, root2->right);

    bool value = root1->data == root2->data;

    if(left && right && value){
        return true;
    }else{
        return false;
    }

}



int main(){
    
   vector<int> arr1 = {11, 22, 3, 54, 15, -1, -1, 23, 21, 22};

   Node* Tree1 = arrrayToBinarytree(arr1);

   int diameter = diameter1(Tree1);
   cout << diameter << endl;
   cout << isBalancedOpt(Tree1);

  return 0;
}