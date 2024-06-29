#include<stdio.h>
#include<bits/stdc++.h>
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


Node* createArrayToNode(vector<int> arr){
    if(arr.empty()){
        return nullptr;
    }

    Node* head = new Node(arr[0]);

    Node* curr= head;

    for(int i = 1; i<arr.size(); i++){
        Node* newNode = new Node(arr[i]);

        curr->next = newNode;

        curr = newNode;
    
    }

    return head;
}


void printList(Node* head){
    Node* temp = head;

  while (temp != nullptr)
  {
      cout << temp->data << " ";

        temp = temp->next;
  }
  
}


// brute force algorithms.....

Node* sortLL(Node* head){
    Node* temp = head;
    vector<int> arr;

    while(temp != nullptr){
        arr.push_back(temp->data);

        temp = temp->next;
    }

    sort(arr.begin(), arr.end());

    Node* head1 = createArrayToNode(arr);

    return head1;
} 


// optimized algorithms.....
//1) mergesort algorithms.....

Node* getMiddle(Node* head){
    if(head == nullptr){
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

  return slow;
}


Node* merge(Node* list1, Node* list2){
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while(list1 != nullptr && list2 != nullptr){
        if(list1->data < list2->data){
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }else{
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }

    if(list1){
        temp->next = list1;
    }else{
        temp->next = list2;
    
    }

    return dummyNode->next;
}


Node* MergeSort(Node* head){
    if(head ==nullptr || head->next == nullptr){
        return head;
    }

    Node* mid = getMiddle(head);

    Node* leftHead = head;
    Node* rightHead = mid->next;

    mid->next = nullptr;

    leftHead = MergeSort(leftHead);
    rightHead = MergeSort(rightHead);

    Node* sortedList = merge(leftHead, rightHead);

    return sortedList;
}

// copyList With random pointer.....

int main(){
    vector<int> arr = {1, 2, 3, 4, 8, 7, 6, 5, 9};

    Node* head = createArrayToNode(arr);

    printList(head);

    cout << endl;

    Node* head1 = sortLL(head);

    printList(head1);

    return 0;
}