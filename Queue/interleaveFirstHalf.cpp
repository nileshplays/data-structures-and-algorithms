#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeQueue(queue<int> &q){
        
    vector<int> ans;
    queue<int> newQ;
    
    int n = q.size();
    for(int i=0; i< n/2 ;i++){
        int ele = q.front();
        q.pop();
        newQ.push(ele);
        cout<<"Yes"<<endl;
    }
    
    while(!newQ.empty()){
        int first = newQ.front();
        ans.push_back(first);
        newQ.pop();
        int second = q.front();
        ans.push_back(second);
        q.pop();
        
    }
    
    return ans;
}

int main(){
    queue<int> q;
    for(int i=11 ; i<19;i++){
        q.push(i);
    }
    rearrangeQueue(q);

    return 0;
}