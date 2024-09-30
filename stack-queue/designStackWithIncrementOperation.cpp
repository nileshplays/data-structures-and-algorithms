#include<bits/stdc++.h>
using namespace std;

class CustomStack {
    int *stack;
    int capacity;
    int size;
    int index;    // index to track where to insert the element
public:
    CustomStack(int maxSize) {
        stack = new int[maxSize];
        capacity = maxSize;
        size = 0;
        index = -1;
    }
    
    void push(int x) {
        if(isFull())
            return;
        index++;
        size++;
        stack[index] = x;
    }
    
    int pop() {
        if(isEmpty())
            return -1;

        int value = stack[index];
        index--;
        size--;
        return value;
    }
    
    void increment(int k, int val) {
        if(isEmpty()){
            return;
        }
        
        int limit = min(size, k);
        for(int i =0; i < limit; i++){
            stack[i] += val;
        }
    }

private:
    bool isFull(){
        return size == capacity;
    }
    bool isEmpty(){
        return size == 0;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */