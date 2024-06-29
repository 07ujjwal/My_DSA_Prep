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


class Stack{
    Node* top;

    public:
    Stack(){
        top = nullptr;
    }

    void push(int data){
        // new node.....
        Node* temp = new Node(data);
   
        // check if stack heap is full....
        if(!temp){
            cout << "Stack Overflow";
            exit(1);
        }
   
       temp->data = data;

        temp->next = top;

        top = temp;
    }


    bool isEmpty(){
        return top == nullptr;
    }

    int peek(){
        if(!isEmpty()){
            return top->data;
        }else{
            exit(1);
        }
    }

    void pop(){
        Node* temp;
        if(top == nullptr){
            cout << "\nStack Underflow" << endl;
            exit(1);
        }else{
            temp = top;

            top = top->next;

            free(temp);
        }
    }

    void display(){

        Node* temp;

        if(top == nullptr){
              cout << "\nStack Underflow";
            exit(1);
        } else{
            temp = top;
            while (temp != nullptr)
            {
               cout << temp->data << " ";

               temp = temp->next;


            }
            
        }
    }
};


int main(){
    Stack s;
    s.push(22);
    s.push(33);
     s.push(44);

    s.display();
    
    cout << "\nTop element is " << s.peek() << endl;

    s.pop();
    s.pop();
 

  s.display();
}
