#include<iostream>
using namespace std;
void reverseArray(int arr[], int n){
    int start=0, end=n-1;
    while(start <= end){
        swap(arr[start], arr[end]);
        start ++; end--;
    }
}
void printArray(int arr[], int n){
    for(int i=0 ; i<n ;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n, arr[20];
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enetr the elements: ";
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    reverseArray(arr,n);
    printArray(arr, n);
    return 0;
}