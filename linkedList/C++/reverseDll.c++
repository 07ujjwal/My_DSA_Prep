#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back =  back1;
    }

     Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};



Node* createArrToDLL(vector<int> &arr){
    if(arr.empty()){
        return nullptr;
    }

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
          Node* newNode = new Node(arr[i]);
          mover->next = newNode;
          mover = newNode;
    }
     return head;
}

void print(Node* head){
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
    
}


// reverrse a linked list


Node* reverseTheDLL(Node* head){
    if(head == NULL){
        return nullptr;
    }

    if(head->next == nullptr){
        return head;
    }

    Node* temp = head;
    stack<int> st;
    
    while (temp != NULL)
    {
       st.push(temp->data);
       temp = temp->next;
    }
    
   temp = head;

    while (temp != NULL)
    {
       temp->data = st.top();
       st.pop();
       temp = temp->next;
    }

    return head;
}

Node* optimalApproch(Node* head){
   
    if (head == NULL || head->next == NULL) {
        return head; 
    }

     Node* prev = NULL;
     Node* temp = head;

     while (temp != NULL)
     {
       prev = temp->back;  

       temp->back = temp->next;

       temp->next = prev;

       temp = temp->back;
     }
  
  return prev->back;
     
}

// add the sum of two linked list...

Node* sunOfList(Node* head1, Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;

    Node* dummyNode = new Node(-1);
    Node* current = dummyNode;
    int carry = 0;

    while (t1 != NULL || t2 != NULL)
    {
       int sum = carry;

       if(t1) sum = sum + t1->data;
       if(t2) sum = sum + t2->data;

       Node* newNode = new Node(sum%10);

       carry = sum / 10;
   
      current->next = newNode;
      current = current->next;
       
       if(t1) t1 = t1->next;
       if(t2) t2 = t2->next;


    }

    if(carry) {
        Node* newNode = new Node(carry);
        current->next = newNode;
    }

    return dummyNode->next;
    
}




int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {5,6,7,8};

    Node* head1 = createArrToDLL(arr1);
    Node* head2 = createArrToDLL(arr2);

    print(head1);
    print(head2);

    // Node* reversed = optimalApproch(head1);
       Node* sum = sunOfList(head1, head2); 

    print(sum);

    return 0;
}