#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = nullptr;
    }

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};



class Queue{
    Node* front;
    Node* back;
   
   public:
    Queue(){
        front = nullptr;
        back = nullptr;
    }
    
    void  enqueue(int x){
        Node* newNode = new Node(x);

        if(newNode == nullptr){
            return;
        }else{
            if(front == nullptr){
                front = newNode;
                back = newNode;
            }else{
                back->next = newNode;
                back = newNode;
            }
        }
    }


    int dequeue(){
        if(front == nullptr){
            return -1;
        }else{
            Node* temp = front;
            front = front->next;
            int val = temp->data;
            delete temp;
            return val;
        }
    }


    int frontVal(){
        if(front == nullptr){
            return -1;
        }else{
            return front->data;
        }
    }

    bool isEmpty(){
        return front == nullptr;
    }

    int size(){
        int cnt = 0;

        Node* temp = front;

        while (temp != back)
        {
            cnt++;
            temp = temp->next;
        }

        return cnt;
        
    }

};


int main(){
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    
    cout<< q.frontVal() << endl;

    cout<< q.size() << endl;

    q.dequeue();

    cout<< q.size() << endl;
   
   return 0;

}