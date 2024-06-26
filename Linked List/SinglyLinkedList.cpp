#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //Destructor for freeing the Node 
    ~Node(){
        int value = this -> data;
        //memory free
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout<<"Memory is free for the data: "<<value <<endl;
    }
};

void insertAtHead(Node* &head , int data){

    //New node Creation
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;

}

void insertAtTail(Node* &tail, int value){
    Node* temp = new Node(value);
    tail -> next = temp;
    temp -> next = NULL;
    tail = temp;
}

void insertAtMiddle(Node* &head, Node* &tail, int position , int value){
    //If posito=ion ==1 then
    if(position == 1){
        insertAtHead(head, value);
        return;
    }
    
    //traverse to position-1 th place
    Node* temp = head;
    int count = 1;
    while(count < position-1){
        temp = temp -> next;
        count++;
    }

    //If inserting at last 
    if(temp -> next == NULL){
        insertAtTail(tail , value);
        return;
    }
    // New node
    Node* newNode = new Node(value);
    newNode -> next = temp ->next;
    temp -> next = newNode;
}

void deleteNode(Node* &head , int position){
    //Start node
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        //memory free
        temp -> next = NULL;
        delete temp;
    }
    else{
        //deleting any midddle node or the last node
        Node* current = head;
        Node* previous = head;
        int count = 1;
        while(count < position ){
            previous = current;
            current = current-> next;
            count++;
        }
        previous -> next = current -> next;
        current -> next = NULL;

        delete current;
    }
}

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp -> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    //Created a New Node
    cout<<"Linked List: "<<endl;
    Node* node1 = new Node(10);
    cout<< node1 -> data<<endl;
    // cout<< node1 -> next<<endl;

    //head Pointed to node 1
    Node* head = node1;

    //tail pointed to the node 1
    Node* tail = node1;

    //

    insertAtHead(head , 10);
    print(head);
    insertAtHead(head , 11);
    print(head);
    insertAtHead(head , 12);
    print(head);
    insertAtTail(tail, 13);
    print(head);
    insertAtTail(tail, 14);
    print(head);
    insertAtMiddle(head,tail,3, 15);
    print(head);
    insertAtMiddle(head,tail,1, 16);
    print(head);
    insertAtMiddle(head,tail,9, 17);
    print(head);
    deleteNode(head , 9);
    deleteNode(head , 1);
    deleteNode(head , 5);
    deleteNode(head , 2);

}
