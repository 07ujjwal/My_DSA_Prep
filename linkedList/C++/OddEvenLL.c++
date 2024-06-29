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
    Node* curr = head;

    for(int i = 1; i<arr.size(); i++){
        Node* newNode = new Node(arr[i]);
        curr->next = newNode;;
        curr = newNode;
    }

    return head;
}


void printList(Node* head){
    Node* temp  = head;
    while (temp!=nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// bruteforce ....
// tc O{2n} sc= O{n}


Node* OddEvenIndex(Node* head){
   if(head  == nullptr || head->next == nullptr){
    return head;
   }

   vector<int> arr;
   Node* temp = head;
   
   while (temp != nullptr && temp->next != nullptr)
   {
       arr.push_back(temp->data);
       temp = temp->next->next;
   }
   
  if(temp) arr.push_back(temp->data);
  temp = head->next;

  while (temp != nullptr && temp->next != nullptr)
  {
     arr.push_back(temp->data);
     temp = temp->next->next;
  }
  
  if(temp) arr.push_back(temp->data);
 
 temp = head;
 int i = 0;

 while (temp != nullptr)
 {
    temp->data = arr[i];
    i++;
    temp  = temp->next;
 }

 return head;
}



Node* segregateEvenOdd(Node* head)
{if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* evenHead = nullptr;
    Node* evenTail = nullptr;
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;

    Node* current = head;

    while (current != nullptr) {
        if (current->data % 2 == 0) {
            if (evenHead == nullptr) {
                evenHead = current;
                evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = current;
            }
        } else {
            if (oddHead == nullptr) {
                oddHead = current;
                oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = current;
            }
        }

        current = current->next;
    }

    // Concatenate even and odd sublists
    if (evenHead != nullptr) {
        evenTail->next = oddHead;
        return evenHead;
    } else {
        return oddHead;
    }
}

// optimise the sc....

Node* OddEvenIndexSCOpt(Node* head){
    if(head == nullptr || head->next == nullptr){
       return head;
    }

    Node* odd = head;
    Node* even = head->next;
    Node* dummyNode = even;

    while (even != nullptr && even->next != nullptr)
    {
       odd->next = odd->next->next;
       even->next = even->next->next;

       odd = odd->next;
       even = even->next;
    }

    odd->next = dummyNode;

    return head;  
}


Node* Sort012(Node* head) {
    if(head == nullptr && head->next == nullptr){
        return head;
    }

    Node* temp = head;
    int zeros = 0;
    int ones = 0;
    int twos = 0;


    while (temp != nullptr)
    {
       if(temp->data == 0){
        zeros++;
       }

        if(temp->data == 1){
        ones++;
       }

        if(temp->data == 2){
         twos++;
       }

       temp = temp->next;
    }
    
    temp = head;

    while (temp != nullptr)
    {
        if(zeros){
            temp->data = 0;
            zeros--;
        }else if(ones){
            temp->data = 1;
            ones--;
        }else{
            temp->data = 2;
            twos--;
        }

        temp = temp->next;
    }

    return head;
    
}


Node* sortInOnePass(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* head0 = nullptr;
    Node* tail0 = nullptr;
    Node* head1 = nullptr;
    Node* tail1 = nullptr;
    Node* head2 = nullptr;
    Node* tail2 = nullptr;

    Node* current = head;

    while (current != nullptr) {
        if (current->data == 0) {
            if (head0 == nullptr) {
                head0 = current;
                tail0 = current;
            } else {
                tail0->next = current;
                tail0 = current;
            }
        } else if (current->data == 1) {
            if (head1 == nullptr) {
                head1 = current;
                tail1 = current;
            } else {
                tail1->next = current;
                tail1 = current;
            }
        } else {
            if (head2 == nullptr)
             {
                head2 = current;
                tail2 = current;
            } else {
                tail2->next = current;
                tail2 = current;
            }
        }

        current = current->next;
    }

    if (head0 != nullptr) {
        if (head1 != nullptr) {
            tail0->next = head1;
            tail1->next = head2;
            tail2->next = nullptr;
        } else {
            tail0->next = head2;
            tail2->next = nullptr;
        }

        return head0;
    } else {
        if (head1 != nullptr) {
            tail1->next = head2;
            tail2->next = nullptr;
            return head1;
        } else {
            return head2;
        }
    }
}



int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> arr2 = {1,2,0,0,1,2,1,0};

    Node* head = createArrayToNode(arr2);

     printList(head);

    // head = segregateEvenOdd(head);
    head = sortInOnePass(head);

    printList(head);

   

    return 0;
}