/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node* solve(Node* head, int k,int len,int cur_len)

{
     if(head==NULL ) return NULL ;

    Node* curr=head;
    Node* nxt=NULL;
    Node* prev= NULL;
    int count=0;
    if(len-cur_len-k < 0 ) return head;

    while(curr!= NULL && count<k){
        nxt=curr->next;
        curr->next = prev;
        prev=curr;
        curr=nxt;
        count++;
        cur_len++;
    }
    if(nxt!=NULL){
        head -> next = solve(nxt, k,len,cur_len) ;
    }
    return prev;

}

Node* kReverse(Node* head, int k) {

    int len=0;
    Node* curr=head;
    while(curr!=NULL){
        len++;
        curr=curr->next;
    }
    return solve(head,k,len,0) ;

    /*
    // Base Case
    if(head == NULL){
        return NULL;
    }
    //step1: reverse first k nodes
    Node* forward = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while(curr!= NULL && (count < k)){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    //step2: recursion call
    if(forward!=NULL){
        head ->next = kReverse(forward, k);
    }
    //step3: return head of reversed list
    return prev;
    */
}