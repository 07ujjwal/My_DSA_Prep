#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* child;

public:
    Node(int data1, Node* next1, Node* child1){
        data = data1;
        next = next1;
        child = child1;
    }

public:
    Node(int data1){
        data = data1;
        next = nullptr;
        child = nullptr;    
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

Node* mergeToLL(Node* head1, Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;

    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while (t1 != nullptr && t2 != nullptr)
    {
       if(t1->data < t2->data){
          temp->child = t1;
          temp = t1;
          t1 = t1->child;
       }else{
        temp->child = t2;
        temp = t2;
        t2 = t2->child;
       }
 
     temp->next = nullptr;
       
    }

    if(t1){
        temp->next = t1;
    }else{
        temp->next = t2;
    }

    return dummyNode->child;
    
}

Node* Flatten(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    head->next = Flatten(head->next);

    head = mergeToLL(head, head->next);

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


// sorting of array....

void selectionSort(vector<int> &arr){
      for(int i = 0; i < arr.size(); i++){
           int min = i;
           for(int j = i; j < arr.size(); j++){
                       if(arr[j] < arr[min]){
                            min = j;
                       }
           }

           swap(arr[i], arr[min]);
      }
}

void bubbleSort(vector<int> &arr){
    int n = arr.size();
    for(int i = n-1; i >= 1 ; i--){
        for(int j = 0; j < i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

Node* flateningofLL(Node* head){
    Node* temp = head;
    vector<int> arr;
    while(temp != nullptr){
       
        if(temp->child == nullptr){
            temp = temp->next;
        }

        Node* temp2 = temp;

        while (temp2->child != nullptr)
        {
            arr.push_back(temp2->data);
            temp2 = temp2->next;
        }
        
        temp = temp->next;
    }

     head = createArrToLL(arr);

    return head;
}



// flatennig the linked list


int main() {
    vector<int> arr1 = {1, 2};
    vector<int> arr2 = {5,7,6,4,8};

    Node* head1 = createArrToLL(arr2);
    Node* head2 = createArrToLL(arr1);

    print(head1);

    
    return 0;
}