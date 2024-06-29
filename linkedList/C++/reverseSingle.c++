#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>

using namespace std;

class Node{
public:
    int data;
    Node* next;

public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


Node* createArrToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i< arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}


void print(Node* head){
    while (head != nullptr)
    {
        cout << head->data <<" ";
        head = head->next;
    }
    
   cout << endl; 
}


Node* reverseSingleLL(Node* head){
    if(head == nullptr){
        return nullptr;
    }

    if(head->next == nullptr){
        return head;
    }

    stack<int> st;
    Node* temp = head;

    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while (temp != nullptr)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    
  return head; 
}


Node* reverseOptimal(Node* head){
      if(head == nullptr){
            return nullptr;
        }

        if(head->next == nullptr){
            return head;
        }

       Node* temp = head;
       Node* prev = nullptr;
        
        
        while(temp != nullptr){
            Node* after = temp->next;

            temp->next = prev;

            prev = temp;

            temp = after;
        }
     return prev;
}


bool checkpallindrome(Node* head){
       if(head == nullptr || head->next == nullptr){
            return true;
        }
 
    stack<int> st;
    Node* temp = head;

    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }

  temp = head;

  while (temp != head)
  {
    if(temp->data != st.top()){
        return false;
    }

    st.pop();

    temp = temp->next;
  }

  return head;

}


bool pallindromeTandH(Node* head){
     if(head == nullptr || head->next == nullptr){
            return true;
        }
  
  Node* slow = head;
  Node* fast = head;

  while (fast != nullptr && fast->next != nullptr)
  {
     slow = slow->next;
     fast = fast->next->next;
  }

  Node* newHead = reverseOptimal(slow->next);
  Node* first = head;
  Node* second = newHead;

  while (second != nullptr)
  {
    if(first->data != second->data){
         reverseOptimal(newHead);
        return false;
    }

    first = first->next;
    second = second->next;
}
   
   reverseOptimal(newHead);
   return true;
}

// add 1 to a linked list.......

Node* AddOneToLL(Node* head){
  
    head = reverseOptimal(head);
    Node* temp = head;

    int carry = 1;

    while (temp != nullptr)
    {
        temp->data = temp->data + carry;

        if(temp->data < 10){
            carry = 0;
            break;
        }else{
            temp->data = 0;
            carry = 1;
        }

        temp = temp->next;
    }
    
 if(carry == 1){
    Node* newNode = new Node(1);
    head = reverseOptimal(head);
    newNode->next = head;
    return newNode;
 }

head = reverseOptimal(head);
return head;

}

// recurssive one after revision(backtracking method)

int main() {
    vector<int> arr1 = {1, 2};
    vector<int> arr2 = {5,6,7,8};

    Node* head1 = createArrToLL(arr1);

    print(head1);
    
    head1 = AddOneToLL(head1);

    print(head1);
  
//   if(pallindromeTandH(head1)){
//     print(head1);
//   }

    return 0;
}