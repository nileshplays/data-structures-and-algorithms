#include<bits/stdc++.h>
using namespace std;

printArray(int arr[] , int n){
    for(int i=0 ; i < 9 ; i++){
        cout<<arr[i]<<" ";
    }
    cout<< endl;
}
void sortOne(int arr[] , int n){
    int left=0 , right=n-1;
    while(left < right){
        while(arr[left]==0 && left< right){
            left++;
        }
        while(arr[right]==1 && left<right){
            right--;
        }
        if(left  < right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
        
    }
}

int main(){
    int arr[8]={1,1,0,0,0,0,1,0};
    sortOne(arr , 9);
    printArray(arr,9);
}