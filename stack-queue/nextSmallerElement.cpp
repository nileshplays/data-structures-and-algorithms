#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for(int i=n-1 ; i >=0 ; i--){

        int current = arr[i];
        while( s.top() >= current){
            s.pop();
        }
        ans[i] = s.top();
        s.push(current);
    }
    
return ans;

    
}