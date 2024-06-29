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



// now creating a tree out of that node;
// 1) iterative method....

Node* ArrayToBinaryTree(vector<int> arr){

    if(arr.empty()){
        return nullptr;
    }
    
   //root node...

    Node* root = new Node(arr[0]);

    //keeping a check on the current node while traversing
    //the list through the queue...
   
    queue<Node*> q;
    q.push(root);

    //index for traversing the given vector 
  
    int index = 1;
   
    while (!q.empty() && index < arr.size())
    {
      Node* current = q.front();
      q.pop();

      if(index < arr.size() && arr[index] != -1){
          current->left = new Node(arr[index]);
          q.push(current->left);
      }

      index++;

      if(index < arr.size() && arr[index] != -1){
        current->right = new Node(arr[index]);
        q.push(current->right);   
      }

      index++;
    }

  return root;

}

//2} recursive method.....

Node* CreateTree(Node* root){
    cout << "Enter the data" << endl;

    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    root =  new Node(data);

    cout << "Enter data to the left of " << root->data << endl;
    root->left = CreateTree(root->left);
    cout << "Enter data to the right of " << root->data << endl;
    root->right = CreateTree(root->right);

    return root;

}

// Level Order traversal..... of a binary tree..

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



void reverseLevelOrderTraversal(Node* root) {

    if(!root){
        return;
    }

   queue<Node*> q;
   stack<Node*> s;
   
   q.push(root);


  while (!q.empty())
  {
    Node* newNode = q.front();
    q.pop();
    s.push(newNode);

    if(newNode->left){
        q.push(newNode->left);
    }

    if(newNode->right){
        q.push(newNode->right);
    }
  }


  while (!s.empty())
  {
    cout << s.top()->data << " ";
    s.pop();
  }
  
  cout << endl;

}


void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";

    inOrder(root->right);
}


// iterative inOrder Traversal........
// uses a stack....

vector<int> iterativeInOrder(Node* root){
   vector<int> ans;

   if(root == NULL){
    return ans;
   }
   
  stack<Node*> st;
  st.push(root);

  while (!st.empty())
  {
    Node* current = st.top();
    st.pop();

    ans.push_back(current->data);
    
    if(current->left){
      st.push(current->left);
    }
    if(current->right){
      st.push(current->right);
     }

  }
  
 return ans;

}

// post order.....


void postOrder(Node *root){
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// iterative post order using 2 stacks.....

vector<int> iterativePostOrder(Node* root){
  vector<int> ans;
  stack<Node*> st1, st2;

  if(root == NULL){
    return ans;
  }

  st1.push(root);

   while (!st1.empty())
   {
      Node* current = st1.top();
      st1.pop();

      st2.push(current);

      if(current->left){
        st1.push(current->left);
      }

      if(current->right){
        st1.push(current->right);
      }


   }
   
   while (!st2.empty())
   {
     ans.push_back(st2.top()->data);
     st2.pop();
   }
   
 return ans;

}




int main(){
    
   vector<int> arr1 = {11, 22, 3, 54, 15, 23, 21};

   Node* Tree1 = ArrayToBinaryTree(arr1);

   reverseLevelOrderTraversal(Tree1);

   vector<int> ans = iterativeInOrder(Tree1);

   for(int a : ans){
    cout << a << " ";
   }

  return 0;
}
