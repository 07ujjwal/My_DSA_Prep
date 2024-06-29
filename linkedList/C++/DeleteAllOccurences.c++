#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1 = nullptr, Node* back1 = nullptr){
        data = data1;
        next = next1;
        back = back1;
    }
};

Node* createArrToDLL(vector<int> &arr){
    if(arr.empty()){
        return nullptr;
    }

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node* newNode = new Node(arr[i]);
        mover->next = newNode;
        newNode->back = mover; // fix: set the back pointer of the new node
        mover = newNode;
    }
    return head;
}

void print(Node* head){
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

Node* deleteAllOcc(Node* head, int key){
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == key) {
            if (temp == head) {
                head = temp->next;
            }
            Node* after = temp->next;
            Node* prev = temp->back;
            if (after)
                after->back = prev;
            if (prev)
                prev->next = after;

            delete temp;
            temp = after;
        }  
        else {
            temp = temp->next;
        }
    }
    
    return head;
}


// pair of sum......


Node* findTail(Node* head){
    while (head != nullptr && head->next != nullptr)
    {
       head = head->next;
    }
    
    return head;
}


vector<pair<int, int>> sumOfPair(Node* head, int k){
    Node* temp1 = head;
    vector<pair<int, int>> arr;

    while (temp1 != nullptr) {
        Node* temp2 = temp1->next;
        while (temp2 != nullptr) {
            if (temp1->data + temp2->data == k) {
                arr.push_back(make_pair(temp1->data, temp2->data));
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return arr;
}


vector<pair<int, int>> twoPointerSum(Node* head, int k){
    Node* temp = head;
    Node* tail = findTail(head);
    vector<pair<int, int>> arr;


    while (temp <= tail )
    {
       if(temp->data + tail->data == k){
        arr.push_back(make_pair(temp->data, tail->data));
        temp = temp->next;
        tail = tail->back;
       } else if(tail->data >= k){
          tail = tail->back;
       } else{
         temp = temp->next;
       }
    }
    
    return arr;
}


//removeing dubicates from a sorted doubly ll...
// since it is a sorted ll the dublicates will always be in a contegious
// manner
//Algo....
//  temp = head 
// while(temp != null && temp->next != null){
//      newNode =temp->next;
//      while(newNode != null && newNode->val == temp->val){
//         newNode = newNode->next;
//    }
//  temp->next = bewNode;
// if(NewNodde) newNode->prev = temp;
// temp = temp->next;
//}
//return head;



Node* removeDublicate(Node* head){
     Node* temp = head;
     while (temp != nullptr && temp->next != nullptr)
     {
         Node* nextNode = temp->next;
         while (nextNode != nullptr && nextNode->data == temp->data)
         {
             Node* dummyNode = nextNode;
             nextNode = nextNode->next;
             delete dummyNode;
         }
         temp->next = nextNode;
         if(nextNode != nullptr) nextNode->back = temp;
         temp = temp->next;
     }

     return head;
     
}


int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 3, 3, 4, 5, 6, 7};

    Node* head = createArrToDLL(arr2);

    print(head);

    // vector<pair<int, int>> arr3 = twoPointerSum(head, 6);
    // for (auto pair : arr3) {
    //     cout << "(" << pair.first << "," << pair.second << ") ";
    // }
    // cout << endl;

    head = removeDublicate(head);

    print(head);
    
    return 0;
}
