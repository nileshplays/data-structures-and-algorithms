#include <bits/stdc++.h>
#include<queue>
using namespace std;

/*
void push(queue<int>& q , int n){
    if(q.empty()){
        q.push(n);
        
    }
    else{
        return;
    }
}
*/

/*
int pop(queue<int>& q){
    if(q.empty()){
        return -1;
    }
    else{
        int ans = q.pop();
        return ans;
    }
}
*/

int main(){

    queue<int> q;

    q.push(1);
    q.push(4);
    q.push(3);
    cout<<"Queue Size: "<<q.size()<<endl;
    q.pop();
    cout<<"Queue Size: "<<q.size()<<endl;
    cout<<"Queue Front: "<<q.front()<<endl;
    // cour<<"Queue Rare: "<<q.rear()<<endl;
}
    