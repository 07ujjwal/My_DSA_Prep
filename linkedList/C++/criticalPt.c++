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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
         if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head; 
        ListNode* current = prev->next;
        ListNode* next = current->next;

        int min_dist = INT_MAX;
        int max_dist = -1;

        int index = 1;
        int first_critical_index = -1;
        int prev_critical_index = -1;

        while (next->next != nullptr)
        {
            if((current->data > prev->data && current->data > next->data) 
            || (current->data < prev->data && current->data < next->data)){
                if(first_critical_index != -1){
                    max_dist = index - first_critical_index;
                    min_dist = min(min_dist, index - prev_critical_index);
                }else{
                     first_critical_index = index;
                }

              prev_critical_index = index;
            }
        
         prev = current;
         current = next;
         next = next->next;
         index++;
        }
        
        if(min_dist == INT16_MAX){
            min_dist = -1;
            max_dist = -1;
        }

        return {min_dist, max_dist};
    }
};

ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the result
void printResult(const vector<int>& result) {
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
}

int main() {
    vector<int> values = {5, 3, 1, 2, 5, 1, 2};
    ListNode* head = createLinkedList(values);
    Solution sol;
    vector<int> result = sol.nodesBetweenCriticalPoints(head);
    printResult(result);  // Output: [1, 3]
    return 0;
}