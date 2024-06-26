LinkedListNode<int> * solve(LinkedListNode<int> *head, LinkedListNode<int> *prev, LinkedListNode<int> *curr)
{
    // base case
    if(curr == NULL)
        return prev;
    LinkedListNode<int> *forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    return solve(head, prev, curr);
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here

    //RECURSIVE APPROACH
      if(head == NULL || head->next == NULL)
    {
        return head;
    }
    else
    {
        LinkedListNode<int> *prev = NULL;
        LinkedListNode<int> *curr = head;
        return solve(head, prev, curr);
    }

    /*
    //ITERATIVE APPROACH
    if(head == NULL || head -> next == NULL){
        return head;
    }
    LinkedListNode<int>* current = head;
    LinkedListNode<int>* previous = NULL;
    LinkedListNode<int>* forward = NULL;

    while(current != NULL){
        forward = current -> next;
        current -> next = previous;
        previous = current;
        current = forward;
    }
    head = previous;
    return head;
    */

}