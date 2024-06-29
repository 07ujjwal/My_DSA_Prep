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


//You are given a linked list of 'n' nodes and an integer 'k', where 'k' is less than or equal to 'n'.
//Your task is to reverse the order of each group of 'k' consecutive nodes, if 'n' is not divisible by 'k', then the last group of nodes should remain unchanged.
//For example, if the linked list is 1->2->3->4->5, and 'k' is 3, we have to reverse the first three elements, and leave the last two elements unchanged. Thus, the final linked list being 3->2->1->4->5.
//Implement a function that performs this reversal, and returns the head of the modified linked list.


Node* reverse(Node* head){
   if(head == nullptr){
    return nullptr;
   }

   if(head->next == nullptr){
    return head;
   }

   Node* prev = nullptr;
   Node* temp = head;

   while (temp != nullptr)
   {
       Node* after = temp->next;

       temp->next = prev;

       prev = temp;

       temp = after;
   }
   
   return prev;
}


Node* findKthNode(Node* head, int k){
    int cnt = 0;

    while (head != nullptr)
    {
        cnt++;
        if(cnt == k){
            break;
        }
        head = head->next;
    }
    
    return head;
}


Node* kRevers(Node* head, int k){
    Node* temp = head;
    Node* prevNode = nullptr;

    while(temp != nullptr){
        Node* kthNode = findKthNode(temp, k);

        if(kthNode == nullptr){
           if(prevNode) prevNode->next = temp;
           break;
        }

        Node* nextNode = kthNode->next;
        kthNode->next = nullptr;
        temp = reverse(temp);

        
        if(temp == head){
            head = kthNode;
        }else{
            prevNode->next = kthNode;
        }

        prevNode = kthNode;
        temp = nextNode;
    }

    return head;
}




int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 3, 3, 4, 5, 6, 7};

    Node* head = createArrayToNode(arr2);

    printList(head);

    // Node* rev = kRevers(head , 3);
    Node* kth = findKthNode(head, 3);
    cout << kth->data;

    // printList(rev);
    
    return 0;
}
