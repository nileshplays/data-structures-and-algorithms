class Solution{
    private:
    void insertattail(Node* &head, Node* &tail , int data) {
        Node* newNode = new Node(data);
        if(head == NULL) {
        head = newNode;
        tail = newNode;
            
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        Node* cloneHead = NULL;
        Node* clonetail = NULL;
        Node* temp = head;
        while(temp) {
            insertattail(cloneHead,clonetail,temp->data);
            temp = temp->next;
        }
       Node* originalNode = head;
       Node* cloneNode = cloneHead;
       while(originalNode && cloneNode) {
           Node* next = originalNode->next;
           originalNode->next  = cloneNode;
           originalNode = next;
           next= cloneNode->next;
           cloneNode->next = originalNode;
           cloneNode = next;
       }
        temp =head;
       while(temp) {
           if(temp->next) {
               temp->next->arb = temp->arb? temp->arb->next : temp->arb;
           }
           temp = temp->next->next;
       }
       originalNode = head;
       cloneNode = cloneHead;
       while(originalNode && cloneNode){
           originalNode->next = cloneNode->next;
           originalNode = originalNode->next;
           if(originalNode){
           cloneNode->next = originalNode->next;
           } 
           cloneNode = cloneNode->next;
       }
       return cloneHead;
    }

};