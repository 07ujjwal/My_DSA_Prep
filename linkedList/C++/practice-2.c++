#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

// class Node{
//     public:
//     int data;
//     Node* next;

//     public:
//     Node(int data1, Node* next1){
//         data = data1;
//         next = next1;
//     }

//     public:
//     Node(int data1){
//         data= data1;
//         next = nullptr;
//     }
// };


// Node* createArrToLL(vector<int> &arr){
//     Node* head = new Node(arr[0]);
//     Node* mover = head;
//     for(int i = 1; i<arr.size(); i++){
//         Node* temp = new Node(arr[i]);
//         mover->next = temp;
//         mover = temp;

//     }

//     return head;
// }

// int lengthOfLL(Node* head){
//     Node* temp = head;
//     int count  = 0;
//     while (temp)
//     {
//        cout << temp->data << " "; 
//        temp = temp->next;
//        count++;
//     }

//     return count;

// }



// int searchInLL(Node* head, int val){
//     Node* temp = head;
//     while (temp)
//     {
//        if(temp->data == val){
//         return 1;
//        }

//        temp = temp->next;
//     }

//     return 0 ;
// }


// Node* deleteHead(Node* head){
//     if(head == NULL) return head;

//     Node* temp = head;
//     head = head->next;
//     free(temp);
//     return head;
// }


// Node* deleteTail(Node* head){
//     if (head == nullptr) {
//         return nullptr;
//     }
    
//     if (head->next == nullptr) {
//         delete head;
//         return nullptr;
//     }

//     Node* temp = head;

//     while (temp->next->next != nullptr) {
//         temp = temp->next;
//     }

//     delete temp->next;
//     temp->next = nullptr;  // Corrected assignment

//     return head;
// }


// Node* deleteNth(Node* head, int n) {
//     if(head == NULL){
//         return head;
//     }

//     if(n == 1){
//         Node* temp = head;
//         head = head->next;
//         free(temp);
//         return head;
//     }

//     int counter = 0;
//     Node* previous = NULL;
//     Node* temp = head;

//     while (temp != NULL)
//     {
//        counter++;
//        if(counter == n){
//         previous->next = previous->next->next;
//         free(temp);
//         break;
//        }

//      previous = temp;
//      temp = temp->next;
//     }

//   return head;
    
// }

// Node* inserterAtHead(Node* head, int el){
//     Node* temp = new Node(el, head);
//     return temp;
// }

// Node* insertAtEnd(Node* head, int el){
//     if(head == NULL){
//         return new Node(el);
//     }

//     Node* temp = head;

//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }
    
//     Node* newNode = new Node(el);
//     temp->next = newNode;
    
//     return head;
// }


// Node* insertAtN(Node* head, int element, int value){
//     if(head == NULL){
//         if(element == 1){
//             return new Node(value);
//         }else{
//             return NULL;
//         }
//     }

//     if(element == 1){
//         return new Node(value, head);
//     }

//     int count = 0;
//     Node* temp = head;

//     while (temp != NULL)
//     {
//          count++;
//          if(count == element-1){
//             Node* newNode = new Node(value);
         
//             newNode->next = temp->next;

//             temp->next = newNode;
           
//            break;
//          }

//          temp = temp->next;
//     }

//     return head;
    
// } 


// Node* insertAtAGivenElement(Node* head, int element, int val){
//     if(head == NULL){
//         if(element == head->data){
//             return new Node(val);
//         }else{
//             return NULL;
//         }
//     }

//    if(element == head->data){
//         return new Node(val);
//    }

//    Node* temp = head;

//    while (temp->next != NULL)
//    { 
//         if(element ==  temp->data){
//              Node* newNode = new Node(val);

//              newNode->next = temp->next;

//              temp->next = newNode;
//         }

//         temp = temp->next;
       
//    }
   
//    return head;

// }


class Node{
    public: 
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
;
};


Node* createArrToDList(vector<int> &arr){
    if(arr.empty()){
        return nullptr;
    }

    Node* head = new Node(arr[0]);
    Node* mover = head;

   for(int i = 1; i<arr.size(); i++){
       Node* temp = new Node(arr[i], nullptr, mover);

       mover->next = temp;

       mover = temp;

   }

   return head;
}

void printTheDList(Node* head){
    Node* temp = head;

    while (temp)
    {
        cout << temp->data << " ";

        temp = temp->next;
    }
    cout << endl;
}

int lengthOfList(Node* head){
    Node* temp = head;
    int count = 0;

   while (temp)
   {
    
     temp = temp->next;
     count++;
   };

  return  count;  
}


Node* deleteHead(Node* head){
    if( head == nullptr || head->next == nullptr ){
        return nullptr;
    }

   Node* temp = head;

   head = head->next;
   head->back = nullptr;
   temp->next =nullptr;
   delete temp;
   return head;
}


Node* deleteTali(Node* head){
    if(head == nullptr || head->next == nullptr){
        delete head;
       return  nullptr;
    }

    Node* tail = head;

   while (tail->next != nullptr)
   {
      tail = tail->next;
   }
   
   Node* prev = tail->back;
   tail->back = nullptr;
   prev->next = nullptr;

   delete tail;
   return head ;
}


Node* deleteKthNode(Node* head, int k){
   if (head == NULL)
 {
       return nullptr;
 }

    int counter = 0;
    Node* temp = head;
    Node* front = NULL;
    Node* prev = NULL;

    while (temp != nullptr)
    {
        counter++;
       
       if(counter == k){
        break;
       }

        temp = temp->next;
    }

prev = temp->back;
front = temp->next;

if(prev == nullptr || front == nullptr){
    delete temp;
    return NULL;
}

if(prev == NULL){
  return   deleteHead(head);
}

else if(front == NULL){
  return   deleteTali(head);
}
else {
   
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete(temp);
}

 return head;

}

Node* insertBeforeHead(Node* head, int val){
   Node* temp = new Node(val, head, nullptr);
   head->back = temp;
   return temp;    
}

Node* insertAfterHead(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }  
    
    
    if(head->next == nullptr){
        Node* newNode = new Node(val);
        head->next = newNode;
        newNode->back = head;
        return head;
    }

   Node* temp = head;
   temp = temp->next;
   Node* newNode = new Node(val);
   newNode->next = temp;
   head->next = newNode;
   temp->back = newNode;

   return head;
}



Node* insertBeforeTail(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }
  
     if(head->next == nullptr){
        Node* newNode = new Node(val);
        head->next = newNode;
        newNode->back = head;
        return head;
    }

    Node* mover = head;
    Node* prev = nullptr;

    while ( mover->next != nullptr)
    {
        mover = mover->next;
    }
    
    prev = mover->back;
    Node* newNode = new Node(val);
    newNode->next = mover;
    prev->next = newNode;
    newNode->back = prev;
    mover->back = newNode;

    return head;
}


Node* insertAfterTail(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }
  
     if(head->next == nullptr){
        Node* newNode = new Node(val);
        head->next = newNode;
        newNode->back = head;
        return head;
    }

  Node* mover = head;
   
     while ( mover->next != nullptr)
    {
        mover = mover->next;
    }
   
   Node* newNode = new Node(val, nullptr, mover);
    mover->next = newNode;

 return head;
};


Node* insertBeforeKthNode(Node* head, int val, int k){
     if(head == NULL){
        if(k == 1){
            return new Node(val);
        }else{
            return nullptr;
        }
     }

     if(k == 1){
        Node* temp = new Node(val);
        head->back = temp;
        temp->next = head;
        temp->back = nullptr;
        return temp;
     }

   int count = 0;
   Node* temp = head;
   Node* prev = nullptr;

   while(temp != nullptr){
      count++;
      if(count == k){
        break;
      }
        temp = temp->next;
   }
  
  prev = temp->back;

  Node* newNode = new Node(val);
  newNode->next = temp;
  prev->next = newNode;
  newNode->back = prev;
  temp->back = newNode;

  return head;
 
}


Node* insertAfterKthNode(Node* head, int val, int k){
    if(head == nullptr){
        if(k == 1){
            return new Node(val);
        }else{
            return nullptr;
        }
    }

    if(k == 1){
        Node* temp = new Node(val, nullptr, head);
        head->next = temp;
        return temp;
    }

    int count = 0;
    Node* front = nullptr;
    Node* temp = head;

    while (temp != nullptr)
    {   count++;
      if(count == k){
        break;
      }
        temp = temp->next;
       
    }
    
    front = temp->next;
    Node* newNode = new Node(val);
    newNode->next = front;
    temp->next = newNode;
    front->back = newNode;
    newNode->back = temp;
    
   return head; 
}



int main(){
    vector<int> arr = {1,2,3,4,5};
//
    Node* head = createArrToDList(arr);
//
   int length =  lengthOfList(head);
//
    printTheDList(head);
//
   head = insertAfterKthNode(head, 100, 4);
//   
    printTheDList(head);
//     
   cout << length;

    // head = insertAtAGivenElement(head, 4,100);

   // lengthOfLL(head);
    return 0;
}