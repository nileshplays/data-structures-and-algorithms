/*
Following is the class structure of the Node class:

class Node
{
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
*/
Node* getMiddle(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* fast =head->next;
    Node* slow= head;
    while(fast != NULL){
        fast= fast->next;
        if(fast!=NULL){
            fast =fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

Node *findMiddle(Node *head) {
    // Write your code here
    //OPTIMIZED APPROACH
    return getMiddle(head);


    /*BRUTE FORCE
    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node* temp = head;
    int count = 1;
    while(temp-> next != NULL){
        temp = temp -> next;
        count++;
    }
    Node* traverse = head;
    int n =count/2;
    int i=0;
    while(i<n-1){
        traverse = traverse -> next;
        i++;
    }
    return traverse->next;
    */
}

