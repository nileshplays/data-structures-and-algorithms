#include <bits/stdc++.h> 
class NQueue{
public:
    // Initialize your data structure.
    int n , k;
    int* front;
    int* rear;
    int* arr;
    int* next;
    int freespot;
    NQueue(int n, int k){
        // Write your code here.
        this -> n=n;
        this ->k =k;
        front = new int[k];
        rear = new int[k];
        for(int i=0 ; i<k ; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for(int i=0 ; i<n ; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
        arr = new int[n];
        freespot = 0;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        // Overflow condition checl
        if(freespot = -1){
            return false;
        }
        //find first free index
        int index= freespot;
        //UPDATE freespot
        freespot = next[index];

        //check weather first element
        if(front[m-1] == -1){
                front[m-1] = index;
        }
        else{
            //link new element to the new element
            next[rear[m-1]] = index;
        }
        //UPdate next as theres no freespot available
        next[index] = -1;
        //update rear
        rear[m-1] = -1;
        //push element
        arr[index] = x;

        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        //UNDERFLOW condition check
        if(front[m-1] == -1){
            return -1;
        }
        //find index to pop
        int index = front[m-1];
        //front ko aage badhao
        front[m-1] = next[index];
        //freeslots ko manage karo
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};