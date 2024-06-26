#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[] ,int n, int key){
    int left=0, right=n-1;
    int mid = left+ (right - left)/2;              // if we directly add it may go out of integer range so manupulating the formula
    while(left <= right){
        if(arr[mid] == key){
            return mid;
        }
        if( key > arr[mid]){
            left= mid+1;
        }
        else{
            right = mid-1;
        }
        mid = left+ (right - left)/2;
    }
    return -1;
}

int main(){
    int arr[20],n,key;
    // cout<<"Enter the no. of elements: ";
    // cin>>n;
    cout<<"Enter the no. of elements and key value: ";
    cin>>n>>key;
    
    for(int i=0 ; i< n ;i++){
        cin>>arr[i];
    }
    cout<<"The key value is at "<<binarySearch(arr,n,key)<<" th index.";
    return 0;
}