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

void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* removeNthFromEnd(Node* head,int n){
    int cnt = 0;
    Node* temp = head;

    while (temp != nullptr)
    {
       cnt++;
       temp = temp->next;
    }
    
   if(cnt == n){
    Node* newHead = head->next;
    free(head);
    return newHead;
   }

   int pos = (cnt - n);
   temp = head;

  while (temp != nullptr)
  {
    pos--;
    if(pos == 0){
        break;
    }

    temp = temp->next;
  }
  
Node* deleteNode = temp->next;
temp->next = temp->next->next;
free(deleteNode);
return head;

}

// finding the yth intersection....

Node* findIntersection(Node* head1, Node* head2) {
    unordered_set<Node*> nodes;
    
    Node* temp = head1;
    while (temp != nullptr) {
        nodes.insert(temp);
        temp = temp->next;
    }

    
    temp = head2;
    while (temp != nullptr) {
        if (nodes.find(temp) != nodes.end()) {
            return temp; 
        }
        temp = temp->next;
    }

    return nullptr; 
}


// optimal.....

Node* collisionPoint(Node *firstHead, Node *secondHead, int d){
     
    Node* temp1 = firstHead;
    Node* temp2 = secondHead;


    while(d){
        d--;
        temp2 = temp2->next;
    }

  while(temp1 != temp2){
      temp2 = temp2->next;
      temp1 = temp1->next;
  }

  return  temp1;

}




Node* findIntersectionOptimal(Node *firstHead, Node *secondHead)
{
    Node* temp1 = firstHead;
    Node* temp2 = secondHead;
    int n1 = 0;
    int n2 = 0;

    while(temp1 != nullptr){
        n1++;
        temp1 = temp1->next;
    }

     while(temp2 != nullptr){
        n2++;
        temp2 = temp2->next;
    }
    
    if(n1 < n2){
        return collisionPoint(firstHead, secondHead, n2-n1);
    }else{
        return collisionPoint(secondHead, firstHead, n1-n2);
    }
}



int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> arr2 = {6,7,3,4,5};
    int N = 3;

    Node* head1 = new Node(arr[0]);
    head1->next = new Node(arr[1]);
    head1->next->next = new Node(arr[2]);
    head1->next->next->next = new Node(arr[3]);
    head1->next->next->next->next = new Node(arr[4]);
   
    Node* head2 = new Node(arr2[0]);
    head2->next = new Node(arr2[1]);
    head2->next->next = new Node(arr2[2]);
    head2->next->next->next = new Node(arr2[3]);
    head2->next->next->next->next = new Node(arr2[4]);
   
    
    printLL(head1);
}