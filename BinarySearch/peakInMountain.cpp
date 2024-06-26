#include<bits/stdc++.h>
using namespace std;

int peakElement(int arr[], int n){
    int start = 0, end = n-1;
    int mid = start + (end - start)/2;
    while(start < end){
        if(arr[mid] < arr[mid+1]){
            start = mid+1;
        }
        else{
            end = mid;
        }
        mid = start + (end - start)/2;
    }
    return arr[start];
}

int main(){
    int arr[] = {1,3,4,5,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Peak Index: "<<peakElement(arr , n);

}