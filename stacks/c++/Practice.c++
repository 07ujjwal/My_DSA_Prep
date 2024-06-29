#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// #define MAX 100

// class Stack {
//     int top;

//     public:
//      int a[MAX];

//      Stack(){top = -1;}
//      bool push(int x);
//      int pop();
//      int peek();
//      bool isEmpty(); 
// };

// bool Stack::push(int data){
//   if(top >= (MAX - 1)){
//     cout << "Stack Overflow" << endl;
//     return false;
//   }else{
//     a[++top] = data;
//     cout << data << " pushed int stack\n";
//     return true;
//   }      
// }

// int  Stack::pop(){
//     if(top < 0){
//         cout << "Stack underflow";
//         return 0;
//     }else{
//        int x = a[top--];
//        return x; 
//     }
// }

// int Stack::peek(){
//     if(top < 0){
//          cout << "Stack underflow";
//         return 0;
//     }else{
//         int x = a[top];
//         return x;
//     }
// }

// bool Stack::isEmpty(){
//     return (top < 0);
// }


// int main() {
//     class Stack s;
//     s.push(2);
//     s.push(3);
//     int popedEl = s.peek();
//     cout << popedEl;
// }

// class Stack{
//      vector<int> a;

//      public:

//      Stack() = default;

//      bool push(int x){
//             a.push_back(x);
//             cout << x << "Pushed into the stack\n";
//             return true;
//      }

//      int pop(){
//         if(isEmpty()){
//             cout << "stack Underflow";
//             return 0;
//         }else{
//             int x = a.back();
//             a.pop_back();

//             return x;
//         }
//      }

//      int top(){
//         if(isEmpty()){
//             cout << "stack Underflow";
//             return 0;
//         }else{
//             return a.back();
//         }
//      }

//    bool isEmpty(){
//       return a.empty();
//    }  
// };


// int main() {
//     Stack s;
//     s.push(10);
//     s.push(20);
//     s.push(30);

//     cout << s.pop() << " Popped from stack\n";

//     cout << "Top element is : " << s.top() << std::endl;

//     cout << "Elements present in stack : ";
//     while (!s.isEmpty()) {
//         cout << s.top() << " ";
//         s.pop();
//     }

//     return 0;
// }


class Node{
    public: 
      int data;
      Node* next;

      Node(int data1){
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
        Node* temp = new Node(data);

        if(!temp){
            cout << "Stack Overflow";
            exit(1);
        }

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
