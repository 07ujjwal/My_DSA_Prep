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

//given a linked list and the value of head our job 
//is to rotate the linked list k number of times..

// edge case--- if the (no of times) of rotation the linked-list is
// of the mnultiple of the length then it comes back to original
// config..

Node* findNThNode(Node* temp, int k){
    int cnt = 1;
    while (temp != nullptr)
    {
       if(cnt == k) return temp;
       cnt++;
       temp = temp->next;

    }
    
    return temp;
}



Node* rotateList(Node* head, int k){

  if(head == NULL||head->next == NULL||k == 0) return head;

    Node* tail = head;
    int length = 1;

    while (tail->next != nullptr)
    {
        length++;
        tail = tail->next;

    }

    if(k % length == 0 ){
        return head;
    }
    
    k = k % length;

    tail->next = head;

   Node* newLastNode = findNThNode(head, length-k);

   head = newLastNode->next;
   newLastNode->next = nullptr;

   return head;
    
}


/// merge two sorted linked list....

void SelectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int temp = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[temp]) {
                temp = j;
            }
        }
        if (temp != i) {
            swap(arr[temp], arr[i]);
        }
    }
}

Node* MergeSorted(Node* head1, Node* head2){
        vector<int> arr;
        Node* temp1 = head1;
        Node* temp2 = head2;
  
  while (temp1 != nullptr)
  {
       arr.push_back(temp1->data);
       temp1 = temp1->next;
  }

  while (temp2 != nullptr)
  {
    arr.push_back(temp2->data);
    temp2 = temp2->next;
  }

  SelectionSort(arr);
  
  Node* newHead = createArrToLL(arr);

  return newHead;

}


int main() {
    vector<int> arr1 = {1, 2};
    vector<int> arr2 = {5,6,7,8};

    Node* head1 = createArrToLL(arr2);
    Node* head2 = createArrToLL(arr1);

    print(head1);

     Node* rotated = MergeSorted(head1, head2);
   
    print(rotated);
  
    return 0;
}