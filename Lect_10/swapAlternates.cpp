#include<iostream>
using namespace std;
void swapAlternates(int arr[], int n){
    for (int i = 0; i < n; i+=2)
    {
        if((i+1) < n){
            swap(arr[i],arr[i+1]);
        }
    }
    
}
void printArray(int arr[], int n){
    cout<<"Swapped array: "<<endl;
    for(int i=0 ; i<n ;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n, arr[20];
    cout<<"Enetr the size : ";
    cin>>n;
    cout<<"Enter the elements: "<<endl;
    for(int i=0 ;i<n ; i++){
        cin>>arr[i];
    }
    swapAlternates(arr,n);
    printArray(arr,n);

    return 0;
}