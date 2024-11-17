#include<bits/stdc++.h>
using namespace std;

void solve(int index,int n,int arr[], int sum, vector<int> &ds, int k , int &count){

    if(index == n){
        if(sum == k){
            count++;
            for(auto it: ds)
                cout<<it<<" ";
            cout<<endl;
        }
        return;
    }

    ds.push_back(arr[index]);
    sum += arr[index];
    solve(index+1 , n , arr, sum, ds , k, count);
    ds.pop_back();
    sum -= arr[index];
    solve(index+1, n , arr, sum, ds, k , count);

}

int main(){
    int arr[] = {1,1,2,2};
    int n = 4;
    vector<int> ds;
    int k = 4;
    int count = 0;
    solve(0, n ,arr, 0, ds , k , count);

    cout<<"Count: "<<count<<endl;
    
}