#include<bits/stdc++.h>
using namespace std;

int peakIndex(int arr[],int n){
    int sum =0, left =0;
    for(int i=0 ; i<n ; i++){
        sum += arr[i];
    }
    int right = sum;
    for(int i=0 ; i<n ; i++){
        left+=arr[i];
        if(left == right){
            return i;
        }
        right -= arr[i];
    }
    return -1;

}

int main(){
    int arr[] = {1,7,3,4,6,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Peak Index: "<<peakIndex(arr , n);

}