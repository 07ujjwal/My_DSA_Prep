#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* createArrToLL(vector<int>& arr) {
    if (arr.empty()) {
        return nullptr;
    }

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, mover);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* deleteHead(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;
    head = head->next;
    head->back = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}


Node* deleteTail(Node* head){
    if(head == nullptr || head->next == nullptr){
        delete head;
        return nullptr;
    }

   
    Node* tail = head;

    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    
    Node* prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;

    delete tail;
    return head;
}

Node* KthNodeDelete(Node* head, int k){
 
 if (head == NULL)
 {
       return nullptr;
 }
       int counter = 0;
       Node* temp = head;
       Node* prev = NULL;
       Node* front = NULL;
   
      while (temp != NULL)
      {
         counter++;
         if(counter == k){
            break;
         }

         temp = temp->next;
      }
      
  prev = temp->back;
  front = temp->next;

if(prev == NULL && front == NULL){
    delete temp;
    return NULL;
}
else if (prev == NULL)
{
 return deleteHead(head);
  
}
else if (front == NULL)
{
   return deleteTail(head);
    
}else
{
    prev->next = front;
    prev->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete(temp);
}

return head;

}


// Node* removeNode(Node* head, int k){
//     if(head == NULL){
//         return nullptr;
//     };

//     Node* temp = head;
//     Node* prev = nullptr;
//     Node* front = nullptr;

//     while (temp->data != k)
//     {
//         temp = temp->next;
//     }
     
//      prev = temp->back;
//      front = temp->next;
  

//     if(prev == nullptr || front == nullptr){
//         delete temp;
//         return nullptr;
//     }else if (prev == nullptr)
//     {
//       return  deleteHead(head);
//     }else if (front == nullptr)
//     {
//       return  deleteTail(head);
//     }else{
//          prev->next = front;
//          front->back = prev;
//          temp->next = nullptr;
//          temp->back = nullptr;
//          delete(temp);
//     }
    
//    return head; 
    
// }


void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;
    
    // edge case if temp is the tail node
    if(front==NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        free (temp);
        return;
    }
    
    //Disconnect temp from the doubly linked list
    prev->next = front;
    front->back = prev;
    
    // Set temp's pointers to NULL
    temp->next = nullptr;
    temp->back = nullptr;
    
    // Free memory of the deleted node
    free(temp);
    return;
}


// insertion before the head.....

Node* inserBeforeHead(Node* head , int element){
    Node* newHead = new Node(element, head, nullptr);
    head->back = newHead;
    return newHead;
}

Node* InserBeforeTail(Node* head,  int element){
    if(head == nullptr){
        return new Node(element);
    }

    Node* tail = head;
    Node* prev = nullptr;

    while (tail->next != nullptr )
    {
         tail = tail->next;  
    }

    prev = tail->back;

    Node* NewNode = new Node(element, tail, prev);
    prev->next = NewNode;
    tail->back = NewNode;

    return head;
    
}


Node* inserBegoreKth(Node* head, int n,int el){
   if(head == nullptr){
     if(n == 1){
        return new Node(el);
     }else{
        return nullptr;
     }
   } 

   if(n == 1){
    return inserBeforeHead(head, el);
   }  

   int cnt = 0;
   Node* front = head;
   Node* prev = nullptr;

   while (front != 0)
   {   cnt++;
       if(cnt == n){
           break;
       }

    front = front->next;

   }
   
   prev = front->back;

   Node* newNode = new Node(el, front, prev);

   front->back = newNode;
   prev->next = newNode;

   return head;  
   
}



int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};

    Node* head = createArrToLL(arr1);

    print(head);

    // deleteNode(head->next);

    head =  inserBegoreKth(head, 1,100);

    print(head);

    return 0;
}
