#include<bits/stdc++.h>
using namespace std;

void fact(int index, vector<int> &arr,vector<int> &ans, vector<vector<int>> &finalAns){
    int n = arr.size();

    if(index >= n){
        finalAns.push_back(ans);
        return;
    }

    ans.push_back(arr[index]);
    fact(index+1, arr,ans, finalAns);
    ans.pop_back();
    fact(index+1,arr, ans, finalAns);
}

int main(){
    vector<int> arr= {3,1,2};
    vector<int> ans;
    vector<vector<int>> finalAns;
    fact(0,arr,ans , finalAns);
    for(int i=0; i<finalAns.size(); i++){
        for(int j =0; j<finalAns[i].size(); j++){
            cout<<finalAns[i][j]<<" ";
        }
        cout<<endl;
    }
}