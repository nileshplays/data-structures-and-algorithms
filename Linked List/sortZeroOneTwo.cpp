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
void insertAtTail(Node* &tail, Node* temp){
    tail-> next = temp;
    tail = temp;
}

Node* sortList(Node *head){
    // Write your code here.
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* temp = head;
    while(temp != NULL){
        int value = temp -> data;
        if(value == 0){
            insertAtTail(zeroTail,temp);
        }
        else if(value ==1){
            insertAtTail(oneTail,temp);
        }
        else if(value ==2){
            insertAtTail(twoTail,temp);
        }
        temp= temp-> next;
    }
    if(oneHead->next != NULL){
        zeroTail-> next = oneHead->next;
    }
    else{
        zeroTail-> next = twoHead->next;
    }   
    oneTail-> next = twoHead-> next;
    twoTail ->next = NULL;
    
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    /*
    Node* temp= head;
    int zeroCnt=0;
    int oneCnt=0;
    int twoCnt=0;

    while(temp != NULL){
        if(temp-> data ==0){
            zeroCnt++;
        }
        else if(temp-> data ==1){
            oneCnt++;
        }
        else if(temp-> data ==2){
            twoCnt++;
        }
        temp = temp-> next;
    }
    temp = head;
    while(temp != NULL){
        if(zeroCnt > 0){
            temp-> data = 0;
            zeroCnt--;
        }
        else if(oneCnt > 0){
            temp -> data = 1;
            oneCnt--;
        }
        else if(twoCnt > 0){
            temp -> data = 2;
            twoCnt--;
        }
        temp = temp-> next;
    }
    */
    head = zeroHead->next;
    return head;

}