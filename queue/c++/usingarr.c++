#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define MAX 100

class Queue{
    private:
      int front;
      int rear;
      int arr[MAX];
     
     public: 
       Queue(){
        front = -1;
        rear = -1;
       }
       
       void enqueue(int x){
          if(rear >= (MAX-1)){
            cout << "queue Overflow" << endl;
            return;
          }

          if(front == -1){
            front = 0;
          }

          arr[++rear] = x;
       }


      int dequeue(){
        if(front == -1 || front > rear){
            return -1;
        }
        return arr[front++];
      }
       

};

int main() {
    Queue queue;


    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout << queue.dequeue() << endl;  // Output: 1
    queue.enqueue(4);
    cout << queue.dequeue() << endl;  // Output: 2


    cout << queue.dequeue() << endl;  // Output: 3
    cout << queue.dequeue() << endl;  // Output: 4
    cout << queue.dequeue() << endl;  // Output: -1 (queue is empty)

    return 0;
}