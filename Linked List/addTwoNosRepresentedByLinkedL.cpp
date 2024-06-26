//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    Node* reverse(Node* head){
        Node* curr = head;
        Node* next=NULL;
        Node* prev=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next = prev;
            prev= curr;
            curr = next;
        }
        return prev;
    }
    
    void insertAtTail(Node* &head, Node* &tail , int digit){
        Node* temp = new Node(digit);
        if(head ==NULL){
            head = temp;
            tail = temp;
            return;
        }
        tail -> next = temp;
        tail = temp;
    }
    
    struct Node* add(struct Node* first, struct Node* second){
        int carry = 0;
        Node* ansHead =NULL;
        Node* ansTail =NULL;
        
        while( first!= NULL || second!= NULL || carry!=0){
            
            int val1 =0;
            if(first!=NULL){
                val1 =first->data;
            }
            int val2 =0;
            if(second!=NULL){
                val2 =second->data;
            }
            int sum = carry + val1 + val2;
            int digit = sum% 10;
            insertAtTail(ansHead , ansTail, digit);
            
            carry = sum/10;
            
            if(first !=NULL)
                first = first->next;
            if(second !=NULL)
                second = second->next;
        }
        
        
        return ansHead;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        num1 = reverse(num1);
        num2 = reverse(num2);
        Node* ans = add(num1 , num2);
        
        ans = reverse(ans);
        while(ans!=NULL and ans->data==0){
            if(ans->next==NULL){
                return ans;
            }
            ans=ans->next;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends