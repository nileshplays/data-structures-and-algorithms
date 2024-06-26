#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head)
{
    // Write your code here
    unordered_map<int, bool> visited;
    Node* curr = head;
    Node* previous = NULL;
    while(curr != NULL){
        if(visited[curr->data] == true){
            Node* nodetoDelete = curr;
            previous->next = curr->next;
            curr=curr->next;
            delete(nodetoDelete);
        }
        else{
            visited[curr->data] = true;
            curr=curr->next;
            if(previous ==NULL){
                previous=head;
            }
            else{
                previous = previous->next;
            }
        }
    }
    return head;
}