#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>

using namespace std;

class ListNode{
public:
    int data;
    ListNode* next;

public:
    ListNode(int data1, ListNode* next1){
        data = data1;
        next = next1;
    }

public:
    ListNode(int data1){
        data = data1;
        next = nullptr;
    }
};


class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* t1 = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int sum = 0;
       
       while (t1 != nullptr)
       {    
            if(t1->data == 0){
                if(sum != 0){
                  ListNode* newNode = new ListNode(sum);
                  temp->next = newNode;
                  temp = newNode;
                  sum = 0;
                }
            }

            sum += t1->data; 

            t1 = t1->next;
       }
       return dummy->next;
    }
};

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // linked list: 0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0
    std::vector<int> values = {0, 3, 1, 0, 4, 5, 2, 0};
    ListNode* head = createList(values);

     Solution solution;
    ListNode* result = solution.mergeNodes(head);

     printList(result);

    return 0;
}

