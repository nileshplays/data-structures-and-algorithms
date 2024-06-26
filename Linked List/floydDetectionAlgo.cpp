#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this-> data =data;
        this-> next =NULL;
    }
};

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp -> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

Node* floydDetect(Node* &head){

    if(head==NULL) 
        return NULL;
    Node* slow = head;
    Node* fast = head;
    // return slow;
    // cout<<"Slow: "<<slow->data<<endl;
    while(slow !=NULL && fast !=NULL)
    {
        fast =fast-> next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow-> next;
        if(slow == fast){
            
            return slow;
        }
    }
    return NULL;

}

Node* getStartingNode(Node* head){
    if(head==NULL) {
        return NULL;
    }
    // cout<<"YEs"<<endl;
    
    Node* intersection = floydDetect(head);
    Node* slow = head;
    bool flag =1;
    int interData = intersection->data;
    int slowData = slow->data;
    cout<<"InterSection: "<<interData<<endl;
    cout<<"Slow data: "<<slow-> data<<endl;
    while(intersection != slow){
        cout<<"YEs"<<endl;
        slow = slow-> next;
        intersection = intersection-> next;
        if(slow == intersection){
            cout<<"Loop Detected at: "<<endl;
            return slow;
        }
        // flag=0;
    }
    return NULL;

}
void removeLoop(Node* &head){
    if(head ==NULL){
        return ;
    }
    Node* startNode = getStartingNode(head);
    Node* temp = startNode;
    while(temp -> next != startNode){
        temp = temp-> next;
    }
    temp->next = NULL;
}

int main(){
    Node* head = new Node(1);
    Node* node2 =new Node(2);
    Node* node3 =new Node(3);

    Node* newNode = new Node(4);
    Node* tail = new Node(5);
    head->next= node2;
    node2->next=node3;
    node3->next=newNode;
    newNode-> next = tail;
    print(head);
    tail->next =node2;

    // cout<<"HEAD: "<<head->data<<endl;
    Node* detect =floydDetect(head);
    cout<<"HEAD: "<<head->data<<endl;
    cout<<"Detected: "<<detect->data<<endl;
    Node* loop = getStartingNode(head);
    cout<<loop->data<<endl;
    removeLoop(head);
    print(head);
}