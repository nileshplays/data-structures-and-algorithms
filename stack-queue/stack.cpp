#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
        int *arr;
        int top;
        int size;
    
    Stack(int size){
        this -> size =size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(size -top >1){
            top++;
            arr[top] =element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }
    int peek(){
        if(top >=0 ){
            return arr[top];
        }
        else{
            cout<<"Stack is Empty"<<endl;
        }
    }
    bool isEmpty(){
        if(top >= 0){
            return 0;
        }
        else{
            return 1;
        }
    }
};


int main(){

    /*
    //creation
    stack<int> s;
    s.push(2);
    s.push(4);
    s.push(8);
    cout<<s.top()<<endl;
    // s.peek();

    s.pop();
    // cout<<s<<endl;
    // s.empty();
    // cout<<s<<endl;
    */

   Stack st(5);
   st.push(12);
   st.push(9);
   cout<< st.peek() <<endl;
   st.pop();
   cout<< st.peek() <<endl;
   cout<< st.isEmpty() <<endl;


    return 0;    
}
