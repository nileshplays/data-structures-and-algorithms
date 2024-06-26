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

void insertNode(Node* &tail ,int element, int data){
    //If Empty List
    if(tail == NULL){
        Node* newNode = new Node(data);
        tail =  newNode;
        newNode -> next = newNode;
    }
    else{
        //Non-Empty list
        //assuming element already in the list
        Node* current = tail;
        while( current-> data != element){
            current = current -> next;

        }
        //element found
        Node* temp = new Node(data);
        temp -> next = current -> next;
        current -> next = temp;
    }
}

void deleteNode(Node* &tail , int element){
    if(tail == NULL){
        cout<<"List is empty,, Please check again"<<endl;
        return;
    }
    else{
        // Assuming Value is present in listy
        Node* previous =tail;
        Node* current = previous -> next;
        while(current -> data != element){
            previous = current;
            current = current -> next;

        }
        previous-> next = current -> next;
        
        //one node list
        if(current == previous){
            tail == NULL;
            cout<<"List is Empty: "<<endl;
        }
        else if(tail ==current){
            tail = previous;
        }
        current -> next = NULL;
        delete current;

    }
}

void printNode(Node* tail){
    Node* temp = tail;
    if(tail == NULL){
        cout<<"List io empty: "<<endl;
        return;
    }
    do{
        cout << tail-> data<<" ";
        tail = tail -> next;
    }
    while(tail != temp);
    cout<<endl;
}

int main(){
    Node* tail = NULL;
    insertNode(tail, 5 ,3);
    printNode(tail);
    insertNode(tail, 3 ,2);
    printNode(tail);
    insertNode(tail, 2 ,1);
    printNode(tail);
    insertNode(tail, 2 ,1);
    printNode(tail);

    deleteNode(tail , 3);
    printNode(tail);
    deleteNode(tail , 1);
    printNode(tail);
    deleteNode(tail , 1);
    printNode(tail);
    deleteNode(tail , 2);
    printNode(tail);
    
}