#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
        this -> prev = NULL;
    }

    //Destructor to free dynamically allocated memory
    ~Node(){
        int value = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory free for value: "<<value<<endl;
    }
};
//Traversing a Linked List
void printNode(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp -> data <<" ";
        temp = temp -> next;
    }
    cout<< endl;
}
//Length of a linked list
int getLengthNode(Node* head){
    cout<<"Length of the List is: ";
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

//Insert at head
void insertAtHead(Node* &head, Node* &tail ,int data){
    //if empty list
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
    
}
//Insertion at TAIL
void insertAtTail(Node* &head,Node* &tail ,int data){
    //if empty list
    if(tail == NULL){
        Node* temp = new Node(data);
        tail == temp;
        head = temp;
    }
    else{
        Node* temp = new Node(data);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void insertAtMiddle(Node* &head , Node* &tail , int position , int data){
    //If position is First
    if(position == 1){
        insertAtHead(head , tail ,data);
        return;
    }
    Node* temp = head;
    int count = 1;
    while(count < position-1){
        temp = temp -> next;
        count++;
    }
    //if position is last
    if(temp -> next == NULL){
        insertAtTail(head,tail, data);
        return;
    }
    //Creating the new node with the data
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    nodeToInsert-> prev = temp;
    temp -> next = nodeToInsert;
    temp -> next -> prev = nodeToInsert;

}
void deleteNode(Node* &head,Node* &tail, int position){
    Node* temp = head;
    if(position == 1){
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;

        delete temp;
    }
    else{
        int count =1;
        Node* current = head;
        Node* previous = head;
        while(count < position){
            previous = current;
            current = current -> next;
            count++;
        }
        // current -> next -> prev = previous;
        previous -> next = current -> next;
        current -> prev  = NULL;
        current -> next = NULL;
        if(position > 2){
            tail = previous;
        }

        delete current;
    }
}


int main(){
    cout<<"Doubly Linked List: "<<endl;
    // Node* node1 = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;
    // cout<<getLengthNode(head)<<endl;
    insertAtHead(head , tail, 9);
    // insertAtHead(head , tail, 1);
    printNode(head);
    // cout<<getLengthNode(head)<<endl;
    insertAtTail(head,tail , 11);
    // insertAtTail(head,tail , 20);
    printNode(head);
    // cout<<getLengthNode(head)<<endl;
    insertAtMiddle(head , tail , 1, 8);
    printNode(head);
    insertAtMiddle(head , tail , 2, 12);
    printNode(head);
    insertAtMiddle(head , tail , 4, 13);
    printNode(head);
    insertAtMiddle(head , tail , 6, 14);
    // printNode(head);
    printNode(head);
    cout<<getLengthNode(head)<<endl;

    deleteNode(head,tail , 2);
    cout<<"Tail at value: "<<tail-> data<<endl;
    deleteNode(head ,tail, 1);
    cout<<"Tail at value: "<<tail-> data<<endl;
    deleteNode(head ,tail, 4);
    cout<<"Tail at value: "<<tail-> data<<endl;
    printNode(head);
    cout<<getLengthNode(head)<<endl;

}