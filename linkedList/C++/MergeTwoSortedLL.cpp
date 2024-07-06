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


Node* mergeSortedLL(Node* head1, Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;

    Node* dummy = new Node(-1);
    Node* temp = dummy;

    while(t1 != nullptr && t2 !=nullptr){
         if(t1->data < t2->data){
              temp->next = t1;
              temp = t1;
              t1 = t1->next;
         }else{
            temp->next = t2;
            temp = t2;
            t2  = t2->next;
         }
    }

 if(t1) {
    temp->next = t1;
 }else{
    temp->next = t2;
 }
 
 return dummy->next;
}

void print(Node* head){
    while (head != nullptr)
    {
        cout << head->data <<" ";
        head = head->next;
    }
    
   cout << endl; 
}

// merge K sorted linked list.......
// bruteforce....

Node* mergeKortedLL(vector<Node*> &arr){
    vector<int> mergedArr;
    for(int i = 0; i < arr.size(); i++){
        Node* temp = arr[i];
        while(temp != nullptr){
            mergedArr.push_back(temp->data);
            temp = temp->next;
        }
    }
    
    sort(mergedArr.begin(), mergedArr.end());
    
    return createArrToLL(mergedArr);
}

// optimised using mergeSortedLL function.......

Node* mergeKsortedLL(vector<Node*> &list){
    Node* head = list[0];
    for(int i = 0; i<list.size(); i++){
       head = mergeKsortedLL(head, list[i]);
    }

    return head;
}

// using a priority queue.......




int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    vector<int> arr1 = {1,4,8,12,16,20};
    vector<Node*> arrLL;
    Node* head = createArrToLL(arr);
    Node* head1 = createArrToLL(arr1);
    arrLL.push_back(head);
    arrLL.push_back(head1);
        Node* merged = mergeKortedLL(arrLL);
        print(merged);
        return 0;

}