#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Queue{
     
   private:  
     stack<int> s1, s2;

     void transfers1Tos2(){
       while (!s1.empty())
       {
           s2.push(s1.top());
           s2.pop();
       }
     }

    public:  
      void enqueue(int x){
        s1.push(x);
      }

      int dequeue(){
        if(s1.empty()){
            if(s2.empty()){
                return -1;
            }

            transfers1Tos2();
        }

        int frontEl = s2.top();
        s2.pop();
        return frontEl;
      }


      int front() {
        if (s2.empty()) {
            if (s1.empty()) {
                return -1; 
            }
            transfers1Tos2();
        }
        return s2.top();
    }


    bool empty() {
        return s1.empty() && s2.empty();
    }

};


int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    cout << q.front() << endl; // 1
    cout << q.dequeue() << endl; // 1
    cout << q.front() << endl; // 2
    cout << q.dequeue() << endl; // 2
    cout << q.empty() << endl; // 1 (true)
    cout << q.dequeue() << endl; // -1

    return 0;
}