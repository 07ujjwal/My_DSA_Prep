#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


Node* createArrToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i< arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void print(Node* head){
    while (head != nullptr)
    {
        cout << head->data <<" ";
        head = head->next;
    }
    
   cout << endl; 
}


int MiddleNode(Node* head){
   Node* temp = head;
   int cnt = 0;

   while (temp != nullptr)
   {
     cnt++;
     temp = temp->next;
   }
   
   temp = head;

  int midNode = (cnt/2) + 1;

  while (temp != 0)
  {
    midNode--;
    if(midNode == 0){
        break;
    }

    temp = temp->next;
  }
  
  return temp->data;
}

bool detectLoop(Node* head){
    Node* temp = head;

    unordered_map<Node*, int> nodeMap;

    while (temp != nullptr)
    {
        if(nodeMap.find(temp) != nodeMap.end()){
            return true;
        }
     
     
     nodeMap[temp] = 1;
      
     temp = temp->next;
    }
    
    return false;
}

// detect the first cycle is done by using unodered set.....
// it stores the occurenc once and if it comes again it will be easily checked

Node* detectTheHeadOfLoop(Node* head){
    Node* temp = head;

    unordered_set<Node*> st;

    while (temp != nullptr)
    {
        if(st.find(temp) != st.end()){
            return temp;
        }
        st.insert(temp);
        temp = temp->next;
    }

    return nullptr;
    
}

//using the slow fast pointer method....
//steps..
//1) detect the loop.
//2) find the starting.(as soon as the loop is detected.
//                    take the slow ptr to head and and then
//                    move the slow and fast ptr by one step untill they 
//                    collide again.)


Node* findMiddle(Node* head){
     if(head == NULL||head->next == NULL) return NULL;
        
    Node* fast = head;
    Node* slow = head;
    Node* entry = head;
        
    while(fast->next != NULL&&fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
            
        if(slow == fast) {
            while(slow != entry) {
                slow = slow->next;
                entry = entry->next;
            }
            return slow;
        }
    }
    return NULL;
    
}

// delete the midddle of LL

Node* deleteNode(Node* head){
    if(head == NULL||head->next == NULL) return NULL;
    
    Node* fast = head;
    Node* slow = head;
    Node* prev = nullptr;

    while (fast != nullptr && fast->next != nullptr)
    {
       prev = slow; 
       slow = slow->next;
       fast = fast->next->next;  
    }
    
   if(prev->next != nullptr){
      prev->next = slow->next;
   }else{
      head = slow->next;
   }
  
  delete slow;
  
 return head; 
}


int main(){
 vector<int> arr1 = {1, 2, 3, 4, 5, 6};

 Node* head1 = createArrToLL(arr1);

 print(head1);

// cout << MiddleNode(head1);
 
 
    
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // fifth->next = nullptr;
    fifth->next = third; 

    if (detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    Node* head2 = findMiddle( head);

    cout << head2->data;

    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}