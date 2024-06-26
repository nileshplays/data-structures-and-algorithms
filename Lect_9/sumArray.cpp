#include<iostream>
using namespace std;
int main(){
    int n,sum=0, arr[20];
    cin>>n;
    for(int i=0; i<n ;i++){
        cin>> arr[i];
        sum+= arr[i];
    }
    cout<< "SUM:  "<<sum<<endl;
    return 0;
}