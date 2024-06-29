#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>

using namespace std;

// self defined datastructure here it is LL;

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



// converting an array into an new linked list...

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


// finding the length of linked list
// and traversal..


int LengthOfLL(Node* head){
    int count = 0;
    Node* temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    }
    return count;
}

//searching in alinked list

int searchInLL(Node* head, int val){
    Node* temp = head;
    while (temp)
    {
      if(temp->data == val){
        return 1;
      }

      temp = temp->next;
    }

    return 0;
}


// All deletions

Node* deleteHead(Node* head){
    if(head == NULL) {return head;}
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* deleteTail(Node* head){
    if (head == nullptr) {
        return nullptr;
    }
    
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;

    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;  // Corrected assignment

    return head;
}


Node* deleteNth(Node* head, int n){
    if(head == NULL) {
        return head;
    }

    if(n == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int counter = 0;
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL)
    {
        counter++;
        if(counter == n){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
       prev = temp;
       temp = temp->next;

    }

    return head;
    
}


Node* deleteVal(Node* head, int el){
    if(head == NULL) {
        return head;
    }

    if(head->data == el){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

   
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL)
    {
       
        if(temp->data == el){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
       prev = temp;
       temp = temp->next;

    }

    return head;
    
}


// All insertions..

Node* isertAtBegining(Node* head, int el){
     Node* temp = new Node(el, head);
     return temp;
}


Node* insertAtEnd(Node* head,  int el){

    if(head == NULL){
        return new Node(el);
    }
  
  Node* temp = head;

    while (temp->next != NULL)
    {    
       temp = temp->next;
    }

    Node* newNode = new Node(el);
    temp->next = newNode;  

    return head;  
}

Node* insertAtMid(Node* head, int k, int el){
   if(head == NULL){
    if(k == 1) {
        return new Node(el);
    }else {
        return NULL;
    }
   }

  if(k == 1){
    Node* temp = new Node(el, head);
    return temp;
  }

  int cnt = 0;
  Node* temp = head;

  while (temp != NULL)
  {
    cnt++;
    if(cnt == k-1){
       Node* newNode = new Node(el);
       // first connect new node to the n + 1 el
       newNode->next = temp->next;
       //then  connect the previous one to new node;
       temp->next = newNode;
      break;

    }
    temp = temp->next;
  }
  

  return head;


}


Node* insertAtGivenElement(Node* head, int element, int value){
    if(head == NULL){
        if(element == head->data){
            return new Node(value);
        }
        else{
            return NULL;
        }
    }

    if(element == head->data){
        Node* temp = new Node(value, head);
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        if(element == temp->data){
            Node* newNode = new Node(value);

            newNode->next = temp->next;

            temp->next = newNode;

            break;
        }

        temp = temp->next;
    }

    return head;
    
}



int main(){
    Node* y = new Node(2, nullptr);
    cout << y->data << endl;

    vector<int> arr1 = {1,2,3,4,5};
    Node* head = createArrToLL(arr1);

    int count = LengthOfLL(head);
    cout << "Search Result: " << searchInLL(head, 6) << endl;

    head = insertAtGivenElement(head, 3, 100);

    cout << "Length after deleting a node: " << LengthOfLL(head) << endl;

    return 0;
}
